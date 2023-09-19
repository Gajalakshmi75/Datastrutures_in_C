#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node * preptr;
    struct node * nextptr;
}*firstnode, *temp;
 

void DLlistcreation(int length);
void Printlist(struct node*node);

int main()
{
    int length;
	printf("\n\n Doubly Linked List : Reverse the list upto nth position in a doubly linked list :\n");
	printf("-------------------------------------------------------------------\n");	   	

    printf(" Input the number of nodes : ");
    scanf("%d", &length);
 
    DLlistcreation(length); 
    Printlist(firstnode);
    
    reverse();
    PrintList(nthnode);
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
void Printlist(struct node * node)
{
    int n = 1;
    while(node != NULL)
        {
            printf(" node %d : %d\n", n, node->data);
            n++;
            node = node->nextptr; // current pointer moves to the next node
        }
    
}
void displayDlListRev()
{
    struct node * tmp;
    int n = 0;
 
    if(ennode == NULL)
    {
        printf(" No data found in the List yet.");
    }
    else
    {
        tmp = ennode;
        printf("\n Data in reverse order are :\n");
        while(tmp != NULL)
        {
            printf(" Data in node %d : %d\n", n+1, tmp->num);
            n++;
            tmp = tmp->preptr; // current pointer set with previous node
        }
    }
} 
void reverse()
{
    struct node *prevNode, *curNode;
    int n,i;
    printf(" Enter the nth position : ");
    scanf("%d", &n);
    nthnode = firstnode;
        for(i=1; i<n; i++)
        {
            nthnode = nthnode->nextptr;
        }
        prevNode = nthnode;
        curNode = nthnode->nextptr;
        nthnode = nthnode->nextptr;
 
        prevNode->nextptr = NULL; //convert the first node as last
 
        while(nthnode != NULL)
        {
            nthnode = nthnode->nextptr;
            curNode->nextptr = prevNode;
 
            prevNode = curNode;
            curNode = nthnode;
        }
        nthnode = prevNode; //convert the last node as head
        
    printf("\n List from the last node to %d th position node: \n",n);
    
}