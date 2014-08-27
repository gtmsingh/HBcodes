#include<stdio.h>
#include<math.h>

int siv[78600]={0},a[1000100];

int seive(int n)
{
    int j,i;

    for(j=2;j<n;j++)
        a[j]=0;

    for(j=2;j<=sqrt(n);)
    {
        i=2;
        while(i*j<n)
        {
            a[i*j]=1;
            i++;
        }
        j++;
        while(a[j]==1 && j<=sqrt(n))
            j++;
    }
    for(j=2,i=0;j<n;j++)
    {
        if(a[j]==0)
        {
            siv[i]=j;
            i++;
        }
    }
    return i;
}

int main()
{
    long long int n,i;
    scanf("%lld",&n);

    n=seive(n);
    printf("%lld\n",n);

    for(i=0;i<n;i++)
        printf("%d ",siv[i]);
    return 0;
}
