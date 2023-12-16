#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
    char  data;
    struct node *link;
};
void display(struct node *first)
{
    if(first == NULL)
    {
        printf("List is empty\n");
        exit(0);
    }
    printf("Contents of list are:\n");
    while(first != NULL)
    {
        printf("%c\n",first->data);
     first = first->link;
    }
}
struct node *insertRear(char ele,struct node *first)
{
   struct node *ptr;
   ptr = (struct node *)malloc(sizeof(struct node *));
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
struct node *create(char s[])
{
    struct node *first;
    first = (struct node *)malloc(sizeof(struct node *));
    first = NULL;
    int i=0;
    while (s[i] != '\0')
    {
    first = insertRear(s[i],first);
    i++;
    }
    return first;
}
int isVowel(char ch)
{
    switch(ch)
    {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
  
                  return 1;
                  break;
        default:
                  return 0;
    }
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
  struct node *deleteFront(struct node *first)
  {
    if(first == NULL)
    {
        printf("List is empty\n");
        exit(0);
    }
    struct node *t = first->link;
    free(first);
     
    return t;
  }
void allVowels(struct node *first)
{
   struct node *temp1 = first;
   struct node *temp2 = first->link;
   struct node *temp3 = first;
   while(temp2->link != NULL)
   {
      if(isVowel(temp2->data))
      {
        struct node *temp = temp2;
        temp1->link = temp2->link;
        free(temp);
        temp2 = temp2->link;
      }
      else
      {
        temp2 = temp2->link;
      }
   }
   if(isVowel(temp2->data))
   {
      first = deleteRear(first);
   }
   if(isVowel(temp3->data))
   {
    first = deleteFront(first);
   }
}
int main()
{
    struct node *head;
    head = (struct node *)malloc(sizeof(struct node *));
    head = NULL;
    char s[15];
    printf("Enter name\n");
    scanf("%s",s);
    head = create(s);
    display(head);
    printf("After removing vowels :\n");
    allVowels(head);
    display(head);
    return 0;
}