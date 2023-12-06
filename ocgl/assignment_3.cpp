#include<iostream>
#include <graphics.h>
#include <math.h>
using namespace std;
int REC(int a1,int b1,int a2,int b2)
{
	float dx,dy,len;
	dx=a2-a1;
	dy=b2-b1;
	
	if(abs(dy)>abs(dx))
	{
		len=abs(dy);
	}
	else
	{
		len=abs(dx);
	}
	float Xinc,Yinc;
	
	Xinc=dx/len;
	Yinc=dy/len;
	
	float x,y;
	x=a1;
	y=b1;
	for(int i=0;i<=len;i++ )
	{
		x=x+Xinc;
		y=y+Yinc;
		putpixel(x,y,12);
	}
}
int main(int argc,char** argv)
{
	initwindow(1000,1000,"Graphics");
	float x1,y1,x2,y2;
	
	cout<<"x1:";
	cin>> x1;
	cout<<"y1:";
	cin>> y1;
	cout<<"x2:";
	cin>> x2;
	cout<<"y2:";
	cin>> y2;
	
	REC(x1,y1,x2,y1);
	REC(x2,y1,x2,y2);
	REC(x2,y2,x1,y2);
	REC(x1,y2,x1,y1);
	
	int T,Q;
	T=(x1+x2)/2;
	Q=(y1+y2)/2;
	
	REC(T,y1,x2,Q);
	REC(x2,Q,T,y2);
	REC(T,y2,x1,Q);
	REC(x1,Q,T,y1);
	
	int xc,yc,r;
	xc=T;
	yc=Q;
	r=60;
	int x,y;
	x=0;
	y=r;
	int S;
	S=3-2*r;
	while(x<=y)
	{
		putpixel(yc+y,xc+x,12);
		putpixel(yc-y,xc+x,12);
		putpixel(xc+x,yc+y,12);
		putpixel(yc-y,xc-x,12);
		putpixel(xc+x,yc-y,12);
		putpixel(yc+y,xc-x,12);
		putpixel(xc-x,yc+y,12);
		putpixel(xc-x,yc-y,12);
		
		if(S<=0)
		{
			x++;
			S=S+(4*x+6);
			
		}
		else{
			x++;
			y--;
			S=S=4*(x-y)+10;
		}
	}
	getch();
	return 0;
	
}
