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
typedef  __int64 LL;
int str[100];
LL _sum[2][20][20];
int len,k;
int center;

void check(int& val){
    while(val < 0){
        val += k;
    }
    val %= k;
}

LL dfs_left(int pos, int left, bool yes, bool notHave) {

    check(left);


    //没计算过，开始计算
    LL ans = 0;
    int _max = yes ? 9 : str[pos];

    if(_max== 9)

    if(pos > center){
        left = left*10%k;
//        printf(" left=%d ",left);
//        printf(" right=%d ",right);
//        puts("");
        for(int i=0; i<=_max; i++) {
//            printf(" i=%d \n",i);
            ans += dfs(pos-1, (left+i)%k, right, yes || i<str[pos],notHave || i != 0);
        }
    }else{
        right = right*10%k;
//        printf(" left=%d ",left);
//        printf(" right=%d ",right);
//        puts("");
        for(int i=0; i<=_max; i++) {
            ans += dfs(pos-1, left, (right+i)%k, yes || i<str[pos],notHave || i != 0);
        }
    }


    //printf("--pos=%d ans=%d left=%d right=%d  nothave=%d\n",pos,ans,left,right,notHave);

    //保存计算过的

    if(yes) {
        if(pos>center){
            _sum[notHave][k][pos][center][left] = ans;
        }else{
           _sum[notHave][k][center][left][right] = ans;
        }
    }
    return ans;
}


//查询，一般是用[0, val]
LL query(LL val) {
    if(val < 10) {
        return 0;
    }
//    printf("--val=%d\n",val);
    len = 0;
    while(val){
        str[len++] = val%10;
        val /= 10;
    }
    LL ans = 0;
//    printf("len=%d\n",len);
    for(center=len-2;center>=0;center--){
        ans += dfs(len-1,0,0,false,false);
//        printf("---%lld center=%d\n",ans,center);
    }
//    puts("----\n");
    return ans;
}

int main() {
    LL a,b;
    memset(_sum,-1,sizeof(_sum));
//    while(~scanf("%I64d%d",&a,&k)){
//        memset(_sum,-1,sizeof(_sum));
//        printf("%I64d\n",query(a));
//    }


    while(~scanf("%I64d%I64d%d",&a,&b,&k)) {
        printf("%I64d\n",query(b)-query(a-1));
    }
    return 0;
}
/*
333 333 3
10 100 2

2
46
*/
