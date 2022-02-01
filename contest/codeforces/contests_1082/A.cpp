/*************************************************************************
  > File Name: A.cpp
  > Author: tiankonguse
  > Mail: i@tiankonguse.com 
  > Created Time: Wed Nov 28 22:45:24 2018
 ************************************************************************/

#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<stack>
#include<map>
#include<set>
#include<queue>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<time.h>
using namespace std;


#ifdef __int64
typedef __int64 LL;
#else
typedef long long LL;
#endif

const int debug = 0;
typedef unsigned uint;
typedef unsigned char uchar;
#define  myprintf(fmt,args...) do{if(debug)printf(fmt, ##args);}while(0)

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    if(debug == 0)freopen("out.txt", "w", stdout);
#endif
    int t,n,x,y,d;

    while(~scanf("%d", &t)){
        while(t--){
            scanf("%d%d%d%d",&n,&x,&y,&d);

            if(x <= y && (y - x)% d == 0){
                printf("%d\n", (y - x) / d);
            }else if(x >= y && (x - y) %  d == 0){
                printf("%d\n", (x-y)/d);
            }else if((y - 1) % d == 0 || (n - y) % d == 0){
                //has ans
                int beginAns = n*2;
                int endAns = n*2;
                if((y - 1) % d == 0){
                    beginAns = (x - 1 + d - 1)/d + (y - 1)/d;
                }
                if((n - y) % d == 0){
                    endAns = (n - x + d - 1)/d + (n - y)/d;
                }
                printf("%d\n", beginAns > endAns ? endAns : beginAns);
            }else{
                printf("-1\n");
            }
        }
    }

    return 0;
}
