#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <bitset>

#define inf 0x3f3f3f3f
#define INF 0x3FFFFFFFFFFFFFFFLL
#define maxn 150050
using namespace std;
int p[maxn];
int main(){
    int n, res, om, em;
    while(~scanf("%d", &n)){
        for(int i=0;i<n;i++){
            scanf("%d", &p[i]);
        }
        em = 0;
        res = om = p[0];
        for(int i=1;i<n;i++){
            om = max(om, em + p[i]);
            em = max(em, om - p[i]);
            res = max(res, om);
        }
        printf("%d\n", res);
    }
    return 0;
}
