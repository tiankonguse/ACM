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
#define maxn 10010
using namespace std;
int m[maxn], d[maxn];
double ma[maxn * 3], da[maxn * 3];
int main(){
    int p, q, r, s, a;
    int c1, c2;
    while(~scanf("%d%d%d%d", &p, &q, &r, &s)){
        memset(m, 0, sizeof(m));
        memset(d, 0, sizeof(d));
        for(int i=1;i<=p;i++) m[i]++;
        for(int i=1;i<=s;i++) m[i]++;
        for(int i=1;i<=r-s;i++) m[i]++;
        for(int i=1;i<=q;i++) d[i]++;
        for(int i=1;i<=r;i++) d[i]++;
        for(int i=1;i<=p-q;i++) d[i]++;
        for(int i=1;i<=10000;i++){
            a = min(m[i], d[i]);
            m[i] -= a;
            d[i] -= a;
        }
        c1 = c2 = 0;
        for(int i=1;i<=10000;i++){
            for(int j=1;j<=m[i];j++) ma[c1++] = 1.0 * i;
            for(int j=1;j<=d[i];j++) da[c2++] = 1.0 * i;
        }
        int p1 = 0, p2 = 0;
        double res = 1.0;
        while(p1 < c1){
            res *= ma[p1++];
            if(res > 1e11){
                while(p2 < c2){
                    res /= da[p2++];
                    if(res < 1) break;
                }
            }
        }
        while(p2 < c2) res /= da[p2++];
        printf("%.5lf\n", res);
    }
    return 0;
}
