#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#define MAX 25

char stack[MAX];
char postfix[MAX];
int top=-1;

void push(int);
int pop(void);
int evaluate(int,int,char);
int result(void);
int main(void)
{
    char ch;
    do
    {
        printf("Enter the postfix expression:\n");
        gets(postfix);
        printf("The result after evaluation of postfix expression:\n");
        printf("%d\n",result());
        printf("Want to continue? type Y/N\n");
        scanf("%c",&ch);
    }while(ch=='y' || ch=='Y');
    getch();
    return 0;
}

void push(int n)
{
    if(top>MAX-1)
    {
        printf("Stack is Overflow:\n");
        exit(0);
    }
    else
    {
        top+=1;
        stack[top]=n;
    }
}
int pop(void)
{
    if(top==-1)
    {
        printf("Stack is Underflow:\n");
        exit(0);
    }
    else
    {
        return(stack[top--]);
    }
}
int evaluate(int x,int y,char c)
{
    if(c=='+')
        return (x+y);
    if(c=='-')
        return (x-y);
    if(c=='*')
        return (x*y);
    if(c=='/')
        return (x/y);
    if(c=='^')
        return (pow(x,y));
}
int result(void)
{
    int num1,num2,ans;
    int i=0;
    for(;i<strlen(postfix);i++)
    {
        if(postfix[i]>='0' && postfix[i]<='9')
            push((int)(postfix[i]-48));
        else
        {
            num2=pop();
            num1=pop();
            ans=evaluate(num1,num2,x);
            push(ans);
        }
    }
    return ans;
}
