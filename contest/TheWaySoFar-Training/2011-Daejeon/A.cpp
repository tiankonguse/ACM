#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;

#define N 2005
int n;
int dx[N] , Dx , Dy , dy[N];
struct box {
    int x1 , y1 , x2 , y2;
    bool operator < (const box& R) const{
        return y1 < R.y1;
    }
}a[N] , tmp;

int t[200005];
int f[200005];
int id(int l , int r) {return l + r | l != r;}
#define MID int mid = l + r >> 1
#define Left l , mid
#define Right mid + 1 , r

void insert(int l , int r , int top , int bot , int w) {
    int p = id(l , r);
    if (top <= l && r <= bot) {
        t[p] = w , f[p] = w;
        return;
    } MID;int L = id(Left) , R = id(Right);
    if (f[p]) {
        f[L] = t[L] = f[R] = t[R] = f[p];
        f[p] = 0;
    }
    if (top <= mid) insert(Left , top , bot , w);
    if (bot > mid) insert(Right , top , bot , w);
    t[p] = max(t[L] , t[R]);
}
int query(int l , int r , int top , int bot) {
    int p = id(l , r);
    if (top <= l && r <= bot) {
        return t[p];
    } MID;
    if (f[p]) {
        int L = id(Left) , R = id(Right);
        f[L] = t[L] = f[R] = t[R] = f[p];
        f[p] = 0;
    }
    int val = 0;
    if (top <= mid) val = max(val , query(Left , top , bot));
    if (bot > mid) val = max(val , query(Right , top , bot));
    return val;
}

bool roller() {
    bool hahaha = 0;
    sort(a , a + n);
    memset(t , 0 , sizeof(t));
    memset(f , 0 , sizeof(f));
    for (int i = 0 , h ; i < n ; ++ i) {
        h = a[i].y1 - query(0 , 99999 , a[i].x1 , a[i].x2 - 1);
        a[i].y2 -= h;
        a[i].y1 -= h;
        insert(0 , 99999 , a[i].x1 , a[i].x2 - 1 , a[i].y2);
        if (h) hahaha = 1;
    }
    return hahaha;
}

void work()
{
    int i , j , x , y;
    scanf("%d",&n);
    Dx = Dy = 0;
    for (i = 0 ; i < n ; ++ i) {
        scanf("%d%d",&x,&y);
        a[i].x1 = x , a[i].y1 = y;
        //dx[Dx ++] = x , dy[Dy ++] = y;
        scanf("%d%d",&x,&y);
        a[i].x2 = x , a[i].y2 = y;
        //dx[Dx ++] = x , dy[Dy ++] = y;
    }
//    sort(dx , dx + Dx) , sort(dy , dy + Dy);
//    Dx = unique(dx , dx + Dx) - dx;
//    Dy = unique(dy , dy + Dy) - dy;
//
//    for (i = 1 ; i <= n ; ++ i) {
//        a[i].first = lower_bound(dx , dx + Dx , a[i].first) - dx;
//        b[i].first = lower_bound(dx , dx + Dx , b[i].first) - dx;
//        a[i].second = lower_bound(dy , dy + Dy , a[i].second) - dy;
//        b[i].second = lower_bound(dy , dy + Dy , b[i].second) - dy;
//    }

    while (1) {
        x = 0;
        x = x << 1 | roller();
        for (i = 0 ; i < n ; ++ i) {
            swap(a[i].x1 , a[i].y1);
            swap(a[i].x2 , a[i].y2);
        }
        x = x << 1 | roller();
        for (i = 0 ; i < n ; ++ i) {
            swap(a[i].x1 , a[i].y1);
            swap(a[i].x2 , a[i].y2);
        }
        if (x == 0) break;
    }
    x = y = 0;
    for (i = 0 ; i < n ; ++ i) {
        x = max(x , a[i].x2);
        y = max(y , a[i].y2);
    }
    printf("%d %d\n" , x , y);
}

int main(){
    //freopen("1.txt" , "r" , stdin);
    int _; scanf("%d",&_); while (_ --)
        work();
    return 0;
}
