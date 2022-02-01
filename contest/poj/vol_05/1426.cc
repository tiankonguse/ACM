#include"iostream"
#include"queue"
#include"cstdio"
#include"string.h"
using namespace std;
bool used[200];
queue<__int64>q;
__int64 bfs(int n){
    __int64 t,d;
    memset(used,false,sizeof(used));
    while(!q.empty())q.pop();
    q.push(1);
    while(!q.empty()){
       t=q.front();
       q.pop();
       d=t%n;
       if(d==0)return t;
       else if(!used[d]){
          used[d]=true;
          q.push(t*10);
          q.push(t*10+1);
       }
    }
}
int main(){
    int n;
    while(scanf("%d",&n)&&n){
        printf("%I64d\n",bfs(n));
    }
    return 0;
}
