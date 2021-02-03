#include <stdio.h>
#define N 101
#define NIL -1
#define INF 1e9
typedef struct{
	int id,weight; //connected vertex's id and weight of the edge
}adj;
typedef struct{
	int dis; //smallest weight from other undiscovered vertex
	int color; //status(WHITE,BLACK)
	//0 ->hasn't been discovered; 1 ->finished
	int pi;
	int edge; //number of edge(s)
	adj vertex[N]; //connected vertex(s) 
}node;
node graph[N];
void prim(int,int);
int main()
{
	int n,matrix;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int curr_edge=0; //current edge number(s)
		for(int j=1;j<=n;j++){
			scanf("%d",&matrix); //input adjacency matrix
			if(matrix!=NIL){//NIL=> no connection between vertex i and j
				graph[i].vertex[++curr_edge].id=j;
				graph[i].vertex[curr_edge].weight=matrix;
			}
		}
		graph[i].edge=curr_edge; //save the number of connected edge(s) for current vertex
	}
	prim(n,1);
	int total=0;
	for(int i=1;i<=n;i++) total+=graph[i].dis;
	printf("%d\n",total);
	return 0;
}
void prim(int n,int r)
{
	//initialization 
	for(int i=1;i<=n;i++){
		graph[i].dis=INF;
		graph[i].color=0;
		graph[i].pi=NIL;
	}
	graph[r].dis=0; //start from vertex r
	while(1)
	{
		int mincost=INF,u;
		for(int i=1;i<=n;i++){
			//find the smallest weight
			if(!graph[i].color && graph[i].dis<mincost){
				mincost=graph[i].dis;
				u=i;
			}
		}
		if(mincost==INF) break; //if all of the vertex have been visited, exit
		graph[u].color=1; //blacken vertex u
		for(int i=1;i<=graph[u].edge;i++){ //each vertex connected to vertex u
			//printf("%d %d %d\n",u,graph[u].vertex[i].id,graph[u].vertex[i].weight);
			if(!graph[graph[u].vertex[i].id].color && graph[u].vertex[i].weight<graph[graph[u].vertex[i].id].dis){
				graph[graph[u].vertex[i].id].pi=u;
				graph[graph[u].vertex[i].id].dis=graph[u].vertex[i].weight;
			}
		}
	}
}
