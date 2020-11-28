// 质数的判定/筛选/分解 By 猛犸也钻地 @ 2012.02.21

#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

class FastSieve {
public:
    static const int MOD = 1000000007, SIZE = 1000050;
    typedef long long LL;
    vector<int> pl,lo,eu,rv;
    // 线性筛出[0,SIZE)范围内的质数
    // lo[]为最小质因子(或其本身)，eu[]为欧拉函数值，rv[]为关于MOD的逆元
    FastSieve(){
        lo=eu=rv=vector<int>(SIZE);
        lo[1]=eu[1]=rv[1]=1;
        for(int x=2;x<SIZE;x++){
            rv[x]=rv[MOD%x]*LL(MOD-MOD/x)%MOD;
            if(!lo[x]) pl.push_back(lo[x]=x),eu[x]=x-1;
            for(size_t i=0;i<pl.size() && x*pl[i]<SIZE;i++){
                lo[x*pl[i]]=pl[i];
                eu[x*pl[i]]=eu[x]*(pl[i]-(x%pl[i]!=0));
                if(x%pl[i]==0) break;
            }
        }
    }
    // 对n做质因数分解
    vector<LL> factorize(LL n){
        vector<LL> u;
        int i,t=sqrt(n+1);
        for(i=0;pl[i]<=t;i++) if(n%pl[i]==0){
            do{
                n/=pl[i];
                u.push_back(pl[i]);
            }while(n%pl[i]==0);
            t=sqrt(n+1);
        }
        if(n>1) u.push_back(n);
        return u;
    }
    // 判断n是否为质数
    bool prime(LL n){
        if(n<SIZE) return n>=2 && lo[n]==n;
        int i,t=sqrt(n+1);
        for(i=0;pl[i]<=t;i++) if(n%pl[i]==0) return false;
        return true;
    }
};

class Primality {
public:
    typedef long long LL;
    // 判断num是否为质数
    bool miller_rabin(LL num){
        if(num<=1) return false;
        if(num<=3) return true;
        if(~num&1) return false;
        const int u[]={2,3,5,7,11,13,17,19,23,29,0};
        LL e=num-1,a,c=0;
        while(~e&1) e/=2,c++;
        for(int i=0;u[i];i++){
            if(num<=u[i]) return true;
            a=POW(u[i],e,num);
            if(a==1) continue;
            for(int j=1;a!=num-1;j++){
                if(j==c) return false;
                a=MUL(a,a,num);
            }
        }
        return true;
    }
    // 求一个小于n的因数，期望复杂度为O(n^0.25)，当n为非合数时返回n本身
    LL pollard_rho(LL n){
        if(n<=3 || miller_rabin(n)) return n; // 保证n为合数时可去掉这行
        while(1){
            int i=1,cnt=2;
            LL x=rand()%n,y=x,c=rand()%n;
            if(!c || c==n-2) c++;
            do{
                LL u=__gcd(n-x+y,n);
                if(u>1 && u<n) return u;
                if(++i==cnt) y=x,cnt*=2;
                x=(c+MUL(x,x,n))%n;
            }while(x!=y);
        }
        return n;
    }
    // 使用rho方法对n做质因数分解，建议先筛去小质因数后再用此函数
    vector<LL> factorize(LL n){
        vector<LL> u;
        if(n>1) u.push_back(n);
        for(size_t i=0;i<u.size();i++){
            LL x=pollard_rho(u[i]);
            if(x==u[i]) continue;
            u[i--]/=x;
            u.push_back(x);
        }
        sort(u.begin(),u.end());
        return u;
    }
    // 返回x与y相乘模m的结果，x与m要小于2^62
    LL MUL(LL x, LL y, LL m){
        LL c,s=0;
        for(c=x%m;y;c=(c+c)%m,y>>=1)
            if(y&1) s=(s+c)%m;
        return s;
    }
    // 返回x的y次方模m的结果，x与m要小于2^62
    LL POW(LL x, LL y, LL m){
        LL c,s=1;
        for(c=x%m;y;c=MUL(c,c,m),y>>=1)
            if(y&1) s=MUL(s,c,m);
        return s;
    }
};
