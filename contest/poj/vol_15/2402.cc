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

using namespace std;
typedef long long ll;
ll num[35], base[35];
int main(){
    num[1] = num[2] = 9;
    base[1] = base[2] = 0;
    for(int i=3;i<30;i+=2){
        num[i] = num[i+1] = num[i-1] * 10;
        base[i] = base[i+1] = base[i-1] * 10 + 9;
    }
    ll n; int m;
    while(scanf("%I64d", &n) && n){
        for(m=1;m<30;m++){
            if(n <= num[m]) break;
            else n -= num[m];
        }
        n += base[m];
        printf("%I64d", n);
        if(m % 2 == 1) n /= 10;
        m >>= 1;
        for(int i=0;i<m;i++){
            printf("%I64d", n % 10);
            n /= 10;
        }
        puts("");
    }
    return 0;
}
