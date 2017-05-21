#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#define MAXN 100100
#define inf 0x7f7f7f7f
using namespace std;
int num[MAXN];
int seg[MAXN];
int beg[MAXN];
int dpm[MAXN][20];
int n,q,cnt;
int max(int a,int b){return a>b?a:b;}
void init(){
    for(int i=1;i<=cnt;i++){dpm[i][0]=seg[i];}
    for(int j=1;(1<<j)<=cnt;j++){
        for(int i=1;i+(1<<j)-1<=cnt;i++){
            dpm[i][j]=max(dpm[i][j-1],dpm[i+(1<<(j-1))][j-1]);
        }
    }
}
int getm(int a,int b){
    int k=(int)(log((double)(b-a+1))/log(2.0));
    return max(dpm[a][k],dpm[b-(1<<k)+1][k]);
}
int main(){
    int a,b,na,nb;
    while(scanf("%d",&n) && n){
        scanf("%d",&q);
        cnt=0;
      //  memset(seg,0,sizeof(seg));
        for(int i=1,t=inf;i<=n;i++){
            scanf("%d",&a);
            if(a!=t){t=a;num[i]=++cnt;beg[cnt]=i;}
            else num[i]=cnt;
        }
       // for(int i=1;i<=n;i++)printf("%d ",num[i]);printf("\n");
       // for(int i=1;i<=cnt;i++)printf("%d ",beg[i]);printf("\n");
        beg[cnt+1]=n+1;
        for(int i=1;i<=cnt;i++)seg[i]=beg[i+1]-beg[i];
        init();
      //  while(cin>>a>>b)cout<<query(1,cnt,a,b,1)<<endl;
        for(int i=0;i<q;i++){
            scanf("%d%d",&a,&b);
            na=num[a],nb=num[b];
          //  printf("na=%d,nb=%d\n",na,nb);
            if(na==nb)printf("%d\n",b-a+1);
            else if(na+1==nb)printf("%d\n",max(beg[nb]-a,b-beg[nb]+1));
            else printf("%d\n",max(max(beg[na+1]-a,b-beg[nb]+1),getm(na+1,nb-1)));
        }
    }
    return 0;
}
