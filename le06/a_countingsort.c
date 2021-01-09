#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define k 10001
#define N 2000001
int *CountingSort(int*,int);
int main()
{
	int n,A[N];
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&A[i]);
	int *res=CountingSort(A,n);
	for(int i=1;i<n;i++) printf("%d ",res[i]);
	printf("%d\n",res[n]);
	return 0;
}
int *CountingSort(int* A,int n)
{
	int C[k];
	int *B=(int*)malloc(sizeof(int)*n);
	memset(C,0,sizeof(C));
	for(int i=0;i<n;i++) C[A[i]]++;
	for(int i=1;i<=k;i++) C[i]+=C[i-1];
	for(int i=n-1;i>=0;i--){
		B[C[A[i]]]=A[i];
		C[A[i]]--;
	}
	return B;
}