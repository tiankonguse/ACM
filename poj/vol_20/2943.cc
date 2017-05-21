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
#include <bitset>

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
#define maxn 222
using namespace std;
bitset<310> s[maxn], t;

int main(){

    int m, n, k, a, res, cnt;
    bool flag;
    while(scanf("%d%d", &m, &n) && (m + n)){
        cnt = 0;
        res = 0;
        for(int i=0;i<n;i++){
            scanf("%d", &k);
            s[cnt].reset();
            for(int j=0;j<k;j++){
                scanf("%d", &a);
                s[cnt].set(a - 1);
            }
            flag = false;
            for(int j=0;j<cnt;j++){
                if(s[j] == s[cnt]){
                    flag = true;
                    break;
                }
            }
            if(!flag) cnt++;
            else res++;
        }
        for(int i=0;i<cnt;i++){
            t.reset();
            for(int j=0;j<cnt;j++){
                if(i == j) continue;
                if((s[i] | s[j]) == s[i]){
                    t |= s[j];
                }
            }
            if(t == s[i]) res++;
        }
        printf("%d\n", res);
    }
    return 0;
}
