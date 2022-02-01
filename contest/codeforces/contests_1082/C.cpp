/*************************************************************************
    > File Name: C.cpp
    > Author: tiankonguse
    > Mail: i@tiankonguse.com 
    > Created Time: Wed Nov 28 23:44:46 2018
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
    int s;
    int r;
    bool operator<(const Node &t2)const {
        if(this->s == t2.s){
            return this->r > t2.r;
        }else{
            return this->s > t2.s;
        }
    }
};
const int N = 111111;
Node nodeList[N];
LL sum[N];

int main(){
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    if(debug == 0)freopen("out.txt", "w", stdout);
    #endif

    int n,m;
    while(~scanf("%d%d", &n, &m)){
        for(int i=0;i<n;i++){
            scanf("%d%d", &(nodeList[i].s), &(nodeList[i].r));
            sum[i] = 0;
        }
        sort(nodeList, nodeList+n);

        for(int i=0; i< n;){
            LL value = 0;
            int preS = nodeList[i].s;
            for(int index = 0;i < n && preS == nodeList[i].s;i++, index++){
                value += nodeList[i].r;
                if(value <= 0){
                    continue;
                }else{
                    sum[index] += value;
                }
            }
        }
        LL ans = 0;
        for(int i=0;i<n;i++){
            if(sum[i] > ans){
                ans = sum[i];
            }
        }
        printf("%lld\n", ans);

    }

    return 0;
}
