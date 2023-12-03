#include<graphics.h>
#include<stdio.h>
#include<math.h>

int main()
{	
    initwindow(1500,750,"Windows BGI");
	outtextxy(10,5,"Lab no: 5(d)");
   	outtextxy(10,20,"Name: Dipesh Shrestha");
   	outtextxy(10,35,"Roll No: 08"); 
   	
   	settextstyle(11,0,1);
	int x[10]={500,450,350,430,400,500,600,570,650,550};
	int y[10]={50,150,170,220,320,250,320,220,170,150};
	char arr[50];
    float Sx=2,Sy=2;
	
	setcolor(10);
   	outtextxy(x[4]+70,y[4]+10,"Object");
   	int posx,posy;
	for(int i=0;i<10;i++)
	{
		posx=20;
		posy=-12;
		if(i%2==0)
		{
			posx=-75;
			posy=-3;
		}
		line(x[i],y[i],x[(i+1)%10],y[(i+1)%10]);
	
		sprintf(arr,"(%d,%d)",x[i],y[i]);
		outtextxy(x[i]+posx,y[i]+posy,arr);
	}	
	for(int j=0;j<10;j++)
	{
		x[j]*=Sx;
		y[j]*=Sy;
	}	
	setcolor(14);
   	outtextxy(x[4]+150,y[4]+10,"Image");
	for(int j=0;j<10;j++)
	{
		line(x[j],y[j],x[(j+1)%10],y[(j+1)%10]);
			
		posx=20;
		posy=-12;
		if(j%2==0)
		{
			posx=-75;
			posy=-3;
		}	
		sprintf(arr,"(%d,%d)",x[j],y[j]);
		outtextxy(x[j]+posx,y[j]+posy,arr);
	}
	getch();	
}


