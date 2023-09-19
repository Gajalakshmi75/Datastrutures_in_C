#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node * preptr;
    struct node * nextptr;
}*firstnode, *temp;
 

void DlListcreation(int length);
void DlLinsertNodeAtEnd(int newData);
void displayDlList(int a);

int main()
{
    int length,newData,a;
	printf("\n\n Doubly Linked List : Insert new node at the end in a doubly linked list :\n");
	printf("------------------------------------------------------------------------------\n");	   	
    printf(" Input the number of nodes : ");
    scanf("%d", &length);
    DlListcreation(length); 
    a=1;
    displayDlList(a);
    printf(" Input data for the last node : ");
    scanf("%d", &newData);
    DlLinsertNodeAtEnd(newData);
    a=2;
    displayDlList(a);
    return 0;
}
 
void DlListcreation(int length)
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

void DlLinsertNodeAtEnd(int newData)
{
    struct node * newnode;
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = newData;
        newnode->nextptr = NULL;        // set next address field of new node  is NULL
        newnode->preptr = temp;       // previous address of new node is linking with ending node
        temp->nextptr = newnode;      // next address of ending node is linking with new node
        temp =newnode;               // set the new node as ending node  

}

void displayDlList(int a)
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
         printf("\n After insertion the new list are :\n");   
        }
        while(temp != NULL)
        {
            printf(" node %d : %d\n", n, temp->data);
            n++;
            temp = temp->nextptr; // current pointer moves to the next node
        }
    
}