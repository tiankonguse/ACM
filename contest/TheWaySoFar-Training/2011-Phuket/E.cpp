#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <cmath>
#include <cassert>
using namespace std;
typedef long long LL;

int n , m;
#define N 2500
bool mex[N + 100];
int sg[25][N];
void init() {
    int i , j , k;
    n = 25 , m = 2500;
    for (i = 0 ; i < n ; ++ i) {
        for (j = 0 ; j < m ; ++ j) {
            memset(mex , 0 , sizeof(mex));
            for (k = 1 ; k <= i ; ++ k)
                mex[sg[i - k][j]] = 1;
            for (k = 1 ; k <= j ; ++ k)
                mex[sg[i][j - k]] = 1;
            for (k = 1 ; k <= i && k <= j; ++ k)
                mex[sg[i - k][j - k]] = 1;
            while (mex[sg[i][j]])
                ++ sg[i][j];
        }
    }
}
int L[] = {1,3,3,6,12,24,12,24,24,24,24,48,48,96,96,96,192,192,384,384,384,768,768,768,768};
int K[] = {0,0,0,8,9,27,37,92,102,127,224,277,347,382,613,693,771,865,919,1032,1165,1252,1293,1373,1732};

LL SG(int i , LL j) {
    if (j < K[i])
        return sg[i][j];
    LL y = (j - K[i]) % L[i] + K[i];
    return sg[i][y] - y + j;
}

void work() {
    LL res = 0 , x , y;
    scanf("%lld%lld%d",&x,&y,&n);
    while (n -- ) {
        scanf("%lld%lld",&x,&y);
        res ^= SG(x - 1 , y - 1);
    }
    puts(res ? "YES" : "NO");
}

int main()
{
    init();
    int _; scanf("%d",&_); while (_ --)
        work();
    return 0;
}
