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
#define maxn 30030
using namespace std;

struct BinaryIndexedTrees{
    int num[maxn];
    void init(){
        memset(num,0,sizeof(num));
    }
    int lowbit(int x){
        return x&(-x);
    }
    void update(int p,int c){
        while(p<maxn){
            num[p] += c;
            p += lowbit(p);
        }
    }
    int sum(int p){
        int t=0;
        while(p>0){
            t += num[p];
            p -= lowbit(p);
        }
        return t;
    }
    int find_kth(int k){  // if (k > limit), return maxn;  if (k < 0) return 1
        int now=0;
        for(int i=20;i>=0;i--){
            now |= (1<<i);
            if(now>=maxn || num[now]>=k){
                now ^= (1<<i);
            }
            else k -= num[now];
        }
        return now + 1;
    }
}bit;

int rk[maxn], arr[maxn], mp[maxn], q[maxn], mx;
bool cmp(int a, int b){
    return arr[a] < arr[b];
}
int main(){
    int n, m, cnt;
    while(~scanf("%d%d", &n, &m)){
        for(int i=1;i<=n;i++) scanf("%d", &arr[i]);
        for(int i=1;i<=m;i++) scanf("%d", &q[i]);
        for(int i=1;i<=n;i++) rk[i] = i;
        sort(rk + 1, rk + n + 1, cmp);
        mp[1] = arr[rk[1]];
        arr[rk[1]] = mx = 1;
        for(int i=2;i<=n;i++){
            if(arr[rk[i]] == mp[mx]) arr[rk[i]] = mx;
            else mp[++mx] = arr[rk[i]], arr[rk[i]] = mx;
        }
       // for(int i=1;i<=n;i++) printf("%d ", arr[i]); puts("");
        cnt = 1;
        bit.init();
        for(int i=1;i<=n;i++){
            bit.update(arr[i], 1);
            while(cnt <= m && i == q[cnt]){
                printf("%d\n", mp[bit.find_kth(cnt++)]);
            }
            if(cnt > m) break;
        }
    }
    return 0;
}
