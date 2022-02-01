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
#include <ctime>

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL

using namespace std;
int const maxn = 1010;
int s[maxn], t[maxn], mp[maxn];
int a[maxn], tmp[maxn], n;
void merge_sort(int l, int r, int &cnt){
    if(l < r){
        int mid = (l + r) >> 1;
        merge_sort(l, mid, cnt);
        merge_sort(mid + 1, r, cnt);
        int i = l, j = mid + 1, k = l;
        for(;i<=mid && j<=r;){
            if(a[i] > a[j]){
                cnt += mid - i + 1;
                tmp[k++] = a[j++];
            }
            else{
                tmp[k++] = a[i++];
            }
        }
        for(;i<=mid;i++) tmp[k++] = a[i];
        for(;j<=r;j++) tmp[k++] = a[j];
        for(i=l;i<=r;i++) a[i] = tmp[i];
    }
}
int main()
{
    for (; ~scanf("%d", &n); )
    {
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d %d", &s[i], &t[i]);
            mp[t[i]] = i;
        }
        for (int i = 1; i <= n; ++i)
        {
            a[i] = mp[s[i]];
        }
        int ret = 0;
        merge_sort(1, n, ret);
        printf("%d\n", ret);
    }
    return 0;
}
