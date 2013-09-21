/*************************************************************************
    > File Name: D 1474.Crayon002.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/14 9:13:40
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
LL one_right_dot[N];
LL one_left_dot[N];
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
    LL twol,twor,L_left,L_right,R_left,R_right;
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
                Map[point[i]] = k++;

            }
        }

        memset(one_right_dot,0,sizeof(one_right_dot));
        memset(one_left_dot,0,sizeof(one_left_dot));


        for(i = 1; i<= n; i++){
            if(str[i].op[0] == 'D'){
                add(Map[str[i].r], 1, one_right_dot);
                add(Map[str[i].l], 1, one_left_dot);
            } else if(str[i].op[0]=='Q') {
                L_right = sum(Map[str[i].l]-1, one_right_dot);
                R_left  = sum(Map[str[i].r], one_left_dot);
                printf("%lld\n",R_left-L_right);
            } else {
                add(Map[strAdd[str[i].pos].r], -1, one_right_dot);
                add(Map[strAdd[str[i].pos].l], -1, one_left_dot);
                num--;
            }
        }

    }

    return 0;
}
