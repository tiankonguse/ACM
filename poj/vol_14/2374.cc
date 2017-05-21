#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#define MAXN 200200
#define inf 10000000000LL
using namespace std;
const int plu = 100002;
int tree[MAXN*4];
void update(int l,int r,int a,int b,int c,int p){
    if(l==a && r==b){
         tree[p]=c;
         return;
    }
    if(tree[p]!=-1){
         tree[2*p]=tree[p];
         tree[2*p+1]=tree[p];
         tree[p]=-1;
    }
    int mid=(l+r)>>1;
    if(b<=mid)update(l,mid,a,b,c,2*p);
    else if(a>mid)update(mid+1,r,a,b,c,2*p+1);
    else{
        update(l,mid,a,mid,c,2*p);
        update(mid+1,r,mid+1,b,c,2*p+1);
    }
}
int query(int l,int r,int a,int p){
    if(tree[p]!=-1)return tree[p];
    int mid=(l+r)>>1;
    if(a<=mid)return query(l,mid,a,2*p);
    else return query(mid+1,r,a,2*p+1);
}
int fl[MAXN][2];
__int64 dp[MAXN][2];
int _abs(int x){return x>0?x:-x;}
int main(){
    int N,M,S;
    while(~scanf("%d%d",&N,&S)){
        S += plu;
        M = 200100;
        memset(tree,0,sizeof(tree));
        for(int i=1;i<=N;i++){
            scanf("%d%d",&fl[i][0],&fl[i][1]);
            fl[i][0] += plu;
            fl[i][1] += plu - 1;
        }
        for(int i=1;i<=N;i++)dp[i][0]=dp[i][1]=inf;
        __int64 res=inf;
       // dp[N][0] = S - fl[N][0];
       // dp[N][1] = fl[N][1]+1 - S;
        int l,r;
       // update(1,M,fl[1][0],fl[1][1],1,1);
        for(int i=1;i<=N;i++){
            l = query(1,M,fl[i][0]-1,1);
            r = query(1,M,fl[i][1]+1,1);
            //printf("i=%d,l=%d,r=%d\n",i,l,r);system("pause");
            if(l==0)dp[i][0]=_abs(fl[i][0]-plu);
            if(r==0)dp[i][1]=_abs(fl[i][1]+1-plu);
            if(l > 0){
                dp[i][0] = min(dp[i][0], min(fl[i][0]-fl[l][0]+dp[l][0],
                                             fl[l][1]-fl[i][0]+1+dp[l][1]));
            }
            if(r > 0){
                dp[i][1] = min(dp[i][1], min(fl[r][1]-fl[i][1]+dp[r][1],
                                             fl[i][1]-fl[r][0]+1+dp[r][0]));
            }
            //cout<<dp[i][0]<<","<<dp[i][1]<<endl;system("pause");
            update(1,M,fl[i][0],fl[i][1],i,1);
        }

        printf("%I64d\n",min(dp[N][0]+S-fl[N][0],dp[N][1]+fl[N][1]+1-S));
    }
    return 0;
}
