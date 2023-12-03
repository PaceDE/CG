#include<graphics.h>
#include<stdio.h>
#include<math.h>

int main()
{
	initwindow(1500,750,"Windows BGI");
   	outtextxy(500,5,"Lab no:6(b)");
   	outtextxy(500,20,"Name: Dipesh Shrestha");
   	outtextxy(500,35,"Roll No: 08");   	
   	settextstyle(11,0,1);  	  
   	int X[2], Y[2],T[2],B[2],R[2],L[2],Ro[4],Ra[4]; 
   	double XWmin, YWmin, XWmax, YWmax,X1[2],Y1[2],m;
	printf("Enter the Bottom left corner and Top right corner points of Clipping Window : ");
	scanf("%lf %lf %lf %lf",&XWmin, &YWmax, &XWmax, &YWmin);
	
	rectangle(XWmin,YWmin,XWmax,YWmax);
	printf("Enter the Two points of line: ");
	scanf("%d %d %d %d", &X[0], &Y[0], &X[1], &Y[1]);
	X1[0]=X[0];
	Y1[0]=Y[0];
	X1[1]=X[1];
	Y1[1]=Y[1];
	setcolor(14);
	rectangle(510,57,520,67);
	outtextxy(540,55,"Unclipped line");
	line(X[0],Y[0],X[1],Y[1]);
	printf("\nUnclipped line: %d %d %d %d \n",X[0],Y[0],X[1],Y[1]);
	setcolor(15);
	
	m=(1.0*Y[1]-Y[0])/(X[1]-X[0]);

	for(int i=0;i<2;i++)
	{
		if(YWmax - Y[i]>0)
	 		T[i]=0;
	 	else
	 		T[i]=1;
	 		
	 	if(Y[i]- YWmin>0)
	 		B[i]=0;
	 	else
	 		B[i]=1;
	 		
	 	if(XWmax - X[i]>0)
	 		R[i]=0;
	 	else
	 		R[i]=1;
	 	
		if(X[i]- XWmin>0)
	 		L[i]=0;
	 	else
	 		L[i]=1; 
	}
	int R1[4]={T[0],B[0],R[0],L[0]};
	int R2[4]={T[1],B[1],R[1],L[1]};
	
	
	for(int j=0;j<4;j++)
	{
		Ro[j]=R1[j] | R2[j];
	}

	if(Ro[0]==0 && Ro[1]==0 && Ro[2]==0 && Ro[3]==0)
	{
		outtextxy(300,500,"The line is completely inside the window");
		goto end;
	}
	else
	{
		for(int k=0;k<4;k++)
		{
			Ra[k]=R1[k] & R2[k];
		}
			for(int i=0;i<4;i++)

		
		if(Ra[0]!=0 && Ra[1]!=0 && Ra[2]!=0 && Ra[3]!=0)
		{
			outtextxy(300,500,"The line is completely outside the window");
			goto end;
		}
			
	}
	if(R1[0] != R2[0])
	{
		if(m>=0)
		{
			Y1[1]=YWmax;
			X1[1]=X[0]+(Y1[1]-Y[0])/m;
		}
		else
		{
			Y1[0]=YWmax;
			X1[0]=X[0]+(Y1[0]-Y[0])/m;
		}
	}
	if(R1[1] != R2[1])
	{
		if(m<0)
		{
			Y1[1]=YWmin;
			X1[1]=X[0]+(Y1[1]-Y[0])/m;
		}
		else
		{
			Y1[0]=YWmin;
			X1[0]=X[0]+(Y1[0]-Y[0])/m;
		}
	}
	if(R1[2] != R2[2])
	{
		X1[1]=XWmax;
		Y1[1]=Y[0]+m*(X1[1]-X[0]);		
	}
	if(R1[3] != R2[3])
	{
		X1[0]=XWmin;
		Y1[0]=Y[0]+m*(X1[0]-X[0]);		
	}
	
	setcolor(10);
	rectangle(510,77,520,87);
   	outtextxy(540,75,"Clipped Line");
   	line(X1[0],Y1[0],X1[1],Y1[1]);
	printf("\nClipped line: %lf %lf %lf %lf \n",X1[0],Y1[0],X1[1],Y1[1]);

	end:
	getch();	
}

