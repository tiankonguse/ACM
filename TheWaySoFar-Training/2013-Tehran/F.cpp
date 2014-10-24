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

int n;

struct circle{
    int ai,bi,ri;
}a[100000];

int cmp(const circle &a, const circle &b){
    return a.bi<b.bi;
}

int aa[100000];
double xx[100000],rr[100000];

int pd(int x,int y){
    double X=xx[x]-xx[y],Y=rr[x]-rr[y],R=rr[x]+rr[y];
    X=X*X; Y=Y*Y; R=R*R;
    return X+Y<=R;
}

int check(double x){
    for (int i=1; i<=n; ++i){
        xx[i]=x*a[i].ai+a[i].bi;
        rr[i]=a[i].ri;
    }
    //cout<<1<<endl;
    for (int i=2; i<=n; ++i)
        if (xx[i]<xx[i-1])  return 1;

    int p=1;
    aa[p]=1;
    for (int i=2; i<=n; ++i){
        while (p && rr[aa[p]]<rr[i])
            if (pd(aa[p--],i)) return 1;
        if (p && pd(aa[p],i)) return 1;
        aa[++p]=i;
    }
    return 0;
}

int main(){
  //  freopen("1.txt","r",stdin);
    while (scanf("%d",&n),n){
        for (int i=1; i<=n; ++i)
            scanf("%d%d%d",&a[i].ri,&a[i].ai,&a[i].bi);
        sort(a+1,a+1+n,cmp);
        double head=0,tail=1e14;
        while (head+(1e-8)<tail){
            double mid=(head+tail)/2;
            if (check(mid)) tail=mid;
            else head=mid;
        }
        check(tail);
        if (tail<1e13) printf("%.2f\n",tail);
        else puts("Collision-Free System");
    }
}
