#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* link;
};

struct node* start= NULL;

void createList()
{
    // int n;
    // printf("Enter the number of nodes: ");
    // scanf("%d", &n);

    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &temp->data);
    temp->link = NULL;
    if(start == NULL)
    {
        start = temp;
    }
    else
    {
        struct node* p;
        p = start;
        while(p->link != NULL)
        {
            p = p->link;
        }
        p->link = temp;
    }
}

void insertAtEnd()

{
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &temp->data);
    temp->link = NULL;
    if(start == NULL)
    {
        start = temp;
    }
    else
    {
        struct node* p;
        p = start;
        while(p->link != NULL)
        {
            p = p->link;
        }
        p->link = temp;
    }
}

void displayList()
{
    struct node* temp;
    temp = start;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->link;
    }
}
void deletePosition()
{
    int pos;
    printf("Enter the position to delete: ");
    scanf("%d", &pos);
    struct node* temp;
    temp = start;
    if(pos == 1)
    {
        start = temp->link;
        free(temp);
    }
    else
    {
        struct node* p;
        p = start;
        int i = 1;
        while(i < pos-1)
        {
            p = p->link;
            i++;
        }
        temp = p->link;
        p->link = temp->link;
        free(temp);
    }
}

int main()
{
    int ch, n;
    while(1)
    {
        printf("Choose:\n1. Create List\n2. Insert at end\n3. Display\n4. Delete Position\n5. Exit\n");
        printf("Enter the choice: \n");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1: printf("Enter the number of nodes: ");
                    scanf("%d", &n);
                    for(int i = 0; i < n; i++)
                    {
                        createList();
                    }
                    break;
            case 2: insertAtEnd();
                    break;
            case 3: displayList();
                    printf("\n");
                    break;
            case 4: deletePosition();
                    break;
            case 5: exit(0);
                    break;
            default: printf("Invalid choice\n");
        }
    }
    printf("Exited successfuly\n");
    return 0;
}