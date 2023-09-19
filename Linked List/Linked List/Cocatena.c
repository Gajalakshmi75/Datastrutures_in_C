#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
}*firstnode1,*firstnode2;

void PrintList(struct node* node);
void Creation(int Length1, int Length2);
void concatenate(struct node *firstnode1,struct node *firstnode2);
int main()
{
    int Length1,Length2;
    printf("\n\n Linked List : To Create and Display Linked List :\n");
	printf("-------------------------------------------------------------\n");
    printf(" Input the Length of nodes : ");
    scanf("%d", &Length1);
    printf(" Input the Length of nodes : ");
    scanf("%d", &Length2);
    Creation(Length1,Length2);
    printf("\n Data entered in the list : \n");
    PrintList(firstnode1);
    printf("\n Data entered in the list : \n");
    
    PrintList(firstnode2);
    concatenate(firstnode1,firstnode2);
    
    printf("\n Data entered in the list : \n");
    PrintList(firstnode1);
    return 0;
}
void Creation(int Length1,int Length2)
{
    struct node *temp,*newnode;
	int data,i;
    firstnode1=NULL;
    for (i=1;i<=Length1;i++)
    {
    	newnode=(struct node *)malloc(sizeof(struct node));
    	printf(" Input data for node %d : ",i);
    	scanf("%d",&data);
    	newnode->data=data;
    	newnode->next=NULL;
        if(firstnode1==NULL)
            firstnode1=newnode;
        else
            temp->next=newnode;
    	temp=newnode;
    }
    firstnode2=NULL;
    for (i=1;i<=Length2;i++)
    {
    	newnode=(struct node *)malloc(sizeof(struct node));
    	printf(" Input data for node %d : ",i);
    	scanf("%d",&data);
    	newnode->data=data;
    	newnode->next=NULL;
        if(firstnode2==NULL)
            firstnode2=newnode;
        else
            temp->next=newnode;
    	temp=newnode;
    }

}
void PrintList(struct node* node) 
{
    int j;
    j=1;
    while (node != NULL) 
    {
        printf("Data of %d Node =  %d \n",j++, node->data);
        node = node->next;
    }
}
void concatenate(struct node *firstnode1,struct node *firstnode2)
{
    if( firstnode1 != NULL && firstnode2!= NULL )
    {
        if (firstnode1->next == NULL)
            firstnode1->next = firstnode2;
        else
            concatenate(firstnode1->next,firstnode2);
    }
    else
    {
        printf("Either a or b is NULL\n");
    }
}
