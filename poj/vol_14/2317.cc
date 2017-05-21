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
#define maxn 105
#define maxl 10010
using namespace std;
char key[maxn], str[maxl];
char mp[maxn][maxn];
int n, m, len;
void shake(){
    char t;
    for(int j=0;j<n;j+=2){
        t = mp[0][j];
        for(int i=0;i<n-1;i++){
            mp[i][j] = mp[i+1][j];
        }
        mp[n-1][j] = t;
    }
    for(int j=1;j<n;j+=2){
        t = mp[n-1][j];
        for(int i=n-1;i>0;i--){
            mp[i][j] = mp[i-1][j];
        }
        mp[0][j] = t;
    }
}
void rattle(){
    char t;
    for(int i=0;i<n;i+=2){
        t = mp[i][n-1];
        for(int j=n-1;j>0;j--){
            mp[i][j] = mp[i][j-1];
        }
        mp[i][0] = t;
    }
    for(int i=1;i<n;i+=2){
        t = mp[i][0];
        for(int j=0;j<n-1;j++){
            mp[i][j] = mp[i][j+1];
        }
        mp[i][n-1] = t;
    }
}
int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
void loop(){
    int lp = n / 2, d, x, y, tx, ty, l;
    int dp;
    for(int k=0;k<lp;k++){
        if(k % 2 == 0) dp = 1, d = 0;
        else dp = 3, d = 1;
        l = n - k * 2 - 1;
        x = y = k;
        for(int i=0;i<4;i++){
            for(int j=0;j<l;j++){
                if(i == 3 && j == l - 1) break;
                tx = x + dir[d][0];
                ty = y + dir[d][1];
                swap(mp[x][y], mp[tx][ty]);
                x = tx;
                y = ty;
            }
            d = (d + dp) % 4;
        }
    }
}
int main(){
    char ch;
    int lk;
    while(gets(key)){
        gets(str);
        n = (key[0] - '0') * 10 + (key[1] - '0');
        if(n == 0) n = 100;
        m = n * n;
        len = strlen(str);
        ch = 'A';
        for(int i=0;i<m;i++){
            if(i < len){
                if(str[i] >= 'a' && str[i] <= 'z') str[i] -= 32;
                mp[i / n][i % n] = str[i];
            }
            else{
                mp[i / n][i % n] = ch++;
                if(ch > 'Z') ch = 'A';
            }
        }
        lk = strlen(key);
        for(int i=2;i<lk;i++){
            if(key[i] == 'R') rattle();
            else if(key[i] == 'S') shake();
            else loop();
        }
        for(int i=0;i<n;i++) printf("%s", mp[i]);
        puts("");
    }
    return 0;
}
