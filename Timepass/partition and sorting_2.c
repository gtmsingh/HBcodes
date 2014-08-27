/*
Given an array, sort the array in such a way that the first part of the sorted array contains odd numbers, and the second part
contains even numbers. The first part has to be sorted in descending order and the second part in ascending order.
Not extra array, no pre or post processing and it has to use a conventional sorting mechanism.
*/

#include<stdio.h>

int swap(int *x,int *y)
{
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
	return 0;
}

int sort(int *arr,int len,int flag)
{
	printf("Sorting : flag=%d length=%d\n",flag,len);
	int i,j;
	if(flag==1)
	{
		for(i=0;i<len;i++)
		    for(j=i+1;j<=len;j++)
		    {
				if(arr[i]<arr[j])
				{
//					printf("1. %d %d\n",arr[i],arr[j]);
                    swap(&arr[i],&arr[j]);
//                    printf("2. %d %d\n",arr[i],arr[j]);
				}
		        	
			}
	}
	else
	{
        for(i=0;i<len;i++)
		    for(j=i+1;j<=len;j++)
		    {
				if(arr[i]>arr[j])
				{
//					printf("1. %d %d\n",arr[i],arr[j]);
                    swap(&arr[i],&arr[j]);
//                    printf("2. %d %d\n",arr[i],arr[j]);
				}
			}
	}
	return 0;
}


int main()
{
	int a[20],i,j,n;
	
	while(1)
	{
        printf("Enter the no. of elements : ");
		scanf("%d",&n);
		for(i=0;i<n;i++)
		    scanf("%d",&a[i]);

		i=0; j=n-1;
		while(i<j)
		{
			while(a[i]%2!=0 && i<j)
			    i++;
			while(a[j]%2==0 && i<j)
			    j--;

			swap(&a[i],&a[j]);
			
			i++;
			j--;
		}           					// j denotes the end of odd nos.

	 	for(i=0;i<n;i++)
		    printf("%d ",a[i]);
		printf("\n");
		
		sort(a,j,1);
		sort(&a[j+1],n-j-2,0);

		for(i=0;i<n;i++)
		    printf("%d ",a[i]);
	}
	
	return 0;
}
