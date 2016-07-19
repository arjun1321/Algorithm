#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct node
{
    int info;
    struct node* left;
    struct node* right;
};
struct node* root;
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
    char ch;
    printf("Where you want to insert node left/right?\n");
    ch=getch();
    if(ch=='r'||ch=='R')
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
    else
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
void preorder_traversal(struct node* temp)
{
    if(temp==NULL)
    {
        return;
    }
    else
    {
        printf("%d ",temp->info);
        preorder_traversal(temp->left);
        preorder_traversal(temp->right);
    }
}
void postorder_traversal(struct node* temp)
{
    if(temp==NULL)
    {
        return;
    }
    else
    {
        postorder_traversal(temp->left);
        postorder_traversal(temp->right);
        printf("%d ",temp->info);
    }
}
int main()
{
    root=NULL;
    int k,ch;
    do
    {
        printf("1:Create tree          2:Inorder traversing\n");
        printf("3:Preorder traversing  4:Postorder traversing\n");
        printf("Enter your choice:\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:create();
            inorder_traversal(root);
            break;
            case 2:inorder_traversal(root);
            break;
            case 3:preorder_traversal(root);
            break;
            case 4:postorder_traversal(root);
            break;
            default:printf("Wrong choice!\n");
        }
        printf("\nWant to continue type 1\n");
        scanf("%d",&k);
    }while(k==1);
    return 0;
}
