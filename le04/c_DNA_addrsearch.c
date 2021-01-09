#include <stdio.h>
#include <string.h>
#include <math.h>
#define N 1000001
#define M 9765625
#define true 'T'
char addrsearch[M];
int chartoaddr(char *);
int main()
{
	int n;
	char inst[7],str[13];
	memset(addrsearch,0,sizeof(addrsearch));
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s %s",inst,str);
		if(!strcmp(inst,"insert")) addrsearch[chartoaddr(str)]=true;
		else if(!strcmp(inst,"find")){
			if(addrsearch[chartoaddr(str)]==true) printf("yes\n");
			else printf("no\n");
		}
	}
	return 0;
}
//A:1 C:2 G:3 T:4
//CCGTA:11230(QUA) 364(DEC)
int chartoaddr(char *str)
{
	int len=strlen(str),num=0;
	for(int i=0;i<len;i++){
		switch(str[i]){ //DEC to QUA convert
			case 'A': num+=(1*pow(5,i));break;
			case 'C': num+=(2*pow(5,i)); break;
			case 'G': num+=(3*pow(5,i)); break;
			case 'T': num+=(4*pow(5,i)); break;
			default: break;
		}
	}
	return num;
}