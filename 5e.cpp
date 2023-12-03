#include<graphics.h>
#include<stdio.h>
#include<math.h>

int main()
{
	
    initwindow(1500,750,"Windows BGI");
	outtextxy(10,5,"Lab no: 5(e)");
   	outtextxy(10,20,"Name: Dipesh Shrestha");
   	outtextxy(10,35,"Roll No: 08"); 
   	
   	settextstyle(11,0,1);
	int x[3]={400,600,500};
	int y[6]={385,385,200,265,265,450};
	char arr[50];
    float Sx=0.5,Sy=0.5;
	
	setcolor(10);
   	outtextxy(x[2],y[5]+10,"Object");
   	int pos;
	for(int i=0;i<3;i++)
	{
		pos=10;
		if(i==0)
		{
			pos=-55;
		}
		line(x[i],y[i],x[(i+1)%3],y[(i+1)%3]);
		line(x[i],y[i+3],x[(i+1)%3],y[((i+1)%3)+3]);	
		sprintf(arr,"(%d,%d)",x[i],y[i]);
		outtextxy(x[i]+pos,y[i]-10,arr);
		sprintf(arr,"(%d,%d)",x[i],y[i+3]);
		outtextxy(x[i]+pos,y[i+3]-10,arr);
	}
	
	for(int j=0;j<3;j++)
	{
		x[j]*=Sx;
		y[j]*=Sy;
		y[j+3]*=Sy;
	}
	
	setcolor(14);
   	outtextxy(x[2],y[5]+10,"Image");
	for(int j=0;j<3;j++)
	{
		line(x[j],y[j],x[(j+1)%3],y[(j+1)%3]);
		line(x[j],y[j+3],x[(j+1)%3],y[((j+1)%3)+3]);		
		pos=10;
		if(j==0)
		{
			pos=-55;
		}		
		sprintf(arr,"(%d,%d)",x[j],y[j]);
		outtextxy(x[j]+pos,y[j]-10,arr);
		sprintf(arr,"(%d,%d)",x[j],y[j+3]);
		outtextxy(x[j]+pos,y[j+3]-10,arr);
	}
	getch();	
}


