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
#define maxn 15
using namespace std;
typedef __int64 ll;
char s1[maxn], s2[maxn];
ll data[maxn] = {
    1,
    10,
    100,
    1000,
    10000,
    100000,
    1000000,
    10000000,
    100000000,
    1000000000,
    10000000000LL
};
int n;
ll res;
ll cnt[maxn];
void dfs(int d){
    if(d == n) return;
    if(s1[d] == '?'){
        ll a = s2[d] - '0';
        res += (9LL - a) * data[ cnt[d + 1] ];
        dfs(d + 1);
    }
    else if(s1[d] > s2[d]){
        res += data[ cnt[d + 1] ];
    }
    else if(s1[d] == s2[d]){
        dfs(d + 1);
    }
}
int main(){

    while(~scanf(" %s", s1)){
        if(s1[0] == '#') break;
        scanf(" %s", s2);
        n = strlen(s1);
        res = 0;
        cnt[n] = 0;
        for(int i=n-1;i>=0;i--){
            cnt[i] = cnt[i + 1] + (s1[i] == '?');
        }

        dfs(0);
        printf("%I64d\n", res);
    }
    return 0;
}
