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

const int MAXN=1000;
int a[MAXN],b[MAXN],c[MAXN];
int VV,n;

int check(double x,int m){
    double C=x*VV*m,ans=0;
    for (int i=1; i<=n; ++i){
        double t=(double)a[i]/b[i];
        ans+=t*x;
        if (t*x<c[i]) C+=t*x;
        else C+=c[i];
    }
    return C>ans;
}

int main(){
    int q,Tnum=0;
    while (scanf("%d%d",&n,&q),n || q){
        scanf("%d",&VV);
        for (int i=1; i<=n; ++i) scanf("%d%d%d",&a[i],&b[i],&c[i]);
        int ans1=0;
        printf("Case %d:\n",++Tnum);
        double C=0;
        for (int i=1;  i<=n; ++i)
            C+=(double)a[i]/b[i];
        ans1=(floor(C+(1e-9))+VV)/VV;
        printf("%d\n",ans1);
        for (;q;--q){
            int x;
            scanf("%d",&x);
            double head=0,tail=1000000;
            while ((tail-head)>1e-5){
                double mid=(head+tail)/2;
                if (check(mid,x)) head=mid;
                else tail=mid;
            }
            if (head>100000-(1e-9)) head=-1;
            printf("%.3f\n",head);
        }
    }
}
