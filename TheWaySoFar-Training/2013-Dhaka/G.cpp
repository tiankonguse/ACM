#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

int f[100005][20];

pair<int,int> la[100005];
int b[100005];
int n;

int find(int l,int r){
    int s=log(r-l+1)/log(2);
    while (l+(1<<s)<r-(1<<s)+1) ++s;
    return max(f[l][s],f[r-(1<<s)+1][s]);
}

int check(int X,int x){
    if (X-x<b[1]) return 0;
    int head=1,tail=n;
    while (head<tail-1){
        int mid=(head+tail)>>1;
        if (b[mid]<=X-x) head=mid;
        else tail=mid;
    }
    if (b[tail]<=X-x) head=tail;
    int k=find(1,head);
    if (k-X>=x) return 1;
    return 0;
}

int main(){
   // freopen("1.txt","r",stdin);
    int T;
    scanf("%d",&T);
    for (int Tnum=1; Tnum<=T; ++Tnum){
        int q;
        scanf("%d%d",&n,&q);
        for (int i=1; i<=n; ++i)
            scanf("%d%d",&la[i].first,&la[i].second);
        sort(la+1,la+1+n);
        for (int i=1; i<=n; ++i) b[i]=la[i].first;
        for (int i=1; i<=n; ++i)
            f[i][0]=la[i].second;
        for (int i=1; i<20; ++i)
            for (int j=1; j<=n-(1<<i)+1; ++j)
                f[j][i]=max(f[j][i-1],f[j+(1<<(i-1))][i-1]);
        printf("Case %d:\n",Tnum);
        for (;q;--q){
            int x;
            scanf("%d",&x);
            int head=0,tail=1000000005;
            while (head!=tail-1){
                int mid=(head+tail)>>1;
                if (check(x,mid)) head=mid;
                else tail=mid;
            }
            printf("%d\n",head);
        }
    }
}
