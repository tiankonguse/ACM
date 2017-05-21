#include"iostream"
using namespace std;
char map[1001][1001];
bool used[1001][1001];
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int w,h,cnt,mx;
bool check(int x,int y){
   if(x>=0 && x<h && y>=0 && y<w)return true;
   else return false;
}
void dfs(int x,int y){
    int tx,ty;
    used[x][y]=true;
    for(int i=0;i<4;i++){
        tx=x+dir[i][0];
        ty=y+dir[i][1];
        if(!check(tx,ty))continue;
        if(map[tx][ty]=='*' && !used[tx][ty]){
            cnt++;
            dfs(tx,ty);
        }
    }
}
int main(){
    mx=0;
    scanf("%d%d",&w,&h);
    for(int i=0;i<h;i++){
       scanf("%s",map[i]);
    }
    for(int i=0;i<h;i++){
       for(int j=0;j<w;j++){
           if(map[i][j]=='*' && !used[i][j]){
                cnt=1;
                dfs(i,j);
                if(cnt>mx)mx=cnt;
           }
       }
    }
    printf("%d\n",mx);
    //system("pause");
    return 0;
}
