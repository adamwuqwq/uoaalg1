#include <stdio.h>
#include <stdlib.h>
#define N 500001
#define SENTINEL 1e9+1
void Merge(int*,int,int,int);
void MergeSort(int*,int,int);
int comp=0;
int main()
{
	int S[N],n;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&S[i]);
	MergeSort(S,0,n);
	for(int i=0;i<n-1;i++) printf("%d ",S[i]);
	printf("%d\n%d\n",S[n-1],comp);
	return 0;
}
void Merge(int *A,int left,int mid,int right)
{
	int n1=mid-left,n2=right-mid;
	int *L=(int *)malloc((n1+1)*sizeof(int));
	int *R=(int *)malloc((n2+1)*sizeof(int));
	for(int i=0;i<n1;i++) L[i]=A[left+i];
	for(int i=0;i<n2;i++) R[i]=A[mid+i];
	L[n1]=SENTINEL;
	R[n2]=SENTINEL;
	int i=0,j=0;
	for(int k=left;k<right;k++){
		comp++;
		if(L[i]<=R[j]) A[k]=L[i++]; //<= -> maintain stability
		else A[k]=R[j++];
	}
	free(L);
	free(R);
}
void MergeSort(int *A,int left,int right)
{
	int mid=0;
	if(left+1<right){
		mid=(left+right)/2;
		MergeSort(A,left,mid);
		MergeSort(A,mid,right);
		Merge(A,left,mid,right);
	}
	else return;
}

