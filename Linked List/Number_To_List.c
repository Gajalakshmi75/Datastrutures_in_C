#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node * nextptr;
}*firstnode, *temp;
 

void Creation(int digit);
void Printlist();

int main()
{
    int digit,number;
	printf("\n\n Given Number into a Linked List :\n");
	printf("-------------------------------------------------------------------\n");	   	

    printf(" Enter the Number: ");
    scanf("%d", &number);
    while (number>0)
    {
        digit=number%10;
        number=number/10;
        Creation(digit);
    }
    Printlist();
    return 0;
}
 
void Creation(int digit)
{
    int i;
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = digit;
    if(firstnode==NULL)
    {
        firstnode =newnode;
        firstnode->nextptr=NULL;
    }
    else
    {
        newnode->nextptr=firstnode;
        firstnode=newnode;
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