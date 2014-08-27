/*This program prints the moving text in the terminal*/
#include<stdio.h>
#include<string.h>
#define MAX 40000000

int main()
{
    int i,j=0,n=70,k,m;
    char a[30],x=' ';
    printf("Enter the name you want to see in the banner : ");
    gets(a);
    printf("Enter the character to use : ");
    scanf("%c",&x);
    m=strlen(a);
    printf("\n\n\n\n");
    for(;1;)
    {
        if(j<=m)
        {
            for(i=m-j;i<m;i++)
                printf("%c",a[i]);
            k=j;
        }
        else
        {
            for(i=0;i<j-m;i++)
                printf("%c",x);
            if(j<=n)
                printf("%s",a);
            else
            {
                for(i=0;i<(m-j+n);i++)
                    printf("%c",a[i]);
            }
            k=j;
        }
        for(i=k;i<n;i++)
            printf("%c",x);

        for(i=0;i<MAX;i++);

        printf("\r");
        j=(j+1)%(n+m);
    }
    return 0;
}
