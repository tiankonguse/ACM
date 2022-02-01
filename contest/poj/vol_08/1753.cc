#include"iostream"
#include"cstdlib"
#include"queue"
#define MAXN (1<<16)
using namespace std;
struct node{
   int s,t;
   node(int i,int j):s(i),t(j){}
};
bool state[MAXN];
queue<node>q;
int bfs(int st){
   while(!q.empty())q.pop();
   if(st==0 || st==MAXN-1)return 0;
   state[st]=true;
   q.push(node(st,0));
   node t(0,0);
   int t2;
   while(!q.empty()){
      t=q.front();
      q.pop();
      for(int i=0;i<16;i++){
         t2=t.s^(1<<i);
         if(i-4>=0)t2^=(1<<(i-4));
         if(i+4<16)t2^=(1<<(i+4));
         if(i%4>0)t2^=(1<<(i-1));
         if(i%4<3)t2^=(1<<(i+1));
         if(state[t2])continue;
         if(t2==0 || t2==MAXN-1)return t.t+1;  
         state[t2]=true;
         q.push(node(t2,t.t+1));
      }
   }
   return -1;
}
int main(){
    int T,st,ans;
    char c;
   // scanf("%d",&T);
   // while(T--){
       st=0;
       memset(state,false,sizeof(state));
       for(int i=15;i>=0;i--){
          scanf(" %c",&c);
          if(c=='b')st+=(1<<i);
       }
       ans=bfs(st);
       if(ans!=-1)printf("%d\n",ans);
       else printf("Impossible\n");
  //     if(T)printf("\n");
  //  }
 //   system("pause");
    return 0;
}
