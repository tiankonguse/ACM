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
        que.push(0);
        int lev = 1;
        for(int i=1;i<n;){
            if(que.empty()){
                lev = -1;
                break;
            }
            lev++;
            int nodeIndex = que.front();que.pop();
            for(;str[nodeIndex].value > 0 && i < n;i++, str[nodeIndex].value--){
               str[i].pre = str[nodeIndex].pos;
               str[i].value--;
               if(str[i].value){
                   que.push(i);
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
