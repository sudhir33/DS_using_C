#include<stdio.h>
#include<string.h>
int pred(char ch)
{
	
	switch(ch)//+
	{
		case '^':return 3;
		case '*':return 2;
		case '/':return 2;
		case '+':return 1;
		case '-':return 1;
		case '(':return -1;
		case ')':return -1;
		default: return 0;
	}
}
char * infix_postfix(char *infix)
/*
infix
a + b - c * d / e ^ f
0 1 2 3 4 5 6 7 8 9 0
                     i
postfix
a b + c d * e f ^ / - 
                    j
*/
{
	int i,n,top=-1,j=0;//n=11  
	n=strlen(infix);
	char st[n],op;
	
	static char postfix[100];
	for(i=0;i<n;i++)//11<11
	{
		if(pred(infix[i]))//if(0)
		{
			if(top==-1)
			{
				st[++top]=infix[i];//+
			}
			else if(infix[i]=='(')
			{
				st[++top]=infix[i];//+
			}
			else if(infix[i]==')')// (     op='('
			{
				op=st[top--];
				while(op!='(')
				{
					postfix[j++]=op;
					op=st[top--];
				}
			}
			else if(pred(infix[i])>pred(st[top]))//3>2
			{
				st[++top]=infix[i];//^	
			}
			else
			{
				while(top!=-1 && pred(infix[i])<=pred(st[top]))
				{
					//0!=-1 && 2<=1
					op=st[top--];//op=*
					postfix[j++]=op;//
				}
				st[++top]=infix[i];//
			}
		}
		else
		{
			//..operend
			postfix[j++]=infix[i];//f
			
		}
	}
	for(i=top;i>=0;i--)
	{
		postfix[j++]=st[i];
	}
	return postfix;
}
int main()
{
	char infix[100],*postfix;
	scanf("%[^\n]s",&infix);//a+b-c*d/e^f
	postfix=infix_postfix(infix);//
	printf("%s",postfix);
	return 0;
}



/*

a*(b-c*d)+(e*f)

(a+b-c*d)*(e-f^g)+h/i

a.  ab+cd* -efg^-*hi/+
b. 












*/
