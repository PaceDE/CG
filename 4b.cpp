#include<graphics.h>
#include<stdio.h>

void boundary_fill4(int x ,int y,int bcolor,int fillcolor)
{
	int value=getpixel(x,y);
	
	if(value!=bcolor && value!=fillcolor)
	{
		putpixel(x,y,fillcolor);
		boundary_fill4(x-1,y,bcolor,fillcolor);
		boundary_fill4(x+1,y,bcolor,fillcolor);
		boundary_fill4(x,y-1,bcolor,fillcolor);
		boundary_fill4(x,y+1,bcolor,fillcolor);
	}	
}
int main()
{
   int gd = DETECT, gm;
   initgraph(&gd, &gm, "" );
   outtextxy(10,5,"Lab no: 4(a)");
   outtextxy(10,20,"Name: Dipesh Shrestha");
   outtextxy(10,35,"Roll No: 08");
   line(150,140,400,140);
   line(150,140,100,200);
   line(400,140,465,200);
   line(100,200,50,230);
   line(465,200,550,240);
   line(50,230,50,270);
   line(550,240,550,270);
   line(50,270,135,270);
   line(550,270,425,270);
   arc(170,270,0,180,35);
   arc(390,270,0,180,35);
   line(205,270,355,270);
   circle(170,270,32);
   circle(390,270,32); 
   line(165,150,275,150);
   line(135,190,275,190);
   line(165,150,135,190);
   line(275,150,275,190); 
   line(285,150,390,150);     
   line(285,190,430,190);
   line(285,150,285,190);
   line(390,150,430,190);
   
   boundary_fill4(300,200,15,14);
   
getch();
   closegraph();
   return 0;
}
