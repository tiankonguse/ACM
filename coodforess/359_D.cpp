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

const int maxn = 401000;
int ans[maxn];
int maxrl,ansNum;

struct T {
    int center;
    int left;
    int right;
    int val;
} str[maxn];


int main() {

    int n,i;
    int now_center,tmp;
    while(~scanf("%d",&n)) {

        for(i=1; i<=n; i++) {
            scanf("%d",&str[i].val);
            str[i].left = str[i].right = i;
            str[i].center = 0;
        }

        now_center = 1;
        str[now_center].center = 1;
        for(i=2; i<=n; i++) {
            if(str[i].val % str[now_center].val == 0) {
                str[now_center].right = i;
            } else if(str[now_center].val % str[i].val == 0) {
                str[now_center].center = 0;
                str[now_center = i].center = 1;
            } else {
                str[now_center = i].center = 1;
            }
        }

        now_center = -1;
        for(i=n; i>=1; i--) {
            if(now_center == -1) {
                if(str[i].center == 0) {
                    continue;
                } else {
                    now_center = i;
                }
            } else {
                if(str[i].val % str[now_center].val == 0) {
                    str[now_center].left = i;
                } else if(str[i].center == 1){
                    now_center = i;
                }else{
                    now_center = -1;
                }
            }
        }

        maxrl = -1;
        ansNum = 0;
        for(i=1; i<=n; i++) {
            if(str[i].center == 1) {
                tmp = str[i].right - str[i].left;
                if(tmp > maxrl) {
                    maxrl = tmp;
                    ansNum = 0;
                    ans[ansNum++] = str[i].left;
                } else if(tmp == maxrl) {
                    ans[ansNum++] = str[i].left;
                }
            }
        }

        printf("%d %d\n",ansNum, maxrl);

        for(i=0; i<ansNum-1; i++) {
            printf("%d ",ans[i]);
        }
        printf("%d\n",ans[ansNum-1]);
    }



    return 0;
}

