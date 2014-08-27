#include<stdio.h>
#include<conio.h>

int a[10],t=-1;

bool isin()
{
	if(t==-1)
	    return false;
	else
	    return true;
}

bool isfull()
{
	if(t==9)
		return true;
	else
	    return false;
}

int top()
{
	if(isin())
		printf("\n<|%d|>\n",a[t]);
	else
	    printf("The stack is empty\n");
	return 0;
}

int push()
{
	if(isfull())
	    printf("The stack is full and you cannot push any more element\n");
	else
	{
		t++;
		printf("Enter the element to be pushed:");
		scanf("%d",&a[t]);
		printf("%d had been succesfully pushed in the stack\n",a[t]);
	}
}

int pop()
{
	if(isin())
	{
		printf("\n<|%d|>\n",a[t]);
		t--;
	}
	else
	    printf("There is no element left to pop\n");
	return 0;
}

int main()
{
	int flag;
	printf("Enter\n1:Push any element\n2:Pop\n3:Top\n4:Check status\n\n");
	scanf("%d",&flag);
	do
	{
		switch(flag)
		{
			case 1:
				push();
				break;

			case 2:
				pop();
				break;

			case 3:
				top();
				break;

			case 4:
				if(isin() && isfull())
				    printf("The Stack is full\n");
				else if(isin())
				    printf("The Stack is not empty\n");
				else
				    printf("The stack is empty\n");
				break;
				
			default:
				printf("You have entered wrong choice\n");
				break;
		}
	printf("Enter\n1:Push any element\n2:Pop\n3:Top\n4:Check status\n0:End\n\n");
	scanf("%d",&flag);
	}while(flag);
	return 0;
}
