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
#include<stdarg.h>
using namespace std;
typedef long long LL;
const int N = 510;

struct T {
    int x0,y0;
    int dir;
    int preDir;
    T() {}
} sta[260000];

int staSize = 0;
int now;
const int x[]= {1,-1,0,0},y[]= {0,0,1,-1};
char dir[] = {'D','U','R','L'};
int str[N][N];
bool pass[N][N];
char ans[3000010];
int size;
int sum;
int n;

inline void push(int x0,int y0,int dir, int preDir){
    sta[staSize].x0 = x0;
    sta[staSize].y0 = y0;
    sta[staSize].dir = dir;
    sta[staSize++].preDir = preDir;
}

inline bool haveLightOn(int x0,int y0,int dir) {
    while(1) {
        x0 += x[dir],y0 += y[dir];
        if (x0 == -1 || y0 == -1 || x0 == n || y0 == n || pass[x0][y0]) {
            return false;
        }
        if (str[x0][y0]) {
            return true;
        }
    }
}

void dfs(int x0,int y0) {

    staSize = 0;
    push(x0,y0,-1,-1);
    while(staSize) {
        now = staSize - 1;

        if(sta[now].dir == -1) {
            pass[sta[now].x0][sta[now].y0] = true;
            if(!str[sta[now].x0][sta[now].y0]) {
                ans[size++] = '1';
                sum++;
            }
        }

        sta[now].dir++;
        while(sta[now].dir < 4) {
            if(haveLightOn(sta[now].x0, sta[now].y0, sta[now].dir)) {
                ans[size++] = dir[sta[now].dir];
                push(sta[now].x0 + x[sta[now].dir], sta[now].y0 + y[sta[now].dir], -1, sta[now].dir);
                break;
            }
            sta[now].dir++;
        }

        if(sta[now].dir == 4) {
            ans[size++] = '2';
            sum--;
            if(sta[now].preDir != -1) {
                ans[size++] = dir[sta[now].preDir^1];
            }
            staSize--;
        }
    }

}

int main() {
    int x0,y0,i,j;
    while(~scanf("%d%d%d",&n,&x0,&y0)) {
        sum = 0;
        size = 0;
        for(i=0; i<n; i++) {
            for(j=0; j<n; j++) {
                scanf("%d",&str[i][j]);
                pass[i][j] = false;
                sum += str[i][j];
            }
        }
        x0--,y0--;
        dfs(x0, y0);
        if(sum) {
            puts("NO");
        } else {
            ans[size++]='\0';
            puts("YES");
            puts(ans);
        }

    }



    return 0;
}

