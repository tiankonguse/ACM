/*************************************************************************
    > File Name: D 1474.Crayon.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/13 18:54:54
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<functional>
#include<algorithm>
using namespace std;
typedef long long LL;
const int N = 510000;
struct T {
    char op[2];
    LL l,r;
    int pos;
} str[N], strAdd[N];
LL point[N];
map<LL,int>Map;
LL two_dot[N];
LL one_left_dot[N];
LL one_right_dot[N];
int m;

int lowb(int t) {
    return t & (-t);
}

void add(int i,int val, LL* dot) {
    for(; i < m; dot[i] += val, i += lowb(i));
}

LL sum(int i, LL* dot) {
    LL s = 0;
    for(; i > 0; s += dot[i], i -= lowb(i));
    return s;
}



int main() {
    int n, i,k,num;
    LL twol,twor,onel,oner;
    while(~scanf("%d",&n)) {
        m = 1;
        k = 1;
        for(i = 1; i <= n; i++) {
            scanf("%s",str[i].op);
            if(str[i].op[0]=='D') {
                scanf("%lld%lld",&str[i].l,&str[i].r);
                point[m++] = str[i].l;
                point[m++] = str[i].r;
                strAdd[k].l = str[i].l;
                strAdd[k].r = str[i].r;
                k++;
            } else if(str[i].op[0]=='Q') {
                scanf("%lld%lld",&str[i].l,&str[i].r);
                point[m++] = str[i].l;
                point[m++] = str[i].r;
            } else {
                scanf("%d",&str[i].pos);
            }
        }
        num = k-1;

        sort(point + 1, point + m);
        point[0] = -1;
        Map.clear();

        k = 1;
        for(i = 1; i < m; i++) {
            if(point[i] != point[i-1]) {
//                printf("--%lld-->%d\n",point[i],k);
                Map[point[i]] = k++;

            }
        }

        memset(two_dot,0,sizeof(two_dot));
        memset(one_left_dot,0,sizeof(one_left_dot));
        memset(one_right_dot,0,sizeof(one_right_dot));

//        printf("--m=%d\n",m);

        for(i = 1; i<= n; i++){
            if(str[i].op[0] == 'D'){
//                printf("D--Map[str[i].l]=%d  Map[str[i].r]=%d\n",Map[str[i].l],Map[str[i].r]);
                add(Map[str[i].l], 1, two_dot);
                add(Map[str[i].r], 1, two_dot);
                add(Map[str[i].r], 1, one_left_dot);
                add(Map[str[i].l], 1, one_right_dot);
//                for(k=1;k<=m;k++){
//                    printf("%2d ",k);
//                }
//                puts("");
//                for(k=1;k<=m;k++){
//                    printf("%2d ",two_dot[k]);
//                }
//                puts("");
//                for(k=1;k<=m;k++){
//                    printf("%2d ",one_dot[k]);
//                }
//                puts("");
            } else if(str[i].op[0]=='Q') {
                twol =sum(Map[str[i].l] -1, two_dot);
                twor = sum(Map[str[i].r], two_dot);
                onel = sum(Map[str[i].r], one_left_dot);
                oner = num - sum(Map[str[i].l]-1, one_right_dot);
//                printf("--twol=%lld twol=%lld onel=%lld oner=%lld \n",twol,twor,onel,oner);

                printf("%lld\n",(twor - twol)-(oner + onel - num));
            } else {
//                printf("C--Map[strAdd[str[i].pos].l]=%d  Map[strAdd[str[i].pos].r]=%d\n",Map[strAdd[str[i].pos].l],Map[strAdd[str[i].pos].r]);
                add(Map[strAdd[str[i].pos].l], -1, two_dot);
                add(Map[strAdd[str[i].pos].r], -1, two_dot);
                add(Map[strAdd[str[i].pos].r], -1, one_left_dot);
                add(Map[strAdd[str[i].pos].l], -1, one_right_dot);
                num--;
//                for(k=1;k<=m;k++){
//                    printf("%2d ",k);
//                }
//                puts("");
//                for(k=1;k<=m;k++){
//                    printf("%2d ",two_dot[k]);
//                }
//                puts("");
//                for(k=1;k<=m;k++){
//                    printf("%2d ",one_dot[k]);
//                }
//                puts("");
            }
        }

    }

    return 0;
}
