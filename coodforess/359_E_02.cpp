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

const int x[]= {1,-1,0,0},y[]= {0,0,1,-1};
char dir[] = {'D','U','R','L'};
int str[N][N];
bool pass[N][N];
char ans[3000010];
int size;
int sum;
int n;

inline bool haveLightOn(int x0,int y0,int dir) {
    for (;;) {
        x0 += x[dir],y0 += y[dir];
        if (x0 == -1 || y0 == -1 || x0 == n || y0 == n || pass[x0][y0]) {
            return false;
        }
        if (str[x0][y0]) {
            return true;
        }
    }
}
int MAXLEV = 240000;
int a,b;

void dfs(int x0,int y0,int lev) {
    int _str[100];
    if(!str[x0][y0]) {
        ans[size++] = '1';
        sum++;
    }
    if(lev >= MAXLEV){
        a = 0;
        b = 1/a;
    }
    _str[9] = a;
    pass[x0][y0] = true;
    for(int i=0; i<4; i++) {
        if(haveLightOn(x0,y0,i)) {
            ans[size++] = dir[i];
            dfs(x0 + x[i], y0 + y[i],1+lev);
            ans[size++] = dir[i^1];
        }
    }
    b = 90;
    for(int i=0;i<b;i++){

    }
    ans[size++] = '2';
    sum--;
}

int main() {
    a++;
    int x0,y0,i,j;
    while(~scanf("%d%d%d",&n,&x0,&y0)) {
        sum = 0;
        size = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                scanf("%d",&str[i][j]);
                pass[i][j] = false;
                sum += str[i][j];
            }
        }
        a--;
        x0--,y0--;
        dfs(x0, y0,0);
        if(sum){
            printf("NO\n");
        }else{
            ans[size++]='\0';
            printf("YES\n%s\n",ans);
        }

    }



    return 0;
}
