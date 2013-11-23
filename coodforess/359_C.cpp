#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<cmath>
#include<stack>
#include<algorithm>
#include<functional>
#include<stdarg.h>
using namespace std;

#ifdef __int64
    typedef __int64 LL;
#else
    typedef long long LL;
#endif

LL str[300100];
LL x,n;
LL MOD = 1000000007;

LL muti_mod(LL a,LL b,LL c) {
    a%=c;
    b%=c;
    LL ret=0;
    while (b) {
        if (b&1) {
            ret+=a;
            if (ret>=c) ret-=c;
        }
        a<<=1;
        if (a>=c) a-=c;
        b>>=1;
    }
    return ret;
}

LL pow_mod(LL a,LL b,LL c) {
    LL ret = 1;
    for(a%=c; b; b>>=1,a=muti_mod(a,a,c)) {
        if(b&1)ret = muti_mod(ret,a,c);
    }
    return ret;
}

LL gcd(LL x,LL y) {
    if(!x || !y)return x?x:y;
    for(LL t; t=x%y; x=y,y=t);
    return y;
}

int main() {
    int i;
    LL mod = 0,ans,k,_ans,_g;
    while(~scanf("%lld%lld",&n,&x)) {
        for(i=0; i<n; i++) {
            scanf("%lld",&str[i]);
        }
        sort(str,str+n);
        mod = 0;
        for(i=0; i<n-1; i++) {
            mod += str[i];
        }
        ans = pow_mod(x,mod,MOD);
        k = 0;
        _g = str[n-1];
        LL _num;
        LL _k;
        LL num;
        for(i=n-1; i>=0; ) {
            if(_g == str[i]) {
                k++;
                i--;
            } else {
                if(k ==0 || k%x != 0) {
                    break;
                } else {
                    num = 0;
                    _k = k;
                    while(_k%x == 0) {
                        num++;
                        _k /= x;
                    }

                    if(num >= _g - str[i]) {
                        _ans = pow_mod(x,_g - str[i],MOD);//不需要mod 肯定小于 mod
                        k /= _ans;
                        _g = str[i];
                        ans = (ans * _ans) % MOD;
                    }else{
                        _ans = pow_mod(x,num,MOD);//不需要mod 肯定小于 mod
                        k /= _ans;
                        _g -= num;
                        ans = (ans * _ans) % MOD;
                    }
                }
            }
        }

        if(k >0 && k % x == 0) {
            num = 0;
            _k = k;
            while(_k > 0 && _k%x == 0) {
                num++;
                _k /= x;
            }
            _ans = pow_mod(x,min(num,_g),MOD);//不需要mod 肯定小于 mod
            ans = (ans * _ans) % MOD;
        }

        printf("%lld\n",ans);

    }



    return 0;
}

