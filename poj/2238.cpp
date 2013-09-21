#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<queue>
#include<functional>
using namespace std;

struct T{
    char ans[50];
    int bit;
    int mod;
}tmp;

queue<T>que;
char ans[50];
int bit;

int main(){
    int a, i;
    while(scanf("%d", &a), a){
        whiel(!que.empty())que.pop();
        if(a<10){
            printf("%d\n",a);
        }else{
            for(i = 1; i <= 9; ++i){
                tmp.ans[1]="\0";
                tmp.bit = 1;
                tmp.mod =i;
                que.push(tmp);
            }
            while(!que.empty()){
            }
            printf()
        }
    }
    return 0;
}
