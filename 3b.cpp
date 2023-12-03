#include<graphics.h>
#include<stdio.h>
#include<math.h>
void drawEllipse(int x,int y,int xc,int yc)
{
	putpixel(xc+x,yc+y,15);
	putpixel(xc+x,yc-y,15);
	putpixel(xc-x,yc+y,15);
	putpixel(xc-x,yc-y,15);

}
int main()
{
	int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    outtextxy(200,5,"Lab no: 3(b)");
    outtextxy(200,20,"Name: Dipesh Shrestha");
    outtextxy(200,35,"Roll No: 08");
	int xc,yc,rx,ry,xk,yk,xk1,yk1;
	float p1k,p2k,p1k1,p2k1;
	printf("Enter the center, semi major and minor axis of ellipse: ");
	scanf("%d %d %d %d",&xc,&yc,&rx,&ry);
	xk=0;
	yk=ry;
	p1k=ry*ry-rx*rx*ry+0.25*rx*rx;
	
	drawEllipse(xk,yk,xc,yc);
	printf("\nRegion 1 \nk \t P1k \t\t P1k+1 \t\t xk \t xk+1 \t yk \t yk+1 \t At(0,0) \t At(xc,yc) \n");
	int k=0;
	do
	{	
		if(p1k<0)
		{
			xk1=xk+1;
			yk1=yk;
			p1k1=p1k+2*ry*ry*xk1+ry*ry;
		}
		else
		{
			xk1=xk+1;
			yk1=yk-1;
			p1k1=p1k+2*ry*ry*xk1-2*rx*rx*yk1+ry*ry;
		}
		printf("%d \t %f \t %f \t %d \t %d \t %d \t %d \t (%d,%d) \t(%d,%d) \n",k,p1k,p1k1,xk,xk1,yk,yk1,xk1,yk1,xk1+xc,yk1+yc);
		drawEllipse(xk1,yk1,xc,yc);
		xk=xk1;
		yk=yk1;
		p1k=p1k1;
		k++;		
	}while(2*rx*rx*yk>=2*ry*ry*xk);
	
	
	p2k=ry*ry*pow((xk+0.5),2)+rx*rx*pow((yk-1),2)-rx*rx*ry*ry;

	printf("\nRegion 2 \nk \t P2k \t\t P2k+1 \t\t xk \t xk+1 \t yk \t yk+1 \t At(0,0) \t At(xc,yc) \n");
	k=0;
	while(1)
	{
		
		if(p2k<=0)
		{
			xk1=xk+1;
			yk1=yk-1;
			p2k1=p2k+2*ry*ry*xk1-2*rx*rx*yk1+rx*rx;
		}
		else
		{
			xk1=xk;
			yk1=yk-1;
			p2k1=p2k-2*rx*rx*yk1+rx*rx;
		}
		printf("%d \t %f \t %f \t %d \t %d \t %d \t %d \t (%d,%d) \t(%d,%d) \n",k,p2k,p2k1,xk,xk1,yk,yk1,xk1,yk1,xk1+xc,yk1+yc);
		drawEllipse(xk1,yk1,xc,yc);
		xk=xk1;
		yk=yk1;
		p2k=p2k1;
		k++;	
		if(xk==rx && yk==0)
		{
			break;	
		}	
	}
	getch();
   closegraph();
   return 0;
	
}
