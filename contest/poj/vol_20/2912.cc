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
#define MAXN 505
#define MAXM 2020
using namespace std;

int parents[MAXN], v[MAXN];
int Find(int a){
    if(parents[a] < 0) return a;
    else{
        int t = parents[a];
        parents[a] = Find(parents[a]);
        v[a] = (v[a] + v[t]) % 3;
        return parents[a];
    }
}
void Union(int a,int b,int c){
    parents[a] += parents[b];
    parents[b] = a;
    v[b] = c % 3;
}
void init(){
    memset(v, 0, sizeof(v));
    memset(parents, 0xff, sizeof(parents));
}

struct results{
    int a,b,c;
}re[MAXM];

char str[30];
int main(){
    int N,M,k,a,b,c,ra,rb;
    while(~scanf("%d%d",&N,&M)){
        getchar();
        for(int i=0;i<M;i++){
            gets(str);
            a = b = k = 0;
            for(;str[k]!='<' && str[k]!='>' && str[k]!='=';k++){
                a = (a<<3) + (a<<1) + str[k] - '0';
            }
            if(str[k] == '=') c = 0;
            else if(str[k] == '<') c = 1;
            else c = 2;
            for(k++;str[k];k++){
                b = (b<<3) + (b<<1) + str[k] - '0';
            }
            re[i].a = a, re[i].b = b, re[i].c = c;
        }
        bool pos = false, tp; int cnt = 0, ans = 0, ar, ai = 0;
        for(int i=0;i<N;i++){
            int conf = 0;
            init();
            tp = true;
            for(int j=0;j<M;j++){
                a = re[j].a, b = re[j].b, c = re[j].c;
                if(a == i || b == i)continue;
                ra = Find(a);
                rb = Find(b);
                if(ra != rb){
                    Union(ra, rb, v[a] - v[b] + c + 3);
                }
                else{
                    if((v[b] - v[a] + 3) % 3 != c){
                        ans = max(ans, j+1);
                        tp = false;
                        break;
                    }
                }
            }
            if(tp){
                ar = i;
                pos = true;
                cnt++;
                if(cnt > 1) break;
            }
        }
        if(!pos) puts("Impossible");
        else if(cnt > 1) puts("Can not determine");
        else printf("Player %d can be determined to be the judge after %d lines\n", ar, ans);
    }
    return 0;
}
