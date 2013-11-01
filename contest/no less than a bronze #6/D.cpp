#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<cmath>
#include<stack>
#include<algorithm>
#include<functional>
using namespace std;
typedef long long LL;

char board[15][15];
char const wall = '#';
char const road = '.';
int ans;
map<int,int>m;
queue<int>que;
int pointx[4];
int pointy[4];
int _pointx[4];
int _pointy[4];
int pos[4];

void init() {
    m.clear();
    while(!que.empty()) {
        que.pop();
    }
    ans = 0;
}


void getTop() {
    bool have[4];
    memset(have, true,sizeof(have));
    int xmin,val;
    for(int i=0; i<4; i++) {
        val = 100;
        for(int j=0; j<4; j++) {
            if(have[j] && pointx[j] <  val) {
                xmin = j;
                val = pointx[j];
            }
        }
        pos[i] = xmin;
        have[xmin] = false;
    }
}

void getBottom() {
    bool have[4];
    memset(have, true,sizeof(have));
    int xmax,val;
    for(int i=0; i<4; i++) {
        val = -100;
        for(int j=0; j<4; j++) {
            if(have[j] && pointx[j] >  val) {
                xmax = j;
                val = pointx[j];
            }
        }
        pos[i] = xmax;
        have[xmax] = false;
    }
}

void getLeft() {
    bool have[4];
    memset(have, true,sizeof(have));
    int ymin,val;
    for(int i=0; i<4; i++) {
        val = 100;
        for(int j=0; j<4; j++) {
            if(have[j] && pointy[j] <  val) {
                ymin = j;
                val = pointy[j];
            }
        }
        pos[i] = ymin;
        have[ymin] = false;
    }
}

void getRight() {
    bool have[4];
    memset(have, true,sizeof(have));
    int ymax,val;
    for(int i=0; i<4; i++) {
        val = -100;
        for(int j=0; j<4; j++) {
            if(have[j] && pointy[j] >  val) {
                ymax = j;
                val = pointy[j];
            }
        }
        pos[i] = ymax;
        have[ymax] = false;
    }
}

void unpush(int now) {
    int x,y;
    for(int i=0; i<4; i++) {
        y = (now & 7)+1;
        now >>= 3;
        x = (now & 7)+1;
        now >>= 3;
        board[x][y] = board[x + 1][y] = board[x][y + 1] = board[x + 1][y + 1] = road;
    }
}

int main(int argc, char* argv[]) {

    int cas,i,j,k,x,y;
    int tmp , now;
    char oldboard[15][15];
    scanf("%d",&cas);

    memset(board, wall, sizeof(board));
    memset(oldboard, wall, sizeof(oldboard));
    for(int ca = 1; ca <= cas; ca++ ) {
        init();
        for(i=1; i<=8; i++) {
            scanf("%s",oldboard[i]+1);
            oldboard[i][9] = wall;
        }
        tmp = 0;
        for(i = 1; i <= 8; i++) {
            for(j = 1; j <= 8; j++) {
                if(oldboard[i][j] <= 'D' && oldboard[i][j] >= 'A') {
                    tmp = tmp<<3 | (i-1);
                    tmp = tmp<<3 | (j-1);
                    oldboard[i][j] = oldboard[i + 1][j] = oldboard[i][j + 1] = oldboard[i + 1][j + 1] = road;
                }
                board[i][j] = oldboard[i][j];
//                printf("%c",board[i][j]);
            }
//            puts("");
        }
        ans = 1;
        m[tmp] = 1;
        que.push(tmp);
//        printf("now=%d\n",tmp);

        while(!que.empty()) {
            now = que.front();
//            printf("--now=%d\n",now);

            que.pop();
            for(i=3; i>=0; i--) {
                pointy[i] = (now & 7)+1;
                now >>= 3;
                pointx[i] = (now & 7)+1;
                now >>= 3;
            }

            getTop();
            now = 0;
            for(i = 0; i<4; i++) {
                int nowI = pos[i];
                y = pointy[nowI];
                for(x = pointx[nowI] - 1; x >= 1; x--) {
                    if(board[x][y] == wall || board[x][y + 1] == wall) {
                        break;
                    }
                }
                x++;
                _pointx[nowI] = x;
                _pointy[nowI] = y;
                board[x][y] = board[x + 1][y] = board[x][y + 1] = board[x + 1][y + 1] = wall;
            }
            for(i=0; i<4; i++) {
                now = now <<3 | (_pointx[i] - 1);
                now = now <<3 | (_pointy[i] - 1);
            }
//            printf("now=%d\n",now);
            if(m[now] == 0) {
                ans++;
                que.push(now);
                m[now] = 1;
            }
            unpush(now);

            getBottom();
            now = 0;
            for(i = 0; i<4; i++) {
                int nowI = pos[i];
                y = pointy[nowI];
                for(x = pointx[nowI] + 1; x < 8; x++) {
                    if(board[x+1][y] == wall || board[x+1][y + 1] == wall) {
                        break;
                    }
                }
                x--;
                _pointx[nowI] = x;
                _pointy[nowI] = y;
                board[x][y] = board[x + 1][y] = board[x][y + 1] = board[x + 1][y + 1] = wall;
            }
            for(i=0; i<4; i++) {
                now = now <<3 | (_pointx[i] - 1);
                now = now <<3 | (_pointy[i] - 1);
            }
//            printf("now=%d\n",now);
            if(m[now] == 0) {
                ans++;
                que.push(now);
                m[now] = 1;
            }
            unpush(now);

            getLeft();
            now = 0;
            for(i = 0; i<4; i++) {
                int nowI = pos[i];
                x = pointx[nowI];
                for(y = pointy[nowI] - 1; y >= 1; y--) {
                    if(board[x][y] == wall || board[x+ 1][y] == wall) {
                        break;
                    }
                }
                y++;
                _pointx[nowI] = x;
                _pointy[nowI] = y;
                board[x][y] = board[x + 1][y] = board[x][y + 1] = board[x + 1][y + 1] = wall;
            }
            for(i=0; i<4; i++) {
                now = now <<3 | (_pointx[i] - 1);
                now = now <<3 | (_pointy[i] - 1);
            }
//            printf("now=%d\n",now);
            if(m[now] == 0) {
                ans++;
                que.push(now);
                m[now] = 1;
            }
            unpush(now);

            getRight();
            now = 0;
            for(i = 0; i<4; i++) {
                int nowI = pos[i];
                x = pointx[nowI];
                for(y = pointy[nowI] + 1; y < 8; y++) {
                    if(board[x][y+1] == wall || board[x+ 1][y+1] == wall) {
                        break;
                    }
                }
                y--;
                _pointx[nowI] = x;
                _pointy[nowI] = y;
                board[x][y] = board[x + 1][y] = board[x][y + 1] = board[x + 1][y + 1] = wall;
            }
            for(i=0; i<4; i++) {
                now = now <<3 | (_pointx[i] - 1);
                now = now <<3 | (_pointy[i] - 1);
            }
//            printf("now=%d\n",now);
            if(m[now] == 0) {
                ans++;
                que.push(now);
                m[now] = 1;
            }
            unpush(now);
//            puts("");
//            getchar();
        }

        printf("Case %d: %d\n",ca,ans);

    }


    return 0;
}






