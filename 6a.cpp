#include<graphics.h>
#include<stdio.h>
#include<math.h>
int transform(double M[3][3], int p[3][1],int p_[3][1])
{
		
	for (int i=0;i<3;i++)
	{
		for (int j=0;j<1;j++)
		{
			p_[i][j] =0;
			for (int k=0;k<3;k++)
			{
				p_[i][j] +=M[i][k] * p[k][j];
			}
		
		}
	}	
}
int main()
{
	initwindow(1500,750,"Windows BGI");
   	outtextxy(10,5,"Lab no:6(a)");
   	outtextxy(10,20,"Name: Dipesh Shrestha");
   	outtextxy(10,35,"Roll No: 08");   	
   	settextstyle(11,0,1);  	
   	double XWmin, YWmin, XWmax, YWmax,XVmin, YVmin, XVmax, YVmax;
   	int A[3][1], B[3][1], C[3][1], A_[3][1], B_[3][1], C_[3][1];
	double Sx,Sy,tx,ty;  
	char arr[50];
	printf("Enter the Bottom left corner and Top right corner points of WindowPort : ");
	scanf("%lf %lf %lf %lf",&XWmin, &YWmax, &XWmax, &YWmin);	
	printf("Enter the Bottom left corner and Top right corner points of ViewPort : ");
	scanf("%lf %lf %lf %lf",&XVmin, &YVmax, &XVmax, &YVmin);	
	Sx = (XVmax-XVmin)/(XWmax-XWmin);
	Sy = (YVmax-YVmin)/(YWmax-YWmin);
	tx = (XWmax*XVmin - XWmin*XVmax)/(XWmax-XWmin);
	ty = (YWmax*YVmin - YWmin*YVmax)/(YWmax-YWmin);
	double M[3][3]={{Sx,0,tx},{0,Sy,ty},{0,0,1}};	
	printf("Enter the three points of Triangle: ");
	scanf("%d %d %d %d %d %d", &A[0][0], &A[1][0], &B[0][0], &B[1][0], &C[0][0], &C[1][0]);
	A[2][0]=1; B[2][0]=1; C[2][0]=1;


	outtextxy(A[0][0]+10, A[1][0]+70,"Window Port Coordinate");
	line(A[0][0], A[1][0], B[0][0], B[1][0]);
	sprintf(arr,"(%d,%d)",A[0][0],A[1][0]);
	outtextxy(A[0][0],A[1][0]-15,arr);
	line(B[0][0], B[1][0], C[0][0], C[1][0]);
	sprintf(arr,"(%d,%d)",B[0][0],B[1][0]);
	outtextxy(B[0][0]-60,B[1][0],arr);
	line(C[0][0], C[1][0], A[0][0], A[1][0]);
	sprintf(arr,"(%d,%d)",C[0][0],C[1][0]);
	outtextxy(C[0][0]+10,C[1][0],arr);

   	transform(M,A,A_);
   	transform(M,B,B_);
   	transform(M,C,C_);
	
	setcolor(14);
	
   	outtextxy(A_[0][0]+10, A_[1][0]+40,"Viewport Coordinates");
   
	line(A_[0][0], A_[1][0], B_[0][0], B_[1][0]);
	sprintf(arr,"(%d,%d)",A_[0][0],A_[1][0]);
	outtextxy(A_[0][0],A_[1][0]-25,arr);
	line(B_[0][0], B_[1][0], C_[0][0], C_[1][0]);
	sprintf(arr,"(%d,%d)",B_[0][0],B_[1][0]);
	outtextxy(B_[0][0]-60,B_[1][0],arr);
	line(C_[0][0], C_[1][0], A_[0][0], A_[1][0]);
	sprintf(arr,"(%d,%d)",C_[0][0],C_[1][0]);
	outtextxy(C_[0][0]+10,C_[1][0],arr);	
	getch();	
}

 /*100 300 300 100
Enter the Bottom left corner and Top right corner points of ViewPort : 50 150 150 50
Enter the three points of Triangle: 200 120 150 200 250 250*/
