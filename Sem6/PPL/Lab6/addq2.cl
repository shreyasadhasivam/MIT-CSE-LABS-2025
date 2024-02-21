 __kernel void strCpy(__global char *s, __global char *res, int len) {
    int tid = get_global_id(0);

    // Get the input character
    char c = s[tid];
    
    // Duplicate characters based on their position
    for (int i = 0; i < len; i++) {
        if (i == tid || i == tid + 1) {   //Duplicate characters for positions tid and tid + 1
            res[tid * len + i] = c;
        } else {                         // Fill remaining characters with 'i'
            res[tid * len + i] = 'i';
        }
    }
}