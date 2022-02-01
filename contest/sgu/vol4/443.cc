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
const int MAXP=10000000;
int pri[MAXP],cnt;
bool mark[MAXP];
int setp() {
    int i,j,m;
    cnt=1;pri[0]=2;mark[4]=1;
    for(i=3;i<MAXP;i+=2){   //如果要全部mark(除了1) 则i++
        if(!mark[i])pri[cnt++]=i;
        for(j=0;j<cnt,pri[j]*i<MAXP;j++){
            mark[i*pri[j]]=1;
            if(!(i%pri[j]))break;
        }
    }
    return cnt;
}
int cal(int n) {
    int s = 0, mx;
    for (int i = 0; pri[i] <= n; ++i) {
        if (n % pri[i] == 0) {
            mx = pri[i];
            s += pri[i];
        }
    }
    s -= mx;
    return mx - s;
}
int main() {
    setp();
    int a, b;
    while (~scanf("%d%d", &a, &b)) {
        a = cal(a), b = cal(b);
        if (a > b) puts("a");
        else puts("b");
    }
    return 0;
}
