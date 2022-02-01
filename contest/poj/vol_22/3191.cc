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
#define maxn 54
using namespace std;
typedef __int64 ll;
ll base[maxn];
int res[maxn];
int main(){
    base[0] = 1;
    for(int i=1;i<=50;i++){
        base[i] = -base[i - 1] * 2LL;
    }
    ll n;
    int m;
    while(~scanf("%I64d", &n)){
        if(n == 0) {puts("0"); continue;}
        m = 0;
        while(n){
            if(n % base[m + 1] != 0){
                n -= base[m];
                res[m] = 1;
            }
            else res[m] = 0;
            m++;
        }
        for(int i=m-1;i>=0;i--) printf("%d", res[i]);
        puts("");
    }
    return 0;
}
