#include <stdio.h>
#include <stdlib.h>

int min;

void swap(int *m,int *n){
int temp=*m;
*m=*n;
*n=temp;
}

void selectionsort(int arr[],int size,int i){
    if(i==size-1){
        return;
    }
    min=i;
int j;
for(j=i+1;j<size;j++){
    if(arr[j]<arr[min]){
        min=j;
    }
}
    swap(&arr[i],&arr[min]);
    selectionsort(arr,size,i+1);

}

int main()
{
    int i;
    int size=7;
    int arr[size];
    printf("enter the array element:\n");
    for(i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    for(i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    selectionsort(arr,size,0);
    for(i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}
