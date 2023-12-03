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
	double s[3][3]={{1.0/3,0,0},{0,1.0/3,0},{0,0,1}};
	double t1[3][3]={{1,0,110},{0,1,120},{0,0,1}};	
	double r[3][3]={{cos(theta),-sin(theta),0},{sin(theta),cos(theta),0},{0,0,1}};
	double t2[3][3]={{1,0,-110},{0,1,-120},{0,0,1}};	
	double t3[3][3]={{1,0,100},{0,1,100},{0,0,1}};	

	double m1[3][3],m[3][3];	
	mul(s,t1,m1);
	mul(m1,r,m);
	mul(m,t2,m1);
	mul(m1,t3,m);
	
	outtextxy(600,10,"Composite matrix : ");
	
	char arr[50];
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			sprintf(arr,("%lf"),m[i][j]);
			outtextxy(600+100*j,30+20*i,arr);
		}
	}
		
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
	outtextxy(10,5,"Lab no: 5(g ii)");
    outtextxy(10,25,"Name: Dipesh Shrestha");
    outtextxy(10,45,"Roll No: 08");
    
    double a[3][1],b[3][1],c[3][1],a_[3][1],b_[3][1],c_[3][1];	
	char arr[50];
	printf("Enter the point A : ");
	scanf("%lf %lf",&a[0][0],&a[1][0]);	
	printf("Enter the point B : ");
	scanf("%lf %lf",&b[0][0],&b[1][0]);
	printf("Enter the point C : ");
	scanf("%lf %lf",&c[0][0],&c[1][0]);
	a[0][2]=1;
	b[0][2]=1;
	c[0][2]=1;	
	
	setcolor(10);
   	outtextxy(b[0][0]+20,b[1][0]+20,"Object");
	line(a[0][0],a[1][0],b[0][0],b[1][0]);
	line(b[0][0],b[1][0],c[0][0],c[1][0]);
	line(c[0][0],c[1][0],a[0][0],a[1][0]);  	
	printf("\nObject: A(%d,%d)  B(%d,%d)  C(%d,%d) \n",int(a[0][0]),int(a[1][0]), int(b[0][0]),int(b[1][0]), int(c[0][0]),int(c[1][0]));	
	 
	transform(a,a_);
	transform(b,b_);
	transform(c,c_);
	
	setcolor(14);
	outtextxy(b_[0][0]+20,b_[1][0]+20,"Image");
	line(a_[0][0],a_[1][0],b_[0][0],b_[1][0]);
	line(b_[0][0],b_[1][0],c_[0][0],c_[1][0]);
	line(c_[0][0],c_[1][0],a_[0][0],a_[1][0]);   
	printf("\nImage: A`(%d,%d)  B`(%d,%d)  C`(%d,%d)",int(a_[0][0]),int(a_[1][0]), int(b_[0][0]),int(b_[1][0]), int(c_[0][0]),int(c_[1][0]));
	getch();	
}


