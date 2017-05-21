#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 10100
using namespace std;
struct segment{
    int x1,x2,y,flag;
    friend bool operator<(segment a,segment b){
        if(a.y==b.y)return a.flag>b.flag;
        else return a.y<b.y;
    }
}seg[MAXN];
int xpos[MAXN];
struct tree_node{
    int cnt,sum,snt;
    bool lf,rf;
}tree[MAXN*4];
void build(int l,int r,int p){
    if(l==r){
        tree[p].cnt=tree[p].sum=tree[p].snt=0;
        tree[p].lf=tree[p].rf=false;
        return;
    }
    int mid=(l+r)>>1;
    build(l,mid,2*p);
    build(mid+1,r,2*p+1);
    tree[p].cnt=tree[p].sum=tree[p].snt=0;
    tree[p].lf=tree[p].rf=false;
}

void update2(int l,int r,int p){
    if(tree[p].cnt>0){
        tree[p].sum=xpos[r]-xpos[l-1];
        tree[p].lf=tree[p].rf=1;
        tree[p].snt=2;
    }
    else if(l==r){
        tree[p].sum=tree[p].snt=0;
        tree[p].lf=tree[p].rf=0;
    }
    else{
        tree[p].sum=tree[2*p].sum+tree[2*p+1].sum;
        tree[p].lf=tree[2*p].lf;
        tree[p].rf=tree[2*p+1].rf;
        tree[p].snt=tree[2*p].snt+tree[2*p+1].snt;
        if(tree[2*p].rf && tree[2*p+1].lf)tree[p].snt-=2;
    }
}
void update(int l,int r,int a,int b,int c,int p){
    if(l==a && r==b){
        tree[p].cnt+=c;
        update2(l,r,p);
        return;
    }
    int mid=(l+r)>>1;
    if(b<=mid)update(l,mid,a,b,c,2*p);
    else if(a>mid)update(mid+1,r,a,b,c,2*p+1);
    else{
        update(l,mid,a,mid,c,2*p);
        update(mid+1,r,mid+1,b,c,2*p+1);
    }
    update2(l,r,p);
}


int find(int x,int l,int r){
    int mid;
    while(l<=r){
        mid=(l+r)>>1;
        if(xpos[mid]==x)return mid;
        else if(xpos[mid]<x)l=mid+1;
        else r=mid-1;
    }
    return -1;
}
int main(){
    int N,M;
    int x1,y1,x2,y2,l,r;
    while(~scanf("%d",&N)){
        N*=2;
        for(int i=0;i<N;i+=2){
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            xpos[i]=x1,xpos[i+1]=x2;
            seg[i].x1=seg[i+1].x1=x1;
            seg[i].x2=seg[i+1].x2=x2;
            seg[i].y=y1, seg[i].flag=1;
            seg[i+1].y=y2, seg[i+1].flag=-1;
        }
        sort(xpos,xpos+N);
        sort(seg,seg+N);
        M=1;
        for(int i=1;i<N;i++){
            if(xpos[i]!=xpos[i-1])xpos[M++]=xpos[i];
        }
        build(1,M-1,1);
        int res=0,tmp=0;
        for(int i=0;i<N;i++){
            l=find(seg[i].x1,0,M-1)+1;
            r=find(seg[i].x2,0,M-1)+1;
            update(1,M-1,l,r-1,seg[i].flag,1);
            if(res!=N-1) res += (seg[i+1].y-seg[i].y)*tree[1].snt;
            res += abs(tree[1].sum-tmp);
            tmp=tree[1].sum;
        }
        printf("%d\n",res);
    }
    return 0;
}
