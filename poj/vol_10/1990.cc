#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define MAXN 20100
using namespace std;
struct cow{
    int id;
    long long x,v;
}c[MAXN];
bool cmp1(cow a,cow b){ return a.x<b.x;}
bool cmp2(cow a,cow b){ return a.v>b.v;}
struct node{
    long long s,k;
}tree[MAXN*4],t1,t2,tmp,tmp1,tmp2;
node operator +(node a,node b){
    node c;
    c.s=a.s+b.s;
    c.k=a.k+b.k;
    return c;
}
void update(int l,int r,int a,long long c,int p){
    if(l==r){
        tree[p].s=c;
        tree[p].k=1;
        return;
    }
    int mid=(l+r)>>1;
    if(a<=mid)update(l,mid,a,c,2*p);
    else update(mid+1,r,a,c,2*p+1);
    tree[p].s=tree[2*p].s+tree[2*p+1].s;
    tree[p].k=tree[2*p].k+tree[2*p+1].k;
}
node query(int l,int r,int a,int b,int p){
    if(l==a && r==b)return tree[p];
    int mid=(l+r)>>1;
    if(b<=mid)return query(l,mid,a,b,2*p);
    else if(a>mid)return query(mid+1,r,a,b,2*p+1);
    else return query(l,mid,a,mid,2*p)+query(mid+1,r,mid+1,b,2*p+1);
}
long long sumx[MAXN];
int main(){
    int N;
    while(~scanf("%d",&N)){
        for(int i=1;i<=N;i++){
            scanf("%lld %lld",&c[i].v,&c[i].x);
        }
        sort(c+1,c+N+1,cmp1);
        sumx[0]=0;
        for(int i=1;i<=N;i++){
          //  cout<<c[i].x<<","<<c[i].v<<endl;
            c[i].id=i;
            sumx[i]=sumx[i-1]+c[i].x;
        }
        sort(c+1,c+N+1,cmp2);
        long long res=0,xsum=0,dsum,x;
        int id;
        for(int i=1;i<=N*4;i++)tree[i].k=tree[i].s=0;
        for(int i=1;i<=N;i++){
            id=c[i].id;
            x=c[i].x;
            xsum=sumx[N]-sumx[id]*2+x*(2LL*id-N);
            t1=query(1,N,id,N,1);
            t2=query(1,N,1,id,1);
           // cout<<t2.k<<" and "<<t1.k<<"::"; cout<<t2.s<<" and "<<t1.s<<endl;
            //cout<<"put "<<id<<endl;
            dsum=t1.s-x*t1.k + x*t2.k-t2.s;
            //cout<<xsum<<","<<dsum<<endl;
            res = res+ (xsum-dsum)*c[i].v;
            update(1,N,id,x,1);
        }
        printf("%lld\n",res);
    }
    return 0;
}
