#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};
typedef struct node n;

n *start=NULL,*temp,*temp2,*current;
int flag;

int display()
{
	current=start;
	while(current!=NULL)
	{
		printf("%d ",current->data);
		current=current->next;
	}
	printf("\n");
	return 0;
}

int insert()
{
	int flag2;
	do
	{
		temp=(n*)malloc(sizeof(n));
		printf("\nCurrent linked list contains:\n");
		display();
		printf("Enter the element to be inserted:");
		scanf("%d",&temp->data);
		printf("Enter the element beside which it is to be inserted:");
		scanf("%d",&flag);
		printf("Insert %d\n1:Before %d\n2:After %d\n",temp->data,flag,flag);
		scanf("%d",&flag2);
		current=start;
		switch(flag2)
		{
			case 1:
				while(current->data!=flag && current!=NULL)
				{
					temp2=current;
					current=current->next;
				}
				if(current==NULL)
				    printf("You have entered wrong test element\n");
				else
				{
					if(current==start)
					{
						start=temp;
						temp->next=current;
					}
					else
					{
						temp2->next=temp;
						temp->next=current;
					}
				}
				break;

			case 2:
				while(current->data!=flag && current!=NULL)
					current=current->next;
				if(current==NULL)
				    printf("You have entered wrong test element");
				else
				{
					temp->next=current->next;
					current->next=temp;
				}
				break;

			default:
				printf("You have entered wrong choice of option given");
				break;
		}
		printf("Current linked list:\n");
		display();
		printf("Enter any number to continue insertion or else enter 0:");
		scanf("%d",&flag);
	}while(flag);
	return 0;
}

int del()
{
	do
	{
        printf("Current linked list contains:\n");
		display();
		current=start;
		printf("Enter the element to be deleted:");
		scanf("%d",&flag);
		while(current->data!=flag && current!=NULL)
		{
			temp=current;
			current=current->next;
		}
		if(current==NULL)
		    printf("No such element exists in the list\n");
		else if(current==start)
		{
			start=current->next;
			printf("Current linked list contains:\n");
 			display();
		}
		else
		{	temp->next=current->next;
            printf("Current linked list contains:\n");
			display();
		}
		printf("Enter any no. to continue deletion else enter 0:");
		scanf("%d",&flag);
	}while(flag);
	return 0;
}

int reverse()
{
	temp=start;
	current=temp->next;
	temp2=current->next;
	temp->next=NULL;
	while(current!=NULL)
	{
			current->next=temp;
			temp=current;
			current=temp2;
			if(temp2!=NULL)
				temp2=temp2->next;
	}
	start=temp;
	return 0;
}
int search()
{
 	do
 	{
		int count=0;
		printf("Enter the element to be searched:");
		scanf("%d",&flag);
		current=start;
		while(current->data!=flag && current!=NULL)
		{
			current=current->next;
			count++;
		}
		if(current!=NULL)
			printf("%d is present after %d elements from starting\n",flag,count);
		else
		    printf("%d is not present in the list",flag);
		printf("Enter any no. to continue searching else enter 0:");
		scanf("%d",&flag);
	}while(flag);
	return 0;
}
int main()
{
	do
	{
		temp=(n*)malloc(sizeof(n*));
		printf("Enter the element:");
		scanf("%d",&temp->data);
		temp->next=NULL;
		if(start==NULL)
			start=temp;
		else
		    current->next=temp;
		current=temp;
		printf("Enter any no. to continue creation else enter 0:");
		scanf("%d",&flag);
	}while(flag);
	printf("You have succefully created a lisked list as follows\n");
	display();
	printf("Enter choice for your desired operation:\n1:Insert\n2:Delete\n3:Display\n4:Reverse the list\n5:Search\n\n");
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

			case 4:
				reverse();
				display();
				break;

			case 5:
				search();
				break;

			case 0:
				break;

	   		default:
				printf("You have enetered wrong choice\n");
	//			printf("Enter choice for your desired operation:\n1:Insert\n2:Delete\n3:Display\n4:Reverse the list\n5:Search\n0:End\n\n");
		//		scanf("%d",&flag);
         		break;
	   	}
	printf("Enter choice for your desired operation:\n1:Insert\n2:Delete\n3:Display\n4:Reverse the list\n5:Search\n0:End\n\n");
   	scanf("%d",&flag);
	}
	while(flag);
   	return 0;
}
