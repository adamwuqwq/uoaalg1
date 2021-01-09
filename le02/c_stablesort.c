#include <stdio.h>
#include <string.h>
#define N 37
typedef struct dat{
	char suit;
	int value;
	int position;
}data;
int main()
{
	data input,bubble[N],selection[N],tmp;
	int i,j,n,mini;
	int stable=1;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf(" %c%d",&input.suit,&input.value);
		input.position=i;
		bubble[i]=selection[i]=input;	
	}
	//bubble sort
	for(i=0;i<n;i++){
		for(j=n-1;j>i;j--){
			if(bubble[j].value<bubble[j-1].value){
				tmp=bubble[j];
				bubble[j]=bubble[j-1];
				bubble[j-1]=tmp;
			}
		}
	}
	//selection sort
	for(i=0;i<n;i++){
		mini=i;
		for(j=i;j<n;j++)
			if(selection[j].value<selection[mini].value) mini=j;
		if(mini!=i){
			tmp=selection[i];
			selection[i]=selection[mini];
			selection[mini]=tmp;
		}
	}
	//bubble print
	for(i=0;i<n;i++){
		if(bubble[i].value==bubble[i+1].value && bubble[i].position>bubble[i+1].position) stable=0;
		if(i==n-1) printf("%c%d\n",bubble[i].suit,bubble[i].value);
		else printf("%c%d ",bubble[i].suit,bubble[i].value);
	}
	if(stable) printf("Stable\n");
	else printf("Not stable\n");
	stable=1;
	//selection print
	for(i=0;i<n;i++){
		if(selection[i].value==selection[i+1].value && selection[i].position>selection[i+1].position) stable=0;
		if(i==n-1) printf("%c%d\n",selection[i].suit,selection[i].value);
		else printf("%c%d ",selection[i].suit,selection[i].value);
	}
	if(stable) printf("Stable\n");
	else printf("Not stable\n");
	return 0;
}
