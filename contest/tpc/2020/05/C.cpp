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

vector<int> one(100011, 0);
vector<int> two(100011, 0);
vector<int> pre(100011, 0);


int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        for(int i=0; i<n; i++) {
            scanf("%d", &one[i]);
        }
        for(int i=0; i<n; i++) {
            scanf("%d", &two[i]);
        }

        if(one[0] != two[0]) {
            printf("No\n");
            continue;
        }

        int root = 0;

        int onePos = 0;
        int twoPos = 0;
        unordered_set<int> oneSet;
        unordered_set<int> twoSet;
        for(int i=0; i<n; ) {
            onePos = twoPos = i;
            int tmpRoot = one[onePos];
            oneSet.clear();
            twoSet.clear();

            do{
                //printf("%d %d\n", onePos, twoPos);
                int tmpVal = one[onePos];
                pre[tmpVal] = root;

                oneSet.insert(tmpVal);
                if(twoSet.count(tmpVal)) {
                    onePos++;
                    continue;
                }

                while(twoPos < n && two[twoPos] != tmpVal) {
                    twoSet.insert(two[twoPos]);
                    twoPos++;
                }
                if(twoPos < n && two[twoPos] == tmpVal){
                    twoSet.insert(two[twoPos]);
                    twoPos++;
                }
            }while(oneSet.size() != twoSet.size());
            i = twoPos;
            root = tmpRoot;
            //printf("root=%d\n", root);
        }



        printf("Yes\n");
        for(int i=1; i<=n; i++) {
            printf("%d%c", pre[i], i < n ? ' ' : '\n');
        }
    }

    return 0;
}
