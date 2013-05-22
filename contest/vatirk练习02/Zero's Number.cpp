/*************************************************************************
    > File Name: Zero's Number.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/22 15:27:40
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
typedef  long long LL;
int str[100];
LL _sum[2][21][21][21][21][21];
int len,k;
int center;

void check(int& val){
    val = (val % k + val)%k;
}

LL dfs(int pos, int left, int right, bool yes, bool notHave) {
    if(pos < 0) {//判断是否结束
        return (left + right)%k == 0;
    }

    check(left);
    check(right);

    //判断是否已经是999且已经计算过。

    if(yes && _sum[notHave][k][pos][center][left][right] != -1) {
        return _sum[notHave][k][pos][center][left][right];
    }
    //没计算过，开始计算
    LL ans = 0;
    int _max = yes ? 9 : str[pos];

    if(pos > center){
        left = left*10%k;
        for(int i=0; i<=_max; i++) {
            ans += dfs(pos-1, (left+i)%k, right, yes || i<str[pos],notHave || i != 0);
        }
    }else{
        right = right*10%k;
        for(int i=0; i<=_max; i++) {
            ans += dfs(pos-1, left, (right+i)%k, yes || i<str[pos],notHave || i != 0);
        }
    }

    //保存计算过的
    if(yes) {
        _sum[notHave][k][pos][center][left][right] = ans;
    }
    return ans;
}


//查询，一般是用[0, val]
LL query(LL val) {
    if(val < 10) {
        return 0;
    }
    len = 0;
    while(val){
        str[len++] = val%10;
        val /= 10;
    }
    LL ans = 0;
    for(center=len-2;center>=0;center--){
        ans += dfs(len-1,0,0,false,false);
    }
    return ans;
}
int main() {
    LL a,b;
    memset(_sum,-1,sizeof(_sum));
    while(~scanf("%lld%lld%d",&a,&b,&k)) {
        printf("%lld\n",query(b)-query(a-1));
    }
    return 0;
}
