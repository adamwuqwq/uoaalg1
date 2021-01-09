#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 101
int isEmpty();
int isFull();
void push(int);
int pop();
int top=0,stack[N];
int main()
{
	char buffer[11];
	int x,y,num;
	while(scanf(" %s",buffer)!=EOF){
		if(!strcmp(buffer,"+")){
			x=pop(); y=pop();
			push(y+x);
		}
		else if(!strcmp(buffer,"-")){
			x=pop(); y=pop();
			push(y-x);
		}
		else if(!strcmp(buffer,"*")){
			x=pop(),y=pop();
			push(y*x);
		}
		else{
			num=atoi(buffer);
			push(num);
		}
	}
	printf("%d\n",stack[1]);
	return 0;
}
int isEmpty()
{
	return top==0;
}
int isFull()
{
	return top==N-1;
}
void push(int num)
{
	if(isFull()) printf("Stack overflow\n");
	else{
		top++;
		stack[top]=num;
	}
}
int pop()
{
	if(isEmpty()) printf("Stack underflow\n");
	else{
		top--;
		return stack[top+1];
	}
}