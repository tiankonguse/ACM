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
typedef __int64 ll;
ll votes[maxn];
int main(){
    int T, N;
    ll res;
    for(scanf("%d", &T);T--;){
        scanf("%d", &N);
        for(int i=0;i<N;i++){
            scanf("%I64d", &votes[i]);
        }
        sort(votes, votes + N);
        res = 1;
        for(int i=(N+1)>>1;i<N;i++){
            res += votes[i];
        }
        for(int i=((N+1)>>1) - 1;i>=0;i--){
            res += votes[i] >> 1;
        }
        printf("%I64d hlasu zajisti strane vitezstvi.\n", res);
    }
    return 0;
}
