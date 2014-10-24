#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <cassert>
//#pragma comment(linker, "/STACK:16777216")
using namespace std;
typedef long long LL;

const int N = 300005;
int n , m , K;
int d[N << 1] , D;
struct Range {
    int l , r , w;
    Range () {}
    Range (int _l , int _r , int _w) {
        l = _l , r = _r , w = _w;
    }
    bool operator < (const Range& R) const {
        return r < R.r;
    }
}a[N];
inline int id(int l , int r) {return l + r | l != r;}
#define MID int mid = l + r >> 1
#define Left l , mid
#define Right mid + 1 , r
struct stree {
    LL mx , f;
}t[N << 2];
void Build(int l , int r) {
    int p = id(l , r);
    t[p].f = 0;
    if (l == r) {
        t[p].mx = d[l + 1] - 1;
    } else {
        MID; Build(Left); Build(Right);
        t[p].mx = t[id(Right)].mx;
    }
}
void add(int l , int r , int top , int bot , int w) {
    int p = id(l , r);
    if (top <= l && r <= bot) {
        t[p].mx += w , t[p].f += w;
        return;
    } MID; int L = id(Left) , R = id(Right);
    if (t[p].f) {
        t[L].mx += t[p].f , t[R].mx += t[p].f;
        t[L].f += t[p].f , t[R].f += t[p].f , t[p].f = 0;
    }
    if (top <= mid) add(Left , top , bot , w);
    if (bot > mid) add(Right , top , bot , w);
    t[p].mx = max(t[L].mx , t[R].mx);
}
LL getmax(int l , int r , int top , int bot) {
    int p = id(l , r);
    if (top <= l && r <= bot)
        return t[p].mx;
    MID; int L = id(Left) , R = id(Right);
    if (t[p].f) {
        t[L].mx += t[p].f , t[R].mx += t[p].f;
        t[L].f += t[p].f , t[R].f += t[p].f , t[p].f = 0;
    } LL res = -1LL << 60;
    if (top <= mid) res = max(res , getmax(Left , top , bot));
    if (bot > mid) res = max(res , getmax(Right , top , bot));
    return res;
}

void work() {
    int i , j , k , l , r , x;
    LL cnt = 0;
    D = K = 0;
    d[D ++] = 0 , d[D ++] = m + m;
    for (i = 0 ; i < n ; ++ i) {
        scanf("%d%d%d",&l,&r,&x); //[l , r)
        cnt += x;
        if (l <= r) {
            if (r - l + 1 < x) cnt = m + 1;
            ++ r;
            a[K ++] = Range(l , r , x);
            a[K ++] = Range(l + m , r + m , x);
            d[D ++] = l , d[D ++] = r , d[D ++] = l + m , d[D ++] = r + m;
            d[D ++] = l + 1 , d[D ++] = l + m + 1;
        } else {
            if (r + m - l + 1 < x) cnt = m + 1;
            a[K ++] = Range(l , r + m + 1 , x);
            d[D ++] = l , d[D ++] = r + m + 1 , d[D ++] = l + 1;
        }
    }
    if (cnt > m) {
        puts("No");
        return;
    }

    sort(d , d + D) , D = unique(d , d + D) - d , n = K;
    for (i = 0 ; i < n ; ++ i) {
        a[i].l = lower_bound(d , d + D , a[i].l) - d;
        a[i].r = lower_bound(d , d + D , a[i].r) - d;
    }
    sort(a , a + n);
    //for (i = 0 ; i < n ; ++ i)
    //    printf("%d %d %d\n" , a[i].l , a[i].r , a[i].w);
    //printf("%d\n" , D);

    bool res = 0;
    Build(0 , D - 2); // The range i equal to [D[i] , D[i + 1])
    for (i = 0 ; i < n && !res ; ++ i) {
        add(0 , D - 2 , 0 , a[i].l , a[i].w);
        if (d[a[i].r] > m) {
            j = d[a[i].r] - m , k = upper_bound(d , d + D , j) - d - 1;
            if (getmax(0 , D - 2 , k , a[i].r - 1) > d[a[i].r])
                res = 1;
        }
    }
    puts(res ? "No" : "Yes");
}

int main()
{
    while (~scanf("%d%d",&n,&m))
        work();
    return 0;
}
