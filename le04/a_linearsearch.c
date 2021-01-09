#include <stdio.h>
#define N 10001
#define M 501
int linearsearch(int);
int S[N],T,n,q;
int main()
{
	int cnt=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&S[i]);
	scanf("%d",&q);
	for(int i=0;i<q;i++){
		scanf("%d",&T);
		if(linearsearch(T)) cnt++;
	}
	printf("%d\n",cnt);
	return 0;		
}
int linearsearch(int num)
{
	int cnt=0;
	for(int i=0;i<n;i++){
		if(S[i]==num) return 1;
	}
	return 0;
}