#include<graphics.h>
#include<stdio.h>
#include<math.h>
double cp[2][50];
double fact(double c)
{
	if(c==1 || c==0)
		return 1;
	else 
		return (c*fact(c-1)); 
	
}
double C(double a,double b)
{
	return fact(a)/(fact(b)*fact(a-b));
}

double x(double u,int n)
{
	double value=0;
	double r=0;
	for(int i=0;i<=n;i++)
	{
		value+=cp[0][i]*C(n,r)*pow(u,r)*pow(1-u,n-r);
		r++;
	}
	return value;
}
double y(double u,int n)
{
	double value=0;
	double r=0;
	for(int i=0;i<=n;i++)
	{
		value+=cp[1][i]*C(n,r)*pow(u,r)*pow(1-u,n-r);
		r++;
	}
	return value;
}
int main()
{
	initwindow(1500,750,"Windows BGI");
	outtextxy(10,5,"Lab no: 8(b)");
    outtextxy(10,25,"Name: Dipesh Shrestha");
    outtextxy(10,45,"Roll No: 08");
    settextstyle(11,0,1);
	int cn,n;
	char arr[50];
	printf("Enter the no of control points: ");
	scanf("%d",&cn);
	n=cn-1;
	printf("Enter the control points: ");
	for(int j=0 ;j<cn;j++)
	{
		for(int i=0;i<2;i++)
		{
			scanf("%lf", &cp[i][j]);
		
		}
		sprintf(arr,"(%d,%d)",int(cp[0][j]),int(cp[1][j]));
		outtextxy(cp[0][j],cp[1][j]+20,arr);
	}
	printf("\t\t x(u) \t\t y(u) \n");
	for(double u=0;u<=1;u=u+0.2)
	{
		if(u<1)
		{
			line(x(u,n),y(u,n),x(u+0.2,n),y(u+0.2,n));
		}
		printf("u = %lf \t %lf \t %lf\n",u,x(u,n),y(u,n));
	}
	getch();

}
