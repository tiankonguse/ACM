/*************************************************************************
    > File Name: C.cpp
    > Author: tiankonguse
    > Mail: i@tiankonguse.com 
    > Created Time: 2018年11月26日  0:05:25
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

int powerHero[2222];
std::map<int, std::set<int> > maxMap;
std::map<int, std::set<int> > leftList;
std::map<int, int> pairMap;

void addData(int pos, std::map<int, std::set<int> >& maplist){
    int val = powerHero[pos];
    maplist[val].insert(pos);
}

void delData(int pos, std::map<int, std::set<int> >& maplist){
    int val = powerHero[pos];
    maplist[val].erase(pos);
    if(maplist[val].size() == 0){
        maplist.erase(val);
    }
}

void bindData(int a, int b){
    pairMap[a] = b;
    pairMap[b] = a;
    addData(a, maxMap);
    addData(b, maxMap);
}

void unbindData(int a, int b){
    pairMap.erase(a);
    pairMap.erase(b);
    delData(a, maxMap);
    delData(b, maxMap);
}

#define  myprintf(fmt,args...) do{\
    if(debug)printf(fmt, ##args);\
}while(0)

int getMax(std::map<int, std::set<int> >& maplist){
    auto itMap = maplist.end();
    itMap--;
    return *(itMap->second.begin());
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    if(debug == 0){
        freopen("out.txt", "w", stdout);
    }
    #endif
    int n,m;
    int a, b;
    while(~scanf("%d%d", &n,&m)){
        maxMap.clear();
        pairMap.clear();
        leftList.clear();
        for(int i=1;i<=n*2;i++){
            scanf("%d", &powerHero[i]);
            addData(i, leftList);
        }
        for(int i=1;i<=m;i++){
            scanf("%d%d", &a, &b);
            bindData(a, b);
        }
        int t;
        scanf("%d", &t);
        
        myprintf("begin cal t = %d\n", t);
        for(int i=0;i<n;i++){
            myprintf("i=%d t=%d\n\n", i, t);
            if(t == 2){
                scanf("%d", &a);
                delData(a, leftList);
               
                //must choose from pair 
                if(pairMap.find(a) != pairMap.end()){
                    b = pairMap[a];
                    myprintf("t=0, pair(%d, %d)\n", a, b);
                    unbindData(a, b);
                }else{
                    if(maxMap.size() > 0){
                        b = getMax(maxMap); 
                        t = 3;
                        myprintf("t=0 get pair, t=2. a=%d (%d, )\n", a, b);
                    }else{
                        b = getMax(leftList); 
                        myprintf("t=0 get max a=%d b=%d\n", a, b);
                    }
                }
                delData(b, leftList);
                printf("%d\n", b);
                fflush(stdout);
            }else if(t == 3){
                //main
                scanf("%d", &a);
                delData(a, leftList);

                if(pairMap.find(a) != pairMap.end()){
                    b = pairMap[a];
                    myprintf("t=2, pair(%d, %d)\n", a, b);
                    unbindData(a, b);
                }

                if(maxMap.size() > 0){
                    b = getMax(maxMap); 
                    myprintf("t=2 get pair. a=%d (%d, )\n", a, b);
                }else{
                    b = getMax(leftList); 
                    myprintf("t=2 get max a=%d b=%d\n", a, b);
                }

                delData(b, leftList);
                printf("%d\n", b);
                fflush(stdout);
            }else{
                if(maxMap.size() > 0){
                    b = getMax(maxMap); 
                    a = pairMap[b];
                    myprintf("t=1, pair(%d, %d)\n", a, b);
                    unbindData(a, b);
                }else{
                    b = getMax(leftList); 
                    myprintf("t=1 get max a=%d b=%d\n", a, b);
                }

                printf("%d\n", b);
                fflush(stdout);
                
                scanf("%d", &a);

                delData(b, leftList);
                delData(a, leftList);
            }
        }
    }
    
    return 0;
}
