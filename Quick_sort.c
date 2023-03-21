#include<stdio.h>
void swap(int *arr,int i,int j)
{
	int temp=arr[i];
	arr[i]=arr[j];
	arr[j]=temp;
}
int partition(int *arr,int L,int H)
{
	int p=H,i,j,temp;
	for(i=L,j=L;i<p;i++)
	{
		if(arr[i]<arr[p])
		{
			swap(arr,i,j);
			j++;
		}
	}
	swap(arr,j,p);
	return j;	
}
void quicksort(int *arr,int L,int H)
{
	if(L<H)
	{
		int par;
		par=partition(arr,L,H);
		quicksort(arr,L,par-1);
		quicksort(arr,par+1,H);	
	}
}
int main()
{
	int arr[100],i,n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	quicksort(arr,0,n-1);//fun call
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
}
