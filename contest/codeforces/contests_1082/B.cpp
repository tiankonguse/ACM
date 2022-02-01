/*************************************************************************
  > File Name: B.cpp
  > Author: tiankonguse
  > Mail: i@tiankonguse.com 
  > Created Time: Wed Nov 28 22:49:23 2018
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

const int N = 111111;
char str[N];

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    if(debug == 0)freopen("out.txt", "w", stdout);
#endif

    int n;
    while(~scanf("%d%s", &n, str+2)){
        str[0] = 'S';
        str[1] = 'S';
        int len = strlen(str);
        int ans = 0;
        //printf("str=%s\n", str);

        int goldenPart = 0; 
        for(int i=1;i<len;i++){
            if(str[i] == 'G' && str[i-1] != 'G'){
                goldenPart++;
                if(goldenPart > 2){
                    break;
                }
            }
        }
        //printf("goldenPart=%d\n", goldenPart);

        int maxPreNum = 0;
        int maxNextNum = 0;
        int dis = 2;

        for(int i=2;i<len;i++){
            if(str[i] == 'G'){
                //first G
                if(str[i-1] != 'G'){
                    maxNextNum = 1;
                }else{
                    maxNextNum++;
                }
                //no swap
                if(maxNextNum > ans){
                    ans = maxNextNum;
                }
                //one seg
                if(goldenPart > 1 && maxNextNum + 1 > ans){
                    ans = maxNextNum + 1;
                }

                //only two seg
                if(dis == 1 && maxPreNum + maxNextNum > ans){
                    ans = maxPreNum + maxNextNum;
                }
                //more seg
                if(dis == 1 && goldenPart > 2 && maxPreNum + maxNextNum + 1 > ans){
                    ans = maxPreNum + maxNextNum + 1;
                }
            }else{
                //first S
                if(str[i-1] == 'G'){
                    maxPreNum = maxNextNum;
                    maxNextNum = 0;
                    dis = 1;
                }else{
                    dis++;
                }
            }
        }
        printf("%d\n", ans);

    }


    return 0;
}
