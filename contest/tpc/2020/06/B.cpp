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

enum {C = 0, V = 1, SPC = 2, SPV = 3};
int str[11][4];
int n,m;
int maxV = 0, minC = 0;
int flag[11];

void dfs(int tmpV, int tmpC, int pos, int selectNum){
    if(selectNum == m){
        if(tmpV > maxV || (tmpV == maxV && minC > tmpC)){
            maxV = tmpV;
            minC = tmpC;
        }
        return;
    }

    // 出口
    if(pos == n){
        return;
    }

    //sp
    if(flag[pos] == 1){
        dfs(tmpV, tmpC, pos + 1, selectNum);
        return;
    }

    //两种选择，一种是选择，一种是不选择
    flag[pos] = 1;
    dfs(tmpV + str[pos][V], tmpC + str[pos][C], pos + 1, selectNum + 1);
    flag[pos] = 0;
    dfs(tmpV, tmpC, pos + 1, selectNum);
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d",&n, &m);

        maxV = minC = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<4;j++){
                scanf("%d", &str[i][j]);
            }

            if(i == 0) {
                maxV += str[i][SPV];
                minC += str[i][SPC];
            }
            if(i < m){
                maxV += str[i][V];
                minC += str[i][C];
            }

            flag[i] = 0;
        }


        for(int i=0;i<n;i++){
            flag[i] = 1;
            dfs(str[i][SPV] + str[i][V], str[i][SPC] + str[i][C], 0, 1);
            flag[i] = 0;
        }
        printf("%d %d\n", maxV, minC);


    }

    return 0;
}


