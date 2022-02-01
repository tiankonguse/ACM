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
#define maxn 500500
using namespace std;
typedef __int64 ll;
int arr[maxn];
int n, b;

bool check(int x) {
    int ret = 0;
    for (int i = 0; i < n; ++i) {
        ret += (arr[i] + x - 1) / x;
        if (ret > b) return false;
    }
    return ret <= b;
}
inline int getint(){
    int ret=0;
  char tmp;
    while(!isdigit(tmp=getchar()));
    do{
		ret=(ret<<3)+(ret<<1)+tmp-'0';
    }while(isdigit(tmp=getchar()));
    return ret;
}
char buf[20];
int main() {
    while (~scanf("%d%d", &n, &b)) {
        if (n == -1 && b == -1) break;
        int s = 0;
        for (int i = 0; i < n; ++i) {
            arr[i] = getint();
            s = max(s, arr[i]);
        }
        int low = 1, high = s, mid, ret;
        while (low + 1 < high) {
            mid = (low + high) >> 1;
            if (check(mid)) {
                ret = mid;
                high = mid;
            }
            else low = mid;
        }
        printf("%d\n", ret);
    }
    return 0;
}
