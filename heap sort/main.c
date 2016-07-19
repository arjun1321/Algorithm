#include <stdio.h>
#include <stdlib.h>
# define MAX 10
int array_list[MAX];
void display(void)
{
    int j;
    for(j=0;j<MAX;j++)
    {
        printf("%d ",array_list[j]);
    }
    printf("\n");
}
void swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void heapify(int last)
{
   int i,c,root;
   for(i=1;i<=last;i++)
   {
       c=i;
       do
       {
           root=(c-1)/2;
           if(array_list[root]<array_list[c])
           {
               swap(&array_list[root],&array_list[c]);
           }
           c=root;
       }while(c!=0);

   }
}
void heap_sort(void)
{
    int last;

    for(last=MAX-1;last>0;last--)
    {
        swap(&array_list[0],&array_list[last]);
        heapify(last-1);
    }
}
int main()
{
    int i;
    printf("Enter the elements in the array list:\n");
    for(i=0;i<MAX;i++)
    {
        scanf("%d",&array_list[i]);
    }
    printf("The unsorted list is: ");
    display();
    heapify(MAX-1);
    printf("The heapified array is: ");
    display();
    heap_sort();
    printf("Sorted list: ");
    display();

    return 0;
}
