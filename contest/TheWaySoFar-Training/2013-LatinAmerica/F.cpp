#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <cassert>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <string>
using namespace std;
typedef long long LL;
const int maxn = 100005;
struct goal
{
    int a,b,c;
}p[maxn];
int n,m;
bool cmp(goal x,goal y)
{
    return x.c < y.c;
}
void init()
{
    for(int i = 0; i < n; ++i){
            scanf("%d%d",&p[i].a,&p[i].b);
            if(p[i].a > p[i].b) p[i].c = 0;
            else p[i].c = p[i].b - p[i].a + 1;
    }
}
void work() {
    sort(p,p + n,cmp);
    int ans = 0;
    for(int i = 0; i < n; ++i)
        if(p[i].c == 0) ans += 3;
        else{
            if(m >= p[i].c){
                m -= p[i].c;
                ans += 3;
            }
            else{
                if(m == p[i].c - 1){
                    m = 0;
                    ans += 1;
                }
                else
                    if(p[i].c == 1) ++ans;
            }
        }
    printf("%d\n",ans);
}



int main() {
    //freopen("1.txt" , "r" , stdin);
    while(~scanf("%d%d",&n,&m)){
        init();
        work();
    }
    return 0;
}
