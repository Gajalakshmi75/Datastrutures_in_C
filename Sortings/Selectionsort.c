#include<stdio.h>
void main(){
  int n,i,j,temp,list[10];
  printf("Enter the size of the List: ");
  scanf("%d",&n);

  printf("Enter %d integer values: ",n);
  for(i=0; i<n; i++)
      scanf("%d",&list[i]);

  //Selection sort logic

  for(i=0; i<n; i++){
      for(j=i+1; j<n; j++){
           if(list[i] > list[j])
	   {
               temp=list[i];
               list[i]=list[j];
               list[j]=temp;
           }
      }
  }

  printf("List after sorting is: ");
  for(i=0; i<n; i++)
      printf(" %d",list[i]);

}
