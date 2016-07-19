#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *backward;
    struct node *forward;
};

struct node *root;
void inorder(int item)
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->info=item;
    if()
}
int main()
{
    root->backward=NULL;
    root->forward=NULL;
    return 0;
}
