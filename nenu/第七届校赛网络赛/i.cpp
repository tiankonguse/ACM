/*************************************************************************
    > File Name: i.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/4/13 14:08:08
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
const int N = 1000000;
LL str[N];

LL find(LL k){
    if(k< N && str[k] != -1){
        return str[k];
    }

    if(k&1){
        if(k < N){
            return str[k] = find(k*3+1) +1;
        }else{
            return find(k*3+1) +1;
        }
    }else{
        if(k < N){
            return str[k] = find(k>>1) +1;
        }else{
            return find(k>>1) +1;
        }
    }

}


int main() {
    LL a,b,ans;
    memset(str,-1,sizeof(str));
    scanf("%lld",&ans);
    str[1]  = 0;
    LL tmp;

    while(~scanf("%lld%lld",&a,&b)){
        ans = 0;
        while(a<=b){
            tmp =find(a);
            //printf("%lld\n",tmp);;
            ans = max(ans,tmp);
            a++;
        }
        printf("%lld\n",ans);
    }

    return 0;
}
