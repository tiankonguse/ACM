#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
int main(){
    int b,w,t;
    while(~scanf("%d%d",&b,&w)){
        if(b==0 && w==0)printf("Impossible\n");
        else{
            if(b==w)t=b+w;
            else if(b>w)t=w+w+1;
            else t=b+b+1;
            int l=(int)sqrt(1.0*t);
            printf("%d\n",l);
        }
    }
    return 0;
}
