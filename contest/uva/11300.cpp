/*************************************************************************
    > File Name: 11300.cpp
    > Author: tiankonguse
    > Mail: i@tiankonguse.com
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
const int N = 1000100;
LL first[N],second[N];
LL sum,ave;

int main() {

    int n,i;
    while(~scanf("%d",&n)){
        sum = 0;
        for(i=0;i<n;i++){
            scanf("%lld",&first[i]);
            sum += first[i];
        }
        ave = sum/n;
        second[0] = 0;
        for(i=1;i<n;i++){
            second[i] = second[i-1] + first[i] - ave;
        }
        sort(second, second+n);
        ave = second[n>>1];
        sum = 0;
        for(i=0;i<n;i++){
            sum += abs(second[i] - ave);
        }
        printf("%lld\n",sum);

    }

    return 0;
}
