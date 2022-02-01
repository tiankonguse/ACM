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
#define MAXN 5050
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
int ra,rb;
bool Union(int a,int b,int d){
    ra = Find(a), rb = Find(b);
    if(ra != rb){
        parents[rb] = ra;
        v[rb] = (v[a] + v[b] + d);
    }
    else{
        return ((v[a] + v[b] + d) % 2 == 0);
    }
    return true;
}
void init(){
    memset(v, 0, sizeof(v));
    memset(parents, 0xff, sizeof(parents));
}
char str[50];
map<int, int>mp;
int main(){
    int N,M,a,b,d,cnt,res;
    bool flag;
    while(~scanf("%d%d",&N,&M)){
        init();
        res = cnt = 0;
        flag = true;
        mp.clear();
        while(M--){
            if(!flag){
                gets(str);
                continue;
            }
            scanf("%d%d%s",&a,&b,str);
            b++;
            if(mp.find(a) == mp.end()) mp[a] = cnt++;
            if(mp.find(b) == mp.end()) mp[b] = cnt++;
            if(str[0] == 'e') d = 0;
            else d = 1;
            flag = Union(mp[a], mp[b], d);
            if(flag) res++;
            else getchar();
        }
        printf("%d\n",res);
    }
    return 0;
}
