#include<stdio.h>
void merge(int *arr1,int n,int *arr2,int m)
{
	int res[100]={0},i=0,j=0,k=0;
	while(i<n && j<m)
	{
		if(arr1[i]>arr2[j])
		{
			res[k]=arr2[j];
			j++;
			k++;
		}
		else
		{
			res[k]=arr1[i];
			i++;
			k++;
		}
	}
	while(i<n)
	{
		res[k]=arr1[i];
		i++;
		k++;
	}
	while(j<m)
	{
		res[k]=arr2[j];
		j++;
		k++;
	}
	for(i=0;i<m+n;i++)
	{
		printf("%d ",res[i]);
	}
	
}
int main()
{
	int arr1[100],arr2[100],i,j,n,m;
	scanf("%d",&n);
	scanf("%d",&m);
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr1[i]);
	}
	for(j=0;j<m;j++)
	{
		scanf("%d",&arr2[j]);
	}
	merge(arr1,n,arr2,m);
}


