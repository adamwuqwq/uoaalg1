#include <stdio.h>
#define N 500001
#define NIL -1
int parent(int);
int left(int);
int right(int);
void maxHeapify(int);
void buildMaxHeap();
void swap(int*,int*);
int A[N],H;
int main()
{
	scanf("%d",&H);
	for(int i=1;i<=H;i++) scanf("%d",&A[i]);
	buildMaxHeap();
	for(int i=1;i<=H;i++) printf(" %d",A[i]);
	printf("\n");
	return 0;
}
int parent(int x)
{
	if(x==1) return NIL;
	else return x/2;
}
int left(int x)
{
	if(x*2>H) return NIL;
	else return x*2;
}
int right(int x)
{
	if(x*2+1>H) return NIL;
	else return x*2+1;
}
void swap(int *x,int *y)
{
	int tmp=*x;
	*x=*y;
	*y=tmp;
}
void maxHeapify(int i)
{
	int l,r,largest;
	l=left(i);
	r=right(i);
	if(l!=NIL && A[l]>A[i]) largest=l;
	else largest=i;
	if(r!=NIL && A[r]>A[largest]) largest=r;
	if(largest!=i){
		swap(&A[i],&A[largest]);
		maxHeapify(largest);
	}
}
void buildMaxHeap()
{
	for(int i=H/2;i>=1;i--) maxHeapify(i);
}
