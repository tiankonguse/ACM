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
#define maxt 110
using namespace std;
typedef __int64 ll;
char mp[maxn][maxn];
char buf[maxt];
ll sub[maxt][maxn];
ll nmp[maxn][maxn];

int fail[maxn], len;
void buildFail(ll *p){
    int j = fail[0] = -1;
    for(int i=1;i<len;i++){
        while(j>=0 && p[j+1] != p[i]) j=fail[j];
        if(p[j+1] != p[i]) fail[i] = j;
        else fail[i] = ++j;
    }
}
bool kmp(ll *str,ll* pat, int l){
    //buildFail(pat);
    int i=0, j=0, cnt=0;
    while(i < l){
       if(pat[j]==str[i]){
           ++i,++j;
           if(j==len){
                 return true;
                j=fail[j-1]+1;
            }
       }
       else if(j==0)++i;
       else j=fail[j-1]+1;
    }
    return false;
}

int main(){
    int n, m, t, p, q, _ca = 1;
    while(~scanf("%d%d%d%d%d", &n, &m, &t, &p, &q)){
        if(n == 0 && m == 0 && t == 0) break;
        for(int i=0;i<n;i++){
            scanf(" %s", mp[i]);
        }
        memset(sub, 0, sizeof(sub));
        for(int i=0;i<t;i++){
            for(int j=0;j<p;j++){
                scanf(" %s", buf);
                for(int k=0;k<q;k++){
                    sub[i][k] = sub[i][k] * 2 + (buf[k] == '*');
                }
            }
        }
        if(p > n || q > m) {
            printf("Case %d: 0\n", _ca++);
            continue;
        }
        memset(nmp, 0, sizeof(nmp));
        for(int i=0;i<m;i++){
            for(int j=0;j<p;j++){
                nmp[0][i] = nmp[0][i] * 2 + (mp[j][i] == '*');
            }
        }
        ll mask = (1LL << p) - 1;
        for(int i=0;i<m;i++){
            for(int j=p;j<n;j++){
                nmp[j - p + 1][i] = ((nmp[j - p][i] << 1) & mask) + (mp[j][i] == '*');
            }
        }
//        for(int i=0;i<=n-p;i++){
//            for(int j=0;j<m;j++){
//                printf("%I64d ", nmp[i][j]);
//            }
//            puts("");
//        }
        len = q;
        int res = 0;
        bool flag;
        for(int i=0;i<t;i++){
            buildFail(sub[i]);
            //for(int j=0;j<q;j++) cout<<sub[i][j]<< " "; cout<<endl;
            flag = false;
            for(int j=0;j<=n-p;j++){
                flag |= kmp(nmp[j], sub[i], m);
                if(flag) break;
            }
            res += flag;
        }
        printf("Case %d: %d\n", _ca++, res);
    }
    return 0;
}
