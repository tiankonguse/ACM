#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

// 0x3f3f3f3f = 1061109567 (recommended)
const int inf = 0x3f3f3f3f;
// 0x3FFFFFFFFFFFFFFFLL = 4611686018427387903 (recommended)
const LL Inf = 0x3FFFFFFFFFFFFFFFLL;
// 10^9 + 7
const int mod = 1000000007;

//memset
//memset(dpMin, 0x3f, sizeof(dpMin)); // inf
//memset(dpMax, 0xc0, sizeof(dpMax)); // -inf

struct Node{
    int x; // the original position
    int t; // the time needed to hover up
    int w; // the time needed to move 1 unit
};

int main() {
    vector<Node> vec;
    int t, n, r, a, b;
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d%d%d",&n,&r,&a,&b);
        vec.resize(n);
        for(int i=0;i<n;i++){
            scanf("%d%d%d", &vec[i].x, &vec[i].t, &vec[i].w);
        }

        //判断是否有答案

        //查找最优答案

    }

    return 0;
}
