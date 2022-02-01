#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 51
int n , m , a , b , c , T;
struct Matrix
{
    int n , m;
    int a[N][N];
    Matrix(int _n , int _m)
    {
        n = _n , m = _m;
        memset(a , 0 , sizeof(a));
    }
};
Matrix operator * (Matrix A , Matrix B)
{
    Matrix res(A.n , B.m);
    for (int i = 0 ; i < A.n ; ++ i)
        for (int j = 0 ; j < A.m ; ++ j)
            for (int k = 0 ; k < B.m ; ++ k)
                res.a[i][k] += A.a[i][j] * B.a[j][k] % m , res.a[i][k] %= m;
    return res;
}

int main(){

    while (scanf("%d%d%d%d%d%d",&n,&m,&a,&b,&c,&T) , n)
    {
        int i , x;
        Matrix I(1 , n) , P(n , n);
        for (i = 0 ; i < n ; ++ i)
            scanf("%d",&I.a[0][i]);
        for (i = 0 ; i < n ; ++ i)
        {
            if (i) P.a[i - 1][i] = a;
            P.a[i][i] = b;
            if (i + 1 < n) P.a[i + 1][i] = c;
        }
        while (T)
        {
            if (T & 1)
                I = I * P;
            P = P * P , T >>= 1;
        }
        for (i = 0 ; i < n ; ++ i)
            printf("%d%c" , I.a[0][i] , " \n"[i + 1 == n]);
    }
}
