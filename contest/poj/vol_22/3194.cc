#include"iostream"
using namespace std;
int N,cnt;
int map[101][101];
int om[101][2];
bool used[101][101];
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
bool check(int x,int y){
     if(x>=0 && x<N && y>=0 && y<N)return true;
     else return false;
}
void dfs(int x,int y,int v){
    int tx,ty;
    used[x][y]=true;
    cnt++;
    for(int i=0;i<4;i++){
         tx=x+dir[i][0];
         ty=y+dir[i][1];
         if(map[tx][ty]==v && !used[tx][ty] && check(tx,ty)){
              dfs(tx,ty,v);
         }
    }
}
int main(){
    int a,b;
    bool flag,f2;
    while(scanf("%d",&N)&&N){
        memset(map,0,sizeof(map));
        memset(used,false,sizeof(used));
        for(int i=1;i<N;i++){
            for(int j=0;j<N;j++){
                scanf("%d%d",&a,&b);
                if(j==0){
                     om[i][0]=a-1;
                     om[i][1]=b-1;
                }
                map[a-1][b-1]=i;
            }
        }
        flag=true;
        for(int i=1;i<N;i++){
            cnt=0;
            dfs(om[i][0],om[i][1],i);
            if(cnt!=N){
                flag=false;
                break;
            }
        }
        if(flag){
             f2=false;
             for(int i=0;i<N;i++){
                for(int j=0;j<N;j++){
                    if(map[i][j]==0){
                        cnt=0;
                        dfs(i,j,0);
                        if(cnt!=N)flag=false;
                        f2=true;
                        break;
                    }
                }
                if(f2)break;
             }
        }
        if(flag)printf("good\n");
        else printf("wrong\n");
    }
    return 0;
}
