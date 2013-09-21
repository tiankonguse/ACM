/*************************************************************************
    > File Name: C.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/4/30 18:59:00
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<cmath>
#include<map>
#include<queue>
#include<stack>
#include<functional>
#include<algorithm>
using namespace std;
typedef long long LL;
LL str[30];
int n;

LL gcd(LL a,LL b) {
    if(b==0)return a;
    return gcd(b,a%b);
}

LL _euler(LL x) {
//    int i;
    LL res=x;
//    LL _max = (LL)(sqrt(x*1.0)+1);
    for(int i=2; i*i<=x; i+= (i==2)?1:2) {
        if(x%i==0) {
            res = res/i*(i-1);
            while(x%i==0)x/=i;
        }
    }
    if(x>1)res = res/x*(x-1);
    return res;
}

LL f(LL x,LL y,LL p) {

    LL a=1,b=x%p;
    if(p<=2||x<2)return x;
    while(y) {
        if(y&1)a=a*b%p;
        y>>=1;
        b=b*b%p;
    }
    return a;
}

//abc mod m = abc mod n mod m, where n = (m)


LL get(int pos,LL mod) {
    if(pos == n)return 1;
    LL tmp = mod/gcd(str[pos],mod);
    tmp = get(pos+1,_euler(tmp));
    //cout<<pos<<" "<<tmp<<" "<<mod<<endl;
    return f(str[pos],tmp,mod);
}


int main() {
    LL p;
p = 1;
for(int i=1;i<10;i++){
    cout<<p<<endl;
    p = p*6%20;
}
    int cas;
    cin>>cas;
    while(cas--) {
        cin>>n>>p;
        bool ok=false;
        for(int i=0; i<n; i++) {
            cin>>str[i];
        }
        cout<<get(0,p)<<endl;
    }

    return 0;
}
