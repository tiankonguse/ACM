#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

// 0x3f3f3f3f = 1061109567 (recommended)
const int inf = 0x3f3f3f3f;
// 0x3FFFFFFFFFFFFFFFLL = 4611686018427387903 (recommended)
const LL Inf = 0x3FFFFFFFFFFFFFFFLL;
// 10^9 + 7
const int mod = 1000000007;

#define memsetMin(arr) memset(arr, 0xc0, sizeof(arr))
#define memsetMax(arr) memset(arr, 0x3f, sizeof(arr))

//memset
//memset(dpMin, 0x3f, sizeof(dpMin)); // inf
//memset(dpMax, 0xc0, sizeof(dpMax)); // -inf

struct Node {
    int c,v,spc,spv;
};

Node str[11];
int n,m;
int maxV = 0, minC = 0;
int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d",&n, &m);

        maxV = minC = 0;
        for(int i=0; i<n; i++) {
            scanf("%d%d%d%d", &str[i].c, &str[i].v, &str[i].spc, &str[i].spv);
        }
        sort(str, str+n, [](Node&a, Node& b) {
            return a.v == b.v ? a.c < b.c : a.v > b.v;
        });


        int topc = 0, topv = 0;
        for(int i=0; i<m-1; i++) {
            topv += str[i].v;
            topc += str[i].c;
        }

        int tmpC = 0, tmpV = 0;
        for(int i=0; i<n; i++) {
            if(i < m-1) {
                tmpC = topc + str[i].spc + str[m-1].c;
                tmpV = topv + str[i].spv + str[m-1].v;
            } else {
                tmpC = topc + str[i].spc + str[i].c;
                tmpV = topv + str[i].spv + str[i].v;
            }
            if(tmpV > maxV || (tmpV == maxV && minC > tmpC)) {
                maxV = tmpV, minC = tmpC;
            }
        }
        printf("%d %d\n", maxV, minC);
    }

    return 0;
}


