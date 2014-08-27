/* WAP to find whether the two array of elements of same size are permutations of each other
*/

#include<stdio.h>

int main()
{
	int a[10],b[10],i,n,x;
	while(1)
	{
        scanf("%d",&n);
		x=i=0;
		while(i<n)
		{
			scanf("%d",&a[i]);
			i++;
		}
		i--;
		while(i>=0)
		{
            scanf("%d",&b[i]);
			i--;
		}
		//Uncomment below code and comment the block X for xor method
/*		x=a[0]^b[0];                    //By XOR operation
		for(i=1;i<n;i++)
		{
			x=x^a[i]^b[i];
		}
*/
		//BLOCK X
		for(i=0;i<n;i++)                //By subtraction
		{
			//printf("x=%d a[%d]=%d b[%d]=%d\n",x,i,a[i],i,b[i]);
			x=x+a[i]-b[i];
		}
		if(x==0)
			printf("YES\n");
		else
		    printf("NO\n");
	}
}
