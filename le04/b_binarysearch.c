#include <stdio.h>
#define N 100000
int binarysearch(int);
int S[N],T,n,q;
int main()
{
	int cnt=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&S[i]);
	scanf("%d",&q);
	for(int i=0;i<q;i++){
		scanf("%d",&T);
		if(binarysearch(T)) cnt++;
	}
	printf("%d\n",cnt);
	return 0;		
}
int binarysearch(int num)
{
	int left=0,right=n,mid;
	while(left<right){
		mid=(left+right)/2;
		if(S[mid]==num) return 1;
		else if(S[mid]<num) left=mid+1;
		else right=mid;
	}
	return 0;
}
