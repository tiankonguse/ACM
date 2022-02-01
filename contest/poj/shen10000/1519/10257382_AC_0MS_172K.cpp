#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int root(int n){
    return n?(n+8)%9+1:0;
}

int main()
{
int n;
char str[10000];
while(scanf("%s",&str),str[0]^'0'){
	n=0;
	for(int i=0;str[i];i++)n+=str[i]-'0';
printf("%d\n",root(n));	
}
return 0;
}
