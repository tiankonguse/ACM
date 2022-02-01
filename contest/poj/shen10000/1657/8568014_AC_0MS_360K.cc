#include<stdio.h>
#include<stdlib.h>


#include<math.h>


int main()
{
	char a[4],b[4];	
	int h,x,y,i;
	scanf("%d",&h);
	
	getchar();
	for(i=0;i<h;i++)
	{
		
	scanf("%s%s",a,b);
	x=abs(a[0]-b[0]);
	y=abs(a[1]-b[1]);

	//wang 
	
	//*********************************
	printf("%d ",x>y?x:y);	
	//**********************************


	//hou
	//**********************************
	if(x==0&&y==0)printf("0 ");
	else if(x==0||y==0||x==y)printf("1 ");
	else printf("2 ");
	//**********************************
	
	
	//jv
	//************************************
	if(x==0&&y==0)printf("0 ");
	else if(x==0||y==0)printf("1 ");
	else printf("2 ");
	
	//************************************
	
	
	//xiang
	//************************************
	if(x==0&&y==0)printf("0\n");
	else if(x==y)printf("1\n");
	else
		if((x+y)%2==0)printf("2\n");
		else printf("Inf\n");
	//************************************
		
	}
	
	
//getchar();getchar();

return 0;	

}
