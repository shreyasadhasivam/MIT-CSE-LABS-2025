
#include <stdio.h>

#define SIZE 5

__global__ void convolution_2d(int *input, int *mask, int *output) {
    int row = blockIdx.y * blockDim.y + threadIdx.y;
    int col = blockIdx.x * blockDim.x + threadIdx.x;

    if (row < SIZE && col < SIZE) {
        int sum = 0;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                int idx = (row + i - SIZE/2) * SIZE + (col + j - SIZE/2);
                if (idx >= 0 && idx < SIZE*SIZE) {
                    sum += input[idx] * mask[i*SIZE+j];
                }
            }
        }
        output[row * SIZE + col] = sum;
    }
}

int main() {
    int input[SIZE*SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25};
    int mask[SIZE*SIZE] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int output[SIZE*SIZE] = {0};

    int *d_input, *d_mask, *d_output;

    cudaMalloc(&d_input, SIZE*SIZE*sizeof(int));
    cudaMalloc(&d_mask, SIZE*SIZE*sizeof(int));
    cudaMalloc(&d_output, SIZE*SIZE*sizeof(int));

    cudaMemcpy(d_input, input, SIZE*SIZE*sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(d_mask, mask, SIZE*SIZE*sizeof(int), cudaMemcpyHostToDevice);

    dim3 threadsPerBlock(32, 32);
    dim3 numBlocks((SIZE + 31)/32, (SIZE + 31)/32);

    convolution_2d<<<numBlocks, threadsPerBlock>>>(d_input, d_mask, d_output);

    cudaMemcpy(output, d_output, SIZE*SIZE*sizeof(int), cudaMemcpyDeviceToHost);

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", output[i*SIZE+j]);
        }
        printf("\n");
    }

    cudaFree(d_input);
    cudaFree(d_mask);
    cudaFree(d_output);

    return 0;
}
