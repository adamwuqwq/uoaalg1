#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FREE 0
#define NOT_FREE 1
#define N 8
#define NOQUEEN -1
int row[N],col[N];
//row[x] -> position of the queens at row x
//col[x] -> show if each position of a given row x is threatened by a queen in the same column (FREE,NOT_FREE)
int dpos[2*N],dneg[2*N];
//dpos[x] -> show if each position of a given x(row+col) is threatened by a queen on the same positive diagonal(/) (FREE,NOT_FREE)
//dneg[x] -> show if each position of a given x(row-col+N-1) is threatened by a queen on the same negative diagonal(\) (FREE,NOT_FREE)
//use (row-col+N-1) instead of row-col to prevent negative number appears
int k,row_flag[N];
//k -> how much of queen(s) have already been placed
//row_flag[x] -> row x a queen (FREE,NOT_FREE)
void putQueen(int);
void printBoard();
int main()
{
	int tmpx,tmpy;
	//data input & initialization 
	memset(row_flag,FREE,sizeof(row_flag));
	memset(col,FREE,sizeof(col));
	memset(dpos,FREE,sizeof(dpos));
	memset(dpos,FREE,sizeof(dneg));
	memset(row,NOQUEEN,sizeof(row));
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		scanf("%d%d",&tmpx,&tmpy);
		row_flag[tmpx]=NOT_FREE; //set current row as NOT_FREE
		col[tmpy]=dpos[tmpx+tmpy]=dneg[tmpx-tmpy+N-1]=NOT_FREE; //set current column and positive&negative diagonal as NOT_FREE 
		row[tmpx]=tmpy; //save column number for current row
	}
	putQueen(0);
	return 0;
}
void putQueen(int i) //serach for row i
{
	if(i==N){
		printBoard();
		return;
	}
	if(row_flag[i]==NOT_FREE) putQueen(i+1);
	else{
		for(int j=0;j<N;j++){ //search each column
			if(col[j]==NOT_FREE || dpos[i+j]==NOT_FREE || dneg[i-j+N-1]==NOT_FREE) continue; //Judge whether we can put a queen on (i,j) 
			else{
				//put a queen at (i,j);
				row[i]=j;
				col[j]=dpos[i+j]=dneg[i-j+N-1]=NOT_FREE;
				//curr_queen++;
				//try next row
				putQueen(i+1);
				col[j]=dpos[i+j]=dneg[i-j+N-1]=FREE; //if the search could not find 8 queens, remove the queen at(i,j) for backtracking
				//curr_queen--;
			}
		}
	}
}
void printBoard()
{
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(j==row[i]) printf("Q");
			else printf(".");
		}
		printf("\n");
	}
}