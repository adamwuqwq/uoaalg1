#include <stdio.h>
#include <string.h>
#define N 1001
int LCS(char*,char*);
int max(int,int);
int main()
{
	int n;
	char buff1[N],buff2[N];
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s",buff1);
		scanf("%s",buff2);
		printf("%d\n",LCS(buff1,buff2));
	}
	return 0;
}
int max(int a,int b)
{
	return a>b?a:b;
}
int LCS(char *ch1,char *ch2)
{
	int ch1_len=strlen(ch1),ch2_len=strlen(ch2);
	int C[N][N]; //LCS length of ch1[1..x],ch2[1..y]
	for(int i=0;i<=ch1_len;i++){ //ch1
		for(int j=0;j<=ch2_len;j++){ //ch2
			if(i==0 || j==0) C[i][j]=0;
			else if(ch1[i-1]==ch2[j-1]) C[i][j]=C[i-1][j-1]+1;
			else C[i][j]=max(C[i][j-1],C[i-1][j]);
		}
	}
	return C[ch1_len][ch2_len];
}