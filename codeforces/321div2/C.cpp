#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<cmath>
#include<stack>
#include<algorithm>
#include<functional>
#include<stdarg.h>
using namespace std;
#ifdef __int64
typedef __int64 LL;
#else
typedef long long LL;
#endif

const int debug = 0;
typedef unsigned uint;
typedef unsigned char uchar;

int const N = 100100;

vector<vector<int> >tree;
bool have[N];
int cat[N];
int ans;
int n,m;

void dfs(int dot, int num){

    if(have[dot]){
        return;
    }
    have[dot] = true;

    if(cat[dot]){
        num = num + 1;
    }else{
        num = 0;
    }
    if(num > m){
        return;
    }

    bool last = true;
    int tmp;
    for(int i=0;i<tree[dot].size();i++){
        tmp = tree[dot][i];
        if(have[tmp]){
            continue;
        }
        last = false;
        dfs(tmp, num);
    }

    if(last){
        ans++;
    }
}

int main() {
    int from, to;

    memset(have,0, sizeof(have));


    scanf("%d%d",&n,&m);
    tree.resize(n+1);

    for(int i=1; i<=n; i++) {
        scanf("%d", &cat[i]);
    }

    for(int i=1; i<n; i++) {
        scanf("%d%d",&from,&to);
        tree[from].push_back(to);
        tree[to].push_back(from);
    }

    ans = 0;
    dfs(1,0);
    printf("%d\n",ans);

    return 0;
}
