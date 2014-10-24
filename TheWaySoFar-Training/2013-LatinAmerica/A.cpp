#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <cassert>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <string>
using namespace std;
typedef long long LL;
const int maxn = 100005;

int map[105][105];
int bo1[105][105],bo2[105][105];
int N,M,tot;
int first[10005],next[1000000],end[1000000];

void add_edge(int x,int y){
    next[++tot]=first[x];
    first[x]=tot;
    end[tot]=y;
}

char str[1000];

void init(int n){
    memset(map,0,sizeof(map));
    for (int i=1; i<=n; ++i){
        scanf("%s",str+1);
        for (int j=1; j<=n; ++j){
            //int ch;
            //while (ch=getchar(),ch!='X' && ch!='.');
            map[i][j]=(str[j]=='X');
        }
    }
    memset(bo1,0,sizeof(bo1));
    memset(bo2,0,sizeof(bo2));
    N=M=0;
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=n; ++j){
            if (map[i][j] || bo1[i][j]) continue;
            ++N;
            int k=j;
            while (k<=n && !map[i][k]) bo1[i][k++]=N;
        }
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=n; ++j){
            if (map[i][j] || bo2[i][j]) continue;
            ++M;
            int k=i;
            while (k<=n && !map[k][j]) bo2[k++][j]=M;
        }
    memset(first,0,sizeof(first));
    tot=0;
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=n; ++j)
            if (!map[i][j]) add_edge(bo1[i][j],bo2[i][j]);
}

int my[10000],bo[10000];

int find(int x){
    for (int k=first[x]; k; k=next[k])
        if (!bo[end[k]]){
            bo[end[k]]=1;
            if (my[end[k]]==0 || find(my[end[k]])){
                my[end[k]]=x;
                return 1;
            }
        }
    return 0;
}

int solve(int n){
    memset(my,0,sizeof(my));
    int ans=0;
    for (int i=1; i<=N; ++i){
        memset(bo,0,sizeof(int)*(M+1));
        if (find(i)) ++ans;
    }
    //printf("%d %d %d\n",N,M,ans);
    return ans;
}

int main() {
    int n;
    //freopen("1.txt" , "r" , stdin);
    while(~scanf("%d",&n)){
        init(n);
        printf("%d\n",solve(n));
    }
    return 0;
}
