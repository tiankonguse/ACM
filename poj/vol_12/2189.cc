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
#define maxn 1010
using namespace std;
int pos[maxn];
int sum[maxn];

int main(){
    int n, p, c, x;
    while(~scanf("%d%d%d", &n, &p, &c)){
        memset(pos, 0, sizeof pos);
        for(int i=0;i<n;i++){
            scanf("%d", &x);
            pos[x]++;
        }
        sum[0] = 0;
        for(int i=1;i<=p;i++){
            sum[i] = sum[i - 1] + pos[i];
        }

        int res = 0;
        for(int i=1;i<=p-1;i++){
            for(int j=i;j<=p-1;j++){
                if(sum[j] - sum[i - 1] <= c){
                    res = max(res, j - i + 1);
                }
            }
        }
        printf("%d\n", res);
    }
    return 0;
}
