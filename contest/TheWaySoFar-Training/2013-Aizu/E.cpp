#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <algorithm>
#define N 362880
using namespace std;

int fac[10];
int A , B;

void inttoA(int x , int* a) {
    bool u[10] = {};
    int i , j , y;
    for (i = 0 ; i < 9 ; ++ i) {
        y = x / fac[8 - i];
        for (j = 0 ; j < 9 ; ++ j)
            if (!u[j]) {
            if (y == 0)
                break;
            -- y;
        }
        a[i] = j , u[j] = 1 , x %= fac[8 - i];
    }
}
void Atoint(int *a , int& x) {
    int i , j , y; x = 0;
    for (i = 0 ; i < 9 ; ++ i) {
        y = a[i];
        for (j = 0 ; j < i ; ++ j)
            if (a[j] < a[i])
                -- y;
        x += fac[8 - i] * y;
    }
}
bool f[N];
int d[N];
struct opt {
    int x , w;
    opt (int _x , int _w) {
        x = _x , w = _w;
    }
    bool operator < (const opt& R) const {
        return w > R.w;
    }
};
int st , ed;
priority_queue <opt> Q;
void update(int x , int w) {
    if (!f[x] && d[x] > w) {
        d[x] = w , Q.push(opt(x , w));
    }
}


void work() {
    int i , x , y , w;
    int a[9] , b[9];
    for (i = 0 ; i < 9 ; ++ i)
        scanf("%d",&a[i]);
    for (i = 0 ; i < 9 ; ++ i)
        scanf("%d",&b[i]);
    Atoint(a , st) , Atoint(b , ed);

    while (!Q.empty()) Q.pop();
    memset(d , 63 , sizeof(d));
    memset(f , 0 , sizeof(f));
    d[st] = 0;
    Q.push(opt(st , 0));
    while (!Q.empty()) {
        x = Q.top().x , w = Q.top().w , Q.pop();
        if (f[x]) continue; f[x] = 1;
        if (x == ed) {
            printf("%d\n" , w);
            break;
        }
        inttoA(x , a);
        for (i = 0 ; i < 9 ; ++ i)
            if (!a[i])
                break;
        swap(a[i] , a[(i + 1) % 9]);
        Atoint(a , y);
        update(y , w + A);
        swap(a[i] , a[(i + 1) % 9]);
        swap(a[i] , a[(i + 8) % 9]);
        Atoint(a , y);
        update(y , w + A);
        swap(a[i] , a[(i + 8) % 9]);
        swap(a[i] , a[(i + 3) % 9]);
        Atoint(a , y);
        update(y , w + B);
        swap(a[i] , a[(i + 3) % 9]);
        swap(a[i] , a[(i + 6) % 9]);
        Atoint(a , y);
        update(y , w + B);
        swap(a[i] , a[(i + 6) % 9]);
    }
}

int main() {
    //freopen("1.txt" , "r" , stdin);
    fac[0] = 1;
    for (int i = 1 ; i < 10 ; ++ i)
        fac[i] = fac[i - 1] * i;
    while (scanf("%d%d",&A,&B) , A || B)
        work();
    return 0;
}
