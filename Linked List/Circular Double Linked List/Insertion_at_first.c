#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    struct node * preptr;
    struct node * nextptr;
}*firstnode, *temp;
 

void ClListcreation(int length);
void displayClList();
void insertNodeAtBeginning(int newData);

int main()
{
    int length,newData;
    firstnode = NULL;
	printf("\n\n Circular Double Linked List : inserting a newnode at begging of circular double linked list :\n");
	printf("-----------------------------------------------------------------------\n");	   	

    printf(" Input the number of nodes : ");
    scanf("%d", &length);
 
    ClListcreation(length); 
    displayClList();
    printf(" Enter the new Data for newnode : ");
    scanf("%d", &newData);
    insertNodeAtBeginning(newData);
    displayClList();
    return 0;
}

void ClListcreation(int length)
{
    int  data,i;
    struct node *newnode;

    if(length >= 1)
    {
        firstnode = (struct node *)malloc(sizeof(struct node));

        printf(" Input data for node 1 : ");
        scanf("%d", &data);
        firstnode->data = data;
        firstnode->nextptr = NULL;
        firstnode->preptr= NULL;
        temp = firstnode;
        for(i=2; i<=length; i++)
        {
            newnode = (struct node *)malloc(sizeof(struct node));
            printf(" Input data for node %d : ", i);
            scanf("%d", &data);
            newnode->data = data;
            newnode->preptr = temp;    // new node is linking with the previous node
            newnode->nextptr = NULL;	// next address of new node set as NULL
            temp->nextptr = newnode;	// previous node is linking with new node
            temp = newnode;   		// previous node is advanced
        }
        temp->nextptr = firstnode; 		//last node is linking with first node
        firstnode->preptr = temp;
    }
}

void displayClList()
{
    struct node *node;
    int n = 1;
        node = firstnode;
        printf("\n\n Data entered in the list are :\n");
        do 
        {
            printf(" Data %d = %d\n", n, node->data);

            node = node->nextptr;
            n++;
        }while(node != firstnode);
    
}
void DlLinsertNodeAtBeginning(int newData)
{
    struct node * newnode;
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = newData;
        newnode->nextptr = firstnode;  // next address of new node is linking with starting node
        newnode->preptr = NULL;     // set previous address field of new node is NULL
        firstnode->preptr = newnode;   // previous address of starting node is linking with new node
        firstnode = newnode;           // set the new node as starting node
    
}
void insertNodeAtBeginning(int newData)
{
    struct node *newnode, *lastnode;
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = newData;
        newnode->nextptr = firstnode;
        lastnode = firstnode;
        while(lastnode->nextptr != firstnode)
        {
            lastnode = lastnode->nextptr;
        }
        lastnode->nextptr = newnode;
        newnode->preptr=lastnode;
        firstnode->preptr = newnode;
        firstnode = newnode;
}