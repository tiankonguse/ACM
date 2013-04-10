#include<stdio.h>
char map[26]={0,1,7,8,5,8,28,38,37,64,87,127};
int main(){char n;while(scanf("%d",&n)!=EOF){if(n<=12){putchar('0');continue;}printf("%d\n",1+map[n-13]);}
return 0;}
