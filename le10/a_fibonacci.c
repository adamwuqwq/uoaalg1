#include <stdio.h>
#define N 45
int fibnum[N]={1,1};
int fib(int);
int main()
{
	int n;
	scanf("%d",&n);
	printf("%d\n",fib(n));
	return 0;
}
int fib(int n)
{
	for(int i=2;i<=n;i++) fibnum[i]=fibnum[i-1]+fibnum[i-2];
	return fibnum[n];
}