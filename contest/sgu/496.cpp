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
#define N 5005
int n , ans;
int A[N] , B[N] , X[N] , Y[N];

void work()
{
    int i , j , a , b , c , d;
    scanf("%d",&n);
    for (i = 1 ; i <= n ; ++ i)
        scanf("%d%d%d%d",&A[i],&B[i],&X[i],&Y[i]);
    for (i = 1 ; i <= n ; ++ i) {
        for (j = i + 1 ; j <= n ; ++ j) {
            if (A[i] == A[j] && B[i] == B[j] || A[i] == X[j] && B[i] == Y[j] || X[i] == A[j] && Y[i] == B[j] || X[i] == X[j] && Y[i] == Y[j]) {
                a = X[i] - A[i];
                b = Y[i] - B[i];
                c = X[j] - A[j];
                d = Y[j] - B[j];
                if (a * c + b * d == 0)
                    ++ ans;
            }
        }
    }
    cout << ans << endl;
}


int main()
{
    work();
    return 0;
}

