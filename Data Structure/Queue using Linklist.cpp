#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node n;
n *start=NULL,*temp,*rear,*front;
bool isin()
{
	if(start==NULL)
	    return false;
	else
	    return true;
}

int enq()
{
	temp=(n*)malloc(sizeof(n));
	printf("Enter the element to be Enqueued:");
	scanf("%d",&temp->data);
	temp->next=NULL;
	if(start==NULL)
	    start=temp;
	else
	    rear->next=temp;
	rear=temp;
	front=start;
}

int deq()
{
	if(isin())
	{
		printf("\n<|%d|>\n",front->data);
		start=front->next;
		front=start;
	}
	else
	    printf("There is no element in the Queue to Dequeue\n");
	return 0;
}

int top()
{
	if(isin())
	    printf("\n<|%d|>\n",front->data);
	else
	    printf("There is no element in the Queue to Dequeue\n");
 	return 0;
}

int main()
{
    int flag;
	printf("Enter\n1:Enqueue any element\n2:Dequeue\n3:Top\n4:Check status\n\n");
	scanf("%d",&flag);
	do
	{
		switch(flag)
		{
			case 1:
				enq();
				break;

			case 2:
				deq();
				break;

			case 3:
				top();
				break;

			case 4:
				if(isin())
				    printf("The Queue is not empty\n");
				else
				    printf("The Queue is empty\n");
				break;

			default:
				printf("You have entered wrong choice\n");
				break;
		}
	printf("Enter\n1:Enqueue any element\n2:Dequeue\n3:Top\n4:Check status\n0:End\n\n");
	scanf("%d",&flag);
	}while(flag);
	return 0;
}
