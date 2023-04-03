#include<stdio.h>
int queue[100],rear=-1,front=-1,size;

void enque(int val)
{
	if(front==0 && rear==size-1)
	{
		printf("Queue is Full\n");
	}
	else if(rear==front-1)
	{
		printf("Queue is Full\n");
	}
	else if(front==-1 && rear==-1)
	{
		front=0;
		rear=0;
		queue[rear]=val;
	}
	else
	{
		rear=(rear+1)%size;
		queue[rear]=val;
	}
}
void display()
{
	int i=front;
	if(front==-1 && rear==-1)
	{
		printf("Queue is empty\n");
		return;
	}
	while(i!=rear)
	{
		printf("%d %d \n",i,queue[i]);
		i=(i+1)%size;
	}
	printf("%d %d \n",i,queue[i]);
}
int deque()
{
	int val;
	if(front==-1 && rear==-1)
	{
		return -1;
	}
	if(front==rear)
	{
		val=queue[front];
		front=-1;
		rear=-1;
		return val;
	}
	val=queue[front];
	front=(front+1)%size;
	return val;
}
int main()
{
	int ch,val;
	scanf("%d",&size);
	while(1)
	{
		printf("1. enque 2. deque 3.display 4.view front 5. view rear 6.exit:");
		scanf("%d",&ch);
		if(ch==1)
		{
			//Enque operation
			scanf("%d",&val);
			enque(val);
		}
		else if(ch==2)
		{
			//deque operation
			val=deque();// fun call
			if(val==-1)
			{
				printf("Queue is Empty\n");
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
		else if(ch==4)
		{
			printf("%d\n",front);
		}
		else if(ch==5)
		{
			printf("%d\n",rear);
		}
		else
		{
			break;
		}
	}
}
