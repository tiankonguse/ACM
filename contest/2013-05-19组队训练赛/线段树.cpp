
#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

#define lson l,m,rt<<1
#deifne rson m+l,r,rt<<1|1

const int maxn = 55555;
int sum[maxn<<2];
int n;
int operate(int a,int b)
{
    return a+b;
}
void pushup(int rt)
{
    sum[rt]=operate(sum[rt<<1],sum[rt<<1|1]);
}
void build(int l=1,int r=n,int rt=1)
{
    if(l==r)
    {
        scanf("%d")
    }
    int m = (l+r)>>1;
    build(lson);
    build(rson);
    pushup(rt);
}
void update(int p,int add,int l=1,int r=n,int rt=1)
{
    if(l==r)
    {
        sum[rt]+=add;return;
    }
    int m = (l+r)>>1;
    if(p<=m)update(p,add,lson);
    else update(p,add,rson);
    pushup(rt);
}
int query(int L,int R,int l=1,int r=n,int rt=1)
{
    if(L<=l&&r<=R)
    {
        return sum[rt];
    }
    int m = (l+r)>>1;
    int ret = 0;
    if(L<=m)ret=operate(ret,query(L,R,lson));
    if(R>m)ret = operate(ret,query(L,R,rson));
    return ret;
}



int main(){

}

