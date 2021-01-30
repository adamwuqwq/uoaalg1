//dfs using recursive function
#include <stdio.h>
#define N 101
typedef struct{
	int d,f; //d ->when vertex is first discovered, f ->when finished examining vertex's adjacency list
	int color; //status(WHITE,GRAY,BLACK)
	//0 ->hasn't been discovered; 1 ->has just been discovered; -1 ->finished
	int edge; //number of edge(s)
	int vertex[N]; //connected vertex(s) 
}node;
node graph[N];
void dfs(int);
void visit(int);
int main()
{
	int n,index;
	scanf("%d",&n); //vertex[1...n]
	for(int i=1;i<=n;i++){
		scanf("%d",&index); //current vertex's index number 
		scanf("%d",&graph[index].edge); //number of edge(s)
		for(int j=1;j<=graph[index].edge;j++) scanf("%d",&graph[index].vertex[j]);
	}
	dfs(n);
	//output result
	for(int i=1;i<=n;i++) printf("%d %d %d\n",i,graph[i].d,graph[i].f);
	return 0;
}
int time=0; //current time
void dfs(int n)
{
	//initialization
	for(int i=1;i<=n;i++) graph[i].color=0;
	//search
	for(int i=1;i<=n;i++){
		if(graph[i].color==0) visit(i);
	}
}
void visit(int u)
{
	graph[u].color=1; //set current vertex's color as "has just been discivered"
	graph[u].d=++time; //when vertex is first discovered
	for(int i=1;i<=graph[u].edge;i++){ //explorer each edge that connected to vertex u
		if(graph[graph[u].vertex[i]].color==0) visit(graph[u].vertex[i]);
	}
	graph[u].color=-1; //Blacken vertex u because the search was finished
	graph[u].f=++time;
}
