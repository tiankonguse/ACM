#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#define MAXN 1005
#define MAXM 1000005
using namespace std;
int N;
int mat[MAXN][MAXN];
int pos[MAXM][2];
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int jd(int x,int y,int k){
    if(x==k && y<N-k-1)return 0;
    else if(y==N-k-1 && x<N-k-1)return 1;
    else if(x==N-k-1 && y>k)return 2;
    else if(y==k && x>k)return 3;
}
bool judge(){
    int r_cnt=N/2;
    int s,sx,sy,x,y,d,p;
    for(int k=0;k<r_cnt;k++){
        s=k*N+k+1;
        sx=pos[s][0];
        sy=pos[s][1];
        if(sx<k || sy<k || sx>=N-k || sy>=N-k ||
            (sx>k && sx<N-k-1 && sy>k && sy<N-k-1)){
            return false;
        }
        x=sx,y=sy,p=mat[x][y];
        for(int i=0;i<N-2*k-1;i++){
            d=jd(x,y,k);
            x+=dir[d][0];
            y+=dir[d][1];
            if(mat[x][y]!=p+1)return false;
            p++;
        }
        for(int i=0;i<N-2*k-1;i++){
            d=jd(x,y,k);
            x+=dir[d][0];
            y+=dir[d][1];
            if(mat[x][y]!=p+N)return false;
            p+=N;
        }
        for(int i=0;i<N-2*k-1;i++){
            d=jd(x,y,k);
            x+=dir[d][0];
            y+=dir[d][1];
            if(mat[x][y]!=p-1)return false;
            p--;
        }
        for(int i=0;i<N-2*k-1;i++){
            d=jd(x,y,k);
            x+=dir[d][0];
            y+=dir[d][1];
            if(mat[x][y]!=p-N)return false;
            p-=N;
        }
    }
    if(N%2==1)return (mat[r_cnt][r_cnt]==r_cnt*N+r_cnt+1);
    else return true;
}
int main(){
    int a;
    int cnt=1;
    while(scanf("%d",&N)&&N){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                scanf("%d",&a);
                mat[i][j]=a;
                pos[a][0]=i;
                pos[a][1]=j;
            }
        }
        printf("%d. %s\n",cnt++,judge()?"YES":"NO");
    }
    return 0;
}
