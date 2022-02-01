#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 200005;
struct aa
{
    int l,r;
    int operator<(const aa &a)const {
        return r<a.r || (r==a.r && l<a.l);
    }
}a[maxn];

int main()
{
    int T;
    //freopen("1.txt","r",stdin);
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        for(int i = 1; i <= n; ++i) scanf("%d%d",&a[i].l,&a[i].r);
        sort(a + 1,a + n + 1);
        int l1 = -10000000,r1 = 10000000;
        int ans = 0;
        for(int i = 1; i <= n; ++i){
            l1 = max(a[i].l,l1 + 1);
            r1 = min(a[i].r,r1 + 1);
            if(r1 <= l1){
                ++ans;
                l1 = a[i].l;
                r1 = a[i].r;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
