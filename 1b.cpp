#include<graphics.h>
#include<stdio.h>
int main()
{
   int gd = DETECT, gm;
   initgraph(&gd, &gm, "");
   outtextxy(10,5,"Lab no: 1(b)");
   outtextxy(10,20,"Name: Dipesh Shrestha");
   outtextxy(10,35,"Roll No: 08"); 
  // House 
   line(0,200,63,200);
   line(535,200,650,200);    
   line(140,80,40,150); 
   line(140,80,210,160); 
   line(140,80,500,120); 
   line(210,160,550,185);
   line(500,120,550,185);   
   line(145,85,64,142);
   line(40,150,64,150);    
   line(64,142,64,250);
   line(194,142,194,275);  
   line(64,250,194,275); 
   line(194,275,535,250); 
   line(535,185,535,250);   
   line(140,160,180,167); 
   line(140,160,140,265);
   line(180,167,180,272);    
   line(80,167,120,175);
   line(80,207,120,215);
   line(100,172,100,210); 
   line(80,167,80,207);
   line(120,175,120,215);   
   line(400,196,460,192); 
   line(400,230,460,225); 
   line(400,212,460,208); 
   line(400,196,400,230); 
   line(460,192,460,225); 
   line(430,194,430,227);  
   circle(150,210,5);  
   // Car
   line(0,427,650,427); 
   line(150,340,250,340);
   line(150,340,125,375);
   line(250,340,285,375);
   line(125,375,97,385);
   line(285,375,340,390);
   line(97,385,97,410);
   line(340,390,340,410);
   line(97,410,135,410);
   line(340,410,295,410);
   arc(155,410,0,180,20);
   arc(275,410,0,180,20);
   line(175,410,255,410);
   circle(155,410,16);
   circle(275,410,16);
   circle(155,410,5);
   circle(275,410,5);
   line(155,350,205,350);
   line(142,370,205,370);
   line(155,350,142,370);
   line(205,350,205,370);      
   line(210,350,250,350);
   line(210,370,270,370);
   line(210,350,210,370);
   line(250,350,270,370);
   //Human
   circle(400,340,11);
   line(395,350,395,352);
   line(405,350,405,352);
   rectangle(390,352,410,385);
   line(392,385,392,425);
   line(410,385,415,425);
   line(400,395,400,425);
   line(400,395,410,425);
   line(402,365,420,355);
   line(402,370,420,360);
   line(420,355,420,360);  
   circle(550,340,11);
   arc(540,335,0,220,10);
   arc(540,335,0,210,8);
   arc(560,335,0,220,10);
   arc(560,335,0,200,8); 
   line(545,350,545,352);
   line(555,350,555,352);
   rectangle(540,352,560,385);
   line(540,385,535,410);
   line(560,385,565,410);
   line(535,410,565,410);
   line(542,410,538,425);
   line(558,410,558,425);
   line(550,410,545,425);
   line(550,410,550,425);
   line(552,365,530,360);
   line(552,370,530,365);
   line(530,360,530,365);
   outtextxy(410,310,"Hi Barbie..");
   outtextxy(495,305,"Hi Ken.."); 
   getch();
   closegraph();
   return 0;
}
