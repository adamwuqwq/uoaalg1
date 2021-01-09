#include <stdio.h>
#define N 2001
int n,q,A[N],M;
int solve(int,int);
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&A[i]);
	int q;
	scanf("%d",&q);
	for(int i=0;i<q;i++){
		scanf("%d",&M);
		if(solve(0,M)) printf("yes\n");
		else printf("no\n");
	}
	return 0;
}
int solve(int p,int t)
{
	if(t==0) return 1;
	else if(p==n) return 0;
	if(solve(p+1,t-A[p])) return 1;
	if(solve(p+1,t)) return 1;
	return 0;
}