#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
using namespace std;
//1.bulid();2.query(a,b)；3.update(a,b)

#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
typedef int LL;
const int maxn = 100010;
bool sign[maxn<<3];//标记
bool sum[maxn<<3];
LL val[maxn<<3],mymin[maxn<<3],mymax[maxn<<3];
int n;

LL _min(LL a, LL b){
    return a<b?a:b;
}
LL _max(LL a, LL b){
    return a>b?a:b;
}

void PushUp(int rt){
    if(sum[rt<<1] && sum[rt<<1|1] && (val[rt<<1] ==val[rt<<1|1])){
        sum[rt]=true;
        mymin[rt]=mymax[rt]=val[rt]=val[rt<<1];
    }else{
        sum[rt]=false;
        mymin[rt]=_min(mymin[rt<<1] ,mymin[rt<<1|1]);
        mymax[rt]=_max(mymax[rt<<1] ,mymax[rt<<1|1]);
    }
}
void PushDown(int rt) {
    if (sign[rt] ) {
        mymax[rt<<1] = mymax[rt<<1|1]=mymin[rt<<1] = mymin[rt<<1|1]=val [rt<<1]  = val [rt<<1|1] = val [rt];
        sign[rt<<1]  = sign[rt<<1|1] = 1;
        sum [rt<<1]  = sum [rt<<1|1] = true;
        sign[rt] = 0;
    }
}

void bulid(int l=1,int r=n,int rt=1){
    sign[rt] = 0;
    if(l==r){// 据题意做相关修改
        scanf("%d",&val[rt]);
        sum[rt]=true;
        mymin[rt]=mymax[rt]=val[rt];
        return ;
    }
    int m=(l+r)>>1;
    bulid(lson);
    bulid(rson);
    PushUp(rt);
}
void update(int L,int R,LL add,int l=1,int r=n,int rt=1){
    if(L<=l && r<=R){// 据题意做相关修改
        if(l==r)sign[rt]=0;
        else sign[rt]=1;
        
        sum[rt]=true;
        mymin[rt]=mymax[rt]=val[rt]=add;
        return ;
    }
    PushDown(rt);
    int m = (l + r) >> 1;
    if (L <= m) update(L , R , add , lson);
    if (R > m) update(L , R , add , rson);
    PushUp(rt);
}
int query(int L,int R,LL add,int l=1,int r=n,int rt=1) {
    
//    printf("rt=%d  sign=%I64d  val=%I64d sum=%d mymin=%I64d mymax=%I64d L=%d R=%d l=%d r=%d\n",rt,sign[rt],val[rt],sum[rt],mymin[rt],mymax[rt],L,R,l,r);
    
    if(sum[rt]){
        if(val[rt]!=add)return 0;
        else  return R-L+1;
    }
    
    if(mymax[rt]<add || mymin[rt]>add)return 0;
    
    PushDown(rt);
    
    int m = (l + r) >> 1;
    
    
    if(L>m) return query(L,R,add,rson);
    if(R<=m)return query(L,R,add,lson);
    int ret = 0;
    ret+=query(L,m,add,lson);
    ret+=query(m+1,R,add,rson);

//    printf("rt=%d L=%d R=%d ret=%d\n",rt,L,R,ret);
    return ret;
}

int main()
{
    int m,op,l,r;
    LL z;

    while(~scanf("%d%d",&n,&m)){
        bulid();

        while(m--){
            scanf("%d%d%d%d",&op,&l,&r,&z);
            l++,r++;
            
            if(op==1){
                update(l,r,z);
            }else{
                printf("%d\n",query(l,r,z));
            }
        }
    }
    return 0;
}
