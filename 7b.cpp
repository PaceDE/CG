#include<graphics.h>
#include<stdio.h>
#include<math.h>
double rotate(double p[4][1],double p_[4][1])
{
	double degree=45;
	double theta= (degree*M_PI)/180;
	double m[4][4]={{cos(theta),-sin(theta),0,0},{sin(theta),cos(theta),0,0},{0,0,1,0},{0,0,0,1}};
		
	for (int i=0;i<4;i++)
	{
		for (int j=0;j<1;j++)
		{
			p_[i][j] =0;
			for (int k=0;k<4;k++)
			{
				p_[i][j] += m[i][k] * p[k][j];
			}
		
		}
	}	
}
int main()
{
	initwindow(1500,750,"Windows BGI");
	outtextxy(10,5,"Lab no: 7(b)");
    outtextxy(10,25,"Name: Dipesh Shrestha");
    outtextxy(10,45,"Roll No: 08");
    settextstyle(11,0,1);
    double lt[4][1],rb[4][1],lt_[4][1],rb_[4][1],depth;
    printf("Enter the top left corner of the face of cube: ");
    scanf("%lf %lf",&lt[0][0],&lt[1][0]);
    printf("Enter the bottom right corner of the face of cube: ");
    scanf("%lf %lf",&rb[0][0],&rb[1][0]);
    depth=50;
    lt[2][0]=depth;
    lt[3][0]=1;
    rb[2][0]=depth;
    rb[3][0]=1;

    bar3d(lt[0][0],lt[1][0],rb[0][0],rb[1][0],depth,1);
    outtextxy((lt[0][0]+rb[0][0])/2,rb[1][0]+10,"Object");
    rotate(lt,lt_);
	rotate(rb,rb_);
    
    bar3d(lt_[0][0],lt_[1][0],rb_[0][0],rb_[1][0],depth,1);
    outtextxy((lt_[0][0]+rb_[0][0])/2,rb_[1][0]+10,"Image");
	getch();	
}

// Input 700 100
 //  	 900 150


