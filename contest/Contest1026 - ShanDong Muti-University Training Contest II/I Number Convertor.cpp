/*************************************************************************
    > File Name: Number Convertor.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/14 20:45:25
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<stack>
#include<functional>
#include<algorithm>
using namespace std;
typedef long long LL;
const int N = 100001 ;
const LL LLMAX = 4557430888798830399LL;
LL str[N];
bool map[N];
int cost[15][6];
queue<int>que;

int getVal(int state,int a,int b){
    if(state == 1)return a+b;
    if(state == 2)return a-b;
    if(state == 3)return a*b;
    if(state == 4)return a/b;
}

int main() {
    int cas,i,j,a,b,n,tmp;
    LL val,tmp_val;

    scanf("%d",&cas);
    while(cas--){
        memset(str,0x3f3f,sizeof(str));
        memset(map,false,sizeof(map));

//        for(i=0;i<100;i++){
//            printf("%lld\n",str[i]);
//        }
        scanf("%d%d%d",&a,&b,&n);
        for(i=0;i<n;i++){
            scanf("%d",&cost[i][0]);
        }
        for(i=0;i<n;i++){
            for(j=1;j<=4;j++){
                scanf("%d",&cost[i][j]);
            }
        }
        str[a] = 0;
        map[a] = true;
        while(!que.empty())que.pop();

        que.push(a);
        while(!que.empty()){
            a = que.front();que.pop();map[a] = false;
            val = str[a];
            for(i=0;i<n;i++){
                for(j=1;j<=4;j++){
                    tmp = getVal(j,a ,cost[i][0]);
                    if(tmp <0 || tmp >= N)continue;
                    tmp_val = val + cost[i][j];

                    if(tmp_val >= str[tmp])continue;

                    if(map[tmp] == false){
                        map[tmp] = true;
                        que.push(tmp);
                    }
                    str[tmp] = tmp_val;
                }
            }
        }

        if(str[b] == LLMAX){
            printf("IMPOSSIBLE\n");
        }else{
            printf("%lld\n",str[b]);
        }


    }


    return 0;
}
