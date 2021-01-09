#include <stdio.h>
int gcd(int,int);
int main()
{
	int x,y;
	scanf("%d%d",&x,&y);
	printf("%d\n",gcd(x,y));
	return 0;
}
int gcd(int x,int y)
{
	if(x%y==0) return y;
	return gcd(y,x%y);
}
