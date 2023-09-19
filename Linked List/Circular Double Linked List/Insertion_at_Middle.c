#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    struct node * preptr;
    struct node * nextptr;
}*firstnode, *temp;
 

void ClListcreation(int length);
void displayClList();
void insertNodeAtMiddle(int newData, int position);

int main()
{
    int length,newData,position;
    firstnode = NULL;
	printf("\n\n Circular Double Linked List : inserting a newnode at Specific position of circular double linked list :\n");
	printf("-----------------------------------------------------------------------\n");	   	

    printf(" Input the number of nodes : ");
    scanf("%d", &length);
 
    ClListcreation(length); 
    displayClList();
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
        insertNodeAtMiddle(newData,position); 
      }
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

void insertNodeAtMiddle(int newData, int position)
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
            newnode->nextptr = temp->nextptr;       
            newnode->preptr = temp;              
            if(temp->nextptr != NULL)
            {
                temp->nextptr->preptr = newnode; 
            }
            temp->nextptr = newnode; 
        }
        else
        {
            printf(" The position you entered, is invalid.\n");
        }
    
} 