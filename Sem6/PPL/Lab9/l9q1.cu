#include <stdio.h>

__global__ void rowOperations(int *matrix, int rows, int cols) {
    int row = blockIdx.x;
    int col = threadIdx.x;

    int index = row * cols + col;

    if (row == 0) {
        // do nothing, keep original values
    } else if (row % 2 == 1) {
        // square elements
        matrix[index] = matrix[index] * matrix[index];
    } else {
        // cube elements
        matrix[index] = matrix[index] * matrix[index] * matrix[index];
    }
}

int main() {
    int rows, cols;

    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    int size = rows * cols * sizeof(int);
    int *matrix, *d_matrix;

    matrix = (int *) malloc(size);
    cudaMalloc(&d_matrix, size);

    printf("Enter elements of matrix (%dx%d): \n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i * cols + j]);
        }
    }

    cudaMemcpy(d_matrix, matrix, size, cudaMemcpyHostToDevice);

    dim3 grid(rows, 1);
    dim3 block(cols, 1);
    rowOperations<<<grid, block>>>(d_matrix, rows, cols);

    cudaMemcpy(matrix, d_matrix, size, cudaMemcpyDeviceToHost);

    printf("\nMatrix after row operations: \n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i * cols + j]);
        }
        printf("\n");
    }

    free(matrix);
    cudaFree(d_matrix);

    return 0;
}
