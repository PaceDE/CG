#include<graphics.h>
#include<stdio.h>

void boundary_fill8(int x ,int y,int bcolor,int fillcolor)
{
	int value=getpixel(x,y);
	
	if(value!=bcolor && value!=fillcolor)
	{
		putpixel(x,y,fillcolor);
		boundary_fill8(x-1,y,bcolor,fillcolor);
		boundary_fill8(x+1,y,bcolor,fillcolor);
		boundary_fill8(x,y-1,bcolor,fillcolor);
		boundary_fill8(x,y+1,bcolor,fillcolor);
		boundary_fill8(x-1,y-1,bcolor,fillcolor);
		boundary_fill8(x-1,y+1,bcolor,fillcolor);
		boundary_fill8(x+1,y-1,bcolor,fillcolor);
		boundary_fill8(x+1,y+1,bcolor,fillcolor);	
	}	
}
int main()
{
   int gd = DETECT, gm;
   initgraph(&gd, &gm, "");
   outtextxy(10,5,"Lab no: 4(b)");
   outtextxy(10,20,"Name: Dipesh Shrestha");
   outtextxy(10,35,"Roll No: 08");
    
  circle(200,200,50);
   boundary_fill8(200,200,15,3);
  
		
   
  
   
  
getch();
   closegraph();
   return 0;
}
