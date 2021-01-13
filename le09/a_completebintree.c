#include <stdio.h>
#define N 251
void parent(int);
void left(int);
void right(int);
int A[N],H;
int main()
{
	scanf("%d",&H);
	for(int i=1;i<=H;i++) scanf("%d",&A[i]);
	for(int i=1;i<=H;i++){
		printf("node %d: key = %d, ",i,A[i]);
		parent(i);
		left(i);
		right(i);
		printf("\n");
	}
	return 0;
}
void parent(int x)
{
	if(x==1) return;
	else printf("parent key = %d, ",A[x/2]);
}
void left(int x)
{
	if(x*2>H) return;
	else printf("left key = %d, ",A[x*2]);
}
void right(int x)
{
	if(x*2+1>H) return;
	else printf("right key = %d, ",A[x*2+1]);
}
