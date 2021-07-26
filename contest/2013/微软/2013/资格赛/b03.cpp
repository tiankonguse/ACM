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

typedef long long LL;

LL find(LL x,LL y){
    if(y < 2 || x < 2)return 0;
    return y*x*(x-1)*(y-1)>>2;
}

int main(){
    int i,j;
    LL t,n,m,k,squ;
    LL x1,y1,x2,y2,tmp;
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        scanf("%lld%lld%lld",&n,&m,&k);

        if(k < 4 || n==1 || m==1){
             printf("Case #%d: 0\n",i);
             continue;
        }

        if(n < m)swap(n,m);

        LL ans = 0;

        for(j=k/n;j<=m;j++){
            if(j<2)j=2;
            y1 = j;
            x1 = k / y1;
            if(x1 < 2)break;
            if(x1>n || (x1 == n && k%y1!=0))continue;

            y2 = k % y1;
            x2 = x1+1;
            //printf("-->j=%d %d  %d %d  %d\n",j,x1,y1,x2,y2);

            tmp = find(x1,y1)-find(x1,y2)+find(x2,y2);
            if(ans < tmp)ans = tmp;
        }


        printf("Case #%d: %lld\n",i,ans);
    }


    return 0;
}
