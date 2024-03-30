#include <stdio.h>
#include <stdlib.h>

__global__ void csr_matrix_vector_multiplication(int *row_ptr, int *col_index, float *values, float *vector, float *result, int rows) {
    int row = blockIdx.x * blockDim.x + threadIdx.x;
    
    if(row < rows) {
        float sum = 0.0;
        for(int j = row_ptr[row]; j < row_ptr[row + 1]; j++) {
            sum += values[j] * vector[col_index[j]];
        }
        result[row] = sum;
    }
}

int main() {
    int rows = 3;
    int cols = 3;
    
    // CSR format for a 3x3 matrix
    int row_ptr[4] = {0, 2, 3, 4};
    int col_index[4] = {0, 2, 1, 2};
    float values[4] = {1.0, 2.0, 3.0, 4.0};
    
    float vector[3] = {1.0, 2.0, 3.0};
    float result[3];
    
    int *d_row_ptr, *d_col_index;
    float *d_values, *d_vector, *d_result;
    
    cudaMalloc(&d_row_ptr, 4 * sizeof(int));
    cudaMemcpy(d_row_ptr, row_ptr, 4 * sizeof(int), cudaMemcpyHostToDevice);
    
    cudaMalloc(&d_col_index, 4 * sizeof(int));
    cudaMemcpy(d_col_index, col_index, 4 * sizeof(int), cudaMemcpyHostToDevice);
    
    cudaMalloc(&d_values, 4 * sizeof(float));
    cudaMemcpy(d_values, values, 4 * sizeof(float), cudaMemcpyHostToDevice);
    
    cudaMalloc(&d_vector, 3 * sizeof(float));
    cudaMemcpy(d_vector, vector, 3 * sizeof(float), cudaMemcpyHostToDevice);
    
    cudaMalloc(&d_result, 3 * sizeof(float));
    
    int block_size = 32;
    int num_blocks = (rows + block_size - 1) / block_size;
    
    csr_matrix_vector_multiplication<<<num_blocks, block_size>>>(d_row_ptr, d_col_index, d_values, d_vector, d_result, rows);
    
    cudaMemcpy(result, d_result, 3 * sizeof(float), cudaMemcpyDeviceToHost);
    
    for(int i = 0; i < rows; i++) {
        printf("Result[%d] = %.2f", i, result[i]);
    }
    
    cudaFree(d_row_ptr);
    cudaFree(d_col_index);
    cudaFree(d_values);
    cudaFree(d_vector);
    cudaFree(d_result);
    
    return 0;
}
