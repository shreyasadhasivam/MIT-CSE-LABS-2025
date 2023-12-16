#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int key;
    struct node *link;
}node;


struct node* reverseList(struct node* head)

{
    if(head->link == NULL)
        return head;
    struct node* rest = reverseList(head->link);
    head->link->link=head;
    head->link=NULL;
    return rest;
}

struct node* sortedMerge(struct node* a, struct node* b)
{
    a = reverseList(a);
    b = reverseList(b);

    struct node* head = NULL;
    struct node* temp;

    while(a!= NULL && b!=NULL)
    {
        if(a->key >= b->key)
        
        {
            temp = a->link;
            a->link= head;
            head = a;
            a= temp;
        }
        else
        {
            temp = b->link;
            b->link = head;
            head = b;
            b = temp;
        }
    }

    while(a!=NULL)
    
    {
        temp = a->link;
        a->link= head;
        head = a;
        a = temp;
    }

    while(b!=NULL)
    {
        temp = b->link;
        b->link= head;
        head = b;
        b = temp;
    }

    return head;
}

void display(struct node* node)
{
    while(node!=NULL)
    {
        printf("%d  ", node->key);
        node = node->link;
    }
}

struct node* newNode(int ele)
{
    struct node* temp = (struct node*)malloc(sizeof(node));
    temp->key = ele;
    temp->link = NULL;
    return temp;
}

int main()

{
    struct node* merge = NULL;

    struct node* a = newNode(2);
    a->link = newNode(4);
    a->link->link= newNode(6);
    a->link->link->link=newNode(8);

    struct node* b =newNode(3);
    b->link= newNode(5);
    b->link->link = newNode(7);
    b->link->link->link = newNode(9);

    printf("List 1: ");
    display(a);
    printf("\n");
    printf("List 2: ");
    display(b);
    printf("\n");
    merge= sortedMerge(a,b);
    printf("After Merging:\n");
    printf("List 1: ");
    display(merge);
    printf("\n");
    return 0;
}