/*************************************************************************
    > File Name: 7.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/1 18:14:11
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
const int N = 11000;
LL ans[30][N];
LL str[N];
int n;
char _str[1001][50000];
LL fun(int pos,int v){

    if(pos > n)return 0;

    if(ans[pos][v] != -1)return ans[pos][v];

    if(str[pos] == v) return ans[pos][v] = 1;

    if(str[pos] > v)return ans[pos][v] = 0;

    return ans[pos][v] = fun(pos,v-str[pos]) + fun(pos+1,v);


}


int main() {
    int v,i;

    while(~scanf("%d%d",&n,&v)){
        for(i=1;i<=n;i++){
            scanf("%lld",&str[i]);
            if(str[i] > v){
                i--,n--;
            }
        }

        sort(str+1,str+n+1);

        memset(ans,-1,sizeof(ans));
        printf("%lld\n",fun(1,v));


    }

    return 0;
}
