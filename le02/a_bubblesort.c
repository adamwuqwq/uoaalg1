#include <stdio.h>
#define N 101
int main()
{
	int A[N],n,i,j,tmp,cnt=0;
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%d",&A[i]);
	for(i=0;i<n;i++){
		for(j=n-1;j>i;j--){
			if(A[j]<A[j-1]){
				tmp=A[j]; //swap(a[j],a[j-1])
				A[j]=A[j-1];
				A[j-1]=tmp;
				cnt++;
			}
		}
	}
	for(i=0;i<n;i++){
		if(i==n-1) printf("%d\n",A[i]);
		else printf("%d ",A[i]);
	}
	printf("%d\n",cnt);
	return 0;
}