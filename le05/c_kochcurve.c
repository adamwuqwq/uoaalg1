#include <stdio.h>
#include <math.h>
#define PI 3.1415926358979323
#define RAD PI/3
typedef struct{
	double x,y;
}point;
int n;
void kochcurve(point,point,int);
int main()
{
	point start,end;
	start.x=0,end.x=100;
	start.y=end.y=0;
	scanf("%d",&n);
	printf("%.8f %.8f\n",start.x,start.y);
	kochcurve(start,end,n);
	printf("%.8f %.8f\n",end.x,end.y);
	return 0;
}
void kochcurve(point left,point right,int depth)
{
	if(depth==0) return;
	point s,u,t,mid,relative;
	s.x=left.x+(right.x-left.x)/3,s.y=left.y+(right.y-left.y)/3;
	t.x=left.x+2*(right.x-left.x)/3,t.y=left.y+2*(right.y-left.y)/3;
	//mid.x=(left.x+right.x)/2,mid.y=(left.y+right.y)/2;
	relative.x=t.x-s.x,relative.y=t.y-s.y;
	u.x=relative.x*cos(RAD)-relative.y*sin(RAD)+s.x;
	u.y=relative.x*sin(RAD)+relative.y*cos(RAD)+s.y;
	kochcurve(left,s,depth-1);
	printf("%.8f %.8f\n",s.x,s.y);
	kochcurve(s,u,depth-1);
	printf("%.8f %.8f\n",u.x,u.y);
	kochcurve(u,t,depth-1);
	printf("%.8f %.8f\n",t.x,t.y);
	kochcurve(t,right,depth-1);
}
