#include <stdio.h>
#define N 1000001
#define M 101
void insertionSort(int*,int,int);
void shellSort(int*,int);
int cnt;
int main()
{
	int A[N],n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%d",&A[i]);
	shellSort(A,n);
	for(i=0;i<n;i++) printf("%d\n",A[i]);
	return 0;
}
void insertionSort(int *A,int n,int g)
{
	int v,i,j;
	for(i=g;i<n;i++){
		v=A[i];
		j=i-g;
		while(j>=0 && A[j]>v){
			A[j+g]=A[j];
			j-=g;
			cnt++;
		}
		A[j+g]=v;
	}
}
void shellSort(int *A,int n)
{
	int G[M],m=0,x=1,i;
	cnt=0;
	for(i=0;x<=n;i++){
		G[i]=x;
		x=x*3+1;
		m++;
	}
	printf("%d\n",m);
	for(i=m-1;i>=0;i--){
		printf("%d ",G[i]);
		insertionSort(A,n,G[i]);
	}
	printf("\n%d\n",cnt);
}
