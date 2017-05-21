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
#define maxn 1000100
using namespace std;
int arr[maxn];

int main() {
    int T, n;
    int h, d;
    for (scanf("%d", &T); T--; ) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &arr[i]);
        }
        h = d = 0;
        int l1 = 0, l2 = 0;
        for (int i = 1; i < n; ++i) {
            if (arr[i] > arr[i - 1]) {
                if (l2 > 0) l1 = 1;
                else ++l1;
                l2 = 0;
            }
            else if (arr[i] < arr[i - 1]) {
                ++l2;
            }
            h = max(h, min(l1, l2));
            if (arr[i] == arr[i - 1]) {
                l1 = l2 = 0;
            }
        }
        l1 = l2 = 0;
        for (int i = 1; i < n; ++i) {
            if (arr[i] < arr[i - 1]) {
                if (l1 > 0) l2 = 1;
                else ++l2;
                l1 = 0;
            }
            else if (arr[i] > arr[i - 1]) {
                ++l1;
            }
            d = max(d, min(l1, l2));
            if (arr[i] == arr[i - 1]) {
                l1 = l2 = 0;
            }
        }
        printf("%d %d\n", h, d);
    }
    return 0;
}
