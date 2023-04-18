#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node *next;
};
typedef struct Node NODE;
NODE *head=NULL,*tail=NULL,*temp,*NN,*res;

//create a new node
NODE * newnode(int val)
{
	NN=(NODE *)malloc(sizeof(NODE));
	NN->data=val;
	NN->next=NULL;
	return NN;		
}
void insert_at_head(NODE *NN)
{
	if(head==NULL && tail==NULL)
	{
		head=NN;
		tail=NN;
		head->next=head;
	}
	else
	{
		NN->next=head;
		head=NN;
		tail->next=head;
	}
}

void display()
{
	if(head==NULL && tail==NULL)
	{
		printf("No Nodes\n");
		return;
	}
	temp=head;
	while(temp->next!=head)
	{
		printf("%d %d %d\n",temp,temp->data,temp->next);
		temp=temp->next;
	}
	printf("%d %d %d\n",temp,temp->data,temp->next);
}
void insert_at_end(NODE *NN)
{
	if(head==NULL && tail==NULL)
	{
		head=NN;
		tail=NN;
		head->next=head;
	}
	else
	{
		tail->next=NN;
		tail=NN;
		tail->next=head;
	}
}

void insert_by_pos(NODE *NN,int pos)
{
	int p;
	temp=head;
	for(p=1;p<pos-1;p++)
	{
		if(temp->next==head)
		{
			printf("Insertion is not possible\n");
			return;
		}
		temp=temp->next;
	}
	NN->next=temp->next;
	temp->next=NN;
}
NODE* delete_at_head()
{
	if(head==NULL && tail==NULL)
	{
		return NULL;
	}
	if(head==tail)
	{
		res=head;
		head=NULL;
		tail=NULL;
		return res;
	}
	res=head;
	head=head->next;
	tail->next=head;
	res->next=NULL;
	return res;
}

NODE * delete_at_end()
{
	if(head==NULL && tail==NULL)
	{
		return NULL;
	}
	if(head==tail)
	{
		res=head;
		head=NULL;
		tail=NULL;
		return res;
	}
	temp=head;
	while(temp->next->next!=head)
	{
		temp=temp->next;
	}
	res=tail;
	temp->next=head;
	tail=temp;
	res->next=NULL;
	return res;
}
NODE * delete_by_pos(int pos)
{
	int p;
	temp=head;
	for(p=1;p<pos-1;p++)
	{
		if(temp->next==head)
		{
			printf("deletion is not possible\n");
			return NULL;
		}
		temp=temp->next;
	}
	res=temp->next;
	temp->next=res->next;
	res->next=NULL;
	return res;
}
int main()
{
	int ch,val,pos;
	while(1)
	{
		printf("1.insert at head\n2.insert at end\n3.insert by pos\n4.display\n5.delete at head\n6.delete at end\n7.delete by pos\n8.exit:");
		scanf("%d",&ch);
		if(ch==1)
		{
			//insert at head
			scanf("%d",&val);
			NN=newnode(val);
			insert_at_head(NN);
		}
		else if(ch==2)
		{
			//insert at end
			scanf("%d",&val);
			NN=newnode(val);
			insert_at_end(NN);
		}
		else if(ch==3)
		{
			//insert by pos
			scanf("%d",&val);
			scanf("%d",&pos);
			NN=newnode(val);
			insert_by_pos(NN,pos);
		}
		else if(ch==4)
		{
			//display
			display();
		}
		else if(ch==5)
		{
			//delete at head
			res=delete_at_head();
			if(res==NULL)
			{
				printf("No Nodes\n");
			}
			else
			{
				printf("%d\n",res->data);
				free(res);
			}
			
		}
		else if(ch==6)
		{
			//delete at end
			res=delete_at_end();
			if(res==NULL)
			{
				printf("No Nodes\n");
			}
			else
			{
				printf("%d\n",res->data);
				free(res);
			}
		}
		else if(ch==7)
		{
			//delete by pos
			scanf("%d",&pos);
			res=delete_by_pos(pos);
			if(res==NULL)
			{
				printf("No Nodes\n");
			}
			else
			{
				printf("%d\n",res->data);
				free(res);
			}
		}
		else
		{
			break;
		}
	}
}






