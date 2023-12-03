#include<stdio.h>
#include<graphics.h>
int main()
{	
	initwindow(1500,750,"Windows BGI");
    outtextxy(10,5,"Lab no: 5(a)");
   	outtextxy(10,20,"Name: Dipesh Shrestha");
   	outtextxy(10,35,"Roll No: 08");
   	settextstyle(11,0,1);
	int x[2], y[2],tv[2]={100,175};
	char arr[50];
	printf("Enter the left and right x pixel of rectangle : ");
	scanf("%d %d", &x[0],&x[1]);	
	printf("Enter the top and bottom y pixel of rectangle : ");
	scanf("%d %d", &y[0],&y[1]);	

	setcolor(10);
   	outtextxy(x[0]+100,y[1]+10,"Object");
	rectangle(x[0],y[0],x[1],y[1]);
	
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			sprintf(arr,"(%d,%d)",x[i],y[j]);
			outtextxy(x[i]+5,y[j]-20,arr);
		}
	}
	
	
	
	for(int i=0;i<2;i++)
	{
		x[i]+=tv[0];
		y[i]+=tv[1];
	}
	
	setcolor(14);
   	outtextxy(x[0]+100,y[1]+10,"Image");
	rectangle(x[0],y[0],x[1],y[1]);

	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			sprintf(arr,"(%d,%d)",x[i],y[j]);
			outtextxy(x[i]+5,y[j]-20,arr);
		}
	}
	
	getch();
	closegraph();	
	return 0;
}
