#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node * nextptr;
}*firstnode;
 

void ClListcreation(int length);
void displayClList(int a);
void ClListDeleteMiddle(int position);

int main()
{
    int length,a,position;
    firstnode = NULL;
	printf("\n\n Circular Linked List : Delete node at the end of a circular linked list :\n");
	printf("-----------------------------------------------------------------------\n");	   	

    printf(" Input the number of nodes : ");
    scanf("%d", &length);
    a=1;
    ClListcreation(length); 
    displayClList(a);
    printf(" Enter the position where u want to insert: ");
    scanf("%d", &position);
    if(position<=1 || position>=length)
    {
     printf("\n Deletion can not be possible in that position.\n ");
    }
        if(position>1 && position<length)      
      {
          ClListDeleteMiddle(position);
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
         printf("\n After Deletion the new list are :\n");   
        }        
        do {
            printf(" Data %d = %d\n", n, temp->data);
            temp = temp->nextptr;
            n++;
        }while(temp != firstnode);
    
}
void ClListDeleteMiddle(int position)
{
    struct node *temp,*delnode;
        int k=1;
        delnode=firstnode;
        while(k!=position)
        {
            temp=delnode;
            delnode=delnode->nextptr;
            k++;
        }
        temp->nextptr=delnode->nextptr;
        printf("\n The deleted node is : %d",delnode->data);
        free(delnode);
}