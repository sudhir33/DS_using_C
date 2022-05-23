#include<stdio.h>
void merge(int *arr,int l,int m,int h)
{
	int i,j,n1,n2,a[100],b[100],k;
	n1=m-l+1;
	n2=h-m;
	k=l;
	for(i=0;i<n1;i++)
	{
		a[i]=arr[k++];
	}
	k=m+1;
	
	for(i=0;i<n2;i++)
	{
		b[i]=arr[k++];
	}
	
	i=0,j=0;
	k=l;
	while(i<n1 && j<n2)
	{
		if(a[i]<b[j])
		{
			arr[k++]=a[i++];
		}
		else
		{
			arr[k++]=b[j++];
		}
	}
	while(i<n1)
	{
		arr[k++]=a[i++];
	}
	while(j<n2)
	{
		arr[k++]=b[j++];
	}
}
void merge_sort(int *arr,int L,int H)
{
	int M;
	if(L<H)
	{
		M=(L+H)/2;
		merge_sort(arr,L,M);//8 1 7 2---> 1 8--> 8
		merge_sort(arr,M+1,H);//1
		merge(arr,L,M,H);// merge(arr,0,0,1)
	}
}
void main()
{
	int arr[100],i,n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	merge_sort(arr,0,n-1);//fun call merge
	for(i=0;i<n;i++)
	{	
		printf("%d ",arr[i]);	
	}
}


/*

8 1 7 2 6 3 5 4

1 8 2 7 3 6 4 5       p=4
0 1 2 3 4 5 6 7 
        L M   H

m-l+1

3/2-1


for(i=0;i<n;i++)
{
		printf("%d ",arr[i]);
}
8
1 4 6 8 2 3 5 10
0 1 2 3 4 5 6  7
    l 



1 2 3 4 5 6 8 10

i<j---> add j j++



*/




















