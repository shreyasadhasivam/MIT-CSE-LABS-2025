#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <cuda_runtime.h>
#define BLOCK_WIDTH 2
#define TILE_WIDTH 2
#define WIDTH 2
__device__ int getTid() {
	int blockSkip = (blockIdx.y * gridDim.x * blockDim.x * blockDim.y);
	int rowSkip = (threadIdx.y * gridDim.x * blockDim.x);
	int rowDisplacement = (blockIdx.x * blockDim.x) + threadIdx.x;
	int tid = blockSkip + rowSkip + rowDisplacement;
	return tid;
}
__global__ void MatAddElementThread(int *a, int *b, int *d) {
	int row = blockIdx.y * blockDim.y + threadIdx.y;
    int col = blockIdx.x * blockDim.x + threadIdx.x;

    int sum = 0;
    for (int k = 0; k < WIDTH; k++) {
        sum += a[row * WIDTH + k] * b[k * WIDTH + col];
    }

    d[row * WIDTH + col] = sum;
}

int main() {
	int *matA, *matB, *matSum;
	int *da, *db, *dc;
	printf("\n== Enter elements of Matrix A==\n");
	matA = (int*)malloc(sizeof(int) * WIDTH * WIDTH);
	for(int i = 0; i < WIDTH * WIDTH; i++)
	{
	scanf("%d", &matA[i]);
	}
	printf("\n== Enter elements of Matrix B==\n");
	matB = (int*)malloc(sizeof(int) * WIDTH * WIDTH);
	for(int i = 0; i < WIDTH * WIDTH; i++)
	{
	scanf("%d", &matB[i]);
	}
	matSum = (int*)malloc(sizeof(int) * WIDTH * WIDTH);
	cudaMalloc((void **) &da, sizeof(int) * WIDTH * WIDTH);
	cudaMalloc((void **) &db, sizeof(int) * WIDTH * WIDTH);
	cudaMalloc((void **) &dc, sizeof(int) * WIDTH * WIDTH);
	cudaMemcpy(da, matA, sizeof(int) * WIDTH *WIDTH, cudaMemcpyHostToDevice);
	cudaMemcpy(db, matB, sizeof(int) * WIDTH *WIDTH, cudaMemcpyHostToDevice);
	int NumBlocks = WIDTH / BLOCK_WIDTH;
	dim3 grid_conf (NumBlocks, NumBlocks);
	dim3 block_conf (BLOCK_WIDTH, BLOCK_WIDTH);
	MatAddElementThread<<<grid_conf, block_conf>>>(da, db, dc);
	cudaMemcpy(matSum,dc,sizeof(int)* WIDTH *WIDTH,cudaMemcpyDeviceToHost);
	printf("\n-=Result=-\n");
	printf("----------------------\n");
	for (int i = 0; i < WIDTH; i++ ) {
	for (int j = 0; j < WIDTH; j++) {
	printf("%6d ", matSum[i * WIDTH + j]);
	}
	printf("\n");
	}
	cudaFree(da);
	cudaFree(db);
	cudaFree(dc);
	free(matA);
	free(matB);
	free(matSum);
	return 0;
}