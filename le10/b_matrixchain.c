#include <stdio.h> 
#define N 101
#define INF 2e9
int m[N][N],p[N];
int min(int,int);
void matrixchainorder(int);
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d%d",&p[i],&p[i+1]);
	matrixchainorder(n);
	printf("%d\n",m[1][n]);
}
int min(int x,int y)
{
	return x<y?x:y;
}
void matrixchainorder(int n)
{
	//initialization
	for(int i=1;i<=n;i++) m[i][i]=0;
	//DP
	for(int l=2;l<=n;l++){ //current length (range of i-j)
		for(int i=1;i<=n-l+1;i++){ 
			int j=i+l-1;
			m[i][j]=INF; //set dafault value to INFINITY
			for(int k=i;k<j;k++){
				int q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
				m[i][j]=min(m[i][j],q);
			}
		}
	}
}