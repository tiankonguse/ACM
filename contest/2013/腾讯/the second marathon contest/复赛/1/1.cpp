/**************************************************************************
 **      File Name: 0.cpp
 **      Author: tiankonguse
 **      Mail: shen10000shen@gmail.com
 **      Created Time: 2013/3/29 18:24:52
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

int gcd(int a, int b){
    return b ? gcd(b, a%b):a;
}

int lcm(int a,int b){
    return a / gcd(a, b) * b;
}

int main(){
    __int64 T,x,Q,t,num;
    double tmp;

    scanf("%I64d",&T);
    while(T--){
        scanf("%I64d",&x);
        scanf("%I64d",&Q);

        while(Q--){
            scanf("%I64d%I64d",&num,&t);

            if(num == 1){
                printf("%.2f\n",t*(60.0-x));
            }else if(num ==2){
                printf("%.2f\n",t*3600.0/(60-x));
            }else{
                printf("%.2f\n",t*12*60*60.0*60/x);
            }
        }
    }

    return 0;
}
/*
1
1
3
1 2
2 2
3 1


118.00
122.03
2592000.00
*/
