#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
	int coeff,expo;
	struct node* link;
};
struct node* head1;
struct node* head2;
struct node* result;
struct node* insert(struct node* head,int coef,int exp)
{
	struct node* temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->coeff=coef;
	temp->expo=exp;
	temp->link=NULL;
	if(head==NULL)
	{
		head=temp;
		return head;
	}
	else if(head->link==NULL)
	{
		head->link=temp;
		return head;
	}
	else
	{
	    struct node* temp1;
	    temp1=head;
		while(temp1->link!=NULL)
		{
			temp1=temp1->link;
		}
		temp1->link=temp;
		return head;
	}
}
void addpolynomial(struct node* p1,struct node* p2)
{
	p1=head1;
	p2=head2;
	while(p1!=NULL||p2!=NULL)
	{
	    if(p1==NULL)
        {
            result=insert(result,p2->coeff,p2->expo);
            p2=p2->link;
        }
        else if(p2==NULL)
        {
            result=insert(result,p1->coeff,p1->expo);
            p1=p1->link;
        }
        else if(p1->expo>p2->expo)
        {
            result=insert(result,p1->coeff,p1->expo);
            p1=p1->link;
        }
        else if(p1->expo<p2->expo)
        {
            result=insert(result,p2->coeff,p2->expo);
            p2=p2->link;
        }
        else
        {
            int sum;
            sum=p1->coeff+p2->coeff;
            if(sum!=0)
            {
                result=insert(result,sum,p1->expo);
            }
            p1=p1->link;
            p2=p2->link;
        }
	}
}
void display(struct node* p)
{
	if(p==NULL)
	{
		printf("Polynomial does not exist:\n");
	}
	else
	{
		while(p->link!=NULL)
		{
			printf("%dx^%d + ",p->coeff,p->expo);
			p=p->link;
		}
		printf("%dx^%d ",p->coeff,p->expo);
	}
}
int main()
{
	head1=NULL;
	head2=NULL;
	result=NULL;
	int k,i,coe,ex;
		printf("Enter the no. of term in a polynomial(1)\n");
		scanf("%d",&k);
		printf("Enter the polynomial:\n");
		for(i=0;i<k;i++)
		{
			printf("Enter the coeff and exponent:\n");
			scanf("%d%d",&coe,&ex);
			head1=insert(head1,coe,ex);
		}
		printf("Enter the no. of term in a polynomial(2)\n");
		scanf("%d",&k);
		printf("Enter the polynomial:\n");
		for(i=0;i<k;i++)
		{
			printf("Enter the coeff and exponent:\n");
			scanf("%d%d",&coe,&ex);
			head2=insert(head2,coe,ex);
		}
		printf("\nFirst polynomial:\n");
		display(head1);
		printf("\nSecond polynomial:\n");
		display(head2);
    printf("\nAddition of polynomial:\n");
    addpolynomial(head1,head2);
    display(result);
	return 0;
}
