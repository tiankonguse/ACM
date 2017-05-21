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
#define maxn 100100
using namespace std;
struct result{
    int x, y, d;
    friend bool operator<(result a, result b){
        return a.x < b.x;
    }
}res[maxn];
int cnt, N;
int dat[12] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};
void check(int n, int d, int x, int y, int ly){
    if(n < 10){
        x += ly * dat[d];
        if(x + y == N){
            res[cnt].x = x;
            res[cnt].y = y;
            res[cnt].d = d;
            cnt++;
        }
        return;
    }
    int a, b, c;
    a = ly;
    b = (n - a) % 10;
    c = (a + b >= 10);
    check(n / 10 - c, d + 1, x + a * dat[d], y + b * dat[d], b);
}
void dfs(int n, int d, int x, int y){
    if(n < 10){
        if(n != 0){
            res[cnt].x = x + n * dat[d];
            res[cnt].y = y;
            res[cnt].d = d;
            cnt++;
        }
        return;
    }
    int a, b, c;
    for(int i=0;i<=9;i++){
        a = i;
        b = (n - i) % 10;
        c = (a + b >= 10);
        if(a == b){
            dfs(n / 10 - c, d + 1, x + a * dat[d], y + b * dat[d]);
        }
        else{
            check(n / 10 - c, d + 1, x + a * dat[d], y + b * dat[d], b);
        }
    }
}

int main(){
    int n;
    while(~scanf("%d", &n)){
        N = n;
        cnt = 0;
        dfs(n, 0, 0, 0);
        sort(res, res + cnt);
        printf("%d\n", cnt);
        for(int i=0;i<cnt;i++){
            printf("%d + %0*d = %d\n", res[i].x, res[i].d, res[i].y, n);
        }
    }
    return 0;
}
