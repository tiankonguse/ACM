#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define MAXN 105
using namespace std;
char mp[MAXN][MAXN];
int board[MAXN][MAXN];
int main(){
    int n,m,r,c;
    while(~scanf("%d%d%d%d",&n,&m,&r,&c)){
        if(n==0 && m==0 && r==0 && c==0)break;
        for(int i=0;i<n;i++){
            scanf(" %s",mp[i]);
            for(int j=0;j<m;j++){
                board[i][j]=mp[i][j]-'0';
            }
        }
        int res=0;
        for(int i=0;i+r<=n;i++){
            for(int j=0;j+c<=m;j++){
                if(board[i][j]==1){
                    res++;
                    for(int it=i;it<i+r;it++){
                        for(int jt=j;jt<j+c;jt++){
                            board[it][jt] ^= 1;
                        }
                    }

                }
            }
        }
        bool flag=true;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==1){
                    flag=false;
                    break;
                }
            }
            if(!flag)break;
        }
        if(!flag)printf("-1\n");
        else printf("%d\n",res);
    }
    return 0;
}
