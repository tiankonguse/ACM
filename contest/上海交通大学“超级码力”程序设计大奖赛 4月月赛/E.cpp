/*************************************************************************
    > File Name: E.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/4/30 19:00:27
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<functional>
#include<algorithm>
using namespace std;
typedef long long LL;LL n,p;
LL f(LL x,LL y)
{

    LL a=1,b=x%p;
    if(p<=2||x<2)return x;
    while(y)
    {
        if(y&1)a=a*b%p;
        y>>=1;
        b=b*b%p;
    }
    return a;
}



int main() {
    LL a1,a2;
     int cas;
   cin>>cas;

    while(cas--){
        cin>>n>>p;
        cin>>a1>>a2;
        cout<<f(a1,a2)<<endl;
    }

    return 0;
}
