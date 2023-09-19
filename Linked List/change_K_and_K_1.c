#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node * preptr;
    struct node * nextptr;
}*firstnode, *temp;
 

void DLlistcreation(int length);
void Printlist();
void swapingtwonodes(int Position);

int main()
{
    int length,Position;
	printf("\n\n Doubly Linked List : swap a paticular position with its pre position  doubly linked list :\n");
	printf("-------------------------------------------------------------------\n");	   	

    printf(" Input the number of nodes : ");
    scanf("%d", &length);
 
    DLlistcreation(length); 
    Printlist();
    printf(" Enter the Position where u want to shit: ");
    scanf("%d", &Position);
    swapingtwonodes(Position);
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
        temp->nextptr = firstnode; 		//last node is linking with first node
        firstnode->preptr = temp;
}
void Printlist()
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
void swapingtwonodes(int Position)
{
    struct node *temp1,*temp2;
    int i;
 
    temp2 = firstnode;
    for(i=1; i<Position && temp2!=NULL; i++)
    {
        temp1 = temp2;
        temp2 = temp2->nextptr;
    }
    temp1->preptr->nextptr = temp2;
    temp2->preptr = temp1->preptr;
    temp2->nextptr->preptr = temp1;
    temp1->nextptr =temp2->nextptr;
    temp2->nextptr =temp1;
    temp1->preptr =temp2;
}
