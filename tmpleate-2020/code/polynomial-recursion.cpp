#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <cassert>
#include <bitset>
#include <complex>
using namespace std;
typedef long long LL;

const int N = 105;
const int Q = 1e9 + 7;
LL n ;
int d[N] , c[N] , t[N] , Deg;
struct Poly
{
    int a[N];
    Poly() {
        memset(a , 0 , sizeof(a));
    }
    int& operator [] (int x) {
        return a[x];
    }
};
inline void add(int& A , int B) {
    A += B;
    if (A >= Q)
        A -= Q;
}
Poly operator * (Poly& X , Poly& Y) {
    int i , j; Poly ans;
    for (i = 0 ; i < Deg ; ++ i)
        for (j = 0 ; j < Deg ; ++ j)
            add(ans[i + j] , (LL)X[i] * Y[j] % Q);
    for (i = Deg + Deg - 2 ; i >= Deg ; -- i) {
        for (j = 1 ; j <= Deg ; ++ j)
            add(ans[i - j] , (LL)ans[i] * c[j] % Q);
        ans[i] = 0;
    }
    return ans;
}

void work() {
    memset(c , 0 , sizeof(c));
    memset(d , 0 , sizeof(d));

    Deg = 2;
    d[0] = 3 , d[1] = 4;
    c[2] = 1 , c[1] = 2;
    n = 3;
    /*  c 为转移关系
    d 为初值 Deg 为阶数*/
    //Fi = 2 * Fi-1 + 1 * Fi - 2
    //F0 = 3 , F1 = 4 , F2 = 11 , F3 = 26...
    Poly ans , P;
    P[1] = 1 , ans[0] = 1;
    while (n) {
        if (n & 1)
            ans = ans * P;
        P = P * P , n >>= 1;
    }
    int res = 0;
    for (int i = 0 ; i < Deg ; ++ i) {
        add(res , (LL)d[i] * ans[i] % Q);
    }
    printf("%d\n" , res);
}

int main()
{
    work();
    return 0;
}
