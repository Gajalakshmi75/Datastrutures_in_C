#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node * preptr;
    struct node * nextptr;
}*firstnode, *temp;
 

void DLlistcreation(int length);
void DlListDeleteFirstNode();
void Printlist(int a);

int main()
{
    int length,a;
	printf("\n\n Doubly Linked List : Delete node from the beginning of a doubly linked list :\n");
	printf("-------------------------------------------------------------------\n");	   	

    printf(" Input the number of nodes(enter more than 2 nodes for better results) : ");
    scanf("%d", &length);
    a=1;
    DLlistcreation(length); 
    Printlist(a);
    a=2;
    DlListDeleteFirstNode();
    Printlist(a);
    return 0;
}
 
void DLlistcreation(int length)
{
    int i, data;
    struct node *newnode;
    firstnode = (struct node *)malloc(sizeof(struct node));
    printf(" Input data for node 1 : "); // assigning data in the first node
    scanf("%d", &data);
    firstnode->data = data;
    firstnode->preptr = NULL;
    firstnode->nextptr = NULL;
    temp = firstnode;
// putting data for rest of the nodes
        for(i=2; i<=length; i++)
        {
                newnode = (struct node *)malloc(sizeof(struct node));
                printf(" Input data for node %d : ", i);
                scanf("%d", &data);
                newnode->data = data;
                newnode->preptr = temp;    // new node is linking with the previous node
                newnode->nextptr = NULL;
 
                temp->nextptr = newnode;   // previous node is linking with the new node
                temp = newnode;            // assign new node as last node
        }
}
void Printlist(int a)
{
    struct node * temp;
    int n = 1;
    
        temp = firstnode;
        if (a==1)
        {
        printf("\n Data entered in the list are :\n");
        }
        else
        {
         printf("\n After Deketion the new list are :\n");   
        }
        while(temp != NULL)
        {
            printf(" node %d : %d\n", n, temp->data);
            n++;
            temp = temp->nextptr; // current pointer moves to the next node
        }
    
    
}
void DlListDeleteFirstNode()
{
    struct node * NodeToDel;
        NodeToDel = firstnode;
        firstnode = firstnode->nextptr;   // move the next address of starting node to 2 node
        firstnode->preptr = NULL;      // set previous address of staring node is NULL
        free(NodeToDel);            // delete the first node from memory
    
}