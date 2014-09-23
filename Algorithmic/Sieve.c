#include<stdio.h>
#include<math.h>
#include<stdlib.h>


int sieve(int x , int *temp, int *prime) {
	int i, j, k=0;
	double sq = sqrt(x);
	for(i=2; i<=sq;) {
		prime[k++] = i;
		j=2;
		while(i*j <= x) {
			temp[i*j] = 1;
			j++;
		}
		i++;
		while(temp[i] == 1 && i<=sq) {
			i++;
		}
	}
	while(i<x) {
		if(temp[i] != 1)
			prime[k++] = i;
		i++;
	}
	return k;
}

int main()
{
    int n,i;
	scanf("%d",&n);
    int *temp=(int*)malloc(sizeof(int)*n+1), *prime = (int*)malloc(sizeof(int)*(n/2)+1);
	n=sieve(n, temp, prime);
    printf("Prime numbers:\n");
    for(i=0; i<n; i++)
        printf("%d ",prime[i]);
        
    printf("\nNumber of prime numbers: %d\n",n);
    return 0;
}
