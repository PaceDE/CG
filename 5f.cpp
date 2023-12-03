#include<graphics.h>
#include<stdio.h>
#include<math.h>
int transform(double s[2][2], int p[2][1],int p_[2][1])
{
		
	for (int i=0;i<2;i++)
	{
		for (int j=0;j<1;j++)
		{
			p_[i][j] =0;
			for (int k=0;k<2;k++)
			{
				p_[i][j] +=s[i][k] * p[k][j];
			}
		
		}
	}	
}
void drawRec(int lt_[2][1],int rt_[2][1],int rb_[2][1],int lb_[2][1])
{
	char arr[50];
	line(lb_[0][0],lb_[1][0],rb_[0][0],rb_[1][0]);
	line(rb_[0][0],rb_[1][0],rt_[0][0],rt_[1][0]);
	line(rt_[0][0],rt_[1][0],lt_[0][0],lt_[1][0]);
	line(lt_[0][0],lt_[1][0],lb_[0][0],lb_[1][0]);
	sprintf(arr,"(%d,%d)",lt_[0][0],lt_[1][0]);
	outtextxy(lt_[0][0]-60,lt_[1][0]-15,arr);	
	sprintf(arr,"(%d,%d)",rb_[0][0],rb_[1][0]);
	outtextxy(rb_[0][0]+10,rb_[1][0]+5,arr);
}
int main()
{
	initwindow(1500,750,"Windows BGI");
   	outtextxy(10,5,"Lab no: 5(b)");
   	outtextxy(10,20,"Name: Dipesh Shrestha");
   	outtextxy(10,35,"Roll No: 08");  	
   	settextstyle(11,0,1);
   	
   	int lt[2][1],rb[2][1],lt_[2][1],rb_[2][1],lb_[2][1],rt_[2][1];
   	double Shx[2][2]={{1,2},{0,1}};
   	double Shy[2][2]={{1,0},{2,1}};
   	double Sh[2][2]={{1,2},{2,1}};
	char arr[50];
	printf("Enter the top left corner points of rectangle : ");
	scanf("%d %d",&lt[0][0],&lt[1][0]);	
	printf("Enter the right bottom corner points of rectangle : ");
	scanf("%d %d",&rb[0][0],&rb[1][0]);	
	int lb[2][1]={{lt[0][0]},{rb[1][0]}};
	int rt[2][1]={{rb[0][0]},{lt[1][0]}};

   	outtextxy(rb[0][0]-100,rb[1][0]+10,"Object");	
	rectangle(lt[0][0],lt[1][0],rb[0][0],rb[1][0]);
	sprintf(arr,"(%d,%d)",lt[0][0],lt[1][0]);
	outtextxy(lt[0][0]-60,lt[1][0]-15,arr);
	sprintf(arr,"(%d,%d)",rb[0][0],rb[1][0]);
	outtextxy(rb[0][0]+10,rb[1][0],arr);
		
	setcolor(14);
   	transform(Shx,lt,lt_);
	transform(Shx,rb,rb_);
	transform(Shx,lb,lb_);
	transform(Shx,rt,rt_);
	drawRec(lt_,rt_,rb_,lb_);
	outtextxy(rb_[0][0]-100,rb_[1][0]+10,"X-shearing");
			
	setcolor(8);
   	transform(Shy,lt,lt_);
	transform(Shy,rb,rb_);
	transform(Shy,lb,lb_);
	transform(Shy,rt,rt_);
	drawRec(lt_,rt_,rb_,lb_);
	outtextxy(rb_[0][0]-100,rb_[1][0]+10,"Y-shearing");

	setcolor(10);
	transform(Sh,lt,lt_);
	transform(Sh,rb,rb_);
	transform(Sh,lb,lb_);
	transform(Sh,rt,rt_);
	drawRec(lt_,rt_,rb_,lb_);	
	outtextxy(rb_[0][0]-100,rb_[1][0]+10,"XY-shearing");
	getch();	
}


