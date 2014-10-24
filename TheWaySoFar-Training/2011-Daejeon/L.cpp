#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1005;
int cnt,x[maxn],y[maxn],mark;
char s[maxn];
void go1(){
    ++cnt;
    if(mark == 0){
            y[cnt] = y[cnt - 1] + 1;
            x[cnt] = x[cnt - 1];
    }
    if(mark == 1){
            x[cnt] = x[cnt - 1] - 1;
            y[cnt] = y[cnt - 1];
    }
    if(mark == 2){
            y[cnt] = y[cnt - 1] - 1;
            x[cnt] = x[cnt - 1];
    }
    if(mark == 3){
            x[cnt] = x[cnt - 1] + 1;
            y[cnt] = y[cnt - 1];
    }
}
void back1(){
    ++cnt;
    if(mark == 0){
            y[cnt] = y[cnt - 1] - 1;
            x[cnt] = x[cnt - 1];
    }
    if(mark == 1){
            x[cnt] = x[cnt - 1] + 1;
            y[cnt] = y[cnt - 1];
    }
    if(mark == 2){
            y[cnt] = y[cnt - 1] + 1;
            x[cnt] = x[cnt - 1];
    }
    if(mark == 3){
            x[cnt] = x[cnt - 1] - 1;
            y[cnt] = y[cnt - 1];
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
        cnt = 0;
        scanf("%s",s);
        mark = 0;
        int len = strlen(s);
        x[0] = 0; y[0] = 0;
        for(int i = 0; i < len; ++i){
            if(s[i] == 'F') go1();
            if(s[i] == 'B') back1();
            if(s[i] == 'L') mark = (mark + 1) % 4;
            if(s[i] == 'R') mark = (mark + 4 - 1) % 4;
        }
        int x1 = -1000,y1 = -1000,x2 = 1000,y2 = 1000;
        for(int i = 0; i <= cnt; ++i){
           //printf("%d %d\n",x[i],y[i]);
            x1 = max(x1,x[i]);
            x2 = min(x2,x[i]);
            y1 = max(y1,y[i]);
            y2 = min(y2,y[i]);
        }
        printf("%d\n",(x1 - x2) * (y1 - y2));
    }
    return 0;
}
