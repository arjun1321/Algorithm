#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node* backward;
    struct node* forward;
};

struct node* first;
struct node* last;

void insert_beg(int item)
{
    struct node* new1;
    new1=(struct node*)malloc(sizeof(struct node));
    new1->info=item;
    if(first==NULL&&last==NULL)
    {
        first=new1;
        last=new1;
        new1->backward=NULL;
        new1->forward=NULL;
    }
    else
    {
        first->backward=new1;
        new1->forward=first;
        new1->backward=NULL;
        first=new1;
    }
}
void insert_end(int item)
{
    struct node* new1;
    new1=(struct node*)malloc(sizeof(struct node));
    new1->info=item;
    if(first==NULL&&last==NULL)
    {
        first=new1;
        last=new1;
        new1->backward=NULL;
        new1->forward=NULL;
    }
    else
    {
        last->forward=new1;
        new1->backward=last;
        new1->forward=NULL;
        last=new1;
    }
}
void delete_beg(void)
{
    struct node* temp;
    temp=first;
    if(first==NULL&&last==NULL)
    {
        printf("List is empty:\n");
    }
    else if(temp->forward==NULL)
    {
        printf("Item deleted is %d\n",temp->info);
        first==NULL;
        last=NULL;
        free(temp);
    }
    else
    {
        printf("Item deleted is %d\n",temp->info);
        first=temp->forward;
        first->backward=NULL;
        free(temp);
    }
}
void delete_end(void)
{
    struct node* temp;
    temp=last;
    if(first==NULL&&last==NULL)
    {
        printf("List is empty:\n");
    }
    else if(temp->backward==NULL)
    {
        printf("Item deleted is %d\n",temp->info);
        first==NULL;
        last=NULL;
        free(temp);
    }
    else
    {
        printf("Item deleted is %d\n",temp->info);
        last=temp->backward;
        last->forward=NULL;
        free(temp);
    }
}
void traverse_right(void)
{
    struct node* temp;
    temp=first;
    if(first==NULL&&last==NULL)
    {
        printf("List is empty:\n");
    }
    else if(temp->forward==NULL)
    {
        printf("The list is %d\n",temp->info);
    }
    else
    {
        printf("The list is ");
        while(temp->forward!=NULL)
        {
            printf("%d ",temp->info);
            temp=temp->forward;
        }
        printf("%d ",temp->info);
        printf("\n");
    }
}
void traverse_left(void)
{
    struct node* temp;
    temp=last;
    if(first==NULL&&last==NULL)
    {
        printf("List is empty:\n");
    }
    else if(temp->backward==NULL)
    {
        printf("The list is %d\n",temp->info);
    }
    else
    {
        printf("The list is ");
        while(temp->backward!=NULL)
        {
            printf("%d ",temp->info);
            temp=temp->backward;
        }
        printf("%d",temp->info);
        printf("\n");
    }
}
int main()
{
    first=NULL;
    last=NULL;
    int ch,n,k;
    do
    {
        printf("1:Insertion beg    2:Insertion end\n");
        printf("3:Deletion beg     4:Deletion end\n");
        printf("5:Traversing right 6:Traversing left\n");
        printf("Enter your choice:\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("Enter the element to insert:\n");
            scanf("%d",&n);
            insert_beg(n);
            traverse_right();
            break;
            case 2:printf("Enter the element to insert:\n");
            scanf("%d",&n);
            insert_end(n);
            traverse_right();
            break;
            case 3:delete_beg();
            traverse_right();
            break;
            case 4:delete_end();
            traverse_right();
            break;
            case 5:traverse_right();
            break;
            case 6:traverse_left();
            break;
            default:printf("Wrong choice!\n");
        }
        printf("Want to continue? type 1\n");
        scanf("%d",&k);
    }while(k==1);
    return 0;
}
