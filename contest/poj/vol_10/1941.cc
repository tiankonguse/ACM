#include"iostream"
#include"cstdio"
#include"cstdlib"
#include"cstring"
using namespace std;
int dx[10]={2,4,8,16,32,64,128,256,512,1024};
int dy[10]={4,8,16,32,64,128,256,512,1024,2048};
char map[10][1025][2050]={" /\\ ","/__\\"};

int main(){
    for(int i=1;i<10;i++){
        for(int ci=0;ci<dx[i-1];ci++){
            for(int cj=0;cj<dy[i-1];cj++){
                map[i][ci][cj+dx[i-1]]=map[i-1][ci][cj];
            }
        }
        for(int ci=0;ci<dx[i-1];ci++){
            for(int cj=0;cj<dy[i-1];cj++){
                map[i][ci+dx[i-1]][cj]=map[i-1][ci][cj];
            }
        }
        for(int ci=0;ci<dx[i-1];ci++){
            for(int cj=0;cj<dy[i-1];cj++){
                map[i][ci+dx[i-1]][cj+dy[i-1]]=map[i-1][ci][cj];
            }
        }
    }
    int N;
    while(scanf("%d",&N)&&N){
        N--;
        for(int i=0;i<dx[N];i++){
            for(int j=0;j<dy[N];j++){
               if(map[N][i][j]==0)printf(" ");
               else printf("%c",map[N][i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
