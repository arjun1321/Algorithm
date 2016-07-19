#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *next;
};
struct node *start;
void insertion_beg(int item)
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
void insertion_end(int item)
{
    struct node *new1;
    new1=(struct node*)malloc(sizeof(struct node));
    struct node *loc;
    new1->info=item;
    new1->next=NULL;
    if(start==NULL)
    {
        start=new1;
    }
    else
    {
        loc=start;
        while(loc->next!=NULL)
        {
            loc=loc->next;
        }
        loc->next=new1;
    }
}
void insertion_loc(int n,int pos)
{
    struct node *new1;
    struct node *loc, *locp;
    loc=start;
    int count=1;
    new1=(struct node*)malloc(sizeof(struct node));
    new1->info=n;
    if(start==NULL && pos==1)
    {
        start=new1;
        new1->next=NULL;
    }
    else if(loc->next==NULL && pos==1)
    {
        new1->next=start;
        start=new1;
    }
    else
    {
    while(count!=pos)
    {
        locp=loc;
        loc=loc->next;
        count=count+1;
    }
    new1->next=locp->next;
    locp->next=new1;
    }
}
void delete_beg(void)
{
    struct node *temp;
    if(start==NULL)
        printf("Empty list\n");
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
void deletion_end(void)
{
    struct node *loc,*locp;
    loc=start;
    while(loc->next!=NULL)
    {
        locp=loc;
        loc=loc->next;
    }
    locp->next=NULL;
    printf("Item deleted %d\n",loc->info);
    free(loc);
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
    int cont;
    int ch,n,pos;
    do
    {
    printf("1:Insertion at begining\n");
    printf("2:Insertion at end\n");
    printf("3:Insertion at specified position\n");
    printf("4:Deletion at begining\n");
    printf("5:Deletion at end\n");
    printf("6:Traversing the list\n");
    printf("Enter your choice\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
            printf("Enter the item to insert:\n");
            scanf("%d",&n);
            insertion_beg(n);
            traversal();
            break;
        case 2:
            printf("Enter the item to insert:\n");
            scanf("%d",&n);
            insertion_end(n);
            traversal();
            break;
        case 3:
            printf("Enter the position where you want to insert item:\n");
            scanf("%d",&pos);
            printf("Enter the item to insert:\n");
            scanf("%d",&n);
            insertion_loc(n,pos);
            traversal();
            break;
        case 4:
            delete_beg();
            traversal();
            break;
        case 5:
            deletion_end();
            traversal();
            break;
        case 6:
            printf("Traversing the array:\n");
            traversal();
            break;
        default:
            printf("Sorry! Wrong choice:\n");
    }
    printf("Want to continue? type 1\n");
    scanf("%d",&cont);
    }while(cont==1);
    return 0;
}
