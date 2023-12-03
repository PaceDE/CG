#include<graphics.h>
#include<stdio.h>
#include<math.h>
double rotate(double p[2][1],double p_[2][1])
{
	double degree=30;
	double theta= (degree*M_PI)/180;
	double m[2][2]={{cos(theta),-sin(theta)},{sin(theta),cos(theta)}};
		
	for (int i=0;i<2;i++)
	{
		for (int j=0;j<1;j++)
		{
			p_[i][j] =0;
			for (int k=0;k<2;k++)
			{
				p_[i][j] += m[i][k] * p[k][j];
			}
		
		}
	}	
}
int main()
{
	initwindow(1500,750,"Windows BGI");
   	outtextxy(10,5,"Lab no: 5(b)");
   	outtextxy(10,20,"Name: Dipesh Shrestha");
   	outtextxy(10,35,"Roll No: 08");
   	
   	settextstyle(11,0,1);
   	
   	
	double l[2][1],r[2][1],l_[2][1],r_[2][1];
	char arr[50];
	printf("Enter the left end point: ");
	scanf("%lf %lf",&l[0][0],&l[1][0]);	
	printf("Enter the right end point: ");
	scanf("%lf %lf",&r[0][0],&r[1][0]);
	rotate(l,l_);
	rotate(r,r_);
		
	setcolor(10);
   	outtextxy(l[0][0]+100,l[1][0]+10,"Object");
	line(l[0][0],l[1][0],r[0][0],r[1][0]);
	sprintf(arr,"(%d,%d)",int(l[0][0]),int(l[1][0]));
	outtextxy(l[0][0],l[1][0]-20,arr);
	sprintf(arr,"(%d,%d)",int(r[0][0]),int(r[1][0]));
	outtextxy(r[0][0],r[1][0]-20,arr);
	
	setcolor(14);
   	outtextxy(l_[0][0]+100,l_[1][0]+10,"Image");
	line(l_[0][0],l_[1][0],r_[0][0],r_[1][0]);
	sprintf(arr,"(%d,%d)",int(l_[0][0]),int(l_[1][0]));
	outtextxy(l_[0][0],l_[1][0]-20,arr);
	sprintf(arr,"(%d,%d)",int(r_[0][0]),int(r_[1][0]));
	outtextxy(r_[0][0],r_[1][0]-20,arr);
	
	
	getch();	
}


