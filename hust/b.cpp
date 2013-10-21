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
using namespace std;
typedef long long LL;
const int N = 1000010;
struct T {
    int pos,val,i;
    bool operator<(const T other)const {
        return this->pos < other.pos;
    }
} str[N],maxVal[N],tmp;
bool cmp(T a, T b) {
    return a.pos < b.pos;
}
int main(int argc, char* argv[]) {
    int n,d,i,j,pos,ans_b,ans_e,ans_val,now_val;


    while(~scanf("%d%d",&n,&d)) {
        for(i=0; i<n; i++) {
            scanf("%d%d",&str[i].pos, &str[i].val);
            str[i].i = i+1;
        }
        sort(str, str+n);
//        puts("");
//        for(i=0; i<n; i++) {
//            printf("%d %d\n",str[i].pos, str[i].val);
//        }
//        puts("");
        if(str[n-1].pos - str[0].pos < d) {
            printf("-1 -1\n");
        } else {
            tmp.val = -1;
            ans_val = -1;
            for(i=n-1; i>=0; i--) {
                if(str[i].val > tmp.val) {
                    tmp = str[i];
                }
                maxVal[i] = tmp;
            }
//
//            puts("");
//            for(i=0; i<n; i++) {
//                printf("%d %d\n",maxVal[i].pos, maxVal[i].val);
//            }
//            puts("");

            for(i=0; i<n; i++) {
                if(str[n-1].pos - str[i].pos < d) {
                    break;
                } else {
                    tmp.pos = str[i].pos + d;
                    pos = lower_bound(str,str+n,tmp, cmp)-str;
                    now_val = maxVal[pos].val + str[i].val;
                    if(now_val > ans_val) {
                        ans_val = now_val;
                        ans_b = str[i].i;
                        ans_e = maxVal[pos].i;
                    }
                }
            }
//            printf("%d %d %d\n",ans_b, ans_e, ans_val);
            printf("%d %d\n",ans_b, ans_e);
        }
    }

    return 0;
}






