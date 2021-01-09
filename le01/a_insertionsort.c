#include <stdio.h>
#define N 101
int main()
{
	int A[N],n,i,j,key,out;
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%d",&A[i]);
	for(out=0;out<n;out++){
		if(out==n-1) printf("%d\n",A[out]);
		else printf("%d ",A[out]);
	}
	for(i=1;i<n;i++){
		key=A[i];
		/*insert A[i] into the sorted sequence A[0,...,j-1]*/
		j=i-1;
		while(j>=0 && A[j]>key){
			A[j+1]=A[j];
			j--;
		}
		A[j+1]=key;
		for(out=0;out<n;out++){
			if(out==n-1) printf("%d\n",A[out]);
			else printf("%d ",A[out]);
		}
	}
	return 0;
}