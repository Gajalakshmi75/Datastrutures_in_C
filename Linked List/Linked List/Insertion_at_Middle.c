#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
}*firstnode;

void PrintList(struct node* node);
void Creation(int Length);
void InsertatMiddle(int newData,int Position);

int main()
{
    int Length,i,newData,Position;
    printf("\n\n Linked List : Insert a new node at the Middle of a Linked List:\n");
	printf("-------------------------------------------------------------\n");
    printf(" Input the Length of nodes : ");
    scanf("%d", &Length);
    Creation(Length);
    printf("\n Data entered in the list : \n");
    PrintList(firstnode);
    printf ("\n Enter  the New Data : ");
    scanf("%d",&newData);
    printf(" Input the position to insert new node : " );
    scanf("%d", &Position);
        if(Position<=1 || Position>=Length)
    {
     printf("\n Insertion can not be possible in that position.\n ");
    }
        if(Position>1 && Position<Length)      
      {
          InsertatMiddle(newData,Position);
       printf("\n Insertion completed successfully.\n ");
      }
    printf("\n The new list are : \n");
    PrintList(firstnode);
    return 0;
}
void Creation(int Length)
{
    struct node *temp,*newnode;
	int data,i;
	firstnode = (struct node *)malloc(sizeof(struct node));
	printf(" Input data for node 1 : ");
    scanf("%d", &data);
    firstnode->data= data;
    firstnode->next = NULL; // links the address field to NULL
    temp=firstnode;
    for (i=2;i<=Length;i++)
    {
    	newnode=(struct node *)malloc(sizeof(struct node));
    	printf(" Input data for node %d : ",i);
    	scanf("%d",&data);
    	newnode->data=data;
    	newnode->next=NULL;
    	temp->next=newnode;
    	temp=temp->next;
    }

}
void PrintList(struct node* node) 
{
    int j;
    j=1;
    while (node != NULL) 
    {
        printf(" Data of %d Node = %d\n",j++, node->data);
        node = node->next;
    }
}
void InsertatMiddle(int newData,int Position)
{
    
    int i;
    struct node *newnode, *temp;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = newData; //Links the data part
    newnode->next = NULL;
    temp = firstnode;
    for(i=2; i<Position; i++)
    {
        temp = temp->next;
    }
    if(temp != NULL)
    {
        newnode->next = temp->next;  //Links the address part of new node
        temp->next = newnode;   
    }
    else
    {
        printf(" Insert is not possible to the given position.\n");
    }
    
}