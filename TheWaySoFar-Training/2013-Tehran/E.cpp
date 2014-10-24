#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <cmath>
#include <cassert>
using namespace std;
typedef long long LL;

#define N 10005

int f[3001][3001],g[3001][3001];
int a[3001],sum[3001];
int vi[3001],tt[3001];

int main(){
    //freopen("1.txt","r",stdin);
    int n,p,L;
    while (scanf("%d%d%d",&n,&p,&L),n || p ||L){
        for (int i=1; i<=n; ++i) scanf("%d",&a[i]);
        sum[0]=0;
        for (int i=1; i<=n; ++i) sum[i]=sum[i-1]+a[i];
        memset(tt,0,sizeof(tt));
        for (int i=1; i<=n; ++i){
            int d=(sum[i]+p-1)/p;
            int c=sum[i-1]/p;
            c=c*p,d=d*p;
            if (d>=sum[n]) d=sum[n];
            vi[i]=d-c;
            if (d>sum[i])  {
                //cout<<1<<endl;
                if (d%p==0) tt[i]=p;
                else tt[i]=d%p;
            }
            //printf("%d %d\n",vi[i],tt[i]);
        }
        memset(f,63,sizeof(f));
        memset(g,63,sizeof(g));
        f[0][0]=0;
        for (int i=0; i<n; ++i)
            for (int j=0; j<=i; ++j){
                g[i+1][j+1]=min(f[i][j]+vi[i+1],g[i][j]+vi[i+1]-tt[i]);
                f[i+1][j]=min(f[i][j],g[i][j]);
            }
        int ans=0;
        for (int i=0; i<=n; ++i)
            if (f[n][i]<=L || g[n][i]<=L) {
                    ans=i;
                    //printf("%d %d %d\n",i,f[n][i],g[n][i]);
            }
        printf("%d\n",ans);
    }
}
