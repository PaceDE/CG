#include<graphics.h>
#include<stdio.h>
#include<math.h>
int main()
{
	int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    outtextxy(10,5,"Lab no: 2(b)");
    outtextxy(10,20,"Name: Dipesh Shrestha");
    outtextxy(10,35,"Roll No: 08");
	int x0,y0,xe,ye,dx,dy,inc1,inc2,pk,pk1,xk,yk,xk1,yk1;
	float m;
	printf("Enter the leftend point and right endpoint: ");
	scanf("%d %d %d %d",&x0,&y0,&xe,&ye);
	m=(float)(ye-y0)/(xe-x0);
	xk=x0;
	yk=y0;
	dx=abs(xe-x0);
	dy=abs(ye-y0);
	putpixel(xk,yk,15);
	if(fabs(m)<1)
	{
		inc1=2*dy;
		inc2=2*dy-2*dx;
		pk=2*dy-dx;
		printf("\nk \t Pk \t Pk+1 \t xk \t xk+1 \t yk \t yk+1 \t Plot \n");
		for(int i=0;i<dx;i++)
		{
			xk1=xk+1;
			if(pk<0)
			{
				yk1=yk;
				pk1=pk+inc1;
			}
			else
			{
				if(m>=0 )
				{
					yk1=yk+1;
				}
				else
				{
					yk1=yk-1;
				}
				pk1=pk+inc2;
			}
			
			printf("%d \t %d \t %d \t %d \t %d \t %d \t %d \t (%d,%d) \n",i,pk,pk1,xk,xk1,yk,yk1,xk1,yk1);
			putpixel(xk1,yk1,15);
			pk=pk1;
			xk=xk1;
			yk=yk1;
		}
		
	}
	
	else
	{
		inc1=2*dx;
		inc2=2*dx-2*dy;
		pk=2*dx-dy;
		printf("k \t Pk \t Pk+1 \t xk \t xk+1 \t yk \t yk+1 \t Plot \n");
		for(int i=0;i<dy;i++)
		{
			if(pk<0)
			{
				xk1=xk;
				pk1=pk+inc1;
			}
			else
			{
				xk1=xk+1;
				pk1=pk+inc2;
			}
			
			if(m>=0 )
				yk1=yk+1;
			else
				yk1=yk-1;

			printf("%d \t %d \t %d \t %d \t %d \t %d \t %d \t (%d,%d) \n",i,pk,pk1,xk,xk1,yk,yk1,xk1,yk1);
			putpixel(xk1,yk1,15);
			pk=pk1;
			xk=xk1;
			yk=yk1;
		}				
	}

   getch();
   closegraph();
   return 0;
	
}
