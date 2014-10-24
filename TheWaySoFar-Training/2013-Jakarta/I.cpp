#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int a[30000];

int check(int n,int m,int x){
    if (n==1) return 1;
    int l=a[0]-x,r=a[0]+x;
    for (int i=1; i<n; ++i){
        l=max(a[i]-x,l+m);
        r=min(a[i]+x,r+m);
       // if (x==1) printf("%d %d\n",l,r);
    }
    return r-l+1>0;
}

int main(){
    //freopen("1.txt","r",stdin);
    int T;
    scanf("%d",&T);
    int num=0;
    for (;T;--T){
        int n,m;
        scanf("%d%d",&n,&m);
        for (int i=0; i<m; ++i) scanf("%d",&a[i]);
        sort(a,a+m);
        int head=0,tail=n;
        int mark=n/m;
        while (head!=tail-1){
            int mid=(head+tail)>>1;
            if (check(m,mark,mid)) tail=mid;
            else head=mid;
        }
        if (check(m,mark,0)) tail=0;
        printf("Case #%d: %d\n",++num,tail);
    }
}
