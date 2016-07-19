#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *next;
};

struct node *front;
struct node *rear;

void insertion_rear(int item)
{
    struct node *new1;
    new1=(struct node*)malloc(sizeof(struct node));
    new1->info=item;
    if(front==NULL)
    {
        front=new1;
        rear=new1;
        new1->next=NULL;
    }
    else
    {
        rear->next=new1;
        new1->next=NULL;
        rear=new1;
    }

}
void deletion_front(void)
{
    struct node *temp;
    if(front==NULL)
        printf("Queue is empty\n");
    else if(front==rear)
    {
        temp=front;
        printf("Item deleted is %d\n",temp->info);
        front=NULL;
        rear=NULL;
        free(temp);
    }
    else
    {
        temp=front;
        printf("Item deleted is %d\n",temp->info);
        front=front->next;
        free(temp);
    }
}
void traversal(void)
{
    struct node *temp;
    temp=front;
    if(front==NULL)
    {
        printf("Queue is empty:\n");
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
    front=NULL;
    rear=NULL;
    int ch,n,k;
    do
    {
        printf("1:Insertion\n");
        printf("2:Deletion\n");
        printf("3:Traversal\n");
        printf("Enter the operation to perform\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("Enter the element to insert:\n");
            scanf("%d",&n);
            insertion_rear(n);
            traversal();
            break;
            case 2:deletion_front();
            traversal();
            break;
            case 3:printf("Traversing the Queue:\n");
            traversal();
            break;
            default:printf("Wrong choice!\n");
        }
        printf("Want to continue type 1:\n");
        scanf("%d",&k);
    }while(k==1);

    return 0;
}
