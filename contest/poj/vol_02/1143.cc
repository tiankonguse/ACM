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
#define maxs 2200000
using namespace std;
bool dp[maxs], mark[maxs];
bool move[22];
int state, mx;
bool dfs(int s){
    if(mark[s]) return dp[s];
    mark[s] = true;
    bool flag = false, res;
    int t;
    for(int i=2;i<=mx;i++){
        if(s & (1 << i)){
            t = s ^ (1 << i);
            for(int j=2;j<=mx;j++){
                if((t & (1 << j)) == 0 && j + i <= mx && (t & (1 << (j + i))) != 0){
                    t ^= (1 << (j + i));
                }
            }
            res = dfs(t);
            if(s == state) move[i] = !res;
            flag |= (!res);
        }
    }
    return dp[s] = flag;
}
int main(){
    int n, _ca = 1, a;
    while(scanf("%d", &n) && n){
        state = mx = 0;
        for(int i=0;i<n;i++){
            scanf("%d", &a);
            mx = max(a, mx);
            state |= (1 << a);
        }
        memset(mark, false, sizeof(mark));
        memset(move, false, sizeof(move));
        mark[0] = true;
        dp[0] = false;
        dfs(state);
        printf("Test Case #%d\n", _ca++);
        if(!dp[state]) puts("There's no winning move.");
        else{
            printf("The winning moves are:");
            for(int i=2;i<=20;i++){
                if(move[i]) printf(" %d", i);
            }
            puts("");
        }
        puts("");
    }
    return 0;
}
