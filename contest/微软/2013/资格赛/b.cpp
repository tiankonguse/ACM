/**************************************************************************
 **      File Name: b.cpp
 **      Author: tiankonguse
 **      Mail: shen10000shen@gmail.com
 **      Created Time: 2013/4/6 13:28:03
/**************************************************************************/

#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<functional>
#include<algorithm>
using namespace std;

typedef __int64 LL;

int main(){
    int i,j;
    LL t,n,m,k,squ,left;
    LL x1,y1,x2,y2;
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        scanf("%lld%lld%lld",&n,&m,&k);

        if(n < m)swap(n,m);

        squ = (LL)sqrt(k * 1.0);


        if(squ >=  m){
            y2 = m;
            x2 = k / m;
            x1 = x2 + 1;
            y1 = k % m;
        }else{
            x1 = squ;
            y1 = squ;
            y2 = squ + 1;
        }



        left = k - squ * squ;
        if(left >= squ){
            left -= squ;
            x1++;
        }

        x2 = left;

        if()


        printf("Case #%d: \n",i);
    }


    return 0;
}
