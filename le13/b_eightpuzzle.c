#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 3
#define NIL -1
#define MIN 12345678
#define QUEUE_MAX 362880
#define MOD 8765437
const int target=123456780;
int dir[4][2]={-1,0,0,1,1,0,0,-1}; //storage each directions: UP,RIGHT,DOWN,LEFT
char vis[MOD];
int step[MOD];
int mat[N][N];
int blank_x,blank_y;
int isEmpty();
void enqueue(int);
int dequeue();
int ptoi(int[N][N]);
int can_move(int,int);
int move(int,int);
int bfs(int);
int main()
{
    int puzzle[N][N];
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++) scanf("%d",&puzzle[i][j]);
    }
    printf("%d\n",bfs(ptoi(puzzle)));
    return 0;
}
//queue operations
int Q[QUEUE_MAX];
int head=0,tail=0;
int isEmpty()
{
    return head==tail;
}
void enqueue(int x)
{
    Q[tail]=x;
    if(tail==QUEUE_MAX-1) tail=0;
    else tail++;
}
int dequeue()
{
    int tmp=Q[head];
    if(head==QUEUE_MAX-1) head=0;
    else head++;
    return tmp;
}
int ptoi(int p[N][N]) //convert a puzzle to an integer number
{
    return p[0][0]*1e8+p[0][1]*1e7+p[0][2]*1e6+p[1][0]*1e5+p[1][1]*1e4+p[1][2]*1e3+p[2][0]*1e2+p[2][1]*1e1+p[2][2];
}
int can_move(int curr_puzzle,int direction) //judge if can move 
{
    for(int i=2;i>=0;i--){ //convert current puzzle from single integer number to an array matrix, storage it
        for(int j=2;j>=0;j--){
            mat[i][j]=curr_puzzle%10;
            curr_puzzle/=10;
            if(mat[i][j]==0){
                blank_x=i; //storage the position of blank cell in current puzzle
                blank_y=j;
            }
        }
    }
    //judge if can move in 4 directions:UP,RIGHT,DOWN,LEFT
    if((direction==0&&blank_x==0)||(direction==1&&blank_y==2)||(direction==2&&blank_x==2)||(direction==3&&blank_y==0)) return 0;
    return 1;
}
int move(int curr_puzzle,int direction) 
{
    int tmp=0;
    int next_x=blank_x+dir[direction][0]; //the position of blank cell in next puzzle
    int next_y=blank_y+dir[direction][1]; 
    mat[blank_x][blank_y]=mat[next_x][next_y]; //move
    mat[next_x][next_y]=0;
    return ptoi(mat);
}
int bfs(int puzzle)
{
    //start search from default puzzle
    enqueue(puzzle);
    vis[(puzzle-MIN)%MOD]=1;
    step[(puzzle-MIN)%MOD]=0;
    while(!isEmpty())
    {
        int curr_puzzle,next_puzzle;
        curr_puzzle=dequeue();
        if(curr_puzzle==target) return step[(curr_puzzle-MIN)%MOD];
        for(int i=0;i<4;i++){ //search in 4 directions: UP,RIGHT,DOWN,LEFT
            if(can_move(curr_puzzle,i)){
                next_puzzle=move(curr_puzzle,i);
                if(!vis[(next_puzzle-MIN)%MOD]){ //judge if next puzzle pattern have been searched before
                    vis[(next_puzzle-MIN)%MOD]=1; //mark next puzzle pattern as visited
                    step[(next_puzzle-MIN)%MOD]=step[(curr_puzzle-MIN)%MOD]+1; //storage current step because one of next puzzle pattern must be the same as previous step
                    enqueue(next_puzzle);
                }
            }
        }
    }
    return NIL;
}