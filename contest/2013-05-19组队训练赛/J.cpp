
#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long LL;
//typedef __int64 LL;




int main(){
    LL n,tmp,sum,a;
    while(~scanf("%lld",&n)){
        scanf("%lld",&sum);
        tmp = sum;
        n--;
        while(n--){
            scanf("%lld",&a);
            if(tmp>=0){
                tmp += a;
            }else{
                tmp = a;
            }
            if(tmp>sum){
                sum = tmp;
            }

        }
        printf("%lld\n",sum);
    }
}
