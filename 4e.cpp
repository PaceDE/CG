#include<graphics.h>
#include<stdio.h>
void flood_fill8(int x ,int y,int fillcolor,int oldcolor)
{
	int current=getpixel(x,y);
	
	if(current==oldcolor)
	{
		putpixel(x,y,fillcolor);
		flood_fill8(x-1,y,fillcolor,oldcolor);
		flood_fill8(x+1,y,fillcolor,oldcolor);
		flood_fill8(x,y-1,fillcolor,oldcolor);
		flood_fill8(x,y+1,fillcolor,oldcolor);	
		flood_fill8(x-1,y+1,fillcolor,oldcolor);	
		flood_fill8(x+1,y+1,fillcolor,oldcolor);
		flood_fill8(x-1,y-1,fillcolor,oldcolor);	
		flood_fill8(x+1,y-1,fillcolor,oldcolor);
			}	
}
int main()
{
   int gd = DETECT, gm;
   initgraph(&gd, &gm, "");
   outtextxy(10,5,"Lab no: 4(d)");
   outtextxy(10,20,"Name: Dipesh Shrestha");
   outtextxy(10,35,"Roll No: 08");
   rectangle(150,125,350,225);
   rectangle(100,100,400,250);
   flood_fill8(200,150,14,0);
   flood_fill8(370,150,10,0);
   getch();
   closegraph();
   return 0;
}
