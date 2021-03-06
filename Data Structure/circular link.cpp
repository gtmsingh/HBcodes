#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}n;

n *start=NULL,*temp,*temp2,*current,*rear;
int flag;

int display()
{
	current=start;
	while(current!=rear)
	{
		printf("%d ",current->data);
		current=current->next;
	}
	printf("%d ",current->data);
	printf("\n");
	return 0;
}

int insert()
{
	int flag2;
	do
	{
		display();
		temp=(n*)malloc(sizeof(n));
		printf("Enter the no. to be inserted:");
		scanf("%d",&temp->data);
		printf("Enter beside which it is to be inserted:");
		scanf("%d",&flag);
		printf("Insert %d\n1-Before %d\n2-After %d\n",temp->data,flag,flag);
		scanf("%d",&flag2);
		current=start;
		switch(flag2)
		{
			case 1:
				while(current->data!=flag && current!=rear)
				{
					temp2=current;
					current=current->next;
				}
				if(current->data!=flag)
				    printf("You have given wrong test element\n");
				else if(current==start)
				{
					temp->next=start;
					start=temp;
					rear->next=start;
				}
				else
				{
					temp2->next=temp;
					temp->next=current;
				}
				break;
				
			case 2:
                while(current->data!=flag && current!=rear)
					current=current->next;
				if(current->data!=flag)
				    printf("You have given wrong test element\n");
				else if(current==rear)
				{
					temp->next=start;
					rear=temp;
				}
				else
				{
					temp->next=current->next;
					current->next=temp;
				}
				break;
				
			default:
				printf("You have given a wrong choice\n");
		}
		printf("Enter any no. to continue creation else enter 0:");
		scanf("%d",&flag);
	}while(flag);
}

int del()
{
	do
	{
		display();
		current=start;
		printf("Enter the no. to be deleted:");
		scanf("%d",&flag);
		while(current!=rear && current->data!=flag)
		{
			temp=current;
            current=current->next;
		}
		if(current->data!=flag)
		    printf("The element to be deleted is not preset in the list");
		else
		{
			if(current==start)
			{
				start=current->next;
				rear->next=start;
			}
			else if(current==rear)
			{
				temp->next=current->next;
				rear=temp;
			}
			else
				temp->next=current->next;
		}
  		printf("Enter any no. to continue deletion else enter 0:");
		scanf("%d",&flag);
	}while(flag);
	return 0;
}
int main()
{
	do
	{
		temp=(n*)malloc(sizeof(n));
		printf("Enter the element:");
		scanf("%d",&temp->data);
		temp->next=start;
		if(start==NULL)
			start=temp;
		else
		    rear->next=temp;
		rear=temp;
		printf("Enter any no. to continue creation else enter 0:");
		scanf("%d",&flag);
	}while(flag);
	printf("You have succefully created a lisked list as follows\n");
	display();
	printf("Enter choice for your desired operation:\n1:Insert\n2:Delete\n3:Display\n\n");
	scanf("%d",&flag);
	do
	{
		switch(flag)
		{
			case 1:
				insert();
				break;

			case 2:
				del();
				break;

			case 3:
				printf("Current linklist contains:\n");
				display();
				break;
				
	   		default:
				printf("You have enetered wrong choice\n");
	   	}
	printf("Enter choice for your desired operation:\n1:Insert\n2:Delete\n3:Display\n0:End\n\n");
   	scanf("%d",&flag);
	}
	while(flag);
   	return 0;
}
