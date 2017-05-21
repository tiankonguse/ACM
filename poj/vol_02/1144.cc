#include"iostream"
#include"cstdlib"
#include"vector"
#include"string"
#include"sstream"
#define min(a,b) (a<b?a:b)
#define MAXN 101
using namespace std;
vector<int> map[MAXN];
bool flag[MAXN],visit[MAXN];
int dfn[MAXN],low[MAXN];
int N,cnt;
void dfs(int u){
    int v,c=0,len=map[u].size();
    cnt++;
    dfn[u]=low[u]=cnt;
    visit[u]=true;
    for(int i=0;i<len;i++){
        v=map[u][i];
        if(!visit[v]){
            c++;
            dfs(v);
            low[u]=min(low[u],low[v]);
            if(u==1){
               if(c==2){
                        flag[u]=true;
               }
            }
            else{
               if(low[v]>=dfn[u])flag[u]=true;
            }
        }
        else {
            low[u]=min(low[u],dfn[v]);
        }
    }
}
int main(){
    int a,b;
    string s;
    while(cin>>N &&N){
         for(int i=1;i<=N;i++)map[i].clear();
         getchar();
         while(getline(cin,s)){
             istringstream in(s);
             in>>a;
             if(a==0)break;
             while(in>>b){
                map[a].push_back(b);
                map[b].push_back(a);
             }
         }
         memset(flag,false,sizeof(flag));
         memset(visit,false,sizeof(visit));
         memset(dfn,0,sizeof(dfn));
         memset(low,0,sizeof(low));
         cnt=0;
         dfs(1);
         cnt=0;
         for(int i=1;i<=N;i++){
                 if(flag[i]){
                    cnt++;
                 }
         }
         printf("%d\n",cnt);
    }
    return 0;
}
