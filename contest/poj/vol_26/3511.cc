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
#define maxp 1001000
using namespace std;
int pri[maxp], cnt;
bool mark[maxp];
int setp(){
    int i, j, m;
    cnt = 1, pri[0] = 2, mark[1] = mark[4] = 1;
    for(i=3;i<maxp;i++){
        if(!mark[i]) pri[cnt++] = i;
        for(j=0;j<cnt,pri[j]*i<maxp;j++){
            mark[i*pri[j]] = 1;
            if(!(i % pri[j])) break;
        }
    }
    return cnt;
}
int sqr[maxn];
bool issqr[maxp];
int cnt_pri[maxp];
int cnt_exp[maxp];

int main(){
    setp();
   // for(int i=1;i<=20;i++) printf("%d ",mark[i]);puts("");
    memset(issqr, false, sizeof(issqr));
    for(int i=1;i<=1000;i++){
        sqr[i] = i * i;
        issqr[ sqr[i] ] = true;
    }
    for(int i=1;i<=1000000;i++){
        cnt_pri[i] = cnt_pri[i-1];
        cnt_exp[i] = cnt_exp[i-1];
        if(!mark[i]){
            cnt_pri[i]++;
            for(int j=1;sqr[j]<i;j++){
                if(issqr[i - sqr[j]]){
                    cnt_exp[i]++;
                    break;
                }
            }
        }
    }
    int l, u;
    while(scanf("%d%d", &l, &u)){
        if(l == -1 && u == -1) break;
        printf("%d %d %d %d\n", l, u, cnt_pri[max(0, u)] - cnt_pri[max(0, l - 1)], cnt_exp[max(0, u)] - cnt_exp[max(0, l - 1)]);
    }
    return 0;
}
