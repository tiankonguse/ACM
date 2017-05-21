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

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
#define maxl 110
#define maxn 10
using namespace std;
char str[maxl];
char board[maxn][maxn];
bool check(int x, int y){
    if(x >= 0 && x < 8 && y >= 0 && y < 8 && (board[x][y] == '.' || board[x][y] == '*')){
        board[x][y] = '*';
        return true;
    }
    else return false;
}
void markr(int x, int y){
    for(int i=x-1;check(i, y);i--);
    for(int i=x+1;check(i, y);i++);
    for(int j=y-1;check(x, j);j--);
    for(int j=y+1;check(x, j);j++);
}
void markb(int x, int y){
    int i, j;
    for(i=x-1,j=y-1;check(i,j);i--,j--);
    for(i=x-1,j=y+1;check(i,j);i--,j++);
    for(i=x+1,j=y-1;check(i,j);i++,j--);
    for(i=x+1,j=y+1;check(i,j);i++,j++);
}
int main(){
    int len, x, y, res; char ch;
    while(gets(str)){
        len = strlen(str);
        x = y = 0;
        for(int i=0;i<len;i++){
            if(isdigit(str[i])){
                for(int j=str[i]-'0';j--;){
                    board[x][y++] = '.';
                }
            }
            else if(str[i] == '/'){
                x++, y = 0;
            }
            else{
                board[x][y++] = str[i];
            }
        }
//        for(int i=0;i<8;i++)puts(board[i]);
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                ch = board[i][j];
                if(ch == '.' || ch == '*') continue;
                else if(ch == 'r' || ch == 'R'){
                    markr(i, j);
                }
                else if(ch == 'n' || ch == 'N'){
                    check(i - 1, j - 2);
                    check(i - 2, j - 1);
                    check(i - 2, j + 1);
                    check(i - 1, j + 2);
                    check(i + 1, j - 2);
                    check(i + 2, j - 1);
                    check(i + 2, j + 1);
                    check(i + 1, j + 2);
                }
                else if(ch == 'b' || ch == 'B'){
                    markb(i, j);
                }
                else if(ch == 'q' || ch == 'Q'){
                    markr(i, j);
                    markb(i, j);
                }
                else if(ch == 'k' || ch == 'K'){
                    check(i - 1, j - 1);
                    check(i - 1, j);
                    check(i - 1, j + 1);
                    check(i, j - 1);
                    check(i, j + 1);
                    check(i + 1, j - 1);
                    check(i + 1, j);
                    check(i + 1, j + 1);
                }
                else if(ch == 'p'){
                    check(i + 1, j - 1);
                    check(i + 1, j + 1);
                }
                else if(ch == 'P'){
                    check(i - 1, j - 1);
                    check(i - 1, j + 1);
                }
            }
        }
//        for(int i=0;i<8;i++) puts(board[i]);
        res = 0;
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                res += board[i][j] == '.';
            }
        }
        printf("%d\n", res);
    }
    return 0;
}
