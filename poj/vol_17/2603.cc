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
#define maxn 10010
using namespace std;
int cnt[maxn];
int a[11];
void fun(int n){
    for(int i=2;i*i<=n;i++){
        while(n % i == 0){
            cnt[i]++;
            n /= i;
        }
    }
    if(n != 1) cnt[n]++;
}
int main(){
    while(~scanf("%d", &a[0])){
        for(int i=1;i<10;i++) scanf("%d", &a[i]);
        memset(cnt, 0, sizeof(cnt));
        for(int i=0;i<10;i++) fun(a[i]);
        int res = 1;
        for(int i=2;i<=10000;i++){
            if(cnt[i]) res = res * (cnt[i] + 1) % 10;
        }
        printf("%d\n", res);
    }
    return 0;
}
