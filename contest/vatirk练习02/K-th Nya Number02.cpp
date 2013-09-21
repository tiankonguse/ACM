/*************************************************************************
    > File Name: K-th Nya Number02.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/22 15:36:09
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


typedef __int64 LL;
int str[100];
LL _sum[100][30][30];
int len;
int x,y;
LL ans;

LL dfs(int pos, int x_num, int y_num, bool yes) {
    if(pos < 0) {
        return x_num == x && y_num == y;
    }
    if(x_num > x || y_num > y) {
        return 0;
    }
    if(yes && _sum[pos][x_num][y_num] != -1) {
        return _sum[pos][x_num][y_num];
    }
    LL ans = 0;
    int _max = yes ? 9 : str[pos];
    for(int i=0; i<=_max; i++) {
        ans += dfs(pos-1, x_num + (i == 4), y_num + (i == 7), yes || i<str[pos]);
    }
    if(yes) {
        _sum[pos][x_num][y_num] = ans;
    }
    return ans;
}

void dfs(int pos, int x_num, int y_num, bool yes, LL k) {
    if(pos < 0)return ;
    int _max = yes ? 9 : str[pos];
    LL tmp;
    for(int i=0; i<=_max; i++) {
        tmp = dfs(pos-1, x_num + (i == 4), y_num + (i == 7), yes || i<str[pos]);
        if(tmp>=k){
            ans = ans*10+i;
            dfs(pos-1,x_num + (i == 4), y_num + (i == 7), yes || i<str[pos],k);
            return;
        }else{
            k -= tmp;
        }
    }
}



LL query(LL val) {
    if(val < 0) {
        return 0;
    }
    len = 0;
    if(val == 0) {
        str[len++] = val;
    } else {
        while(val) {
            str[len++] = val%10;
            val /= 10;
        }
    }
    return dfs(len-1,0,0,false);
}

int main() {
    int cas,ca=1;
    LL P,Q,k,Q_P_num,P_num;
    int n;
    scanf("%d",&cas);
    while(cas--) {
        memset(_sum, -1, sizeof(_sum));
        scanf("%I64d%I64d%d%d",&P,&Q,&x,&y);
        P_num = query(P);
        Q_P_num = query(Q) - P_num;
//        printf("%lld %lld\n",P_num,Q_num);
        printf("Case #%d:\n",ca++);
        scanf("%d",&n);
        while(n--) {
            scanf("%I64d",&k);
            if(Q_P_num < k) {
                printf("Nya!\n");
            } else {
                ans = 0;
                dfs(len-1,0,0,false,P_num + k);
                printf("%I64d\n",ans);
            }
        }
    }


    return 0;
}
