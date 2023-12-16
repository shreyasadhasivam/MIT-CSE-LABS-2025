#include <stdio.h>
#include <stdlib.h>
#include<limits.h>
struct mab {
    int offset;
    int size;
    int allocated;
    struct mab *next;
    struct mab *prev;
};

typedef struct mab Mab;
typedef Mab *MabPtr;
MabPtr memSplit(MabPtr m, int size) {
    // Split a memory block into two parts, one allocated and one free.
    if (m->size > size) {
        MabPtr newBlock = (MabPtr)malloc(sizeof(Mab));
        newBlock->offset = m->offset + size;
        newBlock->size = m->size - size;
        newBlock->allocated = 0;
        newBlock->next = m->next;
        newBlock->prev = m;

        if (m->next != NULL) {
            m->next->prev = newBlock;
        }

        m->size = size;
        m->next = newBlock;
    }
    return m;
}

MabPtr memMerge(MabPtr m) {
    // Merge adjacent free memory blocks.
    MabPtr current = m;
    
    while (current != NULL && current->next != NULL) {
        if (current->allocated == 0 && current->next->allocated == 0) {
            current->size += current->next->size;
            current->next = current->next->next;
            if (current->next != NULL) {
                current->next->prev = current;
            }
        }
        current = current->next;
    }
    
    return m;
}
MabPtr memFree(MabPtr m) {
    // Free a memory block.
    m->allocated = 0;
    // Merge adjacent free blocks.
    return memMerge(m);
}
MabPtr memChk(MabPtr m, int size) {
    // Find the best-fit memory block in terms of size.
    MabPtr bestFitBlock = NULL;
    int bestFitSize = INT_MAX;

    while (m != NULL) {
        if (m->allocated == 0 && m->size >= size && m->size < bestFitSize) {
            bestFitSize = m->size;
            bestFitBlock = m;
        }
        m = m->next;
    }

    return bestFitBlock;
}

MabPtr memAlloc(MabPtr m, int size) {
    // Allocate memory block of the specified size using Best Fit policy.
    MabPtr block = memChk(m, size);

    if (block != NULL) {
        if (block->size > size) {
            // Split the block if it's larger than needed.
            memSplit(block, size);
        }
        block->allocated = 1;
    }

    return block;
}

MabPtr memChkWorstFit(MabPtr m, int size) {
    // Find the worst-fit memory block in terms of size.
    MabPtr worstFitBlock = NULL;
    int worstFitSize = -1;

    while (m != NULL) {
        if (m->allocated == 0 && m->size >= size && m->size > worstFitSize) {
            worstFitSize = m->size;
            worstFitBlock = m;
        }
        m = m->next;
    }

    return worstFitBlock;
}

MabPtr memAllocWorstFit(MabPtr m, int size) {
    // Allocate memory block of the specified size using Worst Fit policy.
    MabPtr block = memChkWorstFit(m, size);

    if (block != NULL) {
        if (block->size > size) {
            // Split the block if it's larger than needed.
            memSplit(block, size);
        }
        block->allocated = 1;
    }

    return block;
}

void worstfit(){
    // Initialize memory linked list.
    MabPtr memory = (MabPtr)malloc(sizeof(Mab));
    memory->offset = 0;
    memory->size = 1024; // Total available memory size.
    memory->allocated = 0;
    memory->next = NULL;
    memory->prev = NULL;

    // Allocate and free memory blocks using Worst Fit policy.
    MabPtr block1 = memAllocWorstFit(memory, 128);
    MabPtr block2 = memAllocWorstFit(memory, 256);

    if (block1 != NULL) {
        printf("Allocated Block 1: Offset %d, Size %d\n", block1->offset, block1->size);
    } else {
        printf("Failed to allocate Block 1.\n");
    }

    if (block2 != NULL) {
        printf("Allocated Block 2: Offset %d, Size %d\n", block2->offset, block2->size);
    } else {
        printf("Failed to allocate Block 2.\n");
    }

    // Clean up memory.
    free(memory);
}


void firstfit() {
    // Initialize memory linked list.
    MabPtr memory = (MabPtr)malloc(sizeof(Mab));
    memory->offset = 0;
    memory->size = 1024; // Total available memory size.
    memory->allocated = 0;
    memory->next = NULL;
    memory->prev = NULL;

    // Allocate and free memory blocks.
    MabPtr block1 = memAlloc(memory, 128);
    MabPtr block2 = memAlloc(memory, 256);
    //MabPtr block3 = memAlloc(memory, 512);
    
    printf("Allocated Block 1: Offset %d, Size %d\n", block1->offset, block1->size);
    printf("Allocated Block 2: Offset %d, Size %d\n", block2->offset, block2->size);
    //printf("Allocated Block 3: Offset %d, Size %d\n", block3->offset, block3->size);

    memFree(block1);
    memFree(block2);
    //memFree(block3);

    printf("Freed Block 1 and Block 2\n");

    // Clean up memory.
    free(memory);
    
}

void bestfit()
{
    // Initialize memory linked list.
    MabPtr memory = (MabPtr)malloc(sizeof(Mab));
    memory->offset = 0;
    memory->size = 1024; // Total available memory size.
    memory->allocated = 0;
    memory->next = NULL;
    memory->prev = NULL;

    // Allocate and free memory blocks using Best Fit policy.
    MabPtr block1 = memAlloc(memory, 128);
    MabPtr block2 = memAlloc(memory, 256);

    if (block1 != NULL) {
        printf("Allocated Block 1: Offset %d, Size %d\n", block1->offset, block1->size);
    } else {
        printf("Failed to allocate Block 1.\n");
    }

    if (block2 != NULL) {
        printf("Allocated Block 2: Offset %d, Size %d\n", block2->offset, block2->size);
    } else {
        printf("Failed to allocate Block 2.\n");
    }

    // Clean up memory.
    free(memory);


}

int main()
{
    printf("First fit Implementation\n\n");
    firstfit();
    printf("\n----------------------------------------------\n");
    printf("Best fit Implementation\n\n");
    bestfit();
    printf("\n----------------------------------------------\n");
    printf("Worst fit Implementation\n\n");
    worstfit();
    printf("\n----------------------------------------------\n");
}