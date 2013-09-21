/*************************************************************************
    > File Name: Spacing.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/25 20:55:40
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
const int N = 50050;
int l[N];
int p;

int main() {
    int t,w,n,x,y,z,i;
    int ans = 1,tmp,num,tmpAns;
    scanf("%d",&t);
    while(t--) {
        scanf("%d%d",&w,&n);
        scanf("%d%d%d",&x,&y,&z);
        p = (w - 1) / 2;
        l[1] = (x % p) + 1;
//        printf("p=%d  x=%d y=%d z=%d l[1]=%d\n",p,x,y,z,l[1]);
        for(i=2; i<=n; i++) {
            l[i] = ((l[i-1]*y+z)%p) +1;
        }
        tmp = 0;
        num = 0;
        ans = 1;
        for(i=1; i<=n; i++) {
//            printf("%d - %d\n",i,l[i]);
            if(tmp == 0) {
                tmp = l[i];
                num = 1;
            } else {
                if(tmp + l[i] +1  > w) {
//                    printf("-%d\n",num);
                    tmpAns = (num-1 + w - tmp + num - 2)/(num-1);
                    if(tmpAns > ans) {
                        ans = tmpAns;
                    }
                    tmp = l[i];
                    num = 1;
                } else if(tmp + l[i] +1 == w) {
                    num = 0;
                    tmp = 0;
                } else {
                    tmp = tmp + l[i] +1;
                    num++;
                }
            }
        }
        printf("%d\n",ans);
    }



    return 0;
}
