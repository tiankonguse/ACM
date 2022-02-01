#include<stdio.h>
#include<string.h>
#include<stdlib.h>
__int64 root(__int64 n){
    return n?(n+8)%9+1:0;
}

int main()
{
__int64 n;
while(scanf("%I64d",&n),n)printf("%I64d\n",root(n));
return 0;
}
