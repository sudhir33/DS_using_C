#include<stdio.h>
#include<stdlib.h>
struct Node{
	int co,pow;
	struct Node *next;
};
typedef struct Node NODE;
NODE *head1=NULL,*head2=NULL,*head3=NULL;
NODE *temp,*temp1,*temp2,*temp3,*NN;

NODE * Newnode(int co,int pow)
{
	NN=(NODE *)malloc(sizeof(NODE));
	NN->co=co;
	NN->pow=pow;
	NN->next=NULL;
	return NN;
}

NODE * createploy(NODE *head)
{
	int co,pow;
	char ch='Y';
	while(ch!='N')
	{
		scanf("%d%d",&co,&pow);
		NN=Newnode(co,pow);
		if(head==NULL)
		{
			head=NN;
		}
		else
		{
			temp=head;
			while(temp->next)
			{
				temp=temp->next;
			}
			temp->next=NN;
		}
		printf("Do u want to enter(Y/N):");
		scanf(" %c",&ch);
	}
	return head;
}
void display(NODE *head)
{
	temp=head;
	while(temp)
	{
		printf("%d %d\t",temp->co,temp->pow);
		temp=temp->next;
	}
	printf("\n");
}
NODE * addploy(NODE *head1,NODE *head2,NODE *head3)
{
	temp1=head1;
	temp2=head2;
	while(temp1 && temp2)
	{
		NN=Newnode(0,0);
		if(head3==NULL)	
		{
			head3=NN;
		}
		else
		{
			temp=head3;
			while(temp->next)
			{
				temp=temp->next;
			}
			temp->next=NN;
		}
		if(temp1->pow==temp2->pow)
		{
			NN->co=temp1->co+temp2->co;
			NN->pow=temp1->pow;
			temp1=temp1->next;
			temp2=temp2->next;
		}
		else if(temp1->pow>temp2->pow)
		{
			NN->co=temp1->co;
			NN->pow=temp1->pow;
			temp1=temp1->next;
		}
		else if(temp1->pow<temp2->pow)
		{
			NN->co=temp2->co;
			NN->pow=temp2->pow;
			temp2=temp2->next;
		}
		
	}
	while(temp1)
	{
		NN=Newnode(0,0);
		if(head3==NULL)	
		{
			head3=NN;
		}
		else
		{
			temp=head3;
			while(temp->next)
			{
				temp=temp->next;
			}
			temp->next=NN;
		}
		NN->co=temp1->co;
		NN->pow=temp1->pow;
		temp1=temp1->next;
	}
	while(temp2)
	{
		NN=Newnode(0,0);
		if(head3==NULL)	
		{
			head3=NN;
		}
		else
		{
			temp=head3;
			while(temp->next)
			{
				temp=temp->next;
			}
			temp->next=NN;
		}
		NN->co=temp2->co;
		NN->pow=temp2->pow;
		temp2=temp2->next;
	}
	return head3;
}

int main()
{
	head1=createploy(head1);
	head2=createploy(head2);
	head3=addploy(head1,head2,head3);
	display(head1);
	display(head2);
	display(head3);
	return 0;
}
