#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define MAX9 1000000007
#define MAX6 1000005
#define MAX5 100005

#define sin(x) scanf("%d",&x)
#define sll(x) scanf("%lld",&x)
#define sst(x) scanf("%s",x)

#define pin(x) printf("%d",x)
#define pll(x) printf("%lld",x)
#define pst(x) printf("%s",x)
#define nl() printf("\n")
#define psp() printf(" ")

#define fon(x,n) for(x=0;x<n;x++)

struct node
{
	int a;
};
typedef struct node nd;

nd arr[100005],temp[100005],lazy[100005];

int updateST(int qi,int qj,int i,int j,int x,int index)
{
	int mid=(i+j)/2;
	
	if(i>j || qi>j || qj<i) {
		return 0;
	}
	
	if(lazy[index].a != 0) {
		
		if(i<=qi && qj<=j)
			arr[index].a += lazy[index].a*(qj-qi+1);
		else if(qi<i && qj>j)
			arr[index].a += lazy[index].a*(j-i+1);
		else if(qj>j)
			arr[index].a += lazy[index].a*(j-qi+1);
		else if(qi<i)
			arr[index].a += lazy[index].a*(qj-i+1);
		else
			printf("err update\n");
			
		if(i!=j) {
			lazy[2*index+1].a += lazy[index].a;
			lazy[2*index+2].a += lazy[index].a;
		}
		lazy[index].a=0;
	}
	
	if(i<=qi && qj<=j)
	{
		arr[index].a += x*(qj-qi+1);
		
		if(i!=j)
		{
			lazy[2*index+1].a += x;
			lazy[2*index+2].a += x;
		}
	}
	else {
		updateST(qi,qj,i,mid,x,2*index+1);
		updateST(qi,qj,mid+1,j,x,2*index+2);
		
		arr[index].a = arr[index*2+1].a+arr[index*2+2].a;
	}
	return 0;
}

int getST(int qi,int qj,int i,int j,int index)
{
	int mid=(i+j)/2;
	
	if(i>j || qi>j || qj<i) {
		return 0;
	}
	
	if(lazy[index].a != 0) {
		if(i<=qi && qj<=j)
			arr[index].a += lazy[index].a*(qj-qi+1);
		else if(qi<i && qj>j)
			arr[index].a += lazy[index].a*(j-i+1);
		else if(qj>j)
			arr[index].a += lazy[index].a*(j-qi+1);
		else if(qi<i)
			arr[index].a += lazy[index].a*(qj-i+1);
		else
			printf("err update\n");
			
		if(i!=j) {
			lazy[2*index+1].a += lazy[index].a;
			lazy[2*index+2].a += lazy[index].a;
		}
		
		lazy[index].a=0;
	}
	if(i<=qi && qj<=j) {
		return arr[index].a;
	}
	else {
		return getST(qi,qj,i,mid,2*index+1)+getST(qi,qj,mid+1,j,2*index+2);
	}
}

int makeST(int i,int j,int index)
{
	int mid;
	
	if(i==j)
		arr[index].a=temp[i].a;
	else
	{
		mid=(i+j)/2;
		arr[index].a=makeST(i,mid,2*index+1)+makeST(mid+1,j,2*index+2);
	}
	return arr[index].a;
}

int main()
{
	int t,n,i,j,flag;
	sin(n);
	fon(i,n)
	{
		sin(temp[i].a);
	}
	makeST(0,n-1,0);
	while(1)
	{
		sin(i),sin(j),sin(flag);
		if(flag==0)
			pin(getST(i,j,0,n-1,0));
		else
			updateST(i,j,0,n-1,flag,0);
		
	}
	return 0;
}

