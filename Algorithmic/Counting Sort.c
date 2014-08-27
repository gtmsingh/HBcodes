//Normal Counting sort of positive numbers <1000000

#include<stdio.h>

int arr[100],b[100],count[1000000];

int main()
{
    int n,i,j,max=0,k;
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

    for(i=0;i<n;i++)
    {
        b[count[arr[i]]-1]=arr[i];
        count[arr[i]]--;
    }
    printf("Sorted list :\n");
    for(i=0;i<n;i++)
        printf("%d ",b[i]);
    printf("\n");
    return 0;
}
