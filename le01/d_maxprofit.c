#include <stdio.h>
#define N 200001
#define MAX -1000000001
int main()
{
	int A[N],n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%d",&A[i]);
	int minv=A[0],maxv=MAX;
	for(i=1;i<n;i++){
		maxv=A[i]-minv>maxv?A[i]-minv:maxv;
		minv=A[i]<minv?A[i]:minv;
	}
	printf("%d\n",maxv);
	return 0;
}