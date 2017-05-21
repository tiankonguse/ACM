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
#define MAXN 50001

int parents[MAXN], v[MAXN], res;
int Find(int a){
    if(!parents[a]) return a;
    else{
        int t = parents[a];
        parents[a] = Find(parents[a]);
        v[a] = (v[a] + v[t]) ;
        return parents[a];
    }
}
int ra, rb;
void Union(int a,int b,int d){
    ra = Find(a), rb = Find(b);
    if(ra != rb){
        parents[rb] = ra;
        v[rb] = (v[a] - v[b] + d ) ;
    }
    else{
        if((v[b] - v[a] - d) % 3 != 0) ++res;
    }
}

int ret; char tmp;
int getint(){
    ret = 0;
    while(!isdigit(tmp=getchar()));
    do{
  	ret=(ret<<3)+(ret<<1)+tmp-'0';
    }while(isdigit(tmp=getchar()));
    return ret;
}
int main(){
    int N,K,D,a,b;
    N = getint();
    K = getint();
    while(K--){
        D = getint();
        a = getint();
        b = getint();
        if(a > N || b > N) ++res;
        else Union(a, b, D - 1);
    }
    printf("%d\n", res);
    return 0;
}
