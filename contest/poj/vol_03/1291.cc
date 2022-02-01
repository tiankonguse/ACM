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
#define MAXN 1010
using namespace std;

int parents[MAXN], v[MAXN];
int Find(int a){
    if(parents[a] < 0) return a;
    else{
        int t = parents[a];
        parents[a] = Find(parents[a]);
        v[a] += v[t];
        return parents[a];
    }
}
void Union(int a,int b,int c){
    if(parents[a] < parents[b]){
        parents[a] += parents[b];
        parents[b] = a;
        v[b] = c;
    }
    else{
        parents[b] += parents[a];
        parents[a] = b;
        v[a] = c;
    }
}
void init(){
    memset(v, 0, sizeof(v));
    memset(parents, 0xff, sizeof(parents));
}
bool used[MAXN];
int cnt[MAXN];
int st[MAXN];
char str[50];
int main(){
    int N,b,ra,rb,d;
    bool flag;
    while(scanf("%d",&N) && N){
        init();
        flag = true;
        for(int i=1;i<=N;i++){
            if(!flag){
                gets(str);
                continue;
            }
            scanf("%*s %d %*s %s", &b, str);
            if(str[0] == 'f') d = 1;
            else d = 0;
            ra = Find(i), rb = Find(b);
            if(ra != rb){
                Union(ra, rb, v[i] + v[b] + d);
            }
            else{
                if((v[i] + v[b]) % 2 != d){
                    getchar();
                    flag = false;
                }
            }
        }
        if(!flag) puts("Inconsistent");
        else{
            memset(cnt, 0, sizeof(cnt));
            memset(used, false, sizeof(used));
            int snt = 0;
            for(int i=1;i<=N;i++){
                ra = Find(i);
                if(v[i] % 2 == 0)cnt[ra]++;
                if(!used[ra]){
                    st[ snt++ ] = ra;
                    used[ra] = true;
                }
            }
            int res = 0;
            for(int i=0;i<snt;i++){
                res += max(-parents[ st[i] ] - cnt[ st[i] ], cnt[ st[i] ]);
            }
            printf("%d\n", res);
        }
    }
    return 0;
}
