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
#include <cassert>
using namespace std;
typedef long long LL;
#define N 2005
int n , m , S;
char Ap[256];
char s[N] , t[N];
int w[256][256] , f[N][N];
int A[N] , B[N];
char a[N << 1] , b[N << 1];
int sa , sb;
void print(int i , int j) {
    if (i == 0 && j == 0) return;
    if (f[i][j] == f[i - 1][j] + w[s[i - 1]][A[s[i - 1]]]) {
        print(i - 1 , j);
        a[sa ++] = s[i - 1];
        b[sb ++] = A[s[i - 1]];
        return;
    }
    if (f[i][j] == f[i][j - 1] + w[B[t[j - 1]]][t[j - 1]]) {
        print(i , j - 1);
        a[sa ++] = B[t[j - 1]];
        b[sb ++] = t[j - 1];
        return;
    }
    if (f[i][j] == f[i - 1][j - 1] + w[s[i - 1]][t[j - 1]]) {
        print(i - 1 , j - 1);
        a[sa ++] = s[i - 1];
        b[sb ++] = t[j - 1];
        return;
    }
}

void work()
{
    int i , j , k;
    cin >> Ap >> s >> t;
    n = strlen(s) , m = strlen(t);
    S = strlen(Ap);
    memset(w , 63 , sizeof(w));
    for (i = 0 ; i < S ; ++ i) {
        for (j = 0 ; j < S ; ++ j) {
            scanf("%d",&k);
            w[Ap[i]][Ap[j]] = k;
        }
    }
    for (i = 0 ; i < 256 ; ++ i) {
        A[i] = B[i] = 0;
        for (j = 1 ; j < 256 ; ++ j) {
            if (w[i][j] < w[i][A[i]])
                A[i] = j;
            if (w[j][i] < w[B[i]][i])
                B[i] = j;
        }
    }
    memset(f , 63 , sizeof(f));
    f[0][0] = 0;
    for (i = 0 ; i <= n ; ++ i) {
        for (j = 0 ; j <= m ; ++ j) {
            if (f[i][j] >= 0x3F3F3F3F) continue;
            if (i < n) {
                f[i + 1][j] = min(f[i + 1][j] , f[i][j] + w[s[i]][A[s[i]]]);
            }
            if (j < m) {
                f[i][j + 1] = min(f[i][j + 1] , f[i][j] + w[B[t[j]]][t[j]]);
            }
            if (i < n && j < m) {
                f[i + 1][j + 1] = min(f[i + 1][j + 1] , f[i][j] + w[s[i]][t[j]]);
            }
        }
    }
    printf("%d\n" , f[n][m]);
    print(n , m);
    a[sa] = b[sb] = 0;
    cout << a << endl << b << endl;
}

int main()
{
    freopen("1.txt" , "r" , stdin);
    //while (~scanf("%d",&n))
        work();
    return 0;
}


