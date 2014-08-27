#include<stdio.h>

int arr[100005],temp[100005];

int merge(int *a,int size,int counter)
{
	int i=0,k=0,j=size;
	while(i<size && j<counter)
	{
		if(a[i]<=a[j])
		{
			temp[k]=*(a+i);
			i++;
		}
		else
		{
			temp[k]=*(a+j);
			j++;
		}
		k++;
	}
	while(i<size)
	{
		temp[k]=*(a+i);
		i++;
		k++;
	}
	while(j<counter)
	{
		temp[k]=*(a+j);
		j++; k++;
	}
	for(i=0;i<counter;i++)
		a[i]=temp[i];
	return 0;
}

int main()
{
    int n,i,j,t;
    scanf("%d",&n);
    i=0;
    while(i<n)
    {
        scanf("%d",&arr[i]);
        i++;
    }
    for(i=1;i<n;i=2*i)
    {
        for(j=0;j<n-i;j=j+2*i)
        {
            if((n-j)>2*i)
                merge(&arr[j],i,2*i);
            else
                merge(&arr[j],i,(n-j));
        }
    }
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n");
    return 0;
}

