#include<stdio.h>
typedef struct _node NODE;

struct _node
{
 int num;
 NODE *next;
};

NODE* New_Node(NODE *Head,int num)
{
 NODE *temp,*Curr;
 if(Head == NULL)
 {
         Head = (NODE*)malloc(sizeof(NODE));
         Head->next = NULL;
         Head->num = num;
         return Head;
 }
 Curr = Head;
 while(Curr->next != NULL)
 {
   Curr = Curr->next;
 }
 temp = (NODE*)malloc(sizeof(NODE));
     if(temp == NULL){
     printf("Cannot create a new node");
     return Head;
     }
 Curr->next = temp;
 temp->num = num;
 temp->next = NULL;


 return Head;
}

void Print_Nodes(NODE *Head)
{
 NODE *temp;
 temp = Head;
 while(temp != NULL)
 {
            printf("%d ",temp->num);
            temp = temp->next;
 }
}

void Rearrange(NODE *Head)
{
 NODE *Even = NULL;
 NODE *Odd = NULL;
 NODE *temp;

 temp = Head;
 while(temp != NULL)
 {
                  if(temp->num %2 == 0)
                    Even = New_Node(Even,temp->num);
                  else
                    Odd = New_Node(Odd,temp->num);
   temp = temp->next;
 }
 free(Head);
 Head = Odd;
 while(Odd->next != NULL)
 Odd = Odd->next;

 Odd->next = Even;

 printf("\nAfter rearrange the list is ::");
 Print_Nodes(Head);

}
int main()
{
    int num=0;
    NODE *Head = NULL;
     printf("Enter the information in the linked list (Enter -1 to exit):");
     scanf("%d",&num);
  while(num != -1)
  {
             Head = New_Node(Head,num);
             printf("Enter the information in the linked list (Enter -1 to exit):");
             scanf("%d",&num);
  }
  Print_Nodes(Head) ;
  Rearrange(Head);
 getch();
}
