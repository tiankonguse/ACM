#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char str0[5006];
int map[5001][5001];
int *p1,*p2;

void fun(int a,int b)
{

	if((a==b)||(a==b+1))
	{
		if(str0[a]==str0[b]){map[a][b]=0;return ;}	
		map[a][b]=1;return ;	
	}	
	
	if(str0[a]==str0[b])
	{
		if(map[a+1][b-1]==-1)fun(a+1,b-1);
	    map[a][b]=map[a+1][b-1];
		return 	;
	}
	p1=&map[a][b-1];
	p2=&map[a+1][b];
	if((*p1)==-1){fun(a,b-1);}	
	if((*p2)==-1){fun(a+1,b);}	
	map[a][b]=1+((*p1)>(*p2)?(*p2):(*p1));	
		return ;
}


int main()
{
	 int n;
	 while(scanf("%d",&n)!=EOF)   
	{
		memset(map,-1,sizeof(map));
		scanf("%s",str0);
		fun(0,n-1);
		printf("%d\n",map[0][n-1]);		
	}
return 0;    
}
