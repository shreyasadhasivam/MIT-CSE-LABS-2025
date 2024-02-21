__kernel void onecomplement(__global int *B, __global int *C)
{
	// Get the index of the current work item
	int i = get_global_id(0);
	
	// Do the operation
	
	if(B[i] == 1)
    {
        C[i] = 0

    }
    else if(B[i] == 0)
    {
        C[i] = 1;
    }
        
	
}