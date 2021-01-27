#include <stdio.h>
#include <string.h>
#define N 101
int matrix[N][N];
int main()
{
	int n,edge,node,vertex;
	scanf("%d",&n);
	memset(matrix,0,sizeof(matrix));
	for(int i=0;i<n;i++){
		scanf("%d",&vertex); //current vertex's index 
		scanf("%d",&edge); //number of edges
		for(int j=0;j<edge;j++){
			scanf("%d",&node);//current node's index
			matrix[vertex][node]=1;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(j!=n) printf("%d ",matrix[i][j]);
			else printf("%d\n",matrix[i][j]);
		}
	}
	return 0;
}