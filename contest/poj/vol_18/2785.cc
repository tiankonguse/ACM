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
typedef __int64 ll;
int const maxn = 4010;
int const maxh = 16000010;
struct Hashmap {
    int p[maxh], v[maxh], next[maxh], idx;
    int dp[maxh];
    void init(){
        idx = 0;
        memset(p, 0xff, sizeof p);
    }
    void add(ll u){
        int x = u % maxh;
        for(int i=p[x];i!=-1;i=next[i]){
            if(v[i] == u){
                dp[i]++;
                return;
            }
        }
        dp[idx] = 1;
        v[idx] = u;
        next[idx] = p[x];
        p[x] = idx++;
    }
    int query(ll u) {
        int x = u % maxh;
        for (int i = p[x]; ~i; i = next[i]) {
            if (v[i] == u) return dp[i];
        }
        return 0;
    }
} h;
ll arr[maxn][4];
ll const base = 1LL << 30;
void getint(ll &r)
{
    char c;c=getchar();
    while(c!='-'&&(c<'0'||c>'9'))c=getchar();
    ll n=0,s=1;if(c=='-')s=-1,c=getchar();
    while(c>='0'&&c<='9')n*=10,n+=c-'0',c=getchar();
    r=n*s;
}
int main() {
    int n;
    while (~scanf("%d", &n)) {
        for (int i = 0; i < n; ++i) {
            getint(arr[i][0]);
            getint(arr[i][1]);
            getint(arr[i][2]);
            getint(arr[i][3]);
        }
        h.init();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                h.add(arr[i][0] + arr[j][1] + base);
            }
        }
        int ret = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                ret += h.query(base - arr[i][2] - arr[j][3]);
            }
        }
        printf("%d\n", ret);
    }
    return 0;
}
