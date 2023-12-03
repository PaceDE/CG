#include<graphics.h>
#include<stdio.h>
#include<math.h>
double max(int a,double b,double c, double d, double e)
{
	if(a>b && a>c && a>d && a>e)
		return a;
	else if(b>c && b>d && b>e)
		return b;
	else if( c>d && c>e)
		return c;
	else if(d>e)
		return d;
	else
		return e;
}
double min(int a,double b,double c, double d, double e)
{
	if(a<b && a<c && a<d && a<e)
		return a;
	else if(b<c && b<d && b<e)
		return b;
	else if( c<d && c<e)
		return c;
	else if(d<e)
		return d;
	else
		return e;
}
double uminCalc(double p, double q)
{
	if(p<0)
		return q/p;
	else 
		return 0;
}
double umaxCalc(double p,double q)
{
	if(p>0)
		return q/p;
	else
		return 1;
}

int main()
{
	initwindow(1500,750,"Windows BGI");
   	outtextxy(500,5,"Lab no:6(c)");
   	outtextxy(500,20,"Name: Dipesh Shrestha");
   	outtextxy(500,35,"Roll No: 08");   	
   	settextstyle(11,0,1);  	  
   	int X[2], Y[2]; 
   	double XWmin, YWmin, XWmax, YWmax,p1,q1,p2,q2,p3,q3,p4,q4,X1[2],Y1[2],umin,umax;

	printf("Enter the Bottom left corner and Top right corner points of Clipping Window : ");
	scanf("%lf %lf %lf %lf",&XWmin, &YWmax, &XWmax, &YWmin);
	
	rectangle(XWmin,YWmin,XWmax,YWmax);
	printf("Enter the Two points of line: ");
	scanf("%d %d %d %d", &X[0], &Y[0], &X[1], &Y[1]);
	setcolor(14);
	rectangle(510,57,520,67);
	outtextxy(540,55,"Unclipped line");
	line(X[0],Y[0],X[1],Y[1]);
	printf("\nUnclipped line: %d %d %d %d \n",X[0],Y[0],X[1],Y[1]);
	setcolor(15);
	
	p1=(X[0]-X[1]);     q1=X[0]-XWmin;
	p2=(X[1]-X[0]);		q2=XWmax-X[0];	
	p3=(Y[0]-Y[1]);		q3=Y[0]-YWmin;
	p4=(Y[1]-Y[0]);		q4=YWmax-Y[0];	
	umin=max(0.0,uminCalc(p1,q1),uminCalc(p2,q2),uminCalc(p3,q3),uminCalc(p4,q4));
	umax=min(1.0,umaxCalc(p1,q1),umaxCalc(p2,q2),umaxCalc(p3,q3),umaxCalc(p4,q4));
	
	if(umin>umax)
	{
		outtextxy(300,500,"The line is completely outside the window");
		goto end;
	}	
	X1[0]=X[0]+umin*(X[1]-X[0]);
	Y1[0]=Y[0]+umin*(Y[1]-Y[0]);
	X1[1]=X[0]+umax*(X[1]-X[0]);
	Y1[1]=Y[0]+umax*(Y[1]-Y[0]);
	setcolor(10);
	rectangle(510,77,520,87);
   	outtextxy(540,75,"Clipped Line");
   	line(X1[0],Y1[0],X1[1],Y1[1]);
	printf("\nClipped line: %lf %lf %lf %lf \n",X1[0],Y1[0],X1[1],Y1[1]);
	
	end:
	getch();	
}

