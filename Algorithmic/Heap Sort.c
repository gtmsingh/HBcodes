#include<stdio.h>

int swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
    return 0;
}

int max_heapify(int *arr,int n,int i)
{
    int j;
    while(i!=-1)
    {
        if(arr[2*i+1]>=arr[2*i+2] || (2*i+2)>=n)
            j=1;
        else
            j=2;

        if(arr[2*i+j]>arr[i] && (2*i+j)<n)
        {
            swap(&arr[2*i+j],&arr[i]);
            i=2*i+j;
        }
        else
            i=-1;
    }
}

int max_heap(int *arr,int n)
{
    int i,j;
    for(i=n/2;i>=0;i--)
    {
        if(arr[2*i+1]>=arr[2*i+2] || (2*i+2)>=n)
            j=1;
        else
            j=2;

        if(arr[2*i+j]>arr[i] && (2*i+j)<n)
        {
            swap(&arr[2*i+j],&arr[i]);
            max_heapify(arr,n,2*i+j);
        }
    }
    return 0;
}

int min_heapify(int *arr,int n,int i)
{
    int j;
    while(i!=-1)
    {
        if(arr[2*i+1]<=arr[2*i+2] || (2*i+2)>=n)
            j=1;
        else
            j=2;

        if(arr[2*i+j]<arr[i] && (2*i+j)<n)
        {
            swap(&arr[2*i+j],&arr[i]);
            i=2*i+j;
        }
        else
            i=-1;
    }
}

int min_heap(int *arr,int n)
{
    int i,j;
    for(i=n/2;i>=0;i--)
    {
        if(arr[2*i+1]<=arr[2*i+2] || (2*i+2)>=n)
            j=1;
        else
            j=2;

        if(arr[2*i+j]<arr[i] && (2*i+j)<n)
        {
            swap(&arr[2*i+j],&arr[i]);
            min_heapify(arr,n,2*i+j);
        }
    }
    return 0;
}

int main()
{
    int n,arr[100],i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);

    printf("Max Heap :\n");
    max_heap(arr,n);

    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n");

    j=n-1;
    while(j>0)
    {
        swap(&arr[0],&arr[j]);
        max_heapify(arr,j,0);
        j--;
    }

    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n");

    printf("Min Heap :\n");
    min_heap(arr,n);

    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n");

    j=n-1;
    while(j>0)
    {
        swap(&arr[0],&arr[j]);
        min_heapify(arr,j,0);
        j--;
    }

    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n");
    return 0;
}
