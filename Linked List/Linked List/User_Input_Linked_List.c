#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct node
{
    int data;
    struct node *next;
};
void printList(struct node* node) {
  while (node != NULL) {
    printf(" %d ", node->data);
    printf(" ->%d| ", node->next);
    node = node->next;
  }
}
int main()
{
    struct node *prev,*head,*newnode;
    int len,i;
    printf ("Length of the List:");
    scanf("%d",&len);
    head=NULL;
    for(i=0;i<len;i++)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter the %d Node Data\n",i+1);
		scanf("%d",&newnode->data);
        newnode->next=NULL;
        if(head==NULL)
            head=newnode;
        else
            prev->next=newnode;
        prev=newnode;
    }
    printList(head);
    return 0;
}