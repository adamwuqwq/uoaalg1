#include stdio.h
#include math.h
#define N 10001
int isPrime(int);
int main()
{
	int tmp,i,n,cnt=0;
	scanf(%d,&n);
	for(i=0;in;i++){
		scanf(%d,&tmp);
		cnt+=isPrime(tmp);
	}
	printf(%dn,cnt);
	return 0;
}
int isPrime(int x)
{
	int i;
	if(x==2) return 1;
	else if(x%2==0) return 0;
	for(i=3;i=sqrt(x);i+=2)
		if(x%i==0) return 0;
	return 1;
}