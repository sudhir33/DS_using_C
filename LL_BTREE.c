#include<stdio.h>
#include<stdlib.h>
struct NodeLL{
	int data;
	struct NodeLL *next;
};
typedef struct NodeLL NODELL;
NODELL *head=NULL,*temp,*NNLL;

struct NodeT{
	struct NodeT *left;
	int data;
	struct NodeT *right;
};
typedef struct NodeT NODETREE;
NODETREE *root=NULL,*NNT,*queue[100];
















NODELL * newnodeLL(int val)
{
	NNLL=(NODELL *)malloc(sizeof(NODELL));
	NNLL->data=val;
	NNLL->next=NULL;
	return NNLL;
}
void createLL(int val)
{
	NNLL=newnodeLL(val);
	if(head==NULL)
	{
		head=NNLL;
	}
	else
	{
		temp=head;
		while(temp->next)
		{
			temp=temp->next;
		}
		temp->next=NNLL;
	}
}
void displayLL()
{
	temp=head;
	while(temp)
	{
		printf("%d %d %d\n",temp,temp->data,temp->next);
		temp=temp->next;
	}
}

/*
                  f                  r
2000 10 3000    4000 20 N  N 30 N  N 40 N  L D R   L D R   
                   2000    3000     4000

10       20     30     40       50      60
               temp
*/

NODETREE * newnodeTree(int val)
{
	NNT=(NODETREE *)malloc(sizeof(NODETREE));
	NNT->data=val;
	NNT->right=NULL;
	NNT->left=NULL;
	return NNT;
}
NODETREE * constructTree(NODELL *head)
{
	int f=0,r=0;
	temp=head;
	NNT=newnodeTree(temp->data);// 
	queue[r]=NNT;
	while(1)
	{
		if(temp->next)// 4000
		{
			NNT=newnodeTree(temp->next->data);// N 40 N
			queue[++r]=NNT;
			queue[f]->left=NNT;
			temp=temp->next;
		}
		else
		{
			return queue[0];//
		}
		if(temp->next)
		{
			NNT=newnodeTree(temp->next->data);// N 30 N
			queue[++r]=NNT;
			queue[f]->right=NNT;
			temp=temp->next;
		}
		else
		{
			return queue[0];
		}
		f++;
	}
	
}
void inorder(NODETREE * root)
{
	if(!root)
	{
		return;
	}
	inorder(root->left);
	printf("%d ",root->data);
	inorder(root->right);
}








int main()
{
	int val,n,i;
	scanf("%d",&n);// no.of values// 5
	for(i=1;i<=n;i++)
	{
		scanf("%d",&val);// 10 20 30 40 50
		createLL(val);//cLL(10)
	}
	//displayLL();
	root=constructTree(head);//
	inorder(root);
}








