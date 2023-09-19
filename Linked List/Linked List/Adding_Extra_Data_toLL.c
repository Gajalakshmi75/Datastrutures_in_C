#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
}*firstnode;

void PrintList(struct node* node);
void Creation(int Length);
void S(int N);
int main()
{
    int Length,i,N;
    printf("\n\n Adding some extra Data to Linked List Data:\n");
	printf("-------------------------------------------------------------\n");
    printf(" Input the Length of nodes : ");
    scanf("%d", &Length);
    Creation(Length);
    printf("\n Data entered in the list : \n");
    PrintList(firstnode);
    printf(" Enter the data which u want to add : ");
    scanf("%d", &N);
    S(N);
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
    firstnode->next = NULL;
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
void S(int N)
{
    struct node *temp;
    temp=firstnode;
    while(temp->next!=NULL)
    {
        temp->data=((temp->data)+N);
        temp = temp->next;
    }
    temp->data =((temp->data)+N);
}
void PrintList(struct node* node) 
{
    int j;
    j=1;
    while (node != NULL) 
    {
        printf("Data of %d Node =  %d \n",j++, node->data);
        node = node->next;
    }
}