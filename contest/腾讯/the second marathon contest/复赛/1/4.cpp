/**************************************************************************
 **      File Name: 4.cpp
 **      Author: tiankonguse
 **      Mail: shen10000shen@gmail.com
 **      Created Time: 2013/3/29 18:25:36
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
struct compare
 {
   bool operator()(const int& l, const int& r)
   {
       return l > r;
   }
 };
priority_queue<int,vector<int>, compare > Q;

int main(){
    int t,n;
    int x1,x2,y1,y2;
    int x,ans;

    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        ans = 0;
        while(!Q.empty())Q.pop();

        while(n--){
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            Q.push(max(min(x1,x2),min(y1,y2)));
        }

        scanf("%d",&n);
        while(n--){
            scanf("%d",&x);
            while(!Q.empty() && x>= Q.top()){
                Q.pop();
                ans++;
            }
            printf("%d\n",ans);
        }

    }

    return 0;
}
/*
1
2
1 1 3 3
2 2 4 4
5
1
2
3
4
5

*/
