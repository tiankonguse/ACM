#include<stdio.h>
#include<string.h>
char str[730][730];
int map[7]={1,3,9,27,81,243,729};
void fun(int l,int y,int x)
{
int i,j,y0=y;
for(i=0;i<l;i++,x++)
for(j=0,y=y0;j<l;j++,y++)	
	str[x][y]=str[i][j];
}
int main()
{
	memset(str,' ',sizeof(str));
	str[0][0]='X';
	int len;
	for(int i=0;i<6;i++)
	{
		len=map[i]+map[i];
		fun(map[i],len,0);	
		fun(map[i],map[i],map[i]);	
		fun(map[i],0,len);	
		fun(map[i],len,len);	
	}
	int n;
	char str2[730][730];
	while(scanf("%d",&n),n+1)
	{
		n--;
		for(int i=0;i<map[n];i++)
		for(int j=0;j<map[n];j++)
			str2[i][j]=str[i][j];
		for(int i=0;i<map[n];i++)
		for(int j=map[n]-1;;j--)
		{
			if(str2[i][j]!=' '){str2[i][j+1]='\0';printf("%s\n",str2[i]);break;}	
		}	
		printf("-\n");	
	}
return 0;	
}