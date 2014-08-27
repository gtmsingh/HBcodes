#include<stdio.h>

int count;

long long int sq(int *n,int r)
{
    long long int temp;
    count++;
    if(r==0)
        return 1;
    else if(r%2==0)
    {
        temp=sq(n,r/2);
        return (temp*temp);
    }
    else
    {
        temp=sq(n,(r-1)/2);
        return (temp*temp*(*n));
    }
}

int main()
{
    int n,r;
    printf("Enter the number : ");
    scanf("%d",&n);
    do
    {
        count=0;
        printf("Enter the exponent : ");
        scanf("%d",&r);
        printf("\nNo. of funtion calls=%d\n%d^%d=%lld\n\n",count,n,r,sq(&n,r));
        printf("Enter the number(-1 to exit) : ");
        scanf("%d",&n);
    }while(n!=-1);
    return 0;
}
