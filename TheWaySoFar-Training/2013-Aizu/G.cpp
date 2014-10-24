#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 300005
using namespace std;
int n , m , a , b;
int C = ~(1<<31), M = (1<<16)-1;
int r() {
  a = 36969 * (a & M) + (a >> 16);
  b = 18000 * (b & M) + (b >> 16);
  return (C & ((a << 16) + b)) % 1000000;
}

struct Point {
    int x , y , z;
    bool operator < (const Point& R) const {
        return x < R.x;
    }
}p[N];
struct query {
    int x , y , z , id;
    query () {}
    query (int _x , int _y , int _z , int _id) {
        x = _x , y = _y , z = _z , id = _id;
    }
    bool operator < (const query& R) const {
        if (y != R.y) return y < R.y;
        if (id != R.id) return id > R.id;
        return z < R.z;
    }
}t[N];
int cnt , D , d[N];
int f[N] , c[N] , g[N];
void add(int* c , int x , int w) {
    for ( ; x <= D ; x += x & -x)
        c[x] = max(c[x] , w);
}
int get(int* c , int x) {
    int res = 0;
    for ( ; x > 0 ; x -= x & -x)
        res = max(res , c[x]);
    return res;
}
void clr(int* c , int x) {
    for ( ; x <= D ; x += x & -x)
        c[x] = 0;
}
void solve(int l , int r)
{
    if (l >= r) return;
    int mid = (l + r) >> 1 , tx = p[mid + 1].x;
    solve(l , mid);
    cnt = 0;
    for (int i = l ; i <= r ; ++ i)
        t[cnt ++] = query(p[i].x , p[i].y , p[i].z , i);
    sort(t , t + cnt);
    for (int i = 0 ; i < cnt ; ++ i)
        if (t[i].id <= mid) {
            add(c , t[i].z , f[t[i].id]);
            if (t[i].x != tx)
                add(g , t[i].z , f[t[i].id]);
        } else {
            if (t[i].x != tx)
                f[t[i].id] = max(f[t[i].id] , get(c , t[i].z - 1) + 1);
            else
                f[t[i].id] = max(f[t[i].id] , get(g , t[i].z - 1) + 1);
        }
    for (int i = 0 ; i < cnt ; ++ i)
        if (t[i].id <= mid)
            clr(c , t[i].z) , clr(g , t[i].z);
    solve(mid + 1 , r);
}

void work() {
    int i ; D = 0;
    for (i = 1 ; i <= m ; ++ i)
        scanf("%d%d%d",&p[i].x,&p[i].y,&p[i].z);
    for (i = m + 1 ; i <= m + n ; ++ i)
        p[i].x = r() , p[i].y = r() , p[i].z = r();
    n += m , sort(p + 1 , p + 1 + n);
    for (i = 1 ; i <= n ; ++ i)
        f[i] = 1 , d[D ++] = p[i].z;
    sort(d , d + D) , D = unique(d , d + D) - d;
    for (i = 1 ; i <= n ; ++ i)
        p[i].z = lower_bound(d , d + D , p[i].z) - d + 1;
    solve(1 , n);
    int ans = 0;
    for (i = 1 ; i <= n ; ++ i)
        ans = max(ans , f[i]);
    printf("%d\n" , ans);
}

int main() {
    while (scanf("%d%d%d%d",&m,&n,&a,&b) , n || m || a || b)
        work();
    return 0;
}
