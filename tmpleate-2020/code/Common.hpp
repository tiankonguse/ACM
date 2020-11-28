// 常用数论函数/离散对数 By 猛犸也钻地 @ 2012.09.27

#include <vector>
#include <cmath>
#include <tr1/unordered_map>
#include <algorithm>
using namespace std;
using namespace tr1;

typedef pair<int,int> PII;
typedef long long LL;

// 求x在模m下的乘法逆元，须保证gcd(x,m)==1，否则不存在逆元
int inv(int x, int m){
    return x>1?inv(m%x,m)*LL(m-m/x)%m:x;
}

// 计算a的e次方模m的值，e必须大于等于0
int pow(LL a, LL e, int m){
    int s=1%m;
    for(a=a%m;e;a=a*a%m,e>>=1)
        if(e&1) s=s*a%m;
    return s;
}

// 求n的欧拉函数值，简易版
int phi(int n){
    int i,m=n;
    for(i=2;i*i<=n;i++) if(n%i==0)
        for(m=m/i*(i-1);n%i==0;n/=i);
    if(n>1) m=m/n*(n-1);
    return m;
}


// 计算第n个斐波那契数，返回第n和第n-1个斐波那契数模m的值
// 其中n必须为非负整数，此数列初值为F[0]=0和F[1]=1
PII fib(LL n, int m){
    if(n<=2) return PII(!!n%m,n/2%m);
    PII t=fib(n/2+1,m);
    int x=t.first,y=t.second;
    int p=(LL(x)*x+LL(y)*y)%m;
    int q=(x*2ll*y-LL(y)*y%m+m)%m;
    if(n&1) return PII(p,q);
    return PII(q,(p-q+m)%m);
}

// 求离散对数，即a^x%m=r的最小非负整数解x，返回-1说明无解
int log(int a, int r, int m){
    if(r>=m) return -1;
    int i,g,x,c=0,at=int(2+sqrt(m));
    for(i=0,x=1%m;i<50;i++,x=LL(x)*a%m) if(x==r) return i;
    for(g=x=1;__gcd(int(LL(x)*a%m),m)!=g;c++) g=__gcd(x=LL(x)*a%m,m);
    if(r%g) return -1;
    if(x==r) return c;
    unordered_map<int,int> u;
    g=phi(m/g),u[x]=0;
    g=pow(a,g-at%g,m);
    for(i=1;i<at;i++){ // Baby Step
        u.insert(PII(x=LL(x)*a%m,i));
        if(x==r) return c+i;
    }
    for(i=1;i<at;i++){ // Giant Step
        unordered_map<int,int>::iterator t=u.find(r=LL(r)*g%m);
        if(t!=u.end()) return c+i*at+t->second;
    }
    return -1;
}
