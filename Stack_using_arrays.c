#include<stdio.h>
int st[100],size,top=-1;
void push(int val)
{
	if(top==size-1)
	{
		printf("Stack is full/overflow\n");
	}
	else
	{
		st[++top]=val;//
	}
}

int pop()
{
	int val;
	if(top==-1)
	{
		return top;
	}
	else
	{
		val=st[top];
		st[top--]=0;
		return val;
	}
}
void display()
{
	int i;
	if(top==-1)
	{
		printf("Stack is empty / underflow\n");
	}
	else
	{
		for(i=top;i>=0;i--)
		{
			printf("%d ",st[i]);
		}
		printf("\n");	
	}	
}
int main()
{
	int ch,val;
	scanf("%d",&size);
	while(1)
	{
		printf("1.Push 2.pop 3.display 4.exit: ");
		scanf("%d",&ch);
		if(ch==1)
		{
			scanf("%d",&val);
			push(val);
		}
		else if(ch==2)
		{
			val=pop();//
			if(val==-1)
			{
				printf("Stack is empty/ underflow\n");
			}
			else
			{
				printf("%d\n",val);
			}
		}
		else if(ch==3)
		{
			display();
		}
		else
		{
			break;
		}
	}
}
