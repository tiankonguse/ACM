#include"iostream"
#include"cstdlib"
#include"string.h"
using namespace std;
int R,C;
int map[21][21],mx=1;
bool used[26];
void dfs(int x,int y,int t){
     if(t>mx)mx=t;
     if(x<R-1 && !used[map[x+1][y]]){
         used[map[x+1][y]]=true;
         dfs(x+1,y,t+1);
         used[map[x+1][y]]=false;
     }
     if(x>0 && !used[map[x-1][y]]){
         used[map[x-1][y]]=true;
         dfs(x-1,y,t+1);
         used[map[x-1][y]]=false;
     }
     if(y<C-1 && !used[map[x][y+1]]){
         used[map[x][y+1]]=true;
         dfs(x,y+1,t+1);
         used[map[x][y+1]]=false;
     }
     if(y>0 && !used[map[x][y-1]]){
         used[map[x][y-1]]=true;
         dfs(x,y-1,t+1);
         used[map[x][y-1]]=false;
     }
}
int main(){
    char ch;
    scanf("%d%d",&R,&C);
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            scanf(" %c",&ch);
            map[i][j]=ch-'A';
        }
    }
    used[map[0][0]]=true;
    dfs(0,0,1);
    printf("%d\n",mx);
    //system("pause");
    return 0;
}
