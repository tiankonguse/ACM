#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#define MAXN (1<<12)
using namespace std;
int main(){
    int s,d,res;
    while(~scanf("%d%d",&s,&d)){
        if(s*4-d<0)res=s*10-2*d;
        else if(s*3-d*2<0)res=s*8-d*4;
        else if(s*2-d*3<0)res=s*6-d*6;
        else if(s-d*4<0)res=s*3-d*9;
        else res=-1;
        if(res<0)printf("Deficit\n");
        else printf("%d\n",res);
    }
    return 0;
}
