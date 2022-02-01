#include"iostream"
#include"queue"
#define MAXN 100000
using namespace std;
struct node{
    int p,step;
    node(int i,int j):p(i),step(j){}
};
queue<node>q;
bool used[MAXN+1];
int bfs(int start,int dest){
   while(!q.empty())q.pop();
   node cur(start,0),t(0,0);
   q.push(cur);
   while(!q.empty()){
      t=q.front();
      q.pop();
      if(used[t.p])continue;
      used[t.p]=true;
      if(t.p==dest){
          return t.step;
      }
      if(t.p-1>=0)q.push(node(t.p-1,t.step+1));
      if(t.p+1<=dest)q.push(node(t.p+1,t.step+1));
      if(t.p*2<=MAXN)q.push(node(t.p*2,t.step+1));
   }
}
int main(){
    int N,K;
   // while(scanf("%d%d",&N,&K)!=EOF){
        scanf("%d%d",&N,&K);
        memset(used,false,sizeof(used));
        printf("%d\n",bfs(N,K));
  //  }
    return 0;
}
