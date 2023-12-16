#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node {
    int count;
    int fibo;    
    Node* link;
};

// #define N 30

int main (void)
{
    int N;
    printf("Enter the value of N:\n");
    scanf("%d", &N);
    Node fibo[N-1];
    Node *head = NULL;
    Node **p = &head;

    int f1 = 0;
    int f2 = 0;

    for (int i = 0; i < N-1; i++) {
        Node *nd = &fibo[i];

        nd->count = i + 1;
        nd->fibo = f2 + f1 ? f2 + f1 : 1;

        f1 = f2;
        f2 = nd->fibo;

        *p = nd;
        p = &(*p)->link;
    }
    *p = NULL;

    Node *nd = head;
    printf("0");
    while (nd) {
        printf(" %d", nd->fibo);
        nd = nd->link;
    }
    printf("\n");

    return (0);
}
