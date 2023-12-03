#include<graphics.h>
#include<stdio.h>
#include<math.h>
int main()
{

	initwindow(1500,750,"Windows BGI");
	outtextxy(10,5,"Lab no: 7(a)");
    outtextxy(10,25,"Name: Dipesh Shrestha");
    outtextxy(10,45,"Roll No: 08");
    settextstyle(11,0,1);
    int x1,x2,y1,y2,mx,my,depth,tx,ty,tz;
    printf("Enter the top left corner of the face of cube: ");
    scanf("%d %d",&x1,&y1);
    printf("Enter the bottom right corner of the face of cube: ");
    scanf("%d %d",&x2,&y2);
    depth=(x2-x1)/2;
    bar3d(x1,y1,x2,y2,depth,1);
    outtextxy((x1+x2)/2,y2+10,"Object");
    printf("Enter the translation vector in x,y,z direction");
    scanf("%d %d %d",&tx,&ty,&tz);
    x1+=tx;
    x2+=tx;
    y1+=ty;
    y2+=ty;
    depth+=tz;
    bar3d(x1,y1,x2,y2,depth,1);
    outtextxy((x1+x2)/2,y2+10,"Image");
	getch();	
}


