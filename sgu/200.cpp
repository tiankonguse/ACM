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

#define N 105
using namespace std;

int a[N][N];
bool f[N * N];
int tot , p[N] , n , m;
int b[N] , len;
void work()
{
    int i , j , k , x;
    scanf("%d%d",&m,&n);
    for (i = 2 ; i * i <= 1000 ; ++ i) if (!f[i])
        for (j = i * i ; j <= 1000 ; j += i) f[j] = 1;
    for (i = 2 ; i <= 1000 && tot < m ; ++ i) if (!f[i])
        p[tot ++] = i;
    for (i = 0 ; i < n ; ++ i) {
        scanf("%d",&x);
        for (j = 0 ; j < m ; ++ j) {
            while (x % p[j] == 0)
                x /= p[j] , a[j][i] ^= 1;
        }
    }

    int rank = 0;
    for (i = 0 ; i < n ; ++ i) {
        int pivot = rank;
        while (pivot < m && !a[pivot][i])
            ++ pivot;
        if (pivot >= m) continue;
        for (j = 0 ; j < n ; ++ j)
            swap(a[rank][j] , a[pivot][j]);
        for (k = 0 ; k < m ; ++ k) {
            if (k != rank && a[k][i])
                for (j = 0 ; j < n ; ++ j) {
                    a[k][j] ^= a[rank][j];
                }
        }
        ++ rank;
    }
    b[0] = 1 , len = 1;
    rank = n - rank;
    for (i = 0 ; i < rank ; ++ i) {

        for (j = 0 ; j < len ; ++ j) {
            b[j] <<= 1;
        }
        for (j = 0 ; j < len ; ++ j) {
            b[j + 1] += b[j] / 10;
            b[j] %= 10;
        }
        while (b[len])
            ++ len;
    }
    -- b[0];
    for (i = len - 1 ; i >= 0 ; -- i)
        printf("%d" , b[i]);
    puts("");
}


int main()
{
    freopen("~input.txt" , "r" , stdin);
    work();
    return 0;
}
