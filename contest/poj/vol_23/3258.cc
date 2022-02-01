#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <set>
#include <queue>

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
#define maxn 50050
using namespace std;

int arr[maxn];
int l, n, m;
int scan(int limit){
    int p = 0, cnt = 0;
    for(int i=1;i<=n+1;i++) {
        if(arr[i] - arr[p] < limit){
            cnt++;
        }
        else p = i;
    }
    return cnt;
}
int main(){
  while(~scanf("%d%d%d", &l, &n, &m)){
        arr[0] = 0, arr[n + 1] = l;
        for(int i=1;i<=n;i++){
            scanf("%d", &arr[i]);
        }
        sort(arr + 1, arr + n + 1);
        int low = 1, high = l, mid;
        int t, res = 0;
        while(low <= high){
            mid = (low + high) >> 1;
            t = scan(mid);
            if(t <= m){
                res = max(res, mid);
                low = mid + 1;
            }
            else high = mid - 1;
        }
        printf("%d\n", res);
	}
    return 0;
}
