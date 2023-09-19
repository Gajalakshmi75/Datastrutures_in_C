#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node * nextptr;
}*firstnode;
 

void ClListcreation(int length);
void ClLinsertNodeAtMiddle(int newData,int position);
void displayClList(int a);

int main()
{
    int length,newData,a,position;
    firstnode = NULL;
	printf("\n\n Circular Linked List :Insert a node at a paticular position in a circular linked list :\n");
	printf("-----------------------------------------------------------------------\n");	   	

    printf(" Input the number of nodes : ");
    scanf("%d", &length);
    a=1;
    ClListcreation(length); 
    displayClList(a);
    printf(" Enter the position where u want to insert: ");
    scanf("%d", &position);
    printf(" Enter the newdata of nodes : ");
    scanf("%d", &newData);
    if(position<=1 || position>=length)
    {
     printf("\n Insertion can not be possible in that position.\n ");
    }
        if(position>1 && position<length)      
      {
          ClLinsertNodeAtMiddle(newData,position);
       printf("\n Insertion completed successfully.\n ");
       a=2;
       displayClList(a);
      }
    return 0;
}

void ClListcreation(int length)
{
    int  data,i;
    struct node *temp, *newnode;

    if(length >= 1)
    {
        firstnode = (struct node *)malloc(sizeof(struct node));

        printf(" Input data for node 1 : ");
        scanf("%d", &data);
        firstnode->data = data;
        firstnode->nextptr = NULL;
        temp = firstnode;
        for(i=2; i<=length; i++)
        {
            newnode = (struct node *)malloc(sizeof(struct node));
            printf(" Input data for node %d : ", i);
            scanf("%d", &data);
            newnode->data = data;
            newnode->nextptr = NULL;	// next address of new node set as NULL
            temp->nextptr = newnode;	// previous node is linking with new node
            temp = newnode;   		// previous node is advanced
        }
        temp->nextptr = firstnode; 		//last node is linking with first node
    }
}

void displayClList(int a)
{
    struct node *temp;
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
        do {
            printf(" Data %d = %d\n", n, temp->data);
            temp = temp->nextptr;
            n++;
        }while(temp != firstnode);
    
}
void ClLinsertNodeAtMiddle(int newData,int position)
{
    struct node *newnode, *curNode;
    int i;

        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = newData;
        curNode = firstnode;
        for(i=2; i<=position-1; i++)
        {
            curNode = curNode->nextptr;
        }
        newnode->nextptr = curNode->nextptr;
        curNode->nextptr = newnode;
    
}