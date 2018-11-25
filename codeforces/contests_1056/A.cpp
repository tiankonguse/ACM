/*************************************************************************
    > File Name: A.cpp
    > Author: tiankonguse
    > Mail: i@tiankonguse.com 
    > Created Time: Sun Nov 25 21:18:02 2018
 ************************************************************************/

#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<stack>
#include<map>
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


int main(){
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    #endif

    int n;
    std::map<int, int> stopMap;
    while(~scanf("%d", &n)){
        stopMap.clear();
        int line = n;
        while(n--){
            int r;
            scanf("%d", &r);
            while(r--){
                int stop;
                scanf("%d", &stop);
                stopMap[stop];
                stopMap[stop]++;
            }
        }
        int first = 1;
        for(auto it = stopMap.begin(); it != stopMap.end();it++){
            if(it->second == line){
                if(first == 0){
                    printf(" ");
                }
                printf("%d", it->first);
                first = 0;
            }
        }
        printf("\n");
    }


    return 0;
}
