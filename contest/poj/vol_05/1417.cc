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
#define MAXN 610
#define MAXP 305
using namespace std;
int parents[MAXN], v[MAXN];
int Find(int a){
    if(parents[a] < 0)return a;
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
char str[10];
bool used[MAXN];
int st[MAXN], snt;
int cnt[MAXN][2];
int dp[MAXP][MAXP];
int num[MAXP][MAXP];
int path[MAXP][MAXP];
int ans[MAXP], ant;
int mark[MAXN];

int main(){
    int N,p1,p2,a,b,c,ra,rb;
    while(scanf("%d%d%d",&N,&p1,&p2) && (N + p1 + p2)){
        init();
        while(N--){
            scanf("%d%d%s",&a,&b,str);
            ra = Find(a);
            rb = Find(b);
            if(str[0] == 'n') c = 1; else c = 0;
            if(ra != rb){
                Union(ra, rb, v[a] + v[b] + c);
            }
        }
        if(p1 == p2){puts("no"); continue;}
        memset(used, false, sizeof(used));
        memset(cnt, 0, sizeof(cnt));
        snt = 0;
        bool flag = true;
        for(int i=1;i<=p1+p2;i++){
            ra = Find(i);
            if(v[i] % 2 == 0)cnt[ra][0]++;
            else cnt[ra][1]++;
            if(!used[ra]){
                used[ra] = true;
                st[ snt++ ] = ra;
            }
        }
        for(int i=0;i<snt;i++){
    //        cnt[ st[i] ][1] = (-parents[ st[i] ] - cnt[ st[i] ][0]);
            if(cnt[ st[i] ][0] == cnt[ st[i] ][1]){
                flag = false;
                break;
            }
        }

        if(!flag){ puts("no"); continue;}
        if(p2 == 0){
            for(int i=1;i<=p1;i++)printf("%d\n",i);
            puts("end");
            continue;
        }
        if(p1 == 0){
            puts("end");
            continue;
        }
//for(int i=0;i<snt;i++) printf("(%d,%d) ",cnt[ st[i] ][0], cnt[ st[i] ][1]); printf("\n");
        memset(dp, 0, sizeof(dp));
        memset(num, 0, sizeof(num));
        dp[0][0] = 1;
        for(int i=0;i<snt;i++){
            for(int j=p1;j>=cnt[ st[i] ][0];j--){
                if(dp[i][j - cnt[ st[i] ][0] ]){
                    dp[i+1][j] += dp[i][j - cnt[ st[i] ][0] ];
                //   if(dp[i+1][j] > 1){flag = false; break;}
                    num[i][j] = 0;
                    path[i][j] = j - cnt[ st[i] ][0];
                }
            }
            for(int j=p1;j>=cnt[ st[i] ][1];j--){
                if(dp[i][j - cnt[ st[i] ][1] ]){
                    dp[i+1][j] += dp[i][j - cnt[ st[i] ][1] ];
                //    if(dp[i+1][j] > 1){flag = false; break;}
                    num[i][j] = 1;
                    path[i][j] = j - cnt[ st[i] ][1];
                }
            }

            //for(int j=1;j<=p1;j++)printf("%d ",dp[i+1][j]);printf("\n");
            //if(!flag) break;
        }
        if(!flag || dp[snt][p1] != 1){ puts("no"); continue;}
        ant = 0;
        memset(mark, 0, sizeof(mark));
        int pa = p1;
        int q=0;
        for(int i=snt-1;i>=0;i--){
            mark[ st[i] ] = num[i][ pa ] + 1;
            pa = path[i][pa];
            q += cnt[ st[i] ][num[i][pa] ];
        }
        for(int i=1;i<=p1+p2;i++){
            ra = Find(i);
            if(mark[ra] && (v[i] % 2 == mark[ra] - 1)) ans[ant++] = i;
        }
        for(int i=0;i<ant;i++){
            printf("%d\n",ans[i]);
        }
        puts("end");
    }
    return 0;
}
