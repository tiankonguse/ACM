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
    int i;
    LL res=x;

    LL _max = (LL)(sqrt(x*1.0)+1);
    for(i=2; i<_max; ++i) {
        if(x%i==0) {
            res = res/i*(i-1);
            while(x%i==0)x/=i;
        }
    }
    if(x>1)res = res/x*(x-1);
    return res;
}

LL powMod(LL x,LL y,LL p) {

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
LL getPowTop(int pos, LL mod) {
	LL a, b = 1;
	for(int i = n-1; i >= pos; i--) {
		a = str[i];
		LL ret = 1;
		for(; b; a *= a, b >>= 1) {
			if(b & 1)
				ret *= a;
			if(ret >= mod || a >= mod){
				return -1;
			}
		}
		b = ret;
	}
	return b;
}

LL powMod(int pos,LL mod) {
    if(pos == n)return 1;
    //LL tmp = mod/gcd(str[pos],mod);
    LL phi_mod = _euler(mod);
    LL b = getPowTop(pos+1,phi_mod);
    if(b == -1){
        b = powMod(pos+1, phi_mod) % phi_mod + phi_mod;
    }
    return powMod(str[pos], b , mod);
}


int main() {
    LL p;


    int cas;
    cin>>cas;
    while(cas--) {
        cin>>n>>p;
        bool ok = false;
        for(int i=0; i<n; i++) {
            cin>>str[i];
			if(str[i] == 1)ok = true;
			if(ok)i--,n--;
        }
        cout<<powMod(0,p)<<endl;
    }

    return 0;
}
