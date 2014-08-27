/* Fibonacci series with high precision(using repitative spuaring) by the use of the following formula :
                                F(n)=   |1 1|^n
                                        |1 0|
*/

#include<stdio.h>
#define mod 1000000009
int count;

int* fib_sq(int r)
{
    int *temp,*mat;
    temp=(int*)malloc(sizeof(int)*4);
    count++;
    if(r==0)
    {
        temp[0]=temp[1]=temp[2]=1;
        temp[3]=0;

        return temp;
    }
    else if(r==1)
    {
        temp[0]=temp[1]=temp[2]=1;
        temp[3]=0;

        return temp;
    }
    else
    {
        mat=(int*)malloc(sizeof(int)*4);
        if(r%2==0)
        {
            temp=fib_sq(r/2);

            mat[0]=(temp[0]*temp[0]+temp[1]*temp[2])%mod;
            mat[1]=(temp[0]*temp[1]+temp[1]*temp[3])%mod;
            mat[2]=(temp[2]*temp[0]+temp[3]*temp[2])%mod;
            mat[3]=(temp[2]*temp[1]+temp[3]*temp[3])%mod;

            return mat;
        }
        else
        {
            temp=fib_sq((r-1)/2);

            mat[0]=(temp[0]*temp[0]+temp[1]*temp[2])%mod;
            mat[1]=(temp[0]*temp[1]+temp[1]*temp[3])%mod;
            mat[2]=(temp[2]*temp[0]+temp[3]*temp[2])%mod;
            mat[3]=(temp[2]*temp[1]+temp[3]*temp[3])%mod;

            temp[0]=mat[0];
            temp[1]=mat[1];
            temp[2]=mat[2];
            temp[3]=mat[3];

            mat[0]=temp[0]+temp[1];
            mat[1]=temp[0];
            mat[2]=temp[2]+temp[3];
            mat[3]=temp[2];

            return mat;
        }
    }

}

int main()
{
    int n,*fib;
    printf("Enter the value of n to find nth fibonacci : ");
    scanf("%d",&n);
    do
    {
        count=0;
        fib=fib_sq(n);
        printf("\nNo. of calls made: %d\nF(%d)=%d\n\n",count,n,fib[0]);
        printf("Enter the value of n to find nth fibonacci(-1 to exit) : ");
        scanf("%d",&n);
    }while(n!=-1);
    return 0;
}
