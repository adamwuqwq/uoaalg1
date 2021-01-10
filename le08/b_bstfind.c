#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node *NodePointer;
struct node{
	int key;
	NodePointer left,right,p; //left child, right child, parent node
};
NodePointer NIL,T; //NIL pointer & BST root node
void insert(int);
void inorder(NodePointer);
void preorder(NodePointer);
void init();
int find(int);
int main()
{
	char inst[10]; //instruction buffer
	int n,num;
	init(); //initial process
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s",inst);
		if(!strcmp(inst,"insert")){
			scanf("%d",&num);
			insert(num);
		}
		else if(!strcmp(inst,"print")){
			inorder(T);
			printf("\n");
			preorder(T);
			printf("\n");
		}
		else if(!strcmp(inst,"find")){
			scanf("%d",&num);
			if(find(num)) printf("yes\n");
			else printf("no\n");
		}
		else printf("invalid input!\n");
	}
}
void init()
{
	NIL=malloc(sizeof(struct node));
	NIL->left=NIL->right=NIL->p=NIL;
	T=NIL;
}
void insert(int key)
{
	//create node that will be inserted
	NodePointer z=malloc(sizeof(struct node));
	z->key=key;
	z->left=z->right=NIL;
	NodePointer y=NIL; //parent of current node
	NodePointer x=T; //current node, initially set as root node of T
	while(x!=NIL){
		y=x;
		if(key<x->key) x=x->left;
		else x=x->right;
	}
	z->p=y;
	if(y==NIL) T=z;
	else if(key<y->key) y->left=z;
	else y->right=z;
}
int find(int key)
{
	NodePointer y=NIL; //parent of current node
	NodePointer x=T; //current node, initially set as root node of T
	while(x!=NIL){
		y=x;
		if(key==x->key) return 1;
		else if(key<x->key) x=x->left;
		else x=x->right;
	}
	return 0;
}
void inorder(NodePointer x)
{
	if(x==NIL) return;
	inorder(x->left);
	printf(" %d",x->key);
	inorder(x->right);
}
void preorder(NodePointer x)
{
	if(x==NIL) return;
	printf(" %d",x->key);
	preorder(x->left);
	preorder(x->right);
}