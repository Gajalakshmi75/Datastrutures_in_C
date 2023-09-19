#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node * preptr;
    struct node * nextptr;
}*firstnode, *temp;
 

void DlListcreation(int length);
void DlLinsertNodeAtMiddle(int newData, int position);
void displayDlList(int a);

int main()
{
    int length,newData,a,position;
	printf("\n\n Doubly Linked List : Insert new node at the end in a doubly linked list :\n");
	printf("------------------------------------------------------------------------------\n");	   	
    printf(" Input the number of nodes (Please Craete more than 2 nodes) : ");
    scanf("%d", &length);
    DlListcreation(length); 
    a=1;
    displayDlList(a);
    printf(" Input the position where you  want to insert a new node : ");
    scanf("%d", &position);

if(position<=1 || position>=length)
    {
     printf("\n Invalid position. Try again.\n ");
    }
	      if(position>1 && position<length)
      {
    printf(" Input data for the position %d : ", position);
    scanf("%d", &newData);          
    DlLinsertNodeAtMiddle(newData,position);  
    a=2;
    displayDlList(a);
      }

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

void DlLinsertNodeAtMiddle(int newData, int position)
{
    int i;
    struct node * newnode;
        temp = firstnode;
        i=1;
        while(i<position-1 && temp!=NULL)
        {
            temp = temp->nextptr;
            i++;
        }
        if(temp!=NULL)
        {
            newnode = (struct node *)malloc(sizeof(struct node));
            newnode->data = newData;
//next address of new node is linking with the next address of temp node            
            newnode->nextptr = temp->nextptr; 
// previous address of new node is linking with the tmp node            
            newnode->preptr = temp;              
            if(temp->nextptr != NULL)
            {
                temp->nextptr->preptr = newnode; // n+1th node is linking with new node
            }
            temp->nextptr = newnode; // n-1th node is linking with new node 
        }
        else
        {
            printf(" The position you entered, is invalid.\n");
        }
    
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