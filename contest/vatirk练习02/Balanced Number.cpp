/*************************************************************************
    > File Name: Balanced Number.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/21 20:19:10
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
int str[100];
int center;
LL _sum[20][20][2000];

LL dfs(int pos,LL sum,bool yes){
    if(pos == -1){
        return sum == 0;
    }

    if(sum <0){
        return 0;
    }

    if(yes && _sum[pos][center][sum] != -1){
        return _sum[pos][center][sum];
    }

    int _max = yes ? 9 : str[pos];
    LL ans = 0;
    for(int i=0;i<=_max;i++){
        ans += dfs(pos-1, sum + (pos - center)*i, yes || i<str[pos]);
    }

    if(yes){
        _sum[pos][center][sum] = ans;
    }

    return ans ;
}

LL getAns(LL now){

    if(now < 0){
        return 0;
    }

    if(now == 0 ){
        return 1;
    }

    LL ans = 0;
    int len = 0;
    while(now){
        str[len++] = now%10;
        now /= 10;
    }
    for(center = 0;center<len;center++){
        ans += dfs(len-1,0,false);
    }
    return ans - len + 1;
}


int main() {

    memset(_sum,-1,sizeof(_sum));

    int cas;
    LL x,y;
    scanf("%d",&cas);
//    for(int i=0;i<=9;i++)
//    {
//        cout<<getAns(i)<<endl;
//    }
    while(cas--){
        scanf("%lld%lld",&x,&y);
        printf("%lld\n",getAns(y) - getAns(x-1));
//        scanf("%d",&y);
//        printf("%d\n",getAns(y));
    }
    return 0;
}
