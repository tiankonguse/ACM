/*************************************************************************
    > File Name: B.cpp
    > Author: tiankonguse
    > Mail: i@tiankonguse.com 
    > Created Time: 2018年11月26日  0:05:19
 ************************************************************************/

#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<stack>
#include<map>
#include<queue>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<time.h>
using namespace std;


#ifdef __int64
typedef __int64 LL;
#else
typedef long long LL;
#endif

const int debug = 0;
typedef unsigned uint;
typedef unsigned char uchar;


int cal(int i, int j){
    return i*i + j*j;
}

LL init(int m, int n, int mod){
    LL sellMax = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(cal(i,j) % mod== 0){
                sellMax++;
            }
        }
    }
    return sellMax;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
   #endif
    LL n;
    int m;

    while(~scanf("%lld%d", &n,&m)){
        LL ans = 0;
        LL sellMax = init(m, m, m);
        
        LL x = n/m;
        LL left = n%m;

        ans += x * x * sellMax;

        ans += 2 * x * init(left, m, m);
        ans += init(left, left, m);
        printf("%lld\n", ans);

    }


    return 0;
}
