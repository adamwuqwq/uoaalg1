#include <stdio.h>
#define N 1000001
void swap(int*,int*);
int partition(int*,int,int);
int main()
{
	int n,cur;
	int A[N];
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&A[i]);
	cur=partition(A,0,n-1);
	for(int i=0;i<n-1;i++){
		if(i==cur) printf("[%d] ",A[i]);
		else printf("%d ",A[i]);
	}
	printf("%d\n",A[n-1]);
	return 0;
}
void swap(int*p1 ,int *p2)
{
	int tmp;
	tmp=*p1;
	*p1=*p2;
	*p2=tmp;
}
int partition(int *A,int p,int r)
{
	int x=A[r];
	int i=p-1;
	for(int j=p;j<r;j++){
		if(A[j]<=x){
			i++;
			swap(&A[i],&A[j]);
		}
	}
	swap(&A[i+1],&A[r]);
	return i+1;
}