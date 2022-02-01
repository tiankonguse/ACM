#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char str0[5006];
short int map[5005][5005];
int min(int a,int b)
{
if(a>b)return b;
return a;	
}
int func(int l, int r) {
	if (map[l][r]!=-1) return map[l][r];
	if (l>=r) return 0;
	if (str0[l]==str0[r]) return map[l][r]=func(l+1,r-1);
	return map[l][r]=1+min(func(l+1,r), func(l,r-1));
}


int main()
{
	 int n;
	 scanf("%d",&n);
	memset(map,-1,sizeof(map));
		scanf("%s",str0);
		printf("%d\n",func(0,n-1));	
		getchar();getchar();	
return 0;    
}
