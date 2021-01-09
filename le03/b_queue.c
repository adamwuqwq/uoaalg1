#include <stdio.h>
#include <string.h>
#define N 100001
#define Q 1001
typedef struct proc{
	char name[11];
	int time;
}process;
int isEmpty();
int isFull();
void enqueue(process);
process dequeue();
process p[N],res[N];
int head=0,tail=0;
int main()
{
	int i,n,q,stime=0,finish=0;
	process buffer,tmp,tmp1;
	scanf("%d%d",&n,&q);
	for(i=0;i<n;i++){
		scanf("%s %d",buffer.name,&buffer.time);
		enqueue(buffer);
	}
	while(!isEmpty()){
		tmp=dequeue();
		if(tmp.time<=q){
			res[finish].time=stime+tmp.time;
			strcpy(res[finish].name,tmp.name);
			finish++;
			stime+=tmp.time;
		}
		else{
			tmp.time-=q;
			enqueue(tmp);
			stime+=q;
		}
	}
	for(i=0;i<finish;i++){
		printf("%s %d\n",res[i].name,res[i].time);
	}
	return 0;
}
int isEmpty()
{
	return head==tail;
}
int isFull()
{
	return head==(tail+1)%N;
}
void enqueue(process x)
{
	if(isFull()) printf("Queue overflow\n");
	else{
		p[tail]=x;
		if(tail+1==N) tail=0;
		else tail++;
	}
}
process dequeue()
{
	if(isEmpty()) printf("Queue underflow\n");
	else{
		process tmp=p[head];
		if(head+1==N) head=0;
		else head++;
		return tmp;
	}
}
