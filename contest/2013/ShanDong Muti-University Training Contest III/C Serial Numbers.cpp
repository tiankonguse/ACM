/*************************************************************************
    > File Name: C Serial Numbers.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/16 19:38:01
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
const int N = 100010;
struct T{
    int val,num;
    T(){};
    T(int val,int num):val(val),num(num){}
}now;
int str[N];
int _str[N];
int *oldstr,*newstr;
queue<T>que;z
int main() {
    int n,m,si,cas,i,tmp;
    scanf("%d",&cas);
    while(cas--){
        scanf("%d%d",&n,&m);
        memset(str,-1,sizeof(str));
        memset(_str,-1,sizeof(_str));
        oldstr = str;
        newstr = _str;
        while(!que.empty())que.pop();

        oldstr[0] = 0;
        que.push(T(0,0));

        for(i=1;i<=n;i++){
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
