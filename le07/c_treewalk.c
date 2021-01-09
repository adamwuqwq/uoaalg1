#include <stdio.h>
#include <stdlib.h>
#define NIL -1
#define ROOT -1
#define N 26
typedef struct{
	int depth,height,degree;
	int parent;
	int left,right;
	int sibling;
}node;
node P[N];
void preParse(int);
void inParse(int);
void postParse(int);
int main()
{
	int n,pos,lnode,rnode;
	scanf("%d",&n);
	//initial process
	for(int i=0;i<n;i++){
		P[i].parent=ROOT;
		P[i].degree=2;
		P[i].sibling=NIL;
	}
	//input&insert
	for(int i=0;i<n;i++){
		scanf("%d%d%d",&pos,&lnode,&rnode);
		P[pos].left=lnode,P[pos].right=rnode;
		if(lnode==NIL) P[pos].degree--;
		else P[lnode].parent=pos,P[lnode].sibling=rnode;
		if(rnode==NIL) P[pos].degree--;
		else P[rnode].parent=pos,P[rnode].sibling=lnode;
	}
	//find root&output
	int rootpos;
	for(int i=0;i<n;i++){
		if(P[i].parent==ROOT){
			rootpos=i;
			break;
		}
	}
	printf("Preorder\n");
	preParse(rootpos);
	printf("\nInorder\n");
	inParse(rootpos);
	printf("\nPostorder\n");
	postParse(rootpos);
	printf("\n");
	return 0;
}
void preParse(int u)
{
	if(u==NIL) return;
	printf(" %d",u);
	preParse(P[u].left);
	preParse(P[u].right);
}
void inParse(int u)
{
	if(u==NIL) return;
	inParse(P[u].left);
	printf(" %d",u);
	inParse(P[u].right);
}
void postParse(int u)
{
	if(u==NIL) return;
	postParse(P[u].left);
	postParse(P[u].right);
	printf(" %d",u);
}

