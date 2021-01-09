#include <stdio.h>
#define N 100001
typedef struct{
	int val;
	char id;
	int pos;
}data;
void swap(data*,data*);
int partition(data*,int,int);
void quicksort(data*,int,int);
int main()
{
	int n,cur,flag=0;
	data A[N];
	scanf(" %d ",&n);
	for(int i=0;i<n;i++){
		scanf(" %c %d",&A[i].id,&A[i].val);
		A[i].pos=i;
	}
	quicksort(A,0,n-1);
	for(int i=1;i<n;i++){
		if(A[i-1].val==A[i].val && A[i-1].pos>A[i].pos){
			flag=1;
			break;
		}
	}
	if(flag) printf("Not stable\n");
	else printf("Stable\n");
	for(int i=0;i<n;i++) printf("%c %d\n",A[i].id,A[i].val);
	return 0;
}
void swap(data *p1 ,data *p2)
{
	data tmp;
	tmp=*p1;
	*p1=*p2;
	*p2=tmp;
}
int partition(data *A,int p,int r)
{
	int x=A[r].val;
	int i=p-1;
	for(int j=p;j<r;j++){
		if(A[j].val<=x){
			i++;
			swap(&A[i],&A[j]);
		}
	}
	swap(&A[i+1],&A[r]);
	return i+1;
}
void quicksort(data *A,int p,int r)
{
	if(p<r){
		int cur=partition(A,p,r);
		quicksort(A,p,cur-1);
		quicksort(A,cur+1,r);
	}
	else return;
}
