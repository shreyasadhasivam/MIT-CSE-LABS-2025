__kernel void dec_to_octal(__global int *B, __global int *C)
{
    // Get the index of the current work item
    int i = get_global_id(0);

    // Do the operation
    int n = 1;

    while (B[i] != 0) {
        C[i] += (B[i] % 8) * n;
        B[i] /= 8;
        n *= 10;
    }


}