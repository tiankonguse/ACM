/*************************************************************************
    > File Name: D.cpp
    > Author: tiankonguse
    > Mail: i@tiankonguse.com 
    > Created Time: Thu Nov 29 00:29:07 2018
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


struct Node{
    int pos;
    int value;
    int pre;
    bool operator<(const Node &t2)const {
        return this->value > t2.value;
    }
};
Node str[555];

int main(){
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    if(debug == 0)freopen("out.txt", "w", stdout);
    #endif
    
    int n;
    while(~scanf("%d", &n)){
        for(int i=0;i<n;i++){
            scanf("%d", &str[i].value);
            str[i].pos = i+1;
            str[i].pre = 0;
        }
        sort(str, str+n);

        std::queue<int> que;

        int nodeIndex = 0;
        int lev = 0;
        int first = 1;
        for(int i=1;i<n;i++){
            if(str[i-1].value > 0){
                lev++;
                str[i-1].value--;
                str[i].value--;
                str[i].pre = str[i-1].pos;
            }else{
               if(str[nodeIndex].value == 0){
                   lev = -1;
                   break;
               }else{
                   if(first == 1 && nodeIndex == 0){
                    lev++;
                    first = 0;
                   }
                    str[nodeIndex].value--;
                    str[i].value--;
                    str[i].pre = str[nodeIndex].pos;
                    if(str[nodeIndex].value == 0){
                        nodeIndex++;
                    }
               } 
            }
        }
        if(lev == -1){
            printf("NO\n");
        }else{
            printf("YES %d\n", lev);
            printf("%d\n", n-1);
            for(int i=1;i<n;i++){
                printf("%d %d\n", str[i].pos, str[i].pre);
            }
        }
    }

    return 0;
}
