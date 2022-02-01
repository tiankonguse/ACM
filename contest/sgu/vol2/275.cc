#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<queue>
#include<list>
#include<stack>
#include<set>
#include<map>
#include<string>
#include<algorithm>
using namespace std;
typedef __int64 ll;
#define eps 1e-12
#define maxn 110
#define maxm 1100000
#define inf 0x3f3f3f3f
#define PB push_back
#define MP make_pair

ll a[maxn];
int n, m, r;


void print() {
    puts("--");
    for (int i = 0; i < n; ++i) {
        for (int j = 10; j >= 0; --j) {
            printf("%d", (a[i] >> j) & 1);
        }
        puts("");
    }
}
int gauss() {
    int i, j, k;
    j = 0;
    for (i = m-1; i >= 0; --i) {
        for (k = j; k < n; ++k) {
            if ( (a[k] >> i) & 1 ) {
                break;
            }
        }
        if (k < n) {
            swap(a[k], a[j]);
            for (k = 0; k < n; ++k) {
                if (k != j && ( (a[k] >> i) & 1)) {
                    a[k] ^= a[j];
                }

            }
            ++j;
        }
//        print();
    }
    return j;
}
inline ll fun(int k) {
    ll res = a[0];
    for (int i = 1; i < r; ++i) {
        if (res ^ a[i] > res) {
            res ^= a[i];
        }
    }
    return res;
}
bool cmp(ll a, ll b) {
    return a < b;
}


int main()
{
    while (~scanf("%d", &n)) {
        m = 63;
        for (int i = 0; i < n; ++i) {
            scanf("%I64d", &a[i]);
        }
        r = gauss();
        printf("%I64d\n", fun(1));
    }
    return 0;
}
