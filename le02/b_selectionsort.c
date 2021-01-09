#include <stdio.h>
#define N 101
int main()
{
	int i,j,n,A[N],tmp,mini,cnt=0;
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%d",&A[i]);
	for(i=0;i<n;i++){
		mini=i;
		for(j=i;j<n;j++)
			if(A[j]<A[mini]) mini=j;
		if(mini!=i){
			tmp=A[i];
			A[i]=A[mini];
			A[mini]=tmp;
			cnt++;
		}
	}
	for(i=0;i<n;i++){
		if(i==n-1) printf("%d\n",A[i]);
		else printf("%d ",A[i]);
	}
	printf("%d\n",cnt);
	return 0;
}