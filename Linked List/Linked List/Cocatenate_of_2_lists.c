#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
}*firstnode1,*firstnode2;

void PrintList(struct node* node);
void Creation1();
void Creation2();
void insert(struct node* head1, struct node* head2,int k);

int main()
{
    int k=2;
    struct node*a=NULL;
    struct node*b=NULL;
    printf("\n\n Linked List : To Create and Display Linked List :\n");
	printf("-------------------------------------------------------------\n");
    Creation1();
    printf("\n Data entered in the list : \n");
    PrintList(firstnode1);
    Creation2();
    printf("\n Data entered in the list : \n");
    PrintList(firstnode2);
    insert(a,b,k);
    PrintList(a);

    return 0;
}
void Creation1()
{
    struct node *temp,*newnode,*a;
	int data,i,Length;
    printf(" Input the Length of nodes : ");
    scanf("%d", &Length);
	firstnode1 = (struct node *)malloc(sizeof(struct node));
	printf(" Input data for node 1 : ");
    scanf("%d", &data);
    firstnode1->data= data;
    firstnode1->next = NULL; // links the address field to NULL
    temp=firstnode1;
    for (i=2;i<=Length;i++)
    {
    	newnode=(struct node *)malloc(sizeof(struct node));
    	printf(" Input data for node %d : ",i);
    	scanf("%d",&data);
    	newnode->data=data;
    	newnode->next=NULL;
        if(a==NULL)
            a=newnode;
        else
    	temp->next=newnode;
    	temp=temp->next;
    }
    

}
void Creation2()
{
    struct node *temp,*b,*newnode;
	int data,i,Length2;
    printf(" Input the Length of nodes : ");
    scanf("%d", &Length2);
	firstnode2 = (struct node *)malloc(sizeof(struct node));
	printf(" Input data for node 1 : ");
    scanf("%d", &data);
    firstnode2->data= data;
    firstnode2->next = NULL; // links the address field to NULL
    temp=firstnode2;
    for (i=2;i<=Length2;i++)
    {
    	newnode=(struct node *)malloc(sizeof(struct node));
    	printf(" Input data for node %d : ",i);
    	scanf("%d",&data);
    	newnode->data=data;
    	newnode->next=NULL;
        if(b==NULL)
            b=newnode;
        else
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
        printf("Data of %d Node =  %d \n",j++, node->data);
        node = node->next;
    }
}

void insert(struct node* head1, struct node* head2,
            int k)
{
    int count = 1;
    struct node* curr = head1;
    while (count < k) {
        curr = curr->next;
        count++;
    }
 
    struct node* temp = curr->next;
 
    curr->next = head2;
 
    while (head2->next != NULL)
        head2 = head2->next;
 
    head2->next = temp;
}