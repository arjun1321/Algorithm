#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *next;
};

struct node *start;
void push(int item)
{
    struct node *new1;
    new1=(struct node*)malloc(sizeof(struct node));
    new1->info=item;
    if(start==NULL)
    {
        start=new1;
        new1->next=NULL;
    }
    else
    {
        new1->next=start;
        start=new1;
    }
}
void pop(void)
{
    struct node *temp;
    if(start==NULL)
        printf("stack is underflow\n");
    else if(start->next==NULL)
    {
        temp=start;
        printf("Item deleted is %d\n",temp->info);
        start=NULL;
        free(temp);
    }
    else
    {
        temp=start;
        printf("Item deleted is %d\n",temp->info);
        start=temp->next;
        free(temp);
    }
}
void traversal(void)
{
    struct node *temp;
    temp=start;
    if(start==NULL)
    {
        printf("List is empty:\n");
    }
    else if(temp->next==NULL)
    {
         printf("the list is ");
         printf("%d\n",temp->info);
    }
    else
    {
        printf("the list is ");
         while(temp->next!=NULL)
       {
            printf(" %d",temp->info);
            temp=temp->next;
       }
       printf(" %d",temp->info);
         printf("\n");
    }
}
int main()
{
    start=NULL;
    int ch,n,k;
    do
    {
        printf("Enter the operation you want to perform:\n");
        printf("1:push 2:pop 3:traversing\n");
        scanf("%d",&ch);
        switch(ch)
    {
        case 1:printf("Enter the element to push in stack:\n");
        scanf("%d",&n);
        push(n);
        traversal();
        break;
        case 2:pop();
        traversal();
        break;
        case 3:printf("Traversing the stack:\n");
        traversal();
        break;
        default:printf("Wrong choice!\n");
    }
    printf("Want to continue type 1:\n");
    scanf("%d",&k);
    }while(k==1);

    return 0;
}
