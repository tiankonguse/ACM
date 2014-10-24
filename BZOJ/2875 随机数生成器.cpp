#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
#define N 200005
typedef long long LL;
LL n , a , c , m , X , g;

LL multi(LL A , LL B)
{
    LL ans = 0;
    for ( ; B ; A += A , A %= m , B >>= 1)
        if (B & 1)
            ans += A , ans %= m;
    return ans;
}

struct matrix
{
    int n , m;
    LL a[2][2];
    matrix (int _n , int _m) { n = _n , m = _m , memset(a , 0 , sizeof(a));}
};

matrix operator * (matrix A , matrix B)
{
    matrix ans(A.n , B.m);
    for (int i = 0 ; i < A.n ; ++ i)
        for (int j = 0 ; j < B.m ; ++ j)
            for (int k = 0 ; k < A.m ; ++ k)
                ans.a[i][j] += multi(A.a[i][k] , B.a[k][j]) , ans.a[i][j] %= m;
    return ans;
}

int main()
{
    freopen("~input.txt" , "r" , stdin);
    cin >> m >> a >> c >> X >> n >> g;
    matrix I(1 , 2) , P(2 , 2);
    I.a[0][0] = X , I.a[0][1] = 1;
    P.a[0][0] = a , P.a[1][0] = c , P.a[1][1] = 1;

    for ( ; n ; P = P * P , n >>= 1)
        if (n & 1)
            I = I * P;
    cout << I.a[0][0] % g << endl;
    return 0;
}
