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
NodePointer find(int);
void delete(NodePointer);
void deleteS(NodePointer,NodePointer);
NodePointer successor(NodePointer);
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
			if(find(num)!=NIL) printf("yes\n");
			else printf("no\n");
		}
		else if(!strcmp(inst,"delete")){
			scanf("%d",&num);
			delete(find(num));
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
NodePointer successor(NodePointer x)
{
	if(x->right!=NIL){
		NodePointer y=x->right;
		while(y->left!=NIL) y=y->left;
		return y;
	}
	else{ //in this case, x represents current node
		NodePointer y=x->p; //parent node of current node
		while(y!=NIL&&x==y->right){
			x=y;
			y=y->p;
		}
		return y;
	}
}
void deleteS(NodePointer x,NodePointer y)
{
	//determine whether node x is left or right child of its parent node x->p
	if(x->p->left==x) x->p->left=y;
	else x->p->right=y;
	free(x);
}
void delete(NodePointer x)
{
	if(x->left==NIL&&x->right==NIL){
		deleteS(x,NIL);
	}
	else if(x->left==NIL){ //only have right child
		NodePointer x_p=x->p,rchild=x->right;
		rchild->p=x_p;
		deleteS(x,rchild);
	}
	else if(x->right==NIL){ //only have left child
		NodePointer x_p=x->p,lchild=x->left;
		lchild->p=x_p;
		deleteS(x,lchild);
	}
	else{
		NodePointer z=successor(x); //successor of node x
		x->key=z->key;
		delete(z);
	}
}
NodePointer find(int key)
{
	NodePointer y=NIL; //parent of current node
	NodePointer x=T; //current node, initially set as root node of T
	while(x!=NIL){
		y=x;
		if(key==x->key) return x;
		else if(key<x->key) x=x->left;
		else x=x->right;
	}
	return NIL;
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