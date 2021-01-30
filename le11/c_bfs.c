//bfs using recursive function
#include <stdio.h>
#define N 101
#define INF 1e9
typedef struct{
	int dis; //distance from vertex 1
	int color; //status(WHITE,GRAY,BLACK)
	//0 ->hasn't been discovered; 1 ->has just been discovered; -1 ->finished
	int edge; //number of edge(s)
	int vertex[N]; //connected vertex(s) 
}node;
node graph[N];
void bfs(int,int);
void enqueue(int);
int dequeue();
int isEmpty();
int main()
{
	int n,index;
	scanf("%d",&n); //vertex[1...n]
	for(int i=1;i<=n;i++){
		scanf("%d",&index); //current vertex's index number 
		scanf("%d",&graph[index].edge); //number of edge(s)
		for(int j=1;j<=graph[index].edge;j++) scanf("%d",&graph[index].vertex[j]);
	}
	bfs(n,1);
	//output result
	for(int i=1;i<=n;i++) printf("%d %d\n",i,graph[i].dis);
	return 0;
}
//build queue Q to storage vertex ID
int Q[N];
int head=0,tail=0;
int isEmpty()
{
	return head==tail;
}
void enqueue(int x)
{
	Q[tail]=x;
	if(tail+1==N) tail=0;
	else tail++;
}
int dequeue()
{
	if(isEmpty()) return -1; //Queue underflow
	else{
		int tmp=Q[head];
		if(head+1==N) head=0;
		else head++;
		return tmp;
	}
}
void bfs(int n,int s) //vertex[1..n], start search from vertex s
{
	//initialization
	for(int i=1;i<=n;i++){
		graph[i].color=0;
		graph[i].dis=INF; 
	}
	//search from vertex s
	graph[s].dis=0;
	enqueue(s);
	while(!isEmpty()){ //do until all of the vertex have been searched
		int u=dequeue(); //current vertex
		for(int v=1;v<=graph[u].edge;v++){ //visit each vertex that connected to current vertex
			if(graph[graph[u].vertex[v]].color==0){ //if this vertex hasn't been visited
				graph[graph[u].vertex[v]].color==1; //set as "has just been discovered"
				graph[graph[u].vertex[v]].dis==graph[u].dis+1; //save distance
				enqueue(graph[u].vertex[v]); //enqueue this vertex
			}
		}
		graph[u].color=-1; //blacken vertex u because the search was finished
	}
}