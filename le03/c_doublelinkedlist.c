//rebuild beta
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 2000000
typedef struct Node *NodePointer;
struct Node{
	int value;
	NodePointer prev;
	NodePointer next;
};
void init();
void insert(int);
NodePointer listSearch(int);
void deleteNode(NodePointer);
void deleteFirst();
void deleteLast();
void delete(int);
NodePointer nil;
int isEmpty();
int main()
{
	int n,i,num;
	NodePointer x;
	char inst[12];
	init();
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%s",inst);
		if(!strcmp(inst,"insert")){
			scanf("%d",&num);
			insert(num);
		}
		else if(!strcmp(inst,"delete")){
			scanf("%d",&num);
			if(!isEmpty()) delete(num);
		}
		else if(!strcmp(inst,"deleteFirst")){
			if(!isEmpty()) deleteFirst();
		}
		else if(!strcmp(inst,"deleteLast")){
			if(!isEmpty()) deleteLast();
		}	
	}
	for(x=nil->next;x->next!=nil;x=x->next) printf("%d ",x->value);	
	printf("%d\n",x->value);
	return 0;
}
void init() //add nil node
{
	nil=malloc(sizeof(struct Node));
	nil->next=nil;
	nil->prev=nil;
}
void insert(int num)
{
	NodePointer x=malloc(sizeof(struct Node));
	x->value=num;
	x->next=nil->next;
	nil->next->prev=x;
	nil->next=x;
	x->prev=nil;
}
NodePointer listSearch(int num)
{
	NodePointer cur;
	cur=nil->next;
	while(cur!=nil&&cur->value!=num){
		cur=cur->next;
	}
	return cur;
}
void deleteNode(NodePointer n)
{
	if(n==nil) return;
	n->prev->next=n->next;
	n->next->prev=n->prev;
	free(n);
}
void deleteFirst()
{
	deleteNode(nil->next);
}
void deleteLast()
{
	deleteNode(nil->prev);
}
void delete(int num)
{
	deleteNode(listSearch(num));
}
int isEmpty()
{
	return nil->next==NULL?1:0;
}