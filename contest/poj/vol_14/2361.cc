#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXN 4
using namespace std;
char map[MAXN][MAXN];
int check(char c){
    int cnt=0;
    for(int i=0;i<3;i++){
        if(map[i][0]==c && map[i][1]==c && map[i][2]==c)cnt++;
        if(map[0][i]==c && map[1][i]==c && map[2][i]==c)cnt++;
    }
    if(map[0][0]==c && map[1][1]==c && map[2][2]==c)cnt++;
    if(map[0][2]==c && map[1][1]==c && map[2][0]==c)cnt++;
    return cnt;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        for(int i=0;i<3;i++)scanf(" %s",map[i]);
        int cx=0,co=0,xw=0,ow=0;
        bool flag=true;
        xw=check('X');
        ow=check('O');
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(map[i][j]=='X')cx++;
                else if(map[i][j]=='O')co++;
            }
        }
        if(xw==0 && ow==0){
            if(cx<co || cx-co>1)flag=false;
        }
        else if(xw>=1 && ow==0){
            if(cx-co!=1)flag=false;
        }
        else if(xw==0 && ow>=1){
            if(cx!=co)flag=false;
        }
        else flag=false;
        printf("%s\n",flag?"yes":"no");
    }
    return 0;
}
