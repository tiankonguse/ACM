#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int f[50010][300];
int a[50010],b[50010],c[50010];
int ll[50010],rr[50010];

int main(){
    int T;
    //freopen("1.txt","r",stdin);
    scanf("%d",&T);
    for (int Tnum=0; Tnum<T; ++Tnum){
        int n,m,d;
        scanf("%d%d%d",&n,&m,&d);
        for (int i=1; i<=n; ++i) scanf("%d",&a[i]);
        for (int j=1; j<=m; ++j) scanf("%d",&b[j]);
        for (int i=1; i<=m; ++i)
            ll[i]=(upper_bound(a,a+n+1,b[i]-d)-a)-1;
        for (int i=1; i<=m; ++i){
            rr[i]=lower_bound(a+1,a+n+1,b[i]+d)-a;
            if (rr[i]>n) rr[i]=n;
            while (rr[i] && b[i]+d<=a[rr[i]]) --rr[i];
        }
        for (int i=1; i<=n; ++i)
            if (ll[i]<0) ll[i]=0;
       // for (int i=1; i<=n; ++i) printf("%d %d\n",ll[i],rr[i]);
        memset(f,0,sizeof(f));
        f[0][1]=1;
        ll[0]=rr[0]=0;
        int bo=0;
        for (int i=1; i<=m; ++i)
            for (int j=1; j<=rr[i]-ll[i]+1; ++j){
                int z=ll[i]+j-1;
                z=z-ll[i-1]+1;
                //printf("%d %d %d\n",ll[i],rr[i],z);
                //if (ll[i-1]+z-1>rr[i-1]){ bo=1; break;}
                if (ll[i-1]+z-1>rr[i-1]) z=rr[i-1]-ll[i-1]+1;
                f[i][j]=(f[i][j-1]+f[i-1][z])%1000000009;
            }
        if (bo) f[m][rr[m]-ll[m]+1]=0;
        printf("Case #%d: %d\n",Tnum+1,f[m][rr[m]-ll[m]+1]);
    }
}
