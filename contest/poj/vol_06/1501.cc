#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#define MAXN 105
using namespace std;
int N;
int dir[8][2]={{0,1},{0,-1},{1,0},{-1,0},{-1,-1},{-1,1},{1,-1},{1,1}};
char map[MAXN][MAXN];
char str[105];
int main(){
    int i,j,tx,ty;
    scanf("%d",&N);
    for(i=0;i<N;i++)scanf(" %s",map[i]);
    while(scanf(" %s",str)){
        if(str[0]=='0')break;
        int len=strlen(str);
        bool flag=false;
        for(i=0;i<N;i++){
            for(j=0;j<N;j++){
                for(int d=0;d<8;d++){
                    for(int k=0;k<len;k++){
                        tx=i+dir[d][0]*k;
                        ty=j+dir[d][1]*k;
                        if(tx<0 || tx>=N || ty<0 || ty>=N || map[tx][ty]!=str[k])
                            break;
                        if(k==len-1)flag=true;
                    }
                    if(flag)break;
                }
                if(flag)break;
            }
            if(flag)break;
        }
        if(flag)printf("%d,%d %d,%d\n",i+1,j+1,tx+1,ty+1);
        else printf("Not found\n");
    }
    return 0;
}
