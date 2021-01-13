#include <stdio.h>
#include <string.h>
#define N 2000001
#define NIL -1
#define INF (2e9+1)
int parent(int);
int left(int);
int right(int);
int heapExtractMax();
void swap(int*,int*);
void maxHeapify(int);
void buildMaxHeap();
void MaxHeapInsert(int);
void heapIncreaseKey(int,int);
int A[N],H=0;
int main()
{
	char inst[8];
	int num;
	while(1){
		scanf("%s",inst);
		if(!strcmp(inst,"insert")){
			scanf("%d",&num);
			MaxHeapInsert(num);
		}
		else if(!strcmp(inst,"extract")){
			printf("%d\n",heapExtractMax());
		}
		else if(!strcmp(inst,"end")) break;
		else printf("invalid input!\n");
	}
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
int heapExtractMax()
{
	if(H<1){
		printf("heap underflow!\n");
		return -INF;
	}
	else{
		int max=A[1];
		A[1]=A[H];
		H--;
		maxHeapify(1);
		return max;
	}
}
void MaxHeapInsert(int key)
{
	H++;
	A[H]=-INF;
	heapIncreaseKey(H,key);
}
void heapIncreaseKey(int i,int key)
{
	if(key<A[i]) printf("new key is smaller than current key!\n");
	else{
		A[i]=key;
		while(i>1 && A[parent(i)]<A[i]){
			swap(&A[parent(i)],&A[i]);
			i=parent(i);
		}
	}
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
