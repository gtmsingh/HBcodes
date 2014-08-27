#include<stdio.h>
#include<conio.h>
int a[10],front=0,rear=0,count=0;

bool isfull()
{
	if(count==1 && front==rear)
	    return true;
	else
	    return false;
}

bool isin()
{
	if(count==0 && front==rear)
	    return false;
	else
	    return true;
}

int display(int f,int r)
{
	if(isin())
	{
		if(isfull())
			r--;
		while(f!=r)
		{
			printf("%d ",a[f]);
			f=(f++)%10;
		}
		printf("\n");
	}
	else
	    printf("There is no element present to be printed");
	return 0;
}
int enq()
{
	if(isfull())
	    printf("The Queue is full\n");
	else
	{
        printf("Enter the element:");
		scanf("%d",&a[rear]);
		rear=(rear+1)%10;
		count=1;
	}
	return 0;
}

int deq()
{
	if(isin())
	{
		printf("<|%d|>",a[front]);
		front=(front+1)%10;
		count=0;
	}
	else
	    printf("There is no element present in the Queue\n");
	return 0;
}

int top()
{
	if(isin())
	    printf("<|%d|>",a[front]);
	else
	    printf("The Queue is empty");
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
				if(isin() && isfull())
				    printf("The Queue is full\n");
				else if(isin())
				    printf("The Queue is not empty\n");
				else
				    printf("The Queue is empty\n");
				break;

			case 5:
				display(front,rear);
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
