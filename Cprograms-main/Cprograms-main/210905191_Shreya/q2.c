#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
};
struct node *insertRear(int ele,struct node *start)
{
   struct node *ptr;
   ptr = (struct node *)malloc(sizeof(struct node *));
   ptr->data = ele;
   if(start == NULL)
   {
    ptr->link = NULL;
    return ptr;
   }
   struct node *temp = start;
   while(temp->link != NULL)
   {
    temp = temp->link;
   }
   temp->link = ptr;
   ptr->link = NULL;
   return start;
}
void display(struct node *start)
{
    if(start == NULL)
    {
        printf("List is empty\n");
        exit(0);
    }
    printf("Contents of list are\n");
    struct node *temp = start;
   do
    {
        printf("%d ",temp->data);
        temp = temp->link;
    }while(temp != start);
    printf("\n");
}

struct node *rightRotate(struct node *start,int k,int n)
{
  struct node *temp = start;
  int count =0;
  while(count != n-k)
  {
    temp = temp->link;
    count++;
  }
  return temp;
}

struct node *leftRotate(struct node *start,int k)
{
   struct node *temp = start;
  int count =0;
  while(count!=k)
  {
    temp = temp->link;
    count++;
  }
  return temp;
}

int main()
{
    struct node *head1;
    struct node *head2;

    head1 = (struct node *)malloc(sizeof(struct node *));
    head2 = (struct node *)malloc(sizeof(struct node *));
    printf("Enter number of elements\n");
    int n1,t;
    scanf("%d",&n1);
    printf("Enter elements \n");
    for(int i=0;i<n1;i++)
    {
        scanf("%d",&t);
        head1 = insertRear(t,head1);
        head2 = insertRear(t,head2);
    }
    struct node *temp1 = head1;
    struct node *temp2 = head2;
     while(temp1->link != NULL)
    {
        temp1 = temp1->link;
    }
     while(temp2->link != NULL)
    {
        temp2 = temp2->link;
    }

    struct node *t1 = head1->link;
    free(head1);
    head1 = t1;
    struct node *t2 = head2->link;
    free(head2);
    head2 = t2;
     temp2->link = head2;
    temp1->link = head1;
    printf("Enter k\n");
    int k;
    scanf("%d",&k);
    display(head1);
   head1=leftRotate(head1,k);
   printf("After rotating left :\n");
   display(head1);
   head2 = rightRotate(head2,k,n1);
   printf("After rotating right :\n");
   display(head2);
    return 0;
}