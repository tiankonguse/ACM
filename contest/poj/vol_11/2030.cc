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
#define maxn 75
using namespace std;
string mark[maxn][maxn];
char mp[maxn][maxn];
bool cmp(string a, string b){
    int l1 = a.length(), l2 = b.length();
    if(l1 != l2) return l1 < l2;
    else return a < b;
}
int main(){
    int n, m;
    string res;
    while(scanf("%d%d", &m, &n) && (n + m)){
        for(int i=1;i<=n;i++) fill(mark[i], mark[i] + m + 1, "");
        for(int i=1;i<=n;i++) scanf(" %s", mp[i] + 1);
        res = "";
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(isdigit(mp[i][j])){
                    mark[i][j] = max(mark[i-1][j], mark[i][j-1], cmp) + mp[i][j];
                    if(mark[i][j] == "0") mark[i][j] = "";
                   // cout<<mark[i][j]<<endl;
                    res = max(res, mark[i][j], cmp);
                }
            }
        }
        cout<<res<<endl;
    }
    return 0;
}
