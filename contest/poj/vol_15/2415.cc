#include"iostream"
#include"queue"
using namespace std;
struct node{
   int a,b,c,step;
   node(int i,int j,int k,int l):a(i),b(j),c(k),step(l){}
};
char mat[51][51];
bool state[51][51][51];
int n;
queue<node>q;
int bfs(int as,int bs,int cs){
    while(!q.empty())q.pop();
    if(as==bs && bs==cs)return 0;
    node tmp(as,bs,cs,0),t(0,0,0,0);
    q.push(tmp);
    state[as][bs][cs]=true;
    while(!q.empty()){
        t=q.front();
        q.pop();
        for(int i=0;i<n;i++){
           if(mat[t.a][i]==mat[t.b][t.c] && !state[i][t.b][t.c]){
               if(i==t.b && t.b==t.c)return t.step+1;
               state[i][t.b][t.c]=true;
               q.push(node(i,t.b,t.c,t.step+1));
           }
           if(mat[t.b][i]==mat[t.a][t.c] && !state[t.a][i][t.c]){
               if(t.a==i && i==t.c)return t.step+1;
               state[t.a][i][t.c]=true;
               q.push(node(t.a,i,t.c,t.step+1));
           }
           if(mat[t.c][i]==mat[t.a][t.b] && !state[t.a][t.b][i]){
               if(t.a==t.b && t.b==i)return t.step+1;
               state[t.a][t.b][i]=true;
               q.push(node(t.a,t.b,i,t.step+1));
           }
        }
    }
    return -1;
}
int main(){
    #ifndef ONLINE_JUDGE
      freopen("hike.in","r",stdin);
      freopen("hiketest.txt","w",stdout);
    #endif
    int as,bs,cs,ans;
    while(scanf("%d",&n)&&n){
           memset(state,false,sizeof(state));
           scanf("%d%d%d",&as,&bs,&cs);
           for(int i=0;i<n;i++){
              for(int j=0;j<n;j++){
                 scanf(" %c",&mat[i][j]);
              }
           }
           ans=bfs(as-1,bs-1,cs-1);
           if(ans==-1){
              printf("impossible\n");
           }
           else printf("%d\n",ans);
    }
    return 0;
}
