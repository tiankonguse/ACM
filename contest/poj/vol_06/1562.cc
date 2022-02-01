#include <iostream>

using namespace std;
char map[101][101];
bool used[101][101];
int dir[8][2]={{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
int M,N;
bool check(int x,int y){
    if(x>=0 && x<M && y>=0 && y<N && used[x][y]==false)return true;
    else return false;
}
void dfs(int x,int y){
    used[x][y]=true;
    for(int i=0;i<8;i++){
        if(check(x+dir[i][0],y+dir[i][1]) && map[x+dir[i][0]][y+dir[i][1]]=='@'){
            dfs(x+dir[i][0],y+dir[i][1]);
        }
    }
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
    #endif
    while(scanf("%d%d",&M,&N) && M){
        memset(used,false,sizeof(used));
        for(int i=0;i<M;i++){
            for(int j=0;j<N;j++){
                scanf(" %c",&map[i][j]);
            }
        }
        int res=0;
        for(int i=0;i<M;i++){
            for(int j=0;j<N;j++){
                if(map[i][j]=='@' && !used[i][j]){
                    dfs(i,j);
                    res++;
                }
            }
        }
        printf("%d\n",res);
    }
    return 0;
}
