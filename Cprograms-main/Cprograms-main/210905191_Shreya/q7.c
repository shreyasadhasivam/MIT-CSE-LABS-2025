#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
    char *data;
    struct node *link;
};
void display(struct node *first)
{
    struct node *temp = first;
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
int isPalindrome(char *str, int start, int end){
   
    if(NULL == str || start < 0 || end < 0)
    {
         return 0;
    }
     if(start >= end)
         {
             return 1;
         }
     if(str[start] == str[end]){
         return isPalindrome(str, start + 1, end - 1);
     }
     return 0;
 }
 struct node *palindrome(struct node *head,struct node *head1)
 {
    struct node *temp1 = head;
    int n; 
      char *s1;
    while(temp1 != NULL)
    {
       if(isPalindrome(temp1->data,0,strlen(temp1->data)-1))
       {
         s1 =  (char *)malloc(10*sizeof(char));
         s1 = temp1->data;   
        head1 = insertRear(s1,head1);
         temp1 = temp1->link; 
       }
       else
       {
        temp1 = temp1->link;
       }
    }
       return head1;
 }
 struct node *notpalindrome(struct node *head,struct node *head2)
 {
    struct node *temp1 = head;
    int n;
      char *s1;
    while(temp1 != NULL)
    {
       if(!(isPalindrome(temp1->data,0,strlen(temp1->data)-1)))
       {
         s1 =  (char *)malloc(10*sizeof(char));
         s1 = temp1->data;
        head2 = insertRear(s1,head2);
        temp1 = temp1->link;
       }
       else
       {
        temp1 = temp1->link;
       }
    }
       return head2;
 }
int main()
{
    struct node *head;
    struct node *head1;
    struct node *head2;
    head = (struct node *)malloc(sizeof(struct node *));
    head1 = (struct node *)malloc(sizeof(struct node *));
    head2 = (struct node *)malloc(sizeof(struct node *));
    head = NULL;
    head1 = NULL;
    head2 = NULL;
     printf("Enter number of words\n");
    int n,i;
    scanf("%d",&n);
    char *s1;
    printf("Enter words\n");
        for(i=0;i<n;i++)
        {
            s1 =  (char *)malloc(10*sizeof(char));
            scanf("%s",s1);
            head = insertRear(s1,head);
        }
    printf("List of words :\n");
    display(head);
    head1=palindrome(head,head1);
    printf("List containing palindromes :\n");
    display(head1);
     head2=notpalindrome(head,head2);
     printf("List containing non palindromes :\n");
     display(head2);
    return 0;
}