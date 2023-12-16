#include<stdio.h>
#include<stdlib.h>

#define MAX 10

int count = 0;
struct stack 
{
    int items[MAX];
    int top
};

typedef struct stack St;

void createEmptyStack(St *s)
{
    s->top = -1;

}

int isFull(St *s)
{
    if(s->top == MAX - 1)
    {
        return 1;
    }
    else 
        return 0;
}

int isEmpty(St *s)
{
    if(s->top == -1)
        return 1;
    else
        return 0;
}

void push(St *s, int ele)
{
    if(isFull(s))
    {
        printf("Stack is full");

    }
    else
    {
        s->top++;
        s->items[s->top] = ele;
    }
    count++;
}

void pop(St *s)
{
    if(isEmpty(s))
    {
        printf("Stack underflow");
    }
    else
    {
        printf("Item popped= %d", s->items[s->top]);
        s->top--;
    }
    count--;
    printf("\n");
}

void printStack(St * s)
{
    printf("Stack: ");
    for(int i=0; i<count;i++)
    {
        printf("%d", s->items[i]);

    }
    printf("\n");
}

int main()
{
    int ch;
    St *s = (st*) malloc(sizeof(st));

    createEmptyStack();
    push(s,1);
    push(s,2);
    push(s,3);
    push(s,4);
    
    printStack(s);

    pop(s);
    printf("After popping out\n");
    printStack(s);


}