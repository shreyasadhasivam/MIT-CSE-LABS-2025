#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
    char *data;
    int count;
    struct node *link;
};
void displaycount(struct node *first)
{
    struct node *temp = first;
    printf("Contents of list are\n");
    while(temp != NULL)
    {
    printf("%s,%d\n",temp->data,temp->count);
     temp = temp->link;
    }
}
void display(struct node *first)
{
    struct node *temp = first;
    printf("The students are:\n");  
    while(temp != NULL)
    {
    printf("%s\n",temp->data);
     temp = temp->link;
    }
}
struct node *insertRear(char *ele,struct node *first)
{
   struct node *ptr;
   ptr = (struct node *)malloc(sizeof(struct node *));
   ptr->data =  (char *)malloc(10*sizeof(char));
   ptr->data = ele;
   if(first == NULL)
   {
    ptr->link = NULL;
    return ptr;
   }
   struct node *temp = first;
   while(temp->link != NULL)
   {
    temp = temp->link;
   }
   temp->link = ptr;
   ptr->link = NULL;
   return first;
}
struct node *Create()
{
    struct node *first;
    first = (struct node *)malloc(sizeof(struct node *));
    first = NULL;
     printf("Enter number of students\n");
    int n,i;
    scanf("%d",&n);
    char *s1;
    printf("Enter names of students\n");
        for(i=0;i<n;i++)
        {
            s1 =  (char *)malloc(10*sizeof(char));
            scanf("%s",s1);
            first = insertRear(s1,first);
        }
        return first;
}
struct node *deleteRear(struct node *first)
  {
    struct node *temp1 = first;
    struct node *temp2 = first->link;
    while(temp2->link != NULL)
    {
        temp2=temp2->link;
         temp1=temp1->link;
    }
   temp1->link = NULL;
    free(temp2);
    return first;
  }
void Search(struct node *first)
{
    struct node *temp1 = first;
    struct node *temp3 = first;
    while(temp1 != NULL)
    {
         struct node *temp2 = temp1->link;
        temp1->count = 1;
        while(temp2 != NULL)
        {
            if(strcmp(temp1->data,temp2->data) == 0 && temp2->link != NULL)
            {
               struct node *temp = temp2;
               temp3->link = temp2->link;
               free(temp);
               temp2 = temp2->link;
               temp3 = temp3->link;
               temp1->count++;
            }
            else if(strcmp(temp1->data,temp2->data) == 0 && temp2->link == NULL)
            {
               first = deleteRear(first);
               temp1->count++;
               temp2 = temp2->link;
               temp3 = temp3->link;
            }
            else{

                temp2 = temp2->link;
                temp3 = temp3->link;
            }
        }
        temp1 = temp1->link;
        temp3 = temp1;
    }
}
int main()
{
    struct node *head;
    head = (struct node *)malloc(sizeof(struct node *));
    head = NULL;
    head =Create();
    display(head);
    printf("After removing occurences :\n");
    Search(head);
    displaycount(head);
    return 0 ;
}