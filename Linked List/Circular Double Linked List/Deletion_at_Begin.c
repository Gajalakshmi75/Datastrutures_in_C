#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    struct node * preptr;
    struct node * nextptr;
}*firstnode, *temp;
 

void ClListcreation(int length);
void displayClList();
void DeleteFirstNode();

int main()
{
    int length;
    firstnode = NULL;
	printf("\n\n Circular Double Linked List : Deletion of first node in circular double linked list :\n");
	printf("-----------------------------------------------------------------------\n");	   	

    printf(" Input the number of nodes : ");
    scanf("%d", &length);
 
    ClListcreation(length); 
    displayClList();
    DeleteFirstNode();
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
void DeleteFirstNode()
{
        struct node *temp,*delnode;
		temp=firstnode;
		while(temp->nextptr!=firstnode)
		{
			temp=temp->nextptr;
		}
		delnode=firstnode;
		firstnode=firstnode->nextptr; 
        firstnode->preptr = temp; 
		printf("\n The deleted node is -> %d\n",delnode->data);
		temp->nextptr=firstnode;
		free (delnode);
}