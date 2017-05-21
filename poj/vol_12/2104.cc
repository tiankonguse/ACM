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
int num[20][maxn];
int leftcnt[20][maxn];
int sd[maxn];
void build(int l, int r, int d){
    if(l == r) return;
    int mid = (l + r) >> 1;
    int lsame = mid - l + 1;
    for(int i=l;i<=r;i++)if(num[d][i] < sd[mid]) lsame--;
    int lp = l, rp = mid + 1;
    for(int i=l;i<=r;i++){
        if(i == l) leftcnt[d][i] = 0;
        else leftcnt[d][i] = leftcnt[d][i - 1];
        if(num[d][i] < sd[mid]){
            num[d + 1][lp++] = num[d][i];
            leftcnt[d][i]++;
        }
        else if(num[d][i] > sd[mid]){
            num[d + 1][rp++] = num[d][i];
        }
        else{
            if(lsame){
                lsame--;
                num[d + 1][lp++] = num[d][i];
                leftcnt[d][i]++;
            }
            else{
                num[d + 1][rp++] = num[d][i];
            }
        }
    }
    build(l, mid, d + 1);
    build(mid + 1, r, d + 1);
}
int query(int l, int r, int a, int b, int k, int d){
    if(l == r) return num[d][l];
    int mid = (l + r) >> 1;
    int ct = leftcnt[d][b], lct = 0;
    if(l < a){
        ct -= leftcnt[d][a - 1];
        lct = leftcnt[d][a - 1];
    }
    if(ct >= k){
        return query(l, mid, l + lct, l + lct + ct - 1, k, d + 1);
    }
    else{
        k -= ct;
        ct = b - a + 1 - ct;
        lct = a - l - lct;
        return query(mid + 1, r, mid + 1 + lct, mid + lct + ct, k, d + 1);
    }
}
int main(){
    int n, m;
    int a, b, k;
    while(~scanf("%d%d", &n, &m)){
        for(int i=1;i<=n;i++){
            scanf("%d", &num[0][i]);
        }
        memcpy(sd, num[0], sizeof(num[0]));
        sort(sd + 1, sd + n + 1);
        build(1, n, 0);
        while(m--){
            scanf("%d%d%d", &a, &b, &k);
            printf("%d\n", query(1, n, a, b, k, 0));
        }
    }
    return 0;
}
