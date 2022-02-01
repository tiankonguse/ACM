#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;
typedef long long LL;

int n;
const int maxn=1050;

int d1[maxn],d2[maxn],t1[maxn],t2[maxn],m1[maxn],m2[maxn];
int TT[maxn];
int find(int x1,int y1,int x2,int y2){
    int t1=y1;
    int t2=y2+(x2-x1)*60;
   // printf("%d %d %d %d\n",x1,y1,x2,y2);
    return t2-t1;
}

void work()
{
    for (int i=1; i<=n;++i){
        scanf("%d/%d%d:%d",&d1[i],&d2[i],&t1[i],&t2[i]);
        while (m1[i]=getchar(),m1[i]!='I' && m1[i]!='O');
        scanf("%d",&m2[i]);
    }
    int ans=0;
    memset(TT,0,sizeof(TT));
    for (int i=1; i<=n; ++i)
        if (m1[i]=='I' && m2[i]!=0){
                int k=0;
                for (int j=i+1; j<=n; ++j)
                    if (m1[j]=='O' && m2[i]==m2[j]){
                        k=j;
                        break;
                    }
                int ans1=0,sum=0;
                for (int j=1,J; j<=n; ++j)
                    if (m2[j]==0){

                        if (m1[j]=='I') J=j;
                        if (m1[j]=='O'){
                            int k1=J,k2=j;
                            k1=max(J,i);
                            k2=min(j,k);
                          //  printf("%d %d\n",k1,k2);
                            if (k1>k2) continue;
                            TT[m2[i]]+=find(t1[k1],t2[k1],t1[k2],t2[k2]);
                        }
                    }
               // ans=max(ans,ans1);
        }
    for (int i=0;i<=1000; ++i) ans=max(ans,TT[i]);
    printf("%d\n",ans);
}

int main()
{
    //freopen("1.txt" , "r" , stdin);
    int T;
    while (scanf("%d",&n),n)
        work();
    return 0;
}
