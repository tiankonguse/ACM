#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <cstdio>
#include <cmath>
#include <map>
#define PI acos(-1.0)
#define inf 0x3f3f3f3f
#define maxn 100700
#define eps 1e-7
using namespace std;

#ifdef __int64
    typedef __int64 LL;
#else
    typedef long long LL;
#endif

int str[maxn];
int s[maxn];
int ans[maxn];

int main(){
//    freopen("Magic_Triangle.in","r",stdin);
//    freopen("Magic_Triangle.out","w",stdout);
    int t,n,m,k;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++){
            scanf("%d",&str[i]);
        }
        memset(s,0,sizeof s);
        memset(ans,0,sizeof ans);
        sort(str,str+n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int l = str[j]-str[i]+1;
                int r = str[j]+str[i];
                s[l]++;
                s[r]--;
            }
        }
        int now = 0;
        for(int i=1;i<=100000;i++){
            now+=s[i];
            ans[i]=now;
        }
        while(m--){
            scanf("%d",&k);
            printf("%d\n",ans[k]);
        }
    }
    return 0;
}
