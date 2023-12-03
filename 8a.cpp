#include<stdio.h>
#include<graphics.h>
#include<math.h>
struct edges
{
 int v1[2];
 int v2[2];
 int surface[2];  
};
int main()
{
	initwindow(1500,750,"Windows BGI");
	outtextxy(10,5,"Lab no: 8(a)");
    outtextxy(10,25,"Name: Dipesh Shrestha");
    outtextxy(10,45,"Roll No: 08");
    settextstyle(11,0,1);
    
    int n,vn,sn;
    char arr[50];
    printf("Enter the no of edges, vertices and surface: ");
    scanf("%d %d %d",&n,&vn,&sn);  
    struct edges e[n];
    
    printf("Enter the vertices and surface associated with edges: \n");
    for(int i=0;i<n;i++)
    {
    	sprintf(arr,"%d",i+1);
    	scanf("%d %d %d %d %d %d",&e[i].v1[0],&e[i].v1[1],&e[i].v2[0],&e[i].v2[1],&e[i].surface[0],&e[i].surface[1]);
	}
	for(int i=0;i<n;i++)
    {
    	line(e[i].v1[0],e[i].v1[1],e[i].v2[0],e[i].v2[1]);
    	sprintf(arr,"(%d,%d)",e[i].v1[0],e[i].v1[1]);
		outtextxy(e[i].v1[0]+10,e[i].v1[1]-10,arr);
		sprintf(arr,"(%d,%d)",e[i].v2[0],e[i].v2[1]);
		outtextxy(e[i].v2[0]+10,e[i].v2[1]-10,arr);
	}
	
	printf("\n Vertex table \n");
	int temp[12];
	int x=0,y=0,z=1,flag;
	int k,l;
	for(int i=0;i<vn;i++)
	{
		 	flag=1;
		printf("V%d : ",i+1);
	
		for(k=0,l=1;k<12;k=k+2,l=l+2)
		{
			if(e[i].v1[0]==temp[k] && e[i].v1[1]==temp[l])
			{
					flag=0;
					break;
			}	
		}	
		if(flag==1)
		{
			printf("(%d,%d)",e[i].v1[0],e[i].v1[1]);
			temp[y]=e[i].v1[0];
			temp[z]=e[i].v1[1];
			y+=2;
			z+=2;
			printf("\n");
			continue;
		}
		flag=1;
		for(k=0,l=1;k<12;k=k+2,l=l+2)
		{
			if(e[i].v2[0]==temp[k] && e[i].v2[1]==temp[l])
			{
					flag=0;
					break;
			}
		
		}	
		if(flag==1)
		{
			printf("(%d,%d)",e[i].v2[0],e[i].v2[1]);
			temp[y]=e[i].v2[0];
			temp[z]=e[i].v2[1];
			y+=2;
			z+=2;
		}
		printf("\n");
	}

	printf("\n Edge table \n");
	for(int i=0;i<n;i++)
	{
		printf("E%d: (%d,%d) and (%d,%d) \n",i+1,e[i].v1[0],e[i].v1[1],e[i].v2[0],e[i].v2[1]);
	}
	
	printf("\n Surface table \n");
	for(int i=0;i<sn;i++)
	{
		printf("S%d : ",i+1);
		for(int j=0;j<n;j++)
		{
			if(e[j].surface[i]==1)
			{
				printf("E%d \t",j+1);
			}
		}
		printf("\n");	
	} 
	getch();
}
/* 200 200 100 500 1 0
100 500 180 400 1 0
200 200 180 400 1 1
180 400 300 600 0 1
300 600 400 400 0 1
200 200 400 400 0 1*/

