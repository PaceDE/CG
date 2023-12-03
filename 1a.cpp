#include<graphics.h>
#include<stdio.h>

 
int main()
{
   int gd = DETECT, gm;
 
   //init graphics
   initgraph(&gd, &gm, "");
   outtextxy(10,5,"Lab no: 1(a)");
   outtextxy(10,20,"Name: Dipesh Shrestha");
   outtextxy(10,35,"Roll No: 08");

   /*line(30,75,70,200); 
   outtextxy(40,215,"Line"; 
   
   arc(150,140,90,270,65);
   outtextxy(120,215,"Arc"); 
   
   circle(250,140,65);
   outtextxy(225,215,"Circle"); 
   
   ellipse(360,140,0,360,30,65);
   outtextxy(336,215,"Ellipse"); 
   
   rectangle(400,75,600,200);
   outtextxy(465,215,"Rectangle"); 
   
   rectangle(30,275,155,400); 
   outtextxy(65,415,"Square"); 
   
   line(250,400,350,400); 
   line(300,275,250,400); 
   line(300,275,350,400); 
   outtextxy(275,415,"Triangle"); 
   
   line(450,370,550,370); 
   line(500,275,450,370); 
   line(500,275,550,370); 
   
   line(450,305,550,305); 
   line(500,400,450,305); 
   line(500,400,550,305); 
   outtextxy(470,415,"Shatkona");  */
   arc(200,200,0,180,10);
 getch();
   closegraph();
   return 0;
}
