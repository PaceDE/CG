#include<graphics.h>
#include<stdio.h>
#include<math.h>
void drawCircle(int x,int y,int xc,int yc)
{
	putpixel(xc+x,yc+y,15);
	putpixel(xc+y,yc+x,15);
	putpixel(xc+y,yc-x,15);
	putpixel(xc+x,yc-y,15);
	putpixel(xc-x,yc-y,15);
	putpixel(xc-y,yc-x,15);
	putpixel(xc-y,yc+x,15);
	putpixel(xc-x,yc+y,15);
}
int main()
{
	int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    outtextxy(200,5,"Lab no: 3(a)");
    outtextxy(200,20,"Name: Dipesh Shrestha");
    outtextxy(200,35,"Roll No: 08");
	int xc,yc,r,pk,pk1,xk,yk,xk1,yk1;
	float m;
	printf("Enter the center and radius of circle: ");
	scanf("%d %d %d",&xc,&yc,&r);
	xk=0;
	yk=r;
	pk=1-r;
	
	drawCircle(xk,yk,xc,yc);
	printf("\nk \t Pk \t Pk+1 \t xk \t xk+1 \t yk \t yk+1 \t At(0,0) \t At(xc,yc) \n");
	int k=0;
	while(yk>xk)
	{
		
		if(pk<0)
		{
			xk1=xk+1;
			yk1=yk;
			pk1=pk+2*xk1+1;
		}
		else
		{
			xk1=xk+1;
			yk1=yk-1;
			pk1=pk+2*xk1+1-2*yk1;
		}
		printf("%d \t %d \t %d \t %d \t %d \t %d \t %d \t (%d,%d) \t\t(%d,%d) \n",k, pk, pk1, xk, xk1, yk, yk1, xk1, yk1, xk1+xc, yk1+yc);
		drawCircle(xk1,yk1,xc,yc);
		xk=xk1;
		yk=yk1;
		pk=pk1;
		k++;
		
	}
	getch();
   closegraph();
   return 0;
	
}
