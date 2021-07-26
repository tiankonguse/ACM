/**************************************************************************
 **      File Name: 1.cpp
 **      Author: tiankonguse
 **      Mail: shen10000shen@gmail.com
 **      Created Time: 2013/3/30 18:19:02
/**************************************************************************/

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

const int N = 1000000007;

//f(n)=nf(n-1)+(-1)^(n)
//Dn=(n-1)(Dn-1+Dn-2)
int main(){
    __int64  str[111];
    str[1]= 0;
    str[2] = 1;
    for(int i=3;i<=100;i++){
        str[i] = ((str[i-1]+str[i-2]%N)*(i-1))%N;
    }
    int n,t;
    scanf("%d",&n);
    while(scanf("%d",&t)){
        printf("%I64d\n",str[t]);
    }
    return 0;
}
