#include"iostream"
using namespace std;
char map[20][20];
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int main(){
    int M,N,s,p,x,y,tx,ty,a,cnt;
    while(~scanf("%d%d",&M,&N)){
        memset(map,0,sizeof(map));
        for(int i=0;i<=M+1;i++)map[i][N+1]=map[i][0]=-1;
        for(int i=0;i<=N;i++)map[M+1][i]=map[0][i]=-1;
        x=1;cnt=y=p=0;a=65;
        while(1){
            tx=x+dir[p][0];
            ty=y+dir[p][1];
            if(map[tx][ty]!=0)p=(p+1)%4;
            else{
                map[tx][ty]=a++;
                if(a>90)a-=26;
                x=tx;y=ty;
                cnt++;
                if(cnt==M*N)break;
            }
        }
        for(int i=1;i<=M;i++){
           for(int j=1;j<=N;j++)printf("%4c",map[i][j]);
           printf("\n");
        }
    }
    return 0;
}
