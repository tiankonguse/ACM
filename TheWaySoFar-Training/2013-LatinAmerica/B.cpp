#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <cassert>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <cmath>
using namespace std;
typedef long long LL;
#define N 100005
int n , m , Q;
int a[N];
char S[N] , T[10];
bool c[N];
inline bool get(int x) {
    bool res = 0;
    for ( ; x > 0 ; x -= x & -x)
        res ^= c[x];
    return res;
}
inline void cover(int x) {
    for ( ; x <= n ; x += x & -x)
        c[x] ^= 1;
}

struct stree {
    bool rev;
    int mx , mn;
}t[N << 1];
#define MID int mid = (l + r) >> 1
#define Left l , mid
#define Right mid + 1 , r
inline int id(int l , int r) { return l + r | l != r; }
inline void pushup(int p , int l , int mid , int r) {
    int L = id(Left) , R = id(Right);
    t[p].mx = max(t[L].mx , t[R].mx);
    if (!~t[L].mn) t[p].mn = t[R].mn;
    else if (!~t[R].mn) t[p].mn = t[L].mn;
    else t[p].mn = min(t[L].mn , t[R].mn);
}
inline void pushdown(int p , int l , int mid , int r) {
    int L = id(Left) , R = id(Right);
    if (t[p].rev) {
        swap(t[L].mn , t[L].mx);
        if (~t[L].mn) t[L].mn = m - t[L].mn , t[L].mx = m - t[L].mx;
        swap(t[R].mn , t[R].mx);
        if (~t[R].mn) t[R].mn = m - t[R].mn , t[R].mx = m - t[R].mx;
        t[L].rev ^= 1 , t[R].rev ^= 1 , t[p].rev ^= 1;
    }
}
void Build(int l , int r) {
    int p = id(l , r);
    t[p].rev = 0;
    if (l == r) {
        t[p].mx = t[p].mn = a[l];
    } else {
        MID; Build(Left); Build(Right);
        pushup(p , l , mid , r);
    }
}
int Query(int l , int r , int top , int bot) {
    int p = id(l , r);
    if (top <= l && r <= bot)
        return t[p].mx;
    int res = -1; MID; pushdown(p , l , mid , r);
    if (top <= mid) res = max(res , Query(Left , top , bot));
    if (bot > mid) res = max(res , Query(Right , top , bot));
    return res;
}
void reverse(int l , int r , int top , int bot) {
    int p = id(l , r);
    if (top <= l && r <= bot){
        t[p].rev ^= 1;
        swap(t[p].mn , t[p].mx);
        if (~t[p].mn) t[p].mn = m - t[p].mn , t[p].mx = m - t[p].mx;
        return;
    }
    MID; pushdown(p , l , mid , r);
    if (top <= mid) reverse(Left , top , bot);
    if (bot > mid) reverse(Right , top , bot);
    pushup(p , l , mid , r);
}
void modify(int l , int r , int x , int w) {
    int p = id(l , r);
    if (x <= l && r <= x) {
        t[p].mx = t[p].mn = w;
        return;
    } MID; pushdown(p , l , mid , r);
    if (x <= mid) modify(Left , x , w);
    if (x > mid) modify(Right , x , w);
    pushup(p , l , mid , r);
}

void work() {
    int i , j , x , y , l , r;
    scanf("%s" , S + 1);
    n = strlen(S + 1) , m = strlen(T);
    for (i = 1 ; i <= n ; ++ i) {
        a[i] = c[i] = 0;
        for (j = 0 ; j < m ; ++ j) {
            if (tolower(S[i + j]) != tolower(T[j]))
                break;
            if (S[i + j] != T[j])
                ++ a[i];
        }
        if (j < m)
            a[i] = -1;
    }
    Build(1 , n);
    while (Q --) {
        scanf("%d%d",&l,&r);
        cover(l) , cover(r + 1);
        if (r - l + 1 < m) {
            puts("-1");
            for (i = max(1 , l - m + 1) ; i <= r ; ++ i) {
                if (!~a[i]) continue;
                x = 0;
                for (j = 0 ; j < m ; ++ j) {
                    if ((S[i + j] != T[j]) ^ get(i + j))
                        ++ x;
                }
                modify(1 , n , i , x);
            }
        } else {
            printf("%d\n" , Query(1 , n , l , r - m + 1));
            reverse(1 , n , l , r - m + 1);
            for (i = max(1 , l - m + 1) ; i < l ; ++ i) {
                if (!~a[i]) continue;
                x = 0;
                for (j = 0 ; j < m ; ++ j) {
                    if ((S[i + j] != T[j]) ^ get(i + j))
                        ++ x;
                }
                modify(1 , n , i , x);
            }
            for (i = max(1 , r - m + 2) ; i <= r ; ++ i) {
                if (!~a[i]) continue;
                x = 0;
                for (j = 0 ; j < m ; ++ j) {
                    if ((S[i + j] != T[j]) ^ get(i + j))
                        ++ x;
                }
                modify(1 , n , i , x);
            }
        }

    }
}

int main(){
    while (~scanf("%d%s" , &Q , T) && Q)
        work();
    return 0;
}
