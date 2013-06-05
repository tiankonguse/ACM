#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
int str[2012][2012];
int mymap[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
struct Point{
    int x,y;
    Point(int _x,int _y):x(_x),y(_y){}
    Point(){}
}now,tmp,from,to;
queue<Point>que;

bool getto(Point& tmp){
    return to.x == tmp.x && to.y == tmp.y;
}

int bfs(){
    while(!que.empty())que.pop();
    if(getto(from))return 0;
    str[from.x][from.y] = 1;
    que.push(from);
    int i;
    while(!que.empty()){
        now = que.front();que.pop();
        for(i=0;i<4;i++){
            tmp.x = now.x + mymap[i][0];
            tmp.y = now.y + mymap[i][1];
            if(getto(tmp))return str[now.x][now.y];
            if(str[tmp.x][tmp.y] != 0)continue;
            str[tmp.x][tmp.y] = str[now.x][now.y] + 1;
            que.push(tmp);
        }
    }
    return -1;
}

int main(){
    int n,m;
    int x,y;
    int i,j;
    int ans;
    while(~scanf("%d%d",&n,&m)){
        memset(str,1,sizeof(str));

        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                scanf("%d",&str[i][j]);
            }
        }
        scanf("%d%d%d%d",&from.x,&from.y,&to.x,&to.y);
        if(str[from.x][from.y] || str[to.x][to.y]){
            printf("No Answer!\n");
        }else{
            ans = bfs();
            if(ans == -1){
                printf("No Answer!\n");
            }else{
                printf("%d\n",ans);
            }

            printf("");
        }
    }

    return 0;
}
