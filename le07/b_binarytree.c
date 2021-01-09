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
int calc(int,int);
int max(int,int);
int main()
{
	int n,pos,lnode,rnode;
	scanf("%d",&n);
	//initial process
	for(int i=0;i<n;i++){
		P[i].parent=ROOT;
		P[i].degree=2;
		P[i].sibling=-1;
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
	//calculate depth&height
	int rootpos;
	for(int i=0;i<n;i++){
		if(P[i].parent==ROOT){
			rootpos=i;
			break;
		}
	}
	calc(rootpos,0);
	//output
	for(int i=0;i<n;i++){
		printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ",i,P[i].parent,P[i].sibling,P[i].degree,P[i].depth,P[i].height);
		if(P[i].degree>0){
			if(P[i].parent==ROOT) printf("root\n");
			else printf("internal node\n");
		}
		else if(P[i].parent!=ROOT) printf("leaf\n");
		else printf("root\n");
	}
	return 0;
}
int calc(int currpos,int currdepth)
{
	P[currpos].depth=currdepth;
	if(P[currpos].degree==0) return currdepth;
	int deepest=max(calc(P[currpos].left,currdepth+1),calc(P[currpos].right,currdepth+1));
	P[currpos].height=deepest-currdepth;
	return deepest;
}
int max(int a,int b)
{
	return a>b?a:b;
}
