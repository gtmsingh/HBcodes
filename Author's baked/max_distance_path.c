/*
*/

#include<stdio.h>

char a[100][100];
int qi[100005],qj[100005],hash[100][100];

int update(int i,int j,int k)
{
    qi[k]=i;
    qj[k]=j;
    hash[i][j]=1;
    return (k+1);
}

int main()
{
    freopen("in.txt","r",stdin);
    int t,n,m,i,j,tempi,tempj,k,count;
    char x;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        scanf("%d,",&m);
        for(i=0;i<n;i++)
        {
            scanf("%s",a[i]);
            for(j=0;j<m;j++)
                hash[i][j]=-1;
        }
        if(a[0][0]!='#')
        {
            qi[0]=qj[0]=0;
            hash[0][0]=1;
            k=1;
            while(k!=0)
            {
                k--;
                tempi=qi[k];
                tempj=qj[k];

                i=tempi+1; j=tempj;

                if(i<n && a[i][j]!='#' && hash[i][j]!=1)
                    k=update(i,j,k);

                i=tempi-1;
                if(i>=0 && a[i][j]!='#' && hash[i][j]!=1)
                    k=update(i,j,k);

                i=tempi;
                j=tempj-1;
                if(j>=0 && a[i][j]!='#' && hash[i][j]!=1)
                    k=update(i,j,k);

                j=tempj+1;
                if(j<m && a[i][j]!='#' && hash[i][j]!=1)
                    k=update(i,j,k);

            }
        }
        count=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(hash[i][j]==-1)
                    count++;
            }
        }
        printf("%d\n",(n*m-count));
    }

}
