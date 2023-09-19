#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node * preptr;
    struct node * nextptr;
}*firstnode, *temp;
 

void DLlistcreation(int length);
void Printlist(int a);
void DlLinsertNodeAtBeginning(int newData);

int main()
{
    int length,newData,a;
	printf("\n\n Doubly Linked List : Insert new node at the beginning in a doubly linked list :\n");
	printf("-------------------------------------------------------------------\n");	   	

    printf(" Input the number of nodes : ");
    scanf("%d", &length);
    a=1;
 
    DLlistcreation(length); 
    Printlist(a);
    printf(" Input data for the first node : ");
    scanf("%d", &newData);
    a=2;
    DlLinsertNodeAtBeginning(newData);
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
        temp = firstnode;
        int n=1;
        if (a==1)
        {
        printf("\n Data entered in the list are :\n");
        }
        else
        {
         printf("\n After insertion the new list are :\n");   
        }
        while(temp != NULL)
        {
            printf(" node %d : %d\n", n, temp->data);
            n++;
            temp = temp->nextptr; // current pointer moves to the next node
        }
    
    
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