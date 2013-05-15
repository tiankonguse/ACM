/*************************************************************************
    > File Name: i_01.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/4/22 17:57:30
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

const int maxn = 1100;
char first[maxn];
char second[maxn];
LL str[maxn][maxn];
LL mod=1000000007;



int main() {
    int i,j;
    while(~scanf("%s%s",first+1,second+1)){
        memset(str,0,sizeof(str));
        for(i=1;first[i];++i){
            for(j=1;second[j];++j){
                str[i][j] = (str[i][j-1] + str[i-1][j])%mod;
                if(first[i] == second[j]){
                    str[i][j] = (str[i][j] +1)%mod;
                }else{
                    str[i][j] = (str[i][j] - str[i-1][j-1] + mod)%mod;
                }
            }
        }
        printf("%lld\n",str[i-1][j-1]);

    }

    return 0;
}
