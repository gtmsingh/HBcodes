//Inplace Counting sort of positive numbers < 1000000

#include<stdio.h>

int arr[100],count[1000000];

void swap(int i,int j)
{
    int temp;
    temp=arr[j];
    arr[j]=arr[i];
    arr[i]=temp;
}

int main()
{
    int n,i,j,max=0;
    for(i=0;i<1000000;i++)
        count[i]=0;

    printf("Enter the number of elements : ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        if(max<arr[i])
            max=arr[i];

        count[arr[i]]++;
    }

    for(i=1;i<=max;i++)
        count[i]+=count[i-1];

    for(i=0,j=0;j<n;)
    {
        if(count[arr[i]]>i+1)
        {
            count[arr[i]]--;
            printf("%d %d\n",i,count[arr[i]]);
            swap(i,count[arr[i]]);
        }
        else
            i++;
        j++;
    }
    printf("Sorted list :\n");
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n");
    return 0;
}
