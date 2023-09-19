#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
}*firstnode;

void PrintList(struct node* node);
void EndNodeDeletion();
void Creation(int Length);

int main()
{
    int Length,i;
    printf("\n\n Linked List : Delete End node of Singly Linked List :\n");
	printf("-------------------------------------------------------------\n");
    printf(" Input the Length of nodes : ");
    scanf("%d", &Length);
    Creation(Length);
    printf("\n Data entered in the list : \n");
    PrintList(firstnode);
    EndNodeDeletion();
    printf("\n New Data of the list : \n");
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
void EndNodeDeletion()
{
    struct node *DelLast, *preNode;
    DelLast = firstnode;
    preNode = firstnode;
    /* Traverse to the last node of the list*/
    while(DelLast->next != NULL)
    {
        preNode = DelLast;
        DelLast = DelLast->next;
        }
        if(DelLast == firstnode)
        {
            firstnode = NULL;
        }
        else
        {
            preNode->next = NULL;
            printf("\n Data of node Last which is being deleted is :  %d\n", DelLast->data);
        }
        free(DelLast);
}