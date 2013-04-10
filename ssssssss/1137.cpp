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

bool getto(int x,int y){
    return to.x == x && to.y == y;
}

int main(){
    int n,m;
    int x,y;
    int i,j;
    while(~scanf("%d%d",&n,&m)){
        memset(str,1,sizeof(str));

        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                scanf("%d",&str[i][j]);

                if(str[i][j])str[i][j]=-1;
                else str[i][j]=-2;
            }
        }
        scanf("%d%d%d%d",&from.x,&from.y,&to.x,&to.y);
        if(str[from.x][from.y] || str[to.x][to.y]){
            printf("No Answer!\n");
        }else{
            if(!getto(from.x,from.y)){
                while(!que.empty())que.pop();
                str[from.x][from.y]=0;
                que.push(from);
                while(!que.empty()){
                    from = que.front();que.pop();
                    for(i=0;i<4;i++){
                        x = from.x+mymap[i][0];
                        y = from.y+mymap[i][1];
                        //Ô½½ç
                        if(x<1 || x>n || y<1 || y>m)continue;
                        //Ç½
                        if(str[x][y] != -2)continue;
                        str[x][y]=str[from.x][from.y]+1;
                        tmp.x=x;
                        tmp.y=y;

                        if(getto(from.x,from.y))break;
                        else que.push(tmp);

                    }
                    if(getto(from.x,from.y))break;
                }
            }
            if(str[to.x][to.y]!= -2){
                printf("%d\n",str[to.x][to.y]);
            }else{
                printf("No Answer!\n");
            }
        }
    }

    return 0;
}
