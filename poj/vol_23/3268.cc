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
#define maxn 1010
#define maxm 100100
using namespace std;
struct edges{
    int u, c, next;
}e1[maxm], e2[maxm];
int idx1, p1[maxn];
int n, m;
void addedge1(int u, int v, int c){
    e1[idx1].u = v;
    e1[idx1].c = c;
    e1[idx1].next = p1[u];
    p1[u] = idx1++;
}
void init1(){
    idx1 = 0;
    memset(p1, 0xff, sizeof(p1));
}
bool used[maxn];
queue<int> q;
int dist1[maxn], dist2[maxn];

void spfa1(int s){
    int t,u,w;
    while(!q.empty())q.pop();
    memset(used,false,sizeof(used));
    for(int i=1;i<=n;i++) dist1[i]=inf;
    dist1[s]=0;
    q.push(s);
    while(!q.empty()){
        t=q.front();
        q.pop();
        used[t]=false;
        for(int i=p1[t];i!=-1;i=e1[i].next){
            u=e1[i].u;
            w=e1[i].c;
            if(dist1[t]+w<dist1[u]){
                dist1[u]=dist1[t]+w;
                if(!used[u]){
                    used[u]=true;
                    q.push(u);
                }
            }
        }
    }
}


int idx2, p2[maxn];

void addedge2(int u, int v, int c){
    e2[idx2].u = v;
    e2[idx2].c = c;
    e2[idx2].next = p2[u];
    p2[u] = idx2++;
}
void init2(){
    idx2 = 0;
    memset(p2, 0xff, sizeof(p2));
}

void spfa2(int s){
    int t,u,w;
    while(!q.empty())q.pop();
    memset(used,false,sizeof(used));
    for(int i=1;i<=n;i++) dist2[i]=inf;
    dist2[s]=0;
    q.push(s);
    while(!q.empty()){
        t=q.front();
        q.pop();
        used[t]=false;
        for(int i=p2[t];i!=-1;i=e2[i].next){
            u=e2[i].u;
            w=e2[i].c;
            if(dist2[t]+w<dist2[u]){
                dist2[u]=dist2[t]+w;
                if(!used[u]){
                    used[u]=true;
                    q.push(u);
                }
            }
        }
    }
}
int main(){
    int x, a, b, c, res;
    while(~scanf("%d%d%d", &n, &m, &x)){
        init1();
        init2();
        for(int i=0;i<m;i++){
            scanf("%d%d%d", &a, &b, &c);
            addedge1(a, b, c);
            addedge2(b, a, c);
        }
        spfa1(x);
        spfa2(x);
        res = 0;
        for(int i=1;i<=n;i++){
            res = max(res, dist1[i] + dist2[i]);
        }
        printf("%d\n", res);
    }
    return 0;
}
