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
#define maxn 50050
using namespace std;
int h[maxn];
int main(){
    int n, p, a;
    while(~scanf("%d", &n)){
        for(int i=1;i<=n;i++) scanf("%d", &h[i]);
        p = 1;
        while(p <= n){
            while(h[p] > h[p - 1]) p++;
            if(p - 1 <= n) printf("%d\n", p - 1);
            if(p > n) break;
            while(h[p] < h[p - 1]) p++;
            h[p - 1] = 0;
        }

    }
    return 0;
}
