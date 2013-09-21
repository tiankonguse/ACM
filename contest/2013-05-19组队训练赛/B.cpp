
#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
LL a[110000];
char in[110000];
LL mod = 1000000007;
int main(){

    a[0] = 1;
    LL sum;
    int len,i;

    for(i=1;i<=100000;i++){
         a[i] = (a[i-1]*10+1)%mod;
    }

    while(~scanf("%s",in)){
            len = strlen(in);
            sum =0;
        for(i=0;in[i];i++){
                sum = (sum + (i+1)*(in[i]-'0')*a[len-i-1])%mod;
        }
        printf("%lld\n",sum);
    }


}
