#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define MAXN 41
using namespace std;
bool used[MAXN];
bool mark[MAXN][MAXN];
int cake[MAXN];
int N,M,sum;
bool dfs(int d){
    if(d==M)return true;
    bool sf=false;
    int sx,sy;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(!mark[i][j]){
                sx=i,sy=j;
                sf=true;break;
            }
        }
        if(sf)break;
    }
    int p=-1;
    for(int k=M-1;k>=0;k--){

        if(!used[k]){
            if(cake[k]==p)continue;
            else p=cake[k];
            if(sx+cake[k]>N || sy+cake[k]>N)continue;
            used[k]=true;
            bool flag=true;
            for(int x=sx;x<sx+cake[k];x++){
                for(int y=sy;y<sy+cake[k];y++){
                    if(mark[x][y]){
                        flag=false;
                        break;
                    }
                }
                if(!flag)break;
            }
            if(flag){
                for(int x=sx;x<sx+cake[k];x++){
                    for(int y=sy;y<sy+cake[k];y++){
                        mark[x][y]=true;
                    }
                }
              /*  for(int i=0;i<N;i++){
                    for(int j=0;j<N;j++){
                        printf("%d",mark[i][j]);
                    }
                    printf("\n");
                }
                printf("sx=%d,sy=%d\n",sx,sy);
                printf("cake=%d\n",cake[k]);
            //    system("pause");*/
                if(dfs(d+1))return true;
                for(int x=sx;x<sx+cake[k];x++){
                    for(int y=sy;y<sy+cake[k];y++){
                        mark[x][y]=false;
                    }
                }
            }
            used[k]=false;
        }
    }
    return false;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&N,&M);
        sum=0;
        for(int i=0;i<M;i++){
            scanf("%d",&cake[i]);
            sum+=(cake[i]*cake[i]);
        }
        sort(cake,cake+M);
        if(sum!=N*N)printf("HUTUTU!\n");
        else{
            memset(used,false,sizeof(used));
            memset(mark,false,sizeof(mark));
            if(dfs(0))printf("KHOOOOB!\n");
            else printf("HUTUTU!\n");
        }
    }
    return 0;
}
