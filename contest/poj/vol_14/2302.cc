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

using namespace std;
bool board[6][6];
int cards[100];
int pos[100][2];
bool check(){
    bool flag1, flag2;
    for(int i=0;i<5;i++){
        flag1 = flag2 = true;
        for(int j=0;j<5;j++){
            flag1 &= board[i][j];
            flag2 &= board[j][i];
        }
        if(flag1 || flag2) return true;
    }
    flag1 = flag2 = true;
    for(int i=0;i<5;i++){
        flag1 &= board[i][i];
        flag2 &= board[i][4-i];
    }
    return (flag1 || flag2);
}
int main(){
    int t,x;
    scanf("%d",&t);
    while(t--){
        memset(board,false,sizeof(board));
        memset(pos,0xff,sizeof(pos));
        board[2][2] = true;
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                if(i==2 && j==2)continue;
                scanf("%d",&x);
                pos[x][0] = i;
                pos[x][1] = j;
            }
        }
        for(int i=0;i<75;i++){
            scanf("%d",&cards[i]);
        }
        for(int i=0;i<75;i++){
            if(pos[cards[i]][0] == -1)continue;
            board[ pos[cards[i]][0] ][ pos[cards[i]][1] ] = true;
            if(check()){
                printf("BINGO after %d numbers announced\n",i+1);
                break;
            }
        }

    }
    return 0;
}
