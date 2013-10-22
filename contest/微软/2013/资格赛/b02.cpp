/**************************************************************************
 **      File Name: b.cpp
 **      Author: tiankonguse
 **      Mail: shen10000shen@gmail.com
 **      Created Time: 2013/4/6 13:28:03
/**************************************************************************/

#include<cstdio>
#include<cmath>
#include<functional>
#include<algorithm>
using namespace std;

typedef long long unsigned LL;

LL find(LL x,LL y){
    if(y < 2 || x < 2)return 0;
    return y*x*(x-1)*(y-1)>>2;
}

int main(){
    int i,j;
    LL t,n,m,k,squ;
    LL x1,y1,x2,y2;
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        scanf("%llu%llu%llu",&n,&m,&k);

        if(k < 4){
             printf("Case #%d: 0\n",i);
             continue;
        }

        if(n < m)swap(n,m);

        squ = (LL)sqrt(k * 1.0);

        if(squ > m)squ = m;

        x1 = k / squ;

        if(x1>=n){
            x2 = n;
            y2 = squ;

            y1 = y2 + 1;
            x1 = k % n;

        }else{
            y1 = squ;
            x2 = x1 + 1;
            y2 = k % squ;
        }


        printf("Case #%d: %llu\n",i,find(x1,y1)-find(x1,y2)+find(x2,y2));
    }


    return 0;
}
