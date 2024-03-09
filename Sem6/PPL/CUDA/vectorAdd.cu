#include<stdio.h>

__global__ void vector_add(float *out, float *a, float *b, int n) {
    for(int i = 0; i < n; i++){
        out[i] = a[i] + b[i];
    }
}

int main(){
    float *a, *b, *out; 
    float *d_a, *d_b, *d_out;
    float N;

    printf("Enter number of elements:");
    scanf("%f",&N);
    // Allocate memory
    a   = (float*)malloc(sizeof(float) * N);
    b   = (float*)malloc(sizeof(float) * N);
    out = (float*)malloc(sizeof(float) * N);

    // Initialize array
    for(int i = 0; i < N; i++){
        a[i] = i;
        b[i] = i+5;
    }

    //allocate device memory
    cudaMalloc((void**)&d_a,sizeof(float)*N);
    cudaMalloc((void**)&d_b,sizeof(float)*N);
    cudaMalloc((void**)&d_out,sizeof(float)*N);


    //transfer data from host to device memory
    cudaMemcpy(d_a,a,sizeof(float)*N,cudaMemcpyHostToDevice);
    cudaMemcpy(d_a,a,sizeof(float)*N,cudaMemcpyHostToDevice);

    // Main function
    vector_add<<<1,1>>>(out, a, b, N);

    //transfer data back to host memory
    cudaMemcpy(out,d_out,sizeof(float)*N,cudaMemcpyDeviceToHost);
    printf("A vector: ");
    for(int i=0;i<N;i++)
    {
        printf("%.2f ",a[i]);
    }
    printf("B vector: ");
    for(int i=0;i<N;i++)
    {
        printf("%.2f ",b[i]);
    }
    printf("Resultant vector: ");
    for(int i=0;i<N;i++)
    {
        printf("%.2f ",out[i]);
    }

    printf("out[0] = %f\n", out[0]);
    printf("PASSED\n");

    cudaFree(d_a);
    free(a);
}