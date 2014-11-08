// 排列组合 By 猛犸也钻地 @ 2013.06.11

#include <vector>
using namespace std;

// C(n,m)表示从n个里面选m个顺序无关的物品的方案数
long long C(int n, int m){
    long long ret=1;
    if(n-m<m) m=n-m;
    for(int i=1;i<=m;i++){
        ret*=n-i+1;
        ret/=i;
    }
    return ret;
}

// P(n,m)表示从n个里面选m个顺序相关的物品的方案数
long long P(int n, int m){
    long long ret=1;
    for(int i=n-m+1;i<=n;i++) ret*=i;
    return ret;
}

// 传入n和m及组合的序号(最小组合的序号为0)，返回对应的组合
vector<int> make_combination(int n, int m, long long idx){
    vector<int> u(m);
    for(int i=0,j=0;i<m;u[i++]=j++)
        for(long long s;(s=C(n-j-1,m-i-1))<=idx;idx-=s) j++;
    return u;
}

// 传入n和m及排列的序号(最小排列的序号为0)，返回对应的排列
vector<int> make_permutation(int n, int m, long long idx){
    vector<int> u(m),at(n);
    for(int i=0;i<n;i++) at[i]=i;
    for(int i=0;i<m;i++){
        long long s=P(n-i-1,m-i-1);
        u[i]=at[idx/s];
        at.erase(at.begin()+idx/s);
        idx%=s;
    }
    return u;
}
