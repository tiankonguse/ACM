#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <cassert>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <string>
using namespace std;
typedef long long LL;

LL A , B , f[200];

LL cal(LL x) {
    LL sum = 0; int cnt = 0;
    for (int i = 58 ; i >= 0 ; -- i) {
        if (x >> i & 1) {
            sum += f[i];
            sum += cnt * (1LL << i);
            ++ cnt;
        }
    }
    return sum;
}

void work() {
    printf("%lld\n" , cal(B + 1) - cal(A));
}



int main() {
    //freopen("1.txt" , "r" , stdin);
    f[1] = 1;
    for (int i = 2 ; i <= 58 ; ++ i)
        f[i] = f[i - 1] * 2 + (1LL << i - 1); //, cout << f[i] << endl;
    while (~scanf("%lld%lld" , &A , &B))
        work();
    return 0;
}
