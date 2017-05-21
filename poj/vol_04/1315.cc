#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#define MAXN 5
using namespace std;
char map[MAXN][MAXN];
int N,res;
int used[MAXN][MAXN];
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
bool check(int x,int y){
    if(x>=0 && x<N && y>=0 && y<N)return true;
    else return false;
} 
void dfs(int d){
    if(d>res)res=d;
    int tx,ty;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(map[i][j]=='.' && !used[i][j]){
                used[i][j]++;
                for(int k=0;k<4;k++){
                    for(int l=1;l<N;l++){
                        tx=i+dir[k][0]*l;
                        ty=j+dir[k][1]*l;
                        if(check(tx,ty)){
                            if(map[tx][ty]=='X')break;
                            else used[tx][ty]++;
                        }
                    }
                }
                dfs(d+1);
                for(int k=0;k<4;k++){
                    for(int l=1;l<N;l++){
                        tx=i+dir[k][0]*l;
                        ty=j+dir[k][1]*l;
                        if(check(tx,ty)){
                            if(map[tx][ty]=='X')break;
                            else used[tx][ty]--;
                        }
                    }
                }
                used[i][j]--;
            }
        }
    }
}
int main(){
    while(scanf("%d",&N)&&N){
        for(int i=0;i<N;i++)scanf("%s",map[i]);
        memset(used,0,sizeof(used));
        res=0;
        dfs(0);
        printf("%d\n",res);
    }
    return 0;
}
