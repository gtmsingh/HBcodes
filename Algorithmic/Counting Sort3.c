//Counting sort of numbers (-1000000,1000000)

#include<stdio.h>

int cp[1000000],cn[1000000];

int main()
{
    freopen("in.txt","r",stdin);
    int a[100],b[100],i,maxp,maxn,n;
    for(i=0;i<1000000;i++)
        cp[i]=cn[i]=0;

    printf("Enter the no. of elements : ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]>0)
        {
            cp[a[i]]++;
            if(maxp<a[i])
                maxp=a[i];
        }
        else
        {
            cn[-a[i]]++;
            if(maxn>a[i])
                maxn=a[i];
        }
    }
    maxn=-maxn;
    for(i=maxn-1;i>=0;i--)
        cn[i]+=cn[i+1];

    for(i=1;i<=maxp;i++)
        cp[i]+=cp[i-1];

    for(i=0;i<n;i++)
    {
        if(a[i]>0)
        {
            b[cp[a[i]]+cn[0]-1]=a[i];
            cp[a[i]]--;
        }
        else
        {
            b[cn[-a[i]]-1]=a[i];
            cn[-a[i]]--;
        }
    }
    printf("Sorted list : \n");
    for(i=0;i<n;i++)
        printf("%d ",b[i]);
    printf("\n");
    return 0;
}
