#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
    char *name;
    int roll_no;
    int marks;
    struct node *link;
};

void display(struct node *start)
{
    struct node *temp = start;
    printf("Contents of list are\n");
    while(temp != NULL)
    {
    printf("%s,%d,%d\n",temp->name,temp->roll_no,temp->marks);
    temp = temp->link;
    }
}
struct node *insertRear(char *n,int roll,int mark,struct node *start)
{
   struct node *ptr;
   ptr = (struct node *)malloc(sizeof(struct node *));
   ptr->name =  (char *)malloc(10*sizeof(char));
   ptr->name = n;
   ptr->roll_no = roll;
   ptr->marks = mark;
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
void swap(struct node *start,struct node *second)
{
    int temproll;
    char *t;
    t = (char *)malloc(sizeof(char *));
    int tempmark;
    t = start->name;
    temproll = start->roll_no;
    tempmark = start->marks;
    start->name = second->name;
    start->roll_no = second->roll_no;
    start->marks = second->marks;
    second->name = t;
    second->roll_no = temproll;
    second->marks = tempmark;
}
struct node *sortHighest(struct node *start,int n)
{
    int temp;
    struct node *ptr = start;
    for(int i=0;i<n-1;i++)
    {
   while(ptr->link != NULL)
   {
          if(ptr->marks<ptr->link->marks)
          {
            swap(ptr,ptr->link);
            ptr = ptr->link;
          }
          else{
            ptr = ptr->link;
          }
   }
   ptr = start;
    }
    return start;
 }


int main()
{
    struct node *head;
    head = (struct node *)malloc(sizeof(struct node *));
    head = NULL;
    printf("Enter number of students\n");
    int n,i;
    scanf("%d",&n);
   // char s[n][15];
    char *s1;
    int roll,mark;
        for(i=0;i<n;i++)
        {
            printf("Enter name of student %d\n",(i+1));
            s1 =  (char *)malloc(10*sizeof(char));
            scanf("%s",s1);
            printf("Enter Roll number of student %d\n",(i+1));
            scanf("%d",&roll);
            printf("Enter marks of student %d\n",(i+1));
            scanf("%d",&mark);
            head = insertRear(s1,roll,mark,head);
        }

    display(head);
    printf("After sorting according to marks :\n");
    head = sortHighest(head,n);
    //printf("After sorting according to marks :\n");
    display(head);
    printf("Second highest marks :\n%s,%d,%d\n",head->link->name,head->link->roll_no,head->link->marks);
    return 0;
}