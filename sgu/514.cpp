#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <cmath>
using namespace std;
typedef long long LL;
#define N 105
int n;
int L[10] , sum[1 << 10];

void work()
{
    int i , j , k , a , b , c;
    int I , J , A , B;
    int W[3];
    scanf("%d",&n);
    for (i = 0 ; i < n ; ++ i)
        scanf("%d",&L[i]);
    sort(L , L + n);
    for (i = 0 ; i < 1 << n ; ++ i)
        for (j = 0 ; j < n ; ++ j)
            if (i >> j & 1)
                sum[i] += L[j];
    int mask = (1 << n) - 1;
    LL ans = 1LL << 60;
    for (i = 0 ; i < 1 << n ; ++ i) {
        I = mask ^ i;
        for (a = I ; a ; a = (a - 1) & I) {
            if (sum[i] > sum[a]) continue;
            A = I ^ a;
            for (j = A ;  ; j = (j - 1) & A) {
                J = A ^ j;
                for (b = J ; b ; b = (b - 1) & J) {
                    if (sum[j] > sum[b]) continue;
                    B = J ^ b;
                    for (k = B ;  ; k = (k - 1) & B) {
                        c = B ^ k;
                        if (sum[k] <= sum[c]) {
                            W[0] = sum[a] - sum[i] , W[1] = sum[b] - sum[j] , W[2] = sum[c] - sum[k];
                            sort(W , W + 3);
                            if (W[0] + W[1] >= W[2]) {
                                int p = W[0] + W[1] + W[2];
                                ans = min(ans , (LL)p * (p - W[0] - W[0]) * (p - W[1] - W[1]) * (p - W[2] - W[2]));
                            }
                        }
                        if (!k) break;
                    }

                }
                if (!j) break;
            }
        }
    }
    printf("%.12f\n" , sqrt(ans) / 4);
}

int main()
{
    work();
    return 0;
}
