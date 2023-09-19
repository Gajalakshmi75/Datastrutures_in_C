#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node * preptr;
    struct node * nextptr;
}*firstnode, *temp;
 

void DLlistcreation(int length);
void Printlist();
void maxnode();
void minnode();

int main()
{
    int length,max,min;
	printf("\n\n Doubly Linked List :Finding Maximum and Minimun Values in Double linked list :\n");
	printf("-------------------------------------------------------------------\n");	   	

    printf(" Input the number of nodes : ");
    scanf("%d", &length);
 
    DLlistcreation(length); 
    Printlist();
    maxnode();
    minnode();
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
                newnode->preptr = temp;  
                newnode->nextptr = NULL;
 
                temp->nextptr = newnode;   
                temp = newnode; 
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
            temp = temp->nextptr; // current pointer moves to the next node
        }
    
}
void maxnode() 
{  
    struct node *maxnode = firstnode;  
    int max;
        max = firstnode->data;  
          
        while(maxnode != NULL) // loop run untill its reaches last node so after getting max value than firsnode also u find another node whether its has max value or not
        {  
             if(max < maxnode->data) // if its false then maxnode Change to its next node  ............ if its true and max value changes to maxnode data 
             {  
                max = maxnode->data;  
             }  
             maxnode = maxnode->nextptr;  
        }              
        printf("Maximum value node in the list: %d\n", max);  
      
}  
void minnode() 
{  
    struct node *minnode = firstnode;  
    int min;
        min = firstnode->data;  
          
        while(minnode != NULL) // loop run untill its reaches last node so after getting min value than firsnode also u find another node whether its has min value or not
        {  
             if(min > minnode->data) // if its false then minnode Change to its next node  ............ if its true and min value changes to minnode data 
             {  
                min = minnode->data;  
             }  
             minnode = minnode->nextptr;  
        }              
        printf("Minimun value node in the list: %d\n", min);  
      
}  