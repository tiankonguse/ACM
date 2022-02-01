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
#define MAXN 105
using namespace std;
const int inf = 0x7f7f7f7f;
int a[MAXN],b[MAXN];
int main(){
    int n,l,r;
    while(~scanf("%d",&n)){
        for(int i=0;i<n;i++){
            scanf("%d", &a[i]);
        }
        b[0] = a[0], b[n-1] = a[n-1];
        for(int i=1;i<n-1;i++){
            l = min(a[i], b[i-1]);
            r = max(a[i], b[i-1]);
            if(a[i+1] > r) b[i] = r;
            else if(a[i+1] < l) b[i] = l;
            else b[i] = a[i+1];
        }
        int res = 0;
        for(int i=0;i<n;i++){
            res += abs(a[i] - b[i]);
            if(i>0) res += abs(b[i] - b[i-1]);
        }
        printf("%d\n",res);
    }
    return 0;
}
