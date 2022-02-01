#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <set>
#include <queue>
#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
#define maxn 1111
#define maxl 88
#define maxm 1111000
using namespace std;
char data[maxn][maxl];
int lens[maxn];
bool check(int a, int b){
    int l1 = lens[a], l2 = lens[b];
    if(l1 + 1 != l2) return false;
    bool flag = true;
    int p = 0, q = 0;
    while(p < l1 && q < l2){
        if(data[a][p] != data[b][q]){
            if(!flag) return false;
            else{
                flag = false;
                q++;
            }
        }
        else{
            p++;
            q++;
        }
    }
    if(flag) return true;
    else if(p == l1 && q == l2) return true;
    else return false;
}
struct edges{
    int u, next;
}e[maxm];
int p[maxn], idx;
void addedge(int u, int v){
    e[idx].u = v;
    e[idx].next = p[u];
    p[u] = idx++;
}
void init(){
    idx = 0;
    memset(p, 0xff, sizeof(p));
}
int res, mx;
bool used[maxn];
void dfs(int u){
    used[u] = true;
    if(lens[u] > mx){
        mx = lens[u];
        res = u;
    }
    int v;
    for(int i=p[u];i!=-1;i=e[i].next){
        v = e[i].u;
        if(!used[v]) dfs(v);
    }
}
int main(){
    int n;
    while(~scanf("%d %s", &n, data[0])){
        lens[0] = strlen(data[0]);
        for(int i=1;i<=n;i++){
            scanf(" %s", data[i]);
            lens[i] = strlen(data[i]);
        }
        init();
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                if(check(i, j)){
                    addedge(i, j);
                    //printf("add(%d, %d)\n", i, j);
                }
            }
        }
        memset(used, false, sizeof(used));
        mx = 0;
        dfs(0);
        printf("%s\n", data[res]);
    }
    return 0;
}
