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
#define maxp 10100
using namespace std;
int parents[maxn];
int Find(int a){
  return parents[a] < 0? a: parents[a] = Find(parents[a]);
}
void Union(int a, int b){
	if(parents[a] < parents[b]){
		parents[a] += parents[b];
		parents[b] = a;
	}
	else{
		parents[b] += parents[a];
		parents[a] = b;
	}
}
void init(){
	memset(parents, 0xff, sizeof(parents));
}
int comu[maxp][2];
bool mark[maxn];
int main(){
    int n, p, a, b, res, tr, ra, rb;
    while(~scanf("%d%d", &n, &p)){
        memset(mark, false, sizeof(mark));
        for(int i=0;i<p;i++){
            scanf("%d%d", &a, &b);
            if(a > b) swap(a, b);
            comu[i][0] = a, comu[i][1] = b;
            mark[a] = mark[b] = mark[a - 1] = true;
        }
        res = inf;
        for(int s=1;s<=n;s++){
            if(!mark[s]) continue;
            init();
            tr = 0;
            for(int j=0;j<p;j++){
                a = comu[j][0], b = comu[j][1];
                if(s >= a && s < b){
                    for(int k=1;k<=a;k++){
                        ra = Find(1);
                        rb = Find(k);
                        if(ra != rb){
                            tr++;
                            Union(ra, rb);
                        }
                        if(Find(a) == Find(1)) break;
                    }
                    ra = Find(1);
                    rb = Find(n);
                    if(ra != rb){
                        tr++;
                        Union(ra, rb);
                    }
                    for(int k=n;k>=b;k--){
                        ra = Find(k);
                        rb = Find(n);
                        if(ra != rb){
                            tr++;
                            Union(ra, rb);
                        }
                        if(Find(b) == Find(n)) break;
                    }
                    //printf("%d, %d %d\n", s, j, tr);
                }
                else{
                    for(int k=b;k>=a;k--){
                        ra = Find(b);
                        rb = Find(k);
                        if(ra != rb){
                            tr++;
                            Union(ra, rb);
                        }
                        if(Find(a) == Find(b)) break;
                    }
                }
             //   printf("%d, %d %d\n", s, j, tr);
            }
           // printf("%d %d\n", s, tr);
            res = min(res, tr);
        }
        printf("%d\n", res);
    }
    return 0;
}
