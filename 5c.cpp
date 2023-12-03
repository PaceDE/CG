#include<graphics.h>
#include<stdio.h>
#include<math.h>

double mul(	double a[3][3],double b[3][3],	double m[3][3])
{
	for (int i=0;i<3;i++)
	{
		for (int j=0;j<3;j++)
		{
			m[i][j] =0;
			for (int k=0;k<3;k++)
			{
				m[i][j] += a[i][k] * b[k][j];
			}
		}
	}
}
double transform(double p[3][1],double p_[3][1])
{
	double degree=-45;
	double theta= (degree*M_PI)/180;
	double t[3][3]={{1,0,120},{0,1,100},{0,0,1}};
	double r[3][3]={{cos(theta),-sin(theta),0},{sin(theta),cos(theta),0},{0,0,1}};
	double rt[3][3]={{1,0,-120},{0,1,-100},{0,0,1}};
	double m1[3][3],m[3][3];
	
	mul(t,r,m1);
	mul(m1,rt,m);
		
	for (int i=0;i<3;i++)
	{
		for (int j=0;j<1;j++)
		{
			p_[i][j] =0;
			for (int k=0;k<3;k++)
			{
				p_[i][j] += m[i][k] * p[k][j];
			}
		
		}
	}	
}
int main()
{
	initwindow(1500,750,"Windows BGI");
	outtextxy(10,5,"Lab no: 5(c)");
    outtextxy(10,20,"Name: Dipesh Shrestha");
    outtextxy(10,35,"Roll No: 08");
    
    settextstyle(11,0,1);
	double lt[3][1],rb[3][1],lt_[3][1],rb_[3][1],lb_[3][1],rt_[3][1];
	char arr[50];
	printf("Enter the top left corner points of rectangle : ");
	scanf("%lf %lf",&lt[0][0],&lt[1][0]);	
	printf("Enter the right bottom corner points of rectangle : ");
	scanf("%lf %lf",&rb[0][0],&rb[1][0]);
	lt[0][2]=1;
	rb[0][2]=1;
	double lb[3][1]={{lt[0][0]},{rb[1][0]},{1}};
	double rt[3][1]={{rb[0][0]},{lt[1][0]},{1}};
	
	setcolor(10);
   	outtextxy(lt[0][0]+100,rb[1][0]+10,"Object");
	rectangle(lt[0][0],lt[1][0],rb[0][0],rb[1][0]);	
	sprintf(arr,"(%d,%d)",int(lt[0][0]),int(lt[1][0]));
	outtextxy(lt[0][0],lt[1][0]-20,arr);
	sprintf(arr,"(%d,%d)",int(rb[0][0]),int(rb[1][0]));
	outtextxy(rb[0][0]+10,rb[1][0]-20,arr);

	transform(lt,lt_);
	transform(rb,rb_);
	transform(lb,lb_);
	transform(rt,rt_);
	
	setcolor(14);
   	outtextxy(lt_[0][0]+100,rb_[1][0]+10,"Image");
	line(lb_[0][0],lb_[1][0],rb_[0][0],rb_[1][0]);
	line(rb_[0][0],rb_[1][0],rt_[0][0],rt_[1][0]);
	line(rt_[0][0],rt_[1][0],lt_[0][0],lt_[1][0]);
	line(lt_[0][0],lt_[1][0],lb_[0][0],lb_[1][0]);
	sprintf(arr,"(%d,%d)",int(lt_[0][0]),int(lt_[1][0]));
	outtextxy(lt_[0][0]+15,lt_[1][0]-15,arr);
	sprintf(arr,"(%d,%d)",int(lb_[0][0]),int(lb_[1][0]));
	outtextxy(lb_[0][0]+15,lb_[1][0]-15,arr);	
	sprintf(arr,"(%d,%d)",int(rb_[0][0]),int(rb_[1][0]));
	outtextxy(rb_[0][0],rb_[1][0]-15,arr);
	sprintf(arr,"(%d,%d)",int(rt_[0][0]),int(rt_[1][0]));
	outtextxy(rt_[0][0],rt_[1][0]-15,arr);

	getch();	
	closegraph();
	return 0;
}


