#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
#define maxn 1010
using namespace std;
int res[maxn] = {0, 1, 5, 11, 20};

int main() {
    int a = 3, b = 3;
    for (int i = 5; i <= 1000; ++i) {
        if (a < b) {
            res[i] = res[i - 1] + b * b;
            ++a;
        }
        else {
            ++b;
            res[i] = res[i - 1] + a * b;
        }
    }
    int n;
    while (~scanf("%d", &n)) {
        printf("%d\n", res[n]);
    }
    return 0;
}
