#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;
typedef long long LL;

#define N 32
int m , Q;
struct Matrix
{
    int n , m ;
    int a[N][N];
    Matrix() {memset(a , 0 , sizeof(a));}
    Matrix(int _n , int _m) {
        n = _n , m = _m , memset(a , 0 , sizeof(a));
    };
    int* operator[] (int i) {
        return a[i];
    }
};
Matrix operator * (Matrix A , Matrix B)
{
    Matrix ans(A.n , B.m);
    for (int i = 0 ; i < A.n ; ++ i)
        for (int j = 0 ; j < A.m ; ++ j)
            for (int k = 0 ; k < B.m ; ++ k)
                ans[i][k] += A[i][j] * B[j][k] % Q , ans[i][k] %= Q;
    return ans;
}
char s[105];
int b[105] , len;

void work()
{
    int i , j , k;
    scanf("%s" , s);
    len = strlen(s);
    for (i = 0 ; i < len ; ++ i)
        b[i] = s[len - i - 1] - '0';
    -- b[i = 0];
    while (b[i] < 0)
        b[i] += 10 , b[i + 1] -= 1 , ++ i;
    if (b[len - 1] == 0)
        -- len;
    scanf("%d%d",&m,&Q);
    Matrix I(1 , 1 << m) , P(1 << m , 1 << m);
    for (i = 0 ; i < 1 << m ; ++ i)
        I[0][i] = 1;
    for (i = 0 ; i < 1 << m ; ++ i) {
        for (j = 0 ; j < 1 << m ; ++ j) {

            for (k = 1 ; k < m ; ++ k) {
                if ((i >> k - 1 & 1) && (i >> k & 1) && (j >> k - 1 & 1) && (j >> k & 1)) break;
                if ((~i >> k - 1 & 1) && (~i >> k & 1) && (~j >> k - 1 & 1) && (~j >> k & 1)) break;
            }
            if (k >= m)
                ++ P[i][j];
        }
    }
    while (len) {
        if (b[0] & 1)
            I = I * P;
        P = P * P;
        for (i = len - 1 , j = 0 ; i >= 0 ; -- i) {
            if (j) b[i] += 10;
            if (b[i] & 1) {
                j = 1;
            } else {
                j = 0;
            }
            b[i] >>= 1;
        }
        while (len && b[len - 1] == 0)
            -- len;
    }
    int ans = 0;
    for (i = 0 ; i < 1 << m ; ++ i)
        ans += I[0][i] , ans %= Q;
    cout << ans << endl;
}

int main()
{
    freopen("1.txt" , "r" , stdin);
    work();
    return 0;
}


