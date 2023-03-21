/*
8

0 1 2 3 4 5 6 7
8 1 7 2 6 3 5 4
L             H    L<=H   0<=7

16
16 1 15 2 14 3 13 4 12 5 11 6 10 7 9 8


8
8 1 7 2 6 3 5 4


            J    
0 1 2 3 4 5 6 7
1 2 7 8 6 3 4 5  p=4



res=1 2 7 8
        i 
*/

#include<stdio.h>
void merge(int *arr,int L,int H,int M)//arr,0,3,1
{
	int i=L,j=M+1,k=0,res[H-L+1];
	while(i<=M && j<=H)
	{
		if(arr[i]>arr[j])
		{
			res[k++]=arr[j++];
		}
		else
		{
			res[k++]=arr[i++];
		}
	}
	
	while(i<=M)
	{
		res[k++]=arr[i++];
	}
	while(j<=H)
	{
		res[k++]=arr[j++];
	}
	k=0;
	for(i=L;i<=H;i++)
	{
		arr[i]=res[k++];
	}
	
}
void merge_sort(int *arr,int L,int H)
{
	if(L<H)
	{
		int M;
		M=(L+H)/2;
		merge_sort(arr,L,M);
		merge_sort(arr,M+1,H); 
		merge(arr,L,H,M);;
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
	merge_sort(arr,0,n-1);//
	
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	return 0;
}




