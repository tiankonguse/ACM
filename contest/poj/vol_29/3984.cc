#include"iostream"
#include"cstring"
#include"cstdio"
#include"cstdlib"
using namespace std;
int maze[6][6];
int dp[6][6];//1 up 2 left
int st[100][2];
int dir[3][2]={{0,0},{-1,0},{0,-1}};
int main(){
    int N=5;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            scanf("%d",&maze[i][j]);
        }
    }
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(i>0 && !maze[i-1][j] && !maze[i][j] && dp[i-1][j]){
                dp[i][j]=1;
            }
            else if(j>0 && !maze[i][j-1] && !maze[i][j] && dp[i][j-1]){
                dp[i][j]=2;
            }
        }
    }
    int l=0;
    int tx,ty,x=4,y=4;
    st[l][0]=st[l][1]=4;
    while(1){
        tx=x+dir[dp[x][y]][0];
        ty=y+dir[dp[x][y]][1];
        l++;
        st[l][0]=tx;
        st[l][1]=ty;
        x=tx;
        y=ty;
        if(x==0 && y==0)break;
    }
    while(l>=0){
        printf("(%d, %d)\n",st[l][0],st[l][1]);
        l--;
    }
    return 0;
}
