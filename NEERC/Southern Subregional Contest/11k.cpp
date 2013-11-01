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


int main() {
    int left,right,num,n,now,start,end;

    int ans[300010][2];
    while(~scanf("%d",&n)) {

        scanf("%d",&now);
        num = 0;
        ans[num][0] = 1;
        ans[num][1] = 1;
        num++;
        left = now - 1;//  <-
        right = 1;  // ->

        for(int i=2; i<=n; i++) {
            scanf("%d",&now);
            if(right !=0 && right <= now -1 ) {
                //->
                right++;
                left = min(now-1, left-1);
                ans[num-1][1] = i;
            } else if(left > 0) {
                right = 0;
                // <-
                left = min(now-1, left-1);
                ans[num-1][1] = i;
            } else {
                if(right == 0) {
                    swap(ans[num-1][0],ans[num-1][1]);
                }
                ans[num][0] = i;
                ans[num][1] = i;
                num++;
                left = now - 1;//  <-
                right = 1;  // ->
            }
        }
        if(right == 0){
            swap(ans[num-1][0],ans[num-1][1]);
        }
        printf("%d\n",num);
        for(int i=0;i<num;i++){
            printf("%d %d\n",ans[i][0],ans[i][1]);
        }
    }

    return 0;
}
/*
8
3 4 1 1 3 2 1 3

4
3 1
4 5
6 6
7 8
*/
