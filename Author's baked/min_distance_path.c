/*
*/

#include<stdio.h>
#include<conio.h>

char a[100][100];
int count[100][100],qi[100005],qj[100005],hash[100][100];

int update(int i,int j,int k,int val)
{
//    printf("update %d %d %d %d\n",i,j,k,val);
    qi[k]=i;
    qj[k]=j;
    count[i][j]=val;
    hash[i][j]=0;
    return (k+1);
}

int main()
{
//    freopen("in.txt","r",stdin);
    int t,n,m,i,j,tempi,tempj,k,val;
    char x;
    scanf("%d",&t);
    while(t--)
    {
//        printf("Enter the no. of rows : ");
        scanf("%d",&n);
//        printf("Enter the no. of columns : ");
        scanf("%d,",&m);
        for(i=0;i<n;i++)
        {
            scanf("%s",a[i]);
            for(j=0;j<m;j++)
                count[i][j]=-1;
        }
        if(a[0][0]!='#')
        {
            qi[0]=qj[0]=hash[0][0]=0;
            count[0][0]=1;
            k=1;
            while(k!=0)
            {
                k--;
                tempi=qi[k];
                tempj=qj[k];
    //            printf("i=%d j=%d\n",i,j);
                if(hash[tempi][tempj]==0)
                {
                    hash[tempi][tempj]=1;

                    i=tempi+1; j=tempj; val=count[tempi][tempj]+1;

                    if(i<n && (count[i][j]==-1 || count[i][j]>val) && a[i][j]!='#')
                        k=update(i,j,k,val);

                    i=tempi-1;
                    if(i>=0 && (count[i][j]==-1 || count[i][j]>val) && a[i][j]!='#')
                        k=update(i,j,k,val);

                    i=tempi;
                    j=tempj-1;
                    if(j>=0 && (count[i][j]==-1 || count[i][j]>val) && a[i][j]!='#')
                        k=update(i,j,k,val);

                    j=tempj+1;
                    if(j<m && (count[i][j]==-1 || count[i][j]>val) && a[i][j]!='#')
                        k=update(i,j,k,val);
                }
            }
        }
        scanf("%d %d",&i,&j);
        while(i!=-1 && j!=-1)
        {
            if(count[i][j]!=-1)
                printf("count=%d\n",count[i][j]);
            else
                printf("This place cannot be reached\n");
            scanf("%d %d",&i,&j);
        }
    }
    return 0;
}
