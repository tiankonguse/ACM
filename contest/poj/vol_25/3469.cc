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

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
#define maxn 50505
#define maxm 1001001
 
using namespace std;
struct edges{
    int u,c,next;
}e[maxm];
int p[maxn],idx;
int N,M;
void addedge(int u,int v,int c,int cc=0){
  //  printf("e[%d]:(%d,%d) = %d\n",idx,u,v,c);
    e[idx].u=v; e[idx].c=c;  e[idx].next=p[u]; p[u]=idx++;
  //  printf("e[%d]:(%d,%d) = %d\n",idx,v,u,c);
    e[idx].u=u; e[idx].c=cc; e[idx].next=p[v]; p[v]=idx++;

}
void init(){ idx=0; memset(p,0xff,sizeof(p));}

int gap[maxn],dis[maxn],pre[maxn],cur[maxn];

int sap(int s,int t){
    memset(dis,0,sizeof(dis));
    memset(gap,0,sizeof(gap));
    for(int i=1;i<=N;i++)cur[i]=p[i];
    int u=pre[s]=s, max_flow=0,step=inf;
    gap[0]=N;
    while(dis[s]<N){
loop:   for(int &i=cur[u];i!=-1;i=e[i].next){
            int v=e[i].u;
            if(e[i].c>0 && dis[u]==dis[v]+1){
                step=min(step,e[i].c);
                pre[v]=u;
                u=v;
                if(v==t){
                    max_flow += step;
                    for(u=pre[u];v!=s;v=u,u=pre[u]){
                        e[cur[u]].c -= step;
                        e[cur[u]^1].c += step;
                    }
                    step=inf;
                }
                goto loop;
            }
        }
        int mindis=N;
        for(int i=p[u];i!=-1;i=e[i].next){
            int v=e[i].u;
            if(e[i].c>0 && mindis>dis[v]){
                cur[u]=i;
                mindis=dis[v];
            }
        }
        if( (--gap[dis[u]])==0) break;
        gap[ dis[u] = mindis+1] ++;
        u=pre[u];
    }
    return max_flow;
}
inline int nextInt()
{
    char c;c=getchar();
    while(c!='-'&&(c<'0'||c>'9'))c=getchar();
    int n=0,s=1;if(c=='-')s=-1,c=getchar();
    while(c>='0'&&c<='9')n*=10,n+=c-'0',c=getchar();
    return n*s;
}
int A[20],k;
inline void print_int(int x)
{
    if(x<0)putchar('-'),x=-x;
    else if(x == 0){putchar('0'); return;}
    k=0;while(x)A[k++]=x%10,x/=10;
    for(int i=k-1;i>=0;i--)putchar('0'+A[i]);
    putchar('\n');
}

int main() {
    int n, m;
    int a, b, c;
    int S, T;
    while (~scanf("%d%d", &n, &m)) {
        init();
        N = n + 2;
        S = N - 1, T = N;
        
        for (int i = 1; i <= n; ++i) {
            a = nextInt();
            b = nextInt();
            addedge(S, i, a);
            addedge(i, T, b);
        }
        for (int i = 1; i <= m; ++i) {
            a = nextInt();
            b = nextInt();
            c = nextInt();
            addedge(a, b, c);
            addedge(b, a, c);
        }
        print_int(sap(S, T));
    }
    return 0;
}
