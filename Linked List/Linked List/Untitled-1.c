#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
}*firstnode,*nthnode;

void PrintList(struct node* node);
void Creation(int Length);
void reverseDispList();
int main()
{
    int Length,i;
    printf("\n\n Linked List : reverse the list upto nth position :\n");
	printf("-------------------------------------------------------------\n");
    printf(" Input the Length of nodes : ");
    scanf("%d", &Length);
    Creation(Length);
    printf("\n Data entered in the list : \n");
    PrintList(firstnode);
    reverseDispList();
    PrintList(nthnode);
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
        printf("Data of %d Node =  %d \n",j++, node->data);
        node = node->next;
    }
}
void reverseDispList()
{
    struct node *prevNode, *curNode;
    int n,i;
    printf(" Enter the nth position : ");
    scanf("%d", &n);
    nthnode = firstnode;
        for(i=1; i<n; i++)
        {
            nthnode = nthnode->next;
        }
        prevNode = nthnode;
        curNode = nthnode->next;
        nthnode = nthnode->next;
 
        prevNode->next = NULL; //convert the first node as last
 
        while(nthnode != NULL)
        {
            nthnode = nthnode->next;
            curNode->next = prevNode;
 
            prevNode = curNode;
            curNode = nthnode;
        }
        nthnode = prevNode; //convert the last node as head
        
    printf("\n List from the last node to %d th position node: \n",n);
    
}