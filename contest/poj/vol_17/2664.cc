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
#define maxc 10000
#define maxn 110
using namespace std;
bool mark[maxc];
int main(){
    int k, m, a, c, r; bool flag;
    while(~scanf("%d", &k) && k){
        scanf("%d", &m);
        memset(mark, false, sizeof(mark));
        for(int i=0;i<k;i++){
            scanf("%d", &a);
            mark[a] = true;
        }
        flag = true;
        for(int i=0;i<m;i++){
            scanf("%d%d", &c, &r);
            for(int j=0;j<c;j++){
                scanf("%d", &a);
                if(mark[a]) r--;
            }
            if(r > 0) flag = false;
        }
        puts(flag?"yes":"no");
    }
    return 0;
}
