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
#define maxn 60060
using namespace std;
typedef __int64 ll;

int parents[maxn];
int Find(int a){
    return parents[a] < 0 ? a : parents[a] = Find(parents[a]);
}
void Union(int a,int b){
    if(parents[a] < parents[b]){ parents[a] += parents[b], parents[b] = a;}
    else{ parents[b] += parents[a], parents[a] = b;}
}
void finit(){
    memset(parents, 0xff, sizeof(parents));
}

struct lines {
    int a, b, r, c, id;
    lines (int _a, int _b, int _r, int _c, int _id) {
        a = _a, b = _b, r = _r, c = _c, id = _id;
    }
    lines () {}
    friend bool operator < (lines x, lines y) {
        if (x.r == y.r) return x.c < y.c;
        else return x.r < y.r;
    }
} l[maxn];

map<int, int> mp;
int main() {
    int n;
    int a, b, r, c;
    int cnt;
    ll sum;
    int ra, rb;
    while (~scanf("%d", &n)) {
        mp.clear();
        sum = 0;
        cnt = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d%d%d%d", &a, &b, &r, &c);
            if (mp.find(a) == mp.end()) {
                mp[a] = cnt++;
            }
            if (mp.find(b) == mp.end()) {
                mp[b] = cnt++;
            }
            sum += c;
            a = mp[a], b = mp[b];
            l[i] = lines(a, b, r, c, i + 1);
        }
        sort(l, l + n);
        finit();
        for (int i = n - 1; i >= 0; --i) {
            ra = Find(l[i].a);
            rb = Find(l[i].b);
            if (ra != rb) {
                Union(ra, rb);
            }
            else sum -= l[i].c;
        }
        printf("%I64d\n", sum);
        for (int i = 0; i < n; ++i) {
            if (i == n - 1) printf("%d\n", l[i].id);
            else printf("%d ", l[i].id);
        }


    }
    return 0;
}
