#include<graphics.h>
#include<stdio.h>
void flood_fill4(int x ,int y,int fillcolor,int oldcolor)
{
	int current=getpixel(x,y);
	
	if(current==oldcolor)
	{
		putpixel(x,y,fillcolor);
		flood_fill4(x-1,y,fillcolor,oldcolor);
		flood_fill4(x+1,y,fillcolor,oldcolor);
		flood_fill4(x,y-1,fillcolor,oldcolor);
		flood_fill4(x,y+1,fillcolor,oldcolor);	
	}	
}
int main()
{
   int gd = DETECT, gm;
   initgraph(&gd, &gm, "");
   outtextxy(10,5,"Lab no: 4(c)");
   outtextxy(10,20,"Name: Dipesh Shrestha");
   outtextxy(10,35,"Roll No: 08");   
   circle(300,250,25);
   circle(300,250,50);
   circle(300,250,100);
   flood_fill4(300,250,14,0);
   flood_fill4(330,250,10,0);
   flood_fill4(355,250,8,0);

   getch();
   closegraph();
   return 0;
}
