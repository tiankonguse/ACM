/*************************************************************************
    > File Name: i.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/4/21 19:13:56
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

const int maxn = 1100;
char first[maxn];
char second[maxn];
long long int str1[maxn][maxn];
long long int str2[maxn][maxn];
long long int mod=1000000007;
int next[maxn];
int _map[30];

int get(int j,int i){
    int tmp = 0,k;
    k = _map[second[j] - 'a'];
    while(k && k <= i){
        tmp = (tmp + str2[k][j])%mod;
        k = next[k];
    }
    return tmp;
}

int main() {

    int i,j,tmp,tmp2;
    while(~scanf("%s%s",first+1,second+1)){
        memset(str1,0,sizeof(str1));
        memset(str2,0,sizeof(str2));
        memset(_map,0,sizeof(_map));
        memset(next,0,sizeof(next));


        for(i=strlen(first+1);i;i--){
            next[i] = _map[first[i] - 'a'];
            _map[first[i] - 'a'] = i;
        }

        for(i=1;first[i];++i){
            tmp = 0;

            for(j=1;second[j];++j){
                if(first[i] == second[j]){
                    str2[i][j] = (str1[i-1][j-1] +1)%mod;
                    tmp = (tmp + str2[i][j]) % mod;
                    str1[i][j] = (str1[i-1][j] + tmp) % mod;
                }else{
                    str2[i][j] = 0;
                    str1[i][j] = (str1[i][j-1] + get(j,i)) % mod;
                }
            }
        }
        printf("%lld\n",str1[i-1][j-1]);

    }

    return 0;
}
