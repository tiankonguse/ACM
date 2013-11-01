#include<stdio.h>
#include<string.h>
int str0[8][2]={{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1},{-2,1},{-1,2}};
char strx[30],stry[30];
bool str1[10][10];
int n=0,m=0;

void cout()
{
for(int i=0;i<=n*m-1;i++)
{
printf("%c%c",stry[i],strx[i]);	
}	
printf("\n");
	
	
}

int fun(int num,int x,int y)
{
	int p1,p2;
	if(num==n*m-1){strx[num]=x+'1';stry[num]=y+'A';return 1;}	
	
	for(int i=0;i<8;i++)
	{
		p1=x+str0[i][0];	
		p2=y+str0[i][1];	
		
		if(p1<0||p2<0||p1>=n||p2>=m||str1[p1][p2]){continue;}	
		
		str1[p1][p2]=true;
		strx[num]=x+'1';
		stry[num]=y+'A';
		if(fun(num+1,p1,p2))return 1;
		str1[p1][p2]=false;
		strx[num]=0;
		stry[num]=0;
	
	}	
	return 0;
}


int main()
{
int w;
scanf("%d",&w);

for(int i=1;i<=w;i++)
{
	if(i!=1)printf("\n");
	scanf("%d%d",&n,&m);
	printf("Scenario #%d:\n",i);	
	
	if(n==1&&m==1){printf("A1\n");continue;}
	
	if(n<=2||m<=2){printf("impossible\n");continue;}
	
	memset(str1,false,sizeof(str1));
	
		str1[0][0]=true;	
	if(fun(0,0,0))cout();
	else printf("impossible\n");
		
}

	
	
return 0;	
}
