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
#define maxn 20200
using namespace std;
int a[maxn], b[maxn];

int main(){
    int n, m, res, p;
    bool flag;
    while(scanf("%d%d", &n, &m) && n + m){
        for(int i=0;i<n;i++) scanf("%d", &a[i]);
        for(int i=0;i<m;i++) scanf("%d", &b[i]);
        if(n > m) puts("Loowater is doomed!");
        else{
            sort(a, a + n);
            sort(b, b + m);
            res = p = 0;
            flag = false;
            for(int i=0;i<n;i++){
                while(p < m && b[p] < a[i]) p++;
                if(p >= m) break;
                else res += b[p++];
                if(i == n - 1) flag = true;
            }
            if(flag) printf("%d\n", res);
            else puts("Loowater is doomed!");
        }
    }
    return 0;
}
