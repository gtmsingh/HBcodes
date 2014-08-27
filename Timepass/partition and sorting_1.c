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

int main()
{
   	int a[20],i,j,n,min;

	while(1)
	{
		min=0;
        printf("\nEnter the no. of elements : ");
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			if(min>a[i])                    // (1)
			    min=a[i];
		}
		min=min+min%2;                      // (2)
		printf("min=%d\n",min);
		for(i=0;i<n;i++)
		{
			a[i]=a[i]-min;        			// (3)
			if(a[i]%2==1)                   // (4)
			    a[i]=-a[i];
		}
		for(i=0;i<n-1;i++)                  // (5)
		{
            for(j=i+1;j<n;j++)
		        if(a[i]>a[j])
					swap(&a[i],&a[j]);
		}
		for(i=0;i<n;i++)
		{
            if(a[i]%2==-1)
				a[i]=-a[i];
			printf("%d ",a[i]+min);
		}
	}
	return 0;
}

/*Explanation :

(1) find out the min of all the inputs
(2) make that no. even so that it does not changes the nature of the original no. when added
(3) add min to all the nos. so that all nos. becomes positive
(4) make the odd nos. negetive
(5) sort in ascending order which will make the odd nos come in first part sorted descending(coz ascending of -ive=descending of +ive)
*/
