/*************************************************************************
    > File Name: nenu_649.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/4/12 19:01:16
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

struct T{
    int a,i;
}tmp;

deque<T>deq;

int main() {
    int ans,n,a,b,nowmin,i,num,left;

    while(~scanf("%d",&n)){
        while(!deq.empty())deq.pop_back();
        ans = 1;
        nowmin = -1;
        num=0;
        left = -1;

        for(i=0;i<n;i++){
            scanf("%d%d",&a,&b);

            if(a>b)swap(a,b);

            if(nowmin <= b){
                num++;
                ans = max(ans,num);
                while(!deq.empty() && deq.back().a < a){
                    deq.pop_back();
                }
                tmp.a = a;
                tmp.i = i;
                deq.push_back(tmp);
                nowmin = deq.front().a;
            }else{
                while(!deq.empty() && deq.front().a > b){
                    left =deq.front().i;
                    deq.pop_front();
                }
                num = i - left;


                ans = max(ans,num);
                while(!deq.empty() && deq.back().a < a){
                    deq.pop_back();
                }
                tmp.a = a;
                tmp.i = i;
                deq.push_back(tmp);
                nowmin = deq.front().a;
            }

        }
        printf("%d\n",ans);
    }




/*
5
10 20
10 20
1 2
2 3
3 4


*/

    return 0;
}
