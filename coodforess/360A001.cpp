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
typedef long long LL;
const int maxn = 1000000000;
const int N = 5010;
int str[N];
int ans[N];
bool have[N];



struct T {
    int op,l,r,val;
} line[N];

int main() {

    int n,m,i,j;
    int op,l,r,val;
    int tmp;
    bool ok;
    while(~scanf("%d%d",&n,&m)) {
        for(i=0; i<m; i++) {
            scanf("%d%d%d%d",&line[i].op, &line[i].l, &line[i].r, &line[i].val);
        }
        memset(have,false,sizeof(have));
        for(i=m-1; i>=0; i--) {
            if(line[i].op == 2) {
                for(j=line[i].l; j<=line[i].r; j++) {
                    if(have[j]) {
                        str[j] = min(str[j], line[i].val);
                    } else {
                        have[j] = true;
                        str[j] = line[i].val;
                    }
                }
            } else {
                for(j=line[i].l; j<=line[i].r; j++) {
                    if(have[j]) {
                        str[j] -= line[i].val;
                    }
                }
            }
        }
        for(i=1; i<=n; i++) {
            if(have[i]) {
                ans[i] = str[i];
            } else {
                ans[i] = 0;
            }
        }

        ok = false;
        for(i=0; i<m; i++) {
            if(line[i].op == 2) {
                for(j=line[i].l,tmp = str[j]; j<=line[i].r; j++) {
                    tmp = max(tmp, str[j]);
                }
                if(tmp != line[i].val) {
                    ok = true;
                    break;
                }
            } else {
                for(j=line[i].l; j<=line[i].r; j++) {
                    str[j] += line[i].val;
                }
            }
        }
        if(ok) {
            printf("NO\n");
        } else {
            puts("YES");
            for(i=1; i<=n; i++) {
                printf("%d ",ans[i]);
            }
            puts("");
        }


    }


    return 0;
}
