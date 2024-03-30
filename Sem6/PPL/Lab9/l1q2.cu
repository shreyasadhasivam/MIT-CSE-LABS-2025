#include <stdio.h>
#include <cuda_runtime.h>

#define N 3  // Size of matrices

__global__ void addMatricesRow(int* A, int* B, int* C) {
    int i = blockIdx.x;  // Each row computed by one thread
    for (int j = 0; j < N; j++) {
        C[i * N + j] = A[i * N + j] + B[i * N + j];
    }
}

__global__ void addMatricesColumn(int* A, int* B, int* C) {
    int j = blockIdx.x;  // Each column computed by one thread
    for (int i = 0; i < N; i++) {
        C[i * N + j] = A[i * N + j] + B[i * N + j];
    }
}

__global__ void addMatricesElement(int* A, int* B, int* C) {
    int idx = threadIdx.x + blockIdx.x * blockDim.x;  // Each element computed by one thread
    int i = idx / N;
    int j = idx % N;
    if (i < N && j < N) {
        C[i * N + j] = A[i * N + j] + B[i * N + j];
    }
}

int main() {
    int A[N * N] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int B[N * N] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int C[N * N] = {0};

    int *d_A, *d_B, *d_C;
    cudaMalloc((void**)&d_A, N * N * sizeof(int));
    cudaMalloc((void**)&d_B, N * N * sizeof(int));
    cudaMalloc((void**)&d_C, N * N * sizeof(int));
    cudaMemcpy(d_A, A, N * N * sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(d_B, B, N * N * sizeof(int), cudaMemcpyHostToDevice);

    // Add matrices using rows
    addMatricesRow<<<N, 1>>>(d_A, d_B, d_C);
    printf("\nRows\n");
    cudaMemcpy(C, d_C, N * N * sizeof(int), cudaMemcpyDeviceToHost);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ",C[i * N + j]);
        }
        printf("\n");
    }
    // Add matrices using columns
    printf("\nColumns\n");
    addMatricesColumn<<<N, 1>>>(d_A, d_B, d_C);
    cudaMemcpy(C, d_C, N * N * sizeof(int), cudaMemcpyDeviceToHost);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ",C[i * N + j]);
        }
        printf("\n");
    }

    // Add matrices using elements
    printf("\nElements\n");
    addMatricesElement<<<(N * N + 255) / 256, 256>>>(d_A, d_B, d_C);

    cudaMemcpy(C, d_C, N * N * sizeof(int), cudaMemcpyDeviceToHost);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ",C[i * N + j]);
        }
        printf("\n");
    }

    cudaFree(d_A);
    cudaFree(d_B);
    cudaFree(d_C);

    return 0;
}
