#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <ctime>

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
using namespace std;
typedef long long ll;
int const maxn = 70070;
int a[maxn], tmp[maxn], n;
void merge_sort(int l, int r, ll &cnt) {
    if (l < r) {
        int mid = (l + r) >> 1;
        merge_sort(l, mid, cnt);
        merge_sort(mid + 1, r, cnt);
        int i = l, j = mid + 1, k = l;
        for (; i <= mid && j <= r; ) {
            if (a[i] > a[j]) {
                cnt += mid - i + 1;
                tmp[k++] = a[j++];
            }
            else {
                tmp[k++] = a[i++];
            }
        }
        for (; i <= mid; ++i) tmp[k++] = a[i];
        for (; j <= r; ++j) tmp[k++] = a[j];
        for (i = l; i <= r; ++i) a[i] = tmp[i];
    }
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
	ll ret = 0;
	merge_sort(0, n - 1, ret);
	printf("%I64d\n", ret);
	return 0;
}

