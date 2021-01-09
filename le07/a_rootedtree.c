#include <stdio.h>
#include <stdlib.h>
#define ROOT -1
#define N 100001
typedef struct{
	int k,depth;
	int parent;
	int *c;
}node;
node P[N];
void calcdepth(int,int);
int main()
{
	int n,pos,child;
	scanf("%d",&n);
	//initial process
	for(int i=0;i<n;i++) P[i].parent=ROOT;
	//input&insert
	for(int i=0;i<n;i++){
		scanf("%d%d",&pos,&child);
		P[pos].k=child;
		if(child!=0){
			P[pos].c=(int*)malloc(child*sizeof(int));
			for(int j=0;j<child;j++){
				scanf("%d",&P[pos].c[j]);
				P[P[pos].c[j]].parent=pos;
			}
		}
	}
	//calculate depth
	int cnt=0,rootpos;
	for(int i=0;i<n;i++){
		if(P[i].parent==ROOT){
			rootpos=i;
			break;
		}
	}
	calcdepth(rootpos,0);
	//output
	for(int i=0;i<n;i++){
		printf("node %d: parent = %d, depth = %d, ",i,P[i].parent,P[i].depth);
		if(P[i].k>0){
			if(P[i].parent==ROOT) printf("root, [");
			else if(P[i].k>0) printf("internal node, [");
			for(int j=0;j<P[i].k-1;j++) printf("%d, ",P[i].c[j]);
			printf("%d]\n",P[i].c[P[i].k-1]);
		}
		else if(P[i].parent!=ROOT) printf("leaf, []\n");
		else printf("root, []\n");
	}
	return 0;
}
void calcdepth(int currpos,int currdepth)
{
	P[currpos].depth=currdepth;
	if(P[currpos].k==0) return;
	for(int i=0;i<P[currpos].k;i++){
		calcdepth(P[currpos].c[i],currdepth+1);
	}
}
