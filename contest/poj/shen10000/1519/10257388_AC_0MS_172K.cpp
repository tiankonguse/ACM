#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int root(char *p){
	int n=0;
	for(int i=0;p[i];i++)n+=p[i]-'0';
    return n?(n+8)%9+1:0;
}

int main()
{
int n;
char str[10000];
while(scanf("%s",&str),str[0]^'0'){
printf("%d\n",root(str));	
}
return 0;
}
