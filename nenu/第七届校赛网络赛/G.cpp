/*************************************************************************
    > File Name: G.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/4/13 13:51:30
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

int main() {
    LL n,m,a,b,k,mod;
    cin>>n;

    while(cin>>n>>m){
        k = n / m;
        mod = n % m;
        cout<<k*(m*(m-1)>>1) + (mod * (mod+1)>>1)<<endl;
    }

    return 0;
}
