#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<string>
#include<queue>
#include<cmath>
#include<stack>
#include<algorithm>
#include<functional>
#include<stdarg.h>
using namespace std;
#ifdef __int64
typedef __int64 LL;
#else
typedef long long LL;
#endif
const int maxn = 555;
const int numDIr = 4;
const int range  = 1;
const int cardbox = 3;
enum {EMPTY,WALL,CAMERA};
enum {N,E,S,W};
const int mapDir[4][2]= {{-1,0},{0,1},{1,0},{0,-1}};
const int isSee[4] = {S,W,N,E};

int n;
char input[maxn][maxn];
int charDir[255];



void initCharDir() {
    charDir['N'] = N;
    charDir['E'] = E;
    charDir['S'] = S;
    charDir['W'] = W;
}
/*
* type: 代表什么物体
*   空地:0
*   墙:1
*   炮:2
* dir:代炮的方向
*   北:0
*   东:1
*   南:2
*   西:3
*/
struct Map {
    char type;
    char dir;
    void init(char type=WALL, char dir=N) {
        this->type=type;
        this->dir=dir;
    }
} mymap[maxn][maxn];

bool isVisit[maxn][maxn][2];

struct Point {
    int x,y,t;
    bool isCarame;
    void init(int x,int y,int t=0) {
        this->x=x;
        this->y=y;
        this->t=t;
        isCarame = false;
    }
    bool operator<(const Point &t2)const {
        return this->t > t2.t;
    }
    bool eq(Point p) {
        return x==p.x && y==p.y;
    }
} from,to;

priority_queue<Point> que;

int ans;

/*
初始化数据
*/
void init() {
    for(int i=0; i<=n+range+1; i++) {
        for(int j=0; j<=n+range+1; j++) {
            input[i][j] = '#';
            mymap[i][j].init();
            isVisit[i][j][0] = isVisit[i][j][1] = false;
        }
    }
}

/*
输入数据
*/
void read() {
    for(int i=range; i<n+range; i++) {
        scanf("%s",input[i]+range);
        input[i][n+range] = '#';
    }
}

/*
由输入的数据得到地图
*/
void getMap() {
    for(int i=range; i<n+range; i++) {
        for(int j=range; j<n+range; j++) {
            switch(input[i][j]) {
            case '.':
                mymap[i][j].init(EMPTY);
                break;
            case '#':
                mymap[i][j].init(WALL);
                break;
            case 'M':
                mymap[i][j].init(EMPTY,N);
                from.init(i,j);
                break;
            case 'T':
                mymap[i][j].init(EMPTY);
                to.init(i,j);
                break;
            default:
                mymap[i][j].init(CAMERA, charDir[input[i][j]]);
                break;
            }
        }
    }
}

/*
测试输出地图
*/
void printMap() {
    for(int i=0; i<=n+range+1; i++) {
        for(int j=0; j<=n+range+1; j++) {
            printf("%d ",mymap[i][j].type);
        }
        printf("\n");
    }
}

/*
判断是不是有答案
*/
bool haveAns() {
    while(!que.empty()) {
        que.pop();
    }
    que.push(from);
    Point now,next;
    int x,y;
    while(!que.empty()) {
        now = que.top();
        que.pop();

        for(int i=0; i<numDIr; i++) {
            x = now.x+mapDir[i][0];
            y = now.y+mapDir[i][1];
            next.init(x,y);
            if(next.eq(to)) {
                return true;
            }
            if(mymap[x][y].type != WALL && !isVisit[x][y][1]) {
                isVisit[x][y][1] = true;
                que.push(next);
            }
        }
    }
    return false;
}

/*
由于测试是否有答案时，修改了一些数据，现在恢复那些数据。
*/
void initMapTime() {
    for(int i=0; i<=n+range+1; i++) {
        for(int j=0; j<=n+range+1; j++) {
            isVisit[i][j][1] = false;
        }
    }
}

/*
检查某个时间的点是否在监控下
*/
bool checkInCarame(const Point& now) {
    int x0,y0,x1,y1,x2,y2,dir,t;
    t = now.t%4;
    x0 = now.x;
    y0=now.y;

    if(mymap[x0][y0].type == CAMERA) {
        return true;
    }

    for(int i=0; i<numDIr; i++) {
        x1 = now.x+mapDir[i][0];
        y1 = now.y+mapDir[i][1];

        if(mymap[x1][y1].type == CAMERA) {
            dir = (mymap[x1][y1].dir + t)%4;
            if(isSee[i] == dir) {
                return true;
            }
        }

// 坑爹呀，一些range为2，所以第二格也判断了
//        x2 = now.x+mapDir[i][0]*2;
//        y2 = now.y+mapDir[i][1]*2;
//
//        if(mymap[x2][y2].type == CAMERA && mymap[x1][y1].type != WALL) {
//            dir = (mymap[x2][y2].dir + t)%4;
//            if(isSee[i] == dir) {
//                return true;
//            }
//        }
    }

    return false;
}

/*
得到答案
*/
int getAns() {
    Point now,next,stayNow;
    int x,y,t;
    while(!que.empty()) {
        que.pop();
    }
    que.push(from);

    while(!que.empty()) {
        now = que.top();
        que.pop();
        x = now.x;
        y = now.y;
        now.isCarame = checkInCarame(now);
        if(isVisit[x][y][now.isCarame])continue;
        isVisit[x][y][now.isCarame] = true;

        if(now.eq(to)) {
            return now.t;
        }

        for(int i=0; i<numDIr; i++) {

            x = now.x+mapDir[i][0];
            y = now.y+mapDir[i][1];

            if(mymap[x][y].type != WALL) {

                next.init(x,y,now.t);
                next.isCarame = checkInCarame(next);
                next.t = now.t + 1;
                if(!now.isCarame && !next.isCarame) {
                    que.push(next);
                    continue;
                }

                next.init(x,y,now.t + cardbox);
                que.push(next);

                stayNow = now;
                stayNow.t++;
                stayNow.isCarame = checkInCarame(stayNow);

                next.init(x,y,stayNow.t);
                next.isCarame = checkInCarame(next);
                next.t = stayNow.t + 1;
                if(!stayNow.isCarame && !next.isCarame) {
                    que.push(next);
                }
            }
        }
    }

    return 0;
}

int main() {
    int t;
    initCharDir();

    scanf("%d",&t);
    for(int ca=1; ca<=t; ca++) {
        scanf("%d",&n);
        init();
        read();
        getMap();

        if(haveAns()) {
            initMapTime();
            printf("Case #%d: %d\n",ca,getAns());
        } else {
            printf("Case #%d: -1\n",ca);
        }


    }

    return 0;
}
