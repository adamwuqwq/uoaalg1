//Single Source Shortest Path (Dijkstra) normal version
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
void dijkstra(int,int);
int main()
{
	int n,curr_vertex,edge_num;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%d",&curr_vertex,&edge_num);
		graph[curr_vertex].edge=edge_num;
		for(int j=0;j<edge_num;j++){
			scanf("%d%d",&graph[curr_vertex].vertex[j].id,&graph[curr_vertex].vertex[j].weight);
		}
	}
	dijkstra(n,0);
	int total=0;
	for(int i=0;i<n;i++) printf("%d %d\n",i,graph[i].dis);
	return 0;
}
void dijkstra(int n,int r)
{
	//initialization 
	for(int i=0;i<n;i++){
		graph[i].dis=INF;
		graph[i].color=0;
		graph[i].pi=NIL;
	}
	graph[r].dis=0; //start from vertex r
	while(1)
	{
		int mincost=INF,u;
		for(int i=0;i<n;i++){
			//find the smallest weight
			if(!graph[i].color && graph[i].dis<mincost){
				mincost=graph[i].dis;
				u=i;
			}
		}
		if(mincost==INF) break; //if all of the vertex have been visited, exit
		graph[u].color=1; //blacken vertex u
		for(int i=0;i<graph[u].edge;i++){ //each vertex connected to vertex u
			//relax[u..v]
			if(!graph[graph[u].vertex[i].id].color && graph[u].dis+graph[u].vertex[i].weight<graph[graph[u].vertex[i].id].dis){
				graph[graph[u].vertex[i].id].pi=u;
				graph[graph[u].vertex[i].id].dis=graph[u].dis+graph[u].vertex[i].weight;
			}
		}
	}
}
