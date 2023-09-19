#include<stdio.h>
void insertsort(int array[],int n);
int main()
{
	int array[10],n,i;
	printf("\n Enter no of elements in the array:");
	scanf("%d",&n);
	printf("\n enter the elements into the array:");
	for(i=0;i<n;i++)
	{
	scanf("%d",&array[i]);
    }
	insertsort(array,n);
	printf("\n The sorted elements are=");
	for(i=0;i<n;i++)
	{
	printf("%d\t",array[i]);
    }

}
void insertsort(int array[],int n)
{
	int temp,i,j;
	for(i=1;i<n;i++)
	{
		temp=array[i];
		j=i-1;
		while((temp<array[j]) && (j>=0))
		{
		array[j+1]=array[j];
		j--;
	    }
	    array[j+1]=temp;
	}

}
