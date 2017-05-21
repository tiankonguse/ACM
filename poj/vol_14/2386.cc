#include <iostream>
#include <cstdlib>
using namespace std;
char map[101][101];
bool used[101][101];
int dir[8][2]={{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1}};
int N,M;
bool check(int x,int y){
     if(x>=N || y>=M || used[x][y]==true)return false;
     else return true;
}
void dfs(int x,int y){
    used[x][y]=true;
    for(int i=0;i<8;i++){
        if(check(x+dir[i][0],y+dir[i][1]) && map[x+dir[i][0]][y+dir[i][1]]=='W'){
           dfs(x+dir[i][0],y+dir[i][1]);
        }
    }
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    scanf("%d%d",&N,&M);
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            scanf(" %c",&map[i][j]);
        }
    }
    int res=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(map[i][j]=='W' && !used[i][j]){
                dfs(i,j);
                res++;
            }
        }
    }
    printf("%d\n",res);

    return 0;
}
