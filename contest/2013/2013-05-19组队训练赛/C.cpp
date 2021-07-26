
#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
//typedef __int64 LL;
const int mod = 1000000007;
LL _root(LL n){
    return n?(n+8)%9+1:0;
}
LL a[10005];
int main(){
    int i,j,n;
    a[0]=1;a[1]=2;
    for(i=1;i<=10000;i++)
    {
        a[i]=(a[i-1]*2)%mod;
    }
    while(scanf("%d",&n)!=EOF)
    {
        LL sum=0,tmp;
        for(i=1;i<=n;i++)
            scanf("%lld",&tmp),(sum += tmp)%=mod;
        cout<<a[n-1]*sum%mod<<endl;

    }
}

