#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node n;
n *start=NULL,*current=NULL,*temp,*temp2;
bool isin()
{
	if(start==NULL)
	    return false;
	else
	    return true;
}

int push()
{
	temp=(n*)malloc(sizeof(n));
	printf("Enter the element to be pushed:");
	scanf("%d",&temp->data);
	temp->next=NULL;
	if(start==NULL)
	    start=temp;
	else
	    current->next=temp;
	printf("%d had been succefully pushed in the stack\n");
	temp2=current;
	current=temp;
}

int pop()
{
	if(isin())
	{
        printf("\n<|%d|>\n",current->data);
		if(current==start)
			start=NULL;
		else
		    temp2->next=current->next;
	}
	else
	    printf("The Stack is empty\n");
	return 0;
}

int top()
{
	if(isin())
	    printf("\n<|%d|>\n",current->data);
	else
	    printf("The Stack is empty\n");
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
				if(isin())
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
