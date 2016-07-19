#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node* left;
    struct node* right;
};
struct node*root;
struct node *get_node(void)
{
    struct node* temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
void insert_node(struct node* root,struct node* new1)
{
    if(new1->info<root->info)
    {
        if(root->left==NULL)
        {
            root->left=new1;
        }
        else
        {
            insert_node(root->left,new1);
        }
    }
    else
    {
        if(root->right==NULL)
        {
            root->right=new1;
        }
        else
        {
            insert_node(root->right,new1);
        }
    }
}
void create(void)
{
    struct node* new1;
    new1=get_node();
    printf("Enter the info:\n");
    scanf("%d",&new1->info);
    if(root==NULL)
    {
        root=new1;
    }
    else
    {
        insert_node(root,new1);
    }
}
void inorder_traversal(struct node* temp)
{
    if(temp==NULL)
    {
        return ;
    }
    else
    {
        inorder_traversal(temp->left);
        printf("%d ",temp->info);
        inorder_traversal(temp->right);
    }
}
void searching(struct node* root,int item)
{
    if(root->info==item)
    {
        printf("Item found:\n");
    }
    else
    {
        if(root->info>item)
        {
            searching(root->left,item);
        }
        else
        {
            searching(root->right,item);
        }
   }
}

int main()
{
    root=NULL;
    int ch,k,n;
    do
    {
        printf("1:Insertion 2:Traversing 3:Searching \n");
        printf("Enter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:create();
            inorder_traversal(root);
            break;
            case 2:inorder_traversal(root);
            break;
            case 3:printf("Enter the item to search\n");
            scanf("%d",&n);
                searching(root,n);
            break;
            default:printf("Wrong choice!\n");
        }
        printf("\nWant to continue type 1\n");
        scanf("%d",&k);
    }while(k==1);
    return 0;
}
