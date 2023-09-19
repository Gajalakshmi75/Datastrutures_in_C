#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
}*firstnode;

void PrintList(struct node* node);
void MiddleNodeDeletion(int Postion);
void Creation(int Length);

int main()
{
    int Length,i,Postion;
    printf("\n\n Linked List : Delete Middle node of Singly Linked List :\n");
	printf("-------------------------------------------------------------\n");
    printf(" Input the Length of nodes : ");
    scanf("%d", &Length);
    Creation(Length);
    printf("\n Data entered in the list : \n");
    PrintList(firstnode);
    printf("\n Input the position of node to delete : ");
    scanf("%d", &Postion);

    if(Postion<=1 || Postion>=Length)
    {
     printf("\n Deletion can not be possible from that position.\n ");
    }
	      if(Postion>1 && Postion<Length)
      {
       printf("\n Deletion completed successfully.\n ");
	   MiddleNodeDeletion(Postion);
      }

	    printf("\n The new List are  : \n");
    PrintList(firstnode);
    return 0;
}
void Creation(int Length)
{
    struct node *temp,*newnode;
	int data,i;
	firstnode = (struct node *)malloc(sizeof(struct node));
	printf(" Input data for node 1 : ");
    scanf("%d", &data);
    firstnode->data= data;
    firstnode->next = NULL; // links the address field to NULL
    temp=firstnode;
    for (i=2;i<=Length;i++)
    {
    	newnode=(struct node *)malloc(sizeof(struct node));
    	printf(" Input data for node %d : ",i);
    	scanf("%d",&data);
    	newnode->data=data;
    	newnode->next=NULL;
    	temp->next=newnode;
    	temp=temp->next;
    }

}
void PrintList(struct node* node) 
{
    int j;
    j=1;
    while (node != NULL) 
    {
        printf(" Data of %d Node = %d\n",j++, node->data);
        node = node->next;
    }
}
void MiddleNodeDeletion(int Postion)
{
    int i;
    struct node *DelMid, *preNode;
    if(firstnode== NULL)
    {
        printf(" There are no nodes in the List.");
    }
    else
    {
        DelMid = firstnode;
        preNode = firstnode;
 
        for(i=2; i<=Postion; i++)
        {
            preNode = DelMid;
            DelMid = DelMid->next;
        }
        if(DelMid != NULL)
        {
            if(DelMid == firstnode)
                firstnode = firstnode->next;
 
            preNode->next = DelMid->next;
            DelMid->next = NULL;
            printf("\n Data of %d Last which is being deleted is :  %d\n",Postion, DelMid->data);
            free(DelMid);
        }
        else
        {
            printf(" Deletion can not be possible from that position.");
        }
    }
}