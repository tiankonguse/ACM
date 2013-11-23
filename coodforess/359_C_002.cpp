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
typedef long long LL;

LL str[300100];
LL x,n;
LL MOD = 1000000007;

LL muti_mod(LL a,LL b,LL c){
	a%=c;b%=c;
    LL ret=0;
    while (b){
        if (b&1){
            ret+=a;
            if (ret>=c) ret-=c;
        }
        a<<=1;
        if (a>=c) a-=c;
        b>>=1;
    }
    return ret;
}

LL pow_mod(LL a,LL b,LL c){
	LL ret = 1;
	for(a%=c;b;b>>=1,a=muti_mod(a,a,c)){
        if(b&1)ret = muti_mod(ret,a,c);
	}
	return ret;
}

LL gcd(LL x,LL y){
	if(!x || !y)return x?x:y;
	for(LL t;t=x%y;x=y,y=t);
	return y;
}

LL get(int k, int x, int n){
    LL ans = 1;
    LL t = gcd(x,k);
    if(t != 1 && n > 0){
        ans = (ans* t) % MOD;
        k /= t;
        n--;
        t = gcd(x,k);
    }
    return ans;
}

int main() {
    int i;
    printf("%lld\n",pow_mod(3,31,MOD));
    LL mod = 0,ans,k,_ans,_x,_j;
    while(~scanf("%lld%lld",&n,&x)){
        for(i=0;i<n;i++){
            scanf("%lld",&str[i]);
        }
        sort(str,str+n);
        mod = 0;
        for(i=0;i<n-1;i++){
                mod += str[i];
        }
        ans = pow_mod(x,mod,MOD);
        k = 1;
        for(i=n-2;i>=0;i--){
            if(str[i+1] == str[i]){
                k++;
            }else{
                break;
            }
        }
//        int j = 0;
//        while(i >= 0){
//            _x = str[j];
//            if(_x == _j)
//        }

        LL tmp =gcd(x,k);
        _ans = get(tmp,x,_x);
            ans = (ans * _ans) % MOD;

        printf("%lld\n",ans);

    }



    return 0;
}

