#include<graphics.h>
#include<stdio.h>
#include<math.h>
int main()
{
	int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    outtextxy(10,5,"Lab no: 2(a)");
    outtextxy(10,20,"Name: Dipesh Shrestha");
    outtextxy(10,35,"Roll No: 08");
	int x0,y0,xe,ye,dx,dy;
	float steplength,xIncrement,yIncrement,x,y;
	printf("Enter the leftend point and right endpoint: ");
	scanf("%d %d %d %d",&x0,&y0,&xe,&ye);
	dx=xe-x0;
	dy=ye-y0;
	x=x0;
	y=y0;
	if(abs(dx)>abs(dy))
	{
		steplength=abs(dx);
	}
	else
	{
		steplength=abs(dy);
	}
	xIncrement=dx/steplength;
	yIncrement=dy/steplength;
	printf("\nk \t x \t\t y \t\t (x,y) \t\t\t\t Plot(round(x),round(y)) \n");
	for(int i=0;i<=steplength;i++)
	{
		printf("%d \t %f \t %f \t (%f,%f) \t\t (%f,%f)\n",i,x,y,x,y,round(x),round(y));
		putpixel(round(x),round(y),7);	
		x=x+xIncrement;
		y=y+yIncrement;		
	}	
	getch();
    closegraph();
    return 0;
	
}
