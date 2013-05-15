#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<ctime>
#include<stack>
#include<queue>
#include<vector>
#include<cstdlib>
#include<algorithm>
#define PI acos(-1.0)
#define inf 0x3fffffff
#define maxn 100010
using namespace std;

typedef long long  LL;

vector<int>factor;
const int S=20;

LL gcd(LL x,LL y) {
    if(!x || !y)return x?x:y;
    for(LL t; t=x%y; x=y,y=t);
    return y;
}
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

LL pow_mod(LL x,LL n,LL mod){
  if (n==1) return x%mod;
    int bit[64],k=0;
    while (n){
        bit[k++]=n&1;n>>=1;
    }
    LL ret=1;
    for (k=k-1;k>=0;k--){
        ret=muti_mod(ret,ret,mod);
        if (bit[k]==1) ret=muti_mod(ret,x,mod);
    }
    return ret;
}

bool check(LL a,LL n,LL x,LL t) {
    LL ret=pow_mod(a,x,n),last=ret;
    for (int i=1; i<=t; i++) {
        ret=muti_mod(ret,ret,n);
        if (ret==1 && last!=1 && last!=n-1) return 1;
        last=ret;
    }
    if (ret!=1) return 1;
    return 0;
}
LL Pollard_rho(LL x,LL c) {
    LL i=1,x0=rand()%x,y=x0,k=2;
    while (1) {
        i++;
        x0=(muti_mod(x0,x0,x)+c)%x;
        LL d=gcd(y-x0,x);
        if (d!=1 && d!=x)return d;
        if (y==x0) return x;
        if (i==k)y=x0,k+=k;
    }
}
bool Miller_Rabin(LL n) {
    LL x=n-1,t=0;
    while ((x&1)==0) x>>=1,t++;
    bool flag=1;
    if (t>=1 && (x&1)) {
        for (int k=0; k<S; k++) { //s=20
            LL a=rand()%(n-1)+1;
            if (check(a,n,x,t)) {
                flag=1;
                break;
            }
            flag=0;
        }
    }
    if (!flag || n==2) return 0;
    return 1;
}
void findfac(LL n) {
    if (!Miller_Rabin(n)) {
        factor.push_back(n);//factor为一个向量
        return;
    }
    LL p=n;
    while (p>=n) p=Pollard_rho(p,rand() % (n-1) +1);
    findfac(p);
    findfac(n/p);
}


int main() {
//    freopen("out.txt","+w",stdout);
    srand((unsigned int )(time(NULL)));

    LL a;

    int k = 1;
    int num;
    int ans[11];
    for(a = 2; ; a++) {
        printf("%d\n",a);
        factor.clear();
        findfac(a);
        num =  factor.size();
        for(; k<=num; k++) {
            ans[k] = a;
            printf("k=%d a=%d\n",k,ans[k]);
        }
        if(k > 9)break;
    }
    for(k=2; k<9; k++) {
        printf("k=%d a=%d\n",k,ans[k]);
    }
//
//    int t;
//    LL n;
//    scanf("%d",&t);
//    while(t--){
//        scanf("%lld",&n);
//        output(n,ans[n]);
//    }

    return 0;
}
