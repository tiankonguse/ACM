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
    int T,x,Q,t,num;
    double tmp;

    scanf("%d",&T);
    while(T--){
        scanf("%d",&x);
        x = 60;
        scanf("%d",&Q);

        tmp = 60.0 * lcm(60,x);

        while(Q--){
            scanf("%d%d",&num,&t);

            if(num == 1){
                printf("%.2f\n",t*3660.0/x);
            }else if(num ==2){
                printf("t=%d  x=%d\n",t,x);
                printf("%.2f\n",t*x*1.0);
            }else{
                printf("%.2f\n",tmp * t);
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

*/
