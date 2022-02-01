#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#define MAXN 127
using namespace std;
char mp[MAXN][MAXN];
bool used[MAXN][MAXN];
int mark[MAXN][MAXN];
int main(){
    int N,_ca=1;
    while(scanf("%d",&N) && N){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                scanf("%d",&mark[i][j]);
            }
        }
        int w = 2*N + 1;
        int h = 2*N - 1;
        int mw = 2*w + 1;
        int mh = 2*h + 1;
        memset(used,false,sizeof(used));
        for(int i=1;i<mh-1;i++)for(int j=1;j<mw-1;j++)mp[i][j]=' ';
        for(int i=0;i<mh;i++)mp[i][0]=mp[i][mw-1]='*';
        for(int j=0;j<mw;j++)mp[0][j]=mp[mh-1][j]='*';
        for(int i=1;i<mh-1;i+=2){
            if(i%4==1){
                for(int j=1;j<mw-1;j+=4){
                    mp[i][j]='H';
                }
            }
            else{
                for(int j=3;j<mw-1;j+=4){
                    mp[i][j]='H';
                }
            }
        }
        for(int i=1;i<mh-1;i+=4){
            for(int j=3;j<mw-1;j+=4){
                mp[i][j]='O';
            }
        }
        int tx,ty;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                tx=1+i*4;
                ty=3+j*4;
                if(mark[i][j]==1){
                    mp[tx][ty-1]=mp[tx][ty+1]='-';
                    used[tx][ty-2]=used[tx][ty+2]=true;
                }
                else if(mark[i][j]==-1){
                    mp[tx-1][ty]=mp[tx+1][ty]='|';
                    used[tx-2][ty]=used[tx+2][ty]=true;
                }
            }
        }
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(mark[i][j]==0){
                    tx=1+i*4;
                    ty=3+j*4;
                    if(i!=0 && !used[tx][ty-2] && !used[tx-2][ty]){
                        used[tx][ty-2]=used[tx-2][ty]=true;
                        mp[tx][ty-1]='-';
                        mp[tx-1][ty]='|';
                    }
                    else if(i!=0 && !used[tx][ty+2] && !used[tx-2][ty]){
                        used[tx][ty+2]=used[tx-2][ty]=true;
                        mp[tx][ty+1]='-';
                        mp[tx-1][ty]='|';
                    }
                    else if(i!=N-1 && !used[tx][ty-2] && !used[tx+2][ty]){
                        used[tx][ty-2]=used[tx+2][ty]=true;
                        mp[tx][ty-1]='-';
                        mp[tx+1][ty]='|';
                    }
                    else if(i!=N-1 && !used[tx][ty+2] && !used[tx+2][ty]){
                        used[tx][ty+2]=used[tx+2][ty]=true;
                        mp[tx][ty+1]='-';
                        mp[tx+1][ty]='|';
                    }
                }
            }
        }


        if(_ca>1)printf("\n");
        printf("Case %d:\n\n",_ca++);
        for(int i=0;i<mh;i++){
            for(int j=0;j<mw;j++){
                printf("%c",mp[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
