#include<graphics.h>
#include<stdio.h>
#include<math.h>
int main()
{

	initwindow(1500,750,"Windows BGI");
	outtextxy(10,5,"Lab no: 7(c)");
    outtextxy(10,25,"Name: Dipesh Shrestha");
    outtextxy(10,45,"Roll No: 08");
    settextstyle(11,0,1);
    int x1,x2,y1,y2,mx,my,depth,Sx=2,Sy=3,Sz=1;
    printf("Enter the top left corner of the face of cube: ");
    scanf("%d %d",&x1,&y1);
    printf("Enter the bottom right corner of the face of cube: ");
    scanf("%d %d",&x2,&y2);
    depth=(x2-x1)/2;
    bar3d(x1,y1,x2,y2,depth,1);
    outtextxy((x1+x2)/2,y2+10,"Object");

    x1*=Sx;
    x2*=Sx;
    y1*=Sy;
    y2*=Sy;
    depth+=Sz;
    bar3d(x1,y1,x2,y2,depth,1);
    outtextxy((x1+x2)/2,y2+10,"Image");
	getch();
	closegraph();
	return 0;	
}


