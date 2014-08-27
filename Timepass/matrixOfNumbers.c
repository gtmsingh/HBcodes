/*Prints the matrix of numbers in row major form with borders*/
#include<stdio.h>

int main()
{
    int n,i,j;
    scanf("%d",&n);
    for(j=0;j<2*n;j++)
    {
        if(j%2==0)
            printf(" ");
        else
            printf("____");
    }printf("\n");
    for(i=0 ; i<n ; i++)
    {
        for(j=0;j<2*n;j++)
        {
            if(j%2==0)
                printf("|");
            else
                printf("    ");
        }printf("|\n");
        for(j=0;j<2*n;j++)
        {
            if(j%2==0)
                printf("|");
            else
            {
                if((n*i+j/2)<10)
                    printf(" %d  ",(n*i+j/2));
                else if((n*i+j/2)<100)
                    printf(" %d ",(n*i+j/2));
                else
                    printf(" %d",(n*i+j/2));
            }

        }printf("|\n");
        for(j=0;j<2*n;j++)
        {
            if(j%2==0)
                printf("|");
            else
                printf("____");
        }printf("|\n");
    }
    return 0;
}
