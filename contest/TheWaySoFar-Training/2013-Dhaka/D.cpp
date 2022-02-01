#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long LL;
LL Q = 10000000000007;
int ca;
void work() {
    int L , N , M;
    scanf("%d%d%d",&L,&M,&N);
    L *= L;
    LL ans = 0 , val = 1; int i;
    for (i = 1 ; i <= M - 1 ; ++ i)
        val = val * (L - i + 1) % Q;
    for (i = M ; i <= N ; ++ i) {
        val = val * (L - i + 1) % Q;
        ans += val;
        if (ans >= Q)
            ans -= Q;
    }
    printf("Case %d: %lld\n" , ++ ca , ans);
}

int main(){
    int _; scanf("%d",&_); while(_ --)
        work();
    return 0;
}
