#include"iostream"
#include"cstdlib"
#include"queue"
#define MAXN (1<<16)
using namespace std;
const int data[16]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768};
struct node{
    int s,e;
  //  node(int s,int e):s(s),e(e){}
}q[MAXN],t;
//queue<node>q;
int state[MAXN];
bool mark[MAXN];
int change(int a,int n){
   int i=n/4,j=n%4;
   for(int k=i*4;k<i*4+4;k++){
       a^=data[k];
   }
   for(int k=0;k<4;k++){
       a^=data[j+k*4];
   }
   a^=data[n];
   return a;
}
void print(int n){
   for(int i=15;i>=0;i--){
      printf("%d",n>>i&1);
      if(i%4==0)printf("\n");
   }
}
int bfs(int s){
   // while(!q.empty())q.pop();
    int ts;
    if(s==0)return 0;
  //  q.push(node(s,0));
  //  node t(0,0);
    state[0]=0;
    q[0].s=s;
    q[0].e=0;
    int l=0,h=1;
    while(l<h){
       t=q[l];
       l++;
       for(int i=0;i<16;i++){
          ts=change(t.s,i);
          if(ts==0){
             return t.e|data[i];
          }
          if(state[ts]==-1){
             state[ts]=t.e|data[i];
             if(!mark[state[ts]]){
               mark[state[ts]]=true;
               q[h].s=ts;
               q[h++].e=state[ts];
             }
          }
       }
    }
    return -1;
}
int res[16];
int main(){
    char ch;
    int n,ans,sta=0,cnt=0;
    memset(state,0xff,sizeof(state)); 
    for(int i=0;i<4;i++){
       for(int j=0;j<4;j++){
          scanf(" %c",&ch);
          if(ch=='-')sta=sta<<1;
          else sta=sta<<1|1;
       }
    }
            
    ans=bfs(sta);
    for(int i=15;i>=0;i--){
       if(ans>>i&1){
           res[cnt++]=15-i;
       }
    }
    printf("%d\n",cnt);

    for(int i=0;i<cnt;i++){
       printf("%d %d\n",res[i]/4+1,res[i]%4+1);
    }
 //   system("pause");
    return 0;
}
