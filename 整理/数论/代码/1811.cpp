#include<cstdio>
#include<cstdlib>
#include<time.h>
#include<vector>
const int S=20;
using namespace std;

typedef long long LL;

vector<LL> factor;

LL muti_mod(LL a,LL b,LL c){    //返回(a*b) mod c,a,b,c<2^63 
    a%=c;
    b%=c;
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

LL pow_mod(LL x,LL n,LL mod){  //返回x^n mod c ,非递归版 
    if (n==1) return x%mod;
    int bit[64],k=0;
    while (n){
        bit[k++]=n&1;
        n>>=1;
    }
    LL ret=1;
    for (k=k-1;k>=0;k--){
        ret=muti_mod(ret,ret,mod);
        if (bit[k]==1) ret=muti_mod(ret,x,mod);
    }
    return ret;
}

bool check(LL a,LL n,LL x,LL t){   //以a为基，n-1=x*2^t，检验n是不是合数 
    LL ret=pow_mod(a,x,n),last=ret;
    for (int i=1;i<=t;i++){
        ret=muti_mod(ret,ret,n);
        if (ret==1 && last!=1 && last!=n-1) return 1;
        last=ret;
    }
    if (ret!=1) return 1;
    return 0;
}

bool Miller_Rabin(LL n){
    LL x=n-1,t=0;
    while ((x&1)==0) x>>=1,t++;
    bool flag=1;
    if (t>=1 && (x&1)){
        for (int k=0;k<S;k++){
            LL a=rand()%(n-1)+1;
            if (check(a,n,x,t)) {flag=1;break;}
            flag=0;
        }
    }
    if (!flag || n==2) return 0;
    return 1;
}

LL gcd(LL a,LL b){
    if (a==0) return 1;
    if (a<0) return gcd(-a,b);
    while (b){
        LL t=a%b; a=b; b=t;
    }
    return a;
}
//pollard_rho分解，给出N的一个非1因数，返回N时为一个没有找到 
LL Pollard_rho(LL x,LL c){
    LL i=1,x0=rand()%x,y=x0,k=2;
    while (1){
        i++;
        x0=(muti_mod(x0,x0,x)+c)%x;
        LL d=gcd(y-x0,x);
        if (d!=1 && d!=x){
            return d;
        }
        if (y==x0) return x;
        if (i==k){
            y=x0;
            k+=k;
        }
    }
}

//递归进行质因数分解N 
void findfac(LL n){           
    if (!Miller_Rabin(n)){
        factor.push_back(n);
        return;
    }
    LL p=n;
    while (p>=n) p=Pollard_rho(p,rand() % (n-1) +1);
    findfac(p);
    findfac(n/p);
}

int main(){
    srand(time(NULL));
    int tests;
    scanf("%d",&tests);
    for (;tests;tests--){
        LL n;
        scanf("%I64d",&n);
        if (!Miller_Rabin(n)) printf("Prime\n");
        else{
            factor.clear();
            findfac(n);
            LL min=n;
            for (vector<LL>::iterator i=factor.begin();i!=factor.end();i++)
                if (*i<min) min=*i;
            printf("%lld\n",min);
        }
    }
}
