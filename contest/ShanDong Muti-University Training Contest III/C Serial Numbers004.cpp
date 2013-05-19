/*************************************************************************
    > File Name: C Serial Numbers004.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/17 9:16:51
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

const int N = 100010;
struct T{
    int val,num;
    T(){};
    T(int val,int num):val(val),num(num){}
}now,que[N];
int que_num;
bool vis[N];
int ans[N];
int main() {
    int n,m,si,cas,i,tmp;
    scanf("%d",&cas);
    while(cas--){
        scanf("%d%d",&n,&m);
        memset(vis,false,sizeof(vis));

        que_num = 0;

        while(n--){
            scanf("%d",&si);
            while(1){
                if(que.front().num == i)break;
                now = que.front();que.pop();
                tmp = now.val;
                now.num++;
//                printf("--i=%d tmp=%d num=%d\n",i,tmp,now.num);
                if(newstr[now.val] != -1){
                    if(oldstr[now.val] > newstr[now.val]){
                        newstr[now.val] = oldstr[now.val];
                    }
                }else{
                    newstr[now.val] = oldstr[now.val];
                    que.push(now);
                }

                now.val = (now.val + si)%m;
//                printf("--i=%d tmp=%d num=%d\n",i,tmp,now.num);
                if(newstr[now.val] != -1){
                    if(oldstr[tmp] +1 > newstr[now.val]){
                        newstr[now.val] = oldstr[tmp] +1;
                    }
                }else{
                    newstr[now.val] = oldstr[tmp] +1;
                    que.push(now);
                }
                oldstr[tmp] = -1;
            }
            swap(oldstr,newstr);
        }
        printf("%d\n",oldstr[0]);

    }




    return 0;
}
