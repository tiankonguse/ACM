#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <cmath>
#include <cassert>
using namespace std;
typedef long long LL;

char s[1000];
int aa[1000],head,tail;

int main(){
    int T,numT=0;
    scanf("%d",&T);
    for (;T;--T){
        int n,k;
        scanf("%d%d",&n,&k);
        scanf("%s",s+1);
        int head=1,tail=0,ans=0;
        for (int i=1; i<=n; ++i){
            int K=0;
            for (int j=head; j<=tail; ++j)
                if (s[i]==s[aa[j]]) K=1;
            ans+=K;
            aa[++tail]=i;
            if (tail-head+1>k) ++head;
        }
        printf("Case %d: %d\n",++numT,ans);
    }
}
