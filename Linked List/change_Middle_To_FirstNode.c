#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node * preptr;
    struct node * nextptr;
}*firstnode, *temp;
 

void DLlistcreation(int length);
void Printlist();
void changeMiddleToFirstNode(int middle);
int main()
{
    int length,middle;
	printf("\n\n Doubly Linked List : Change the Middle node of the list to the first node of the list:\n");
	printf("-------------------------------------------------------------------\n");	   	

    printf(" Input the number of nodes : ");
    scanf("%d", &length);
 
    DLlistcreation(length); 
    Printlist();
    middle=(length/2);
    changeMiddleToFirstNode(middle);
    printf(" After Change MiddleNode to FirstNode : ");
    Printlist();
    return 0;
}
 
void DLlistcreation(int length)
{
    int i, data;
    struct node *newnode;
    firstnode = (struct node *)malloc(sizeof(struct node));
    printf(" Input data for node 1 : "); 
    scanf("%d", &data);
    firstnode->data = data;
    firstnode->preptr = NULL;
    firstnode->nextptr = NULL;
    temp = firstnode;
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
void Printlist()
{
    struct node * temp;
    int n = 1;
    temp = firstnode;
    printf("\n\n Data entered on the list are :\n");
    while(temp != NULL)
        {
            printf(" node %d : %d\n", n, temp->data);
            n++;
            temp = temp->nextptr;
        }
    
}

void changeMiddleToFirstNode(int middle)
{
    int i;
    temp = firstnode;
    while(i<middle && temp!=NULL)
        {
            temp = temp->nextptr;
            i++;
        }
            temp->preptr->nextptr = temp->nextptr;
            temp->nextptr->preptr = temp->preptr;
            temp->nextptr=firstnode;
            firstnode->preptr =temp;
            temp->preptr=NULL;
            firstnode=temp;
        
} 