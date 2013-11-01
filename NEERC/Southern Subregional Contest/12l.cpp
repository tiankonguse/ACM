/*************************************************************************
    > File Name: 0.cpp
    > Author: tiankonguse
    > Mail: i@tiankonguse.com
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<map>
#include<string>
#include<cmath>
#include<queue>
#include<stack>
#include<functional>
#include<algorithm>
using namespace std;
typedef int LL;

int main() {
     LL   n,dollar,share,a,b;
    LL upNum,downNum;
    LL pre,now;
    LL num;
    while(~scanf("%d%d%d%d",&n,&dollar,&a,&b)) {
        share = 0;
        upNum = downNum = 0;
        scanf("%d",&pre);
        for(LL i=1;i<n;i++) {
            scanf("%d",&now);
            if(pre < now) {
                downNum = 0;
                upNum++;
                num = min(upNum*a, dollar/now);
                share += num;
                dollar -= num * now;

            } else if(pre > now) {
                upNum = 0;
                downNum++;
                num = min(downNum*b, share);
                share -= num;
                dollar += num * now;
            } else {
                upNum = 0;
                downNum = 0;
            }
//            printf("%d %d %d\n",i,share,dollar);
            pre = now;
//            printf("-%d\n",num);
        }
        printf("%d %d\n",dollar,share);

    }

    return 0;
}
