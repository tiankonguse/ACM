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
int arr[maxn], rk[maxn], mp[maxn];
int n, mx;
bool cmp(int a, int b){
    return arr[a] < arr[b];
}
void lisan(){
    for(int i=1;i<=n;i++) rk[i] = i;
    sort(rk + 1, rk + n + 1, cmp);
    mp[1] = arr[rk[1]];
    arr[rk[1]] = mx = 1;
    for(int i=2;i<=n;i++){
        if(arr[rk[i]] == mp[mx]) arr[rk[i]] = mx;
        else mp[++mx] = arr[rk[i]], arr[rk[i]] = mx;
    }
}
int q[maxn];
int num[maxn];

int main() {
    while (~scanf("%d", &n)) {
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &arr[i]);
        }
        lisan();
        memset(num, 0, sizeof num);
        int l = 0, h = 0, cnt = 0, ret = inf;

        for (int i = 1; i <= n; ++i) {
            q[h++] = arr[i];
            if (num[ arr[i] ] == 0) ++cnt;
            ++num[ arr[i] ];
            while (l < h && num[ q[l] ] >= 2) {
                --num[ q[l] ];
                ++l;
            }
            if (cnt == mx) ret = min(ret, h - l);
        }

        printf("%d\n", ret);
    }
    return 0;
}
