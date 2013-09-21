
#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
LL _root(LL n){
    return n?(n+8)%9+1:0;
}
int main(){
    LL i,j,x;
    while(scanf("%lld",&x)!=EOF)
    {
        //if(x<10)
        printf("%lld\n",_root(x));
    }
}
