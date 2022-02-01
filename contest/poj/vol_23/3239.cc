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
#define maxn 305
using namespace std;
int res[maxn];
void solve(int n){
    int m, cnt = 1;
    if(n % 6 == 2){
        m = n >> 1;
        if(m % 2 == 0){
            for(int i=m;i<=n;i+=2){
                res[cnt++] = i;
            }
            for(int i=2;i<=m-2;i+=2){
                res[cnt++] = i;
            }
            for(int i=m+3;i<=n;i+=2){
                res[cnt++] = i;
            }
            for(int i=1;cnt<=n;i+=2){
                res[cnt++] = i;
            }
        }
        else{
            for(int i=m;i<=n-1;i+=2){
                res[cnt++] = i;
            }
            for(int i=1;i<=m-2;i+=2){
                res[cnt++] = i;
            }
            for(int i=m+3;i<=n;i+=2){
                res[cnt++] = i;
            }
            for(int i=2;cnt<=n;i+=2){
                res[cnt++] = i;
            }
        }
    }
    else if(n % 6 == 3){
        solve(n - 1);
        res[n] = n;
    }
    else{
        if(n % 2 == 0){
            for(int i=2;i<=n;i+=2){
                res[cnt++] = i;
            }
            for(int i=1;i<=n-1;i+=2){
                res[cnt++] = i;
            }
        }
        else{
            for(int i=1;i<=n;i+=2){
                res[cnt++] = i;
            }
            for(int i=2;i<=n-1;i+=2){
                res[cnt++] = i;
            }
        }
    }
}

int main(){
    int n;
    while(scanf("%d", &n) && n){
        solve(n);
        for(int i=1;i<=n;i++){
            if(i == n) printf("%d\n", res[i]);
            else printf("%d ", res[i]);
        }
    }
    return 0;
}
