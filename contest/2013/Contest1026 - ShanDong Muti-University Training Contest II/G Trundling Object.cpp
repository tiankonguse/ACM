/*************************************************************************
    > File Name: Trundling Object.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/14 18:56:44
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<stack>
#include<functional>
#include<algorithm>
using namespace std;
struct T{
    int x,y,a,b,c;
    void init(int x,int y,int a,int b,int c){
        this->x = x;
        this->y = y;
        this->a = a;
        this->b = b;
        this->c = c;
    }
}now,tmp;
const char R = 'R';
const char B = 'B';
const char OTHER = '.';
const int XY = 200;
char map[800][800];
bool isVisited[800][800][10];
int a,b,c;
queue<T>que;

int getState(int aa,int bb,int cc){

    if(aa == a && bb == b && cc == c ){
        return 1;
    }
    if(aa == a && bb == c && cc == b){
        return 2;
    }
    if(aa == b && bb == a && cc == c){
        return 3;
    }
    if(aa == b && bb == c && cc == a){
        return 4;
    }
    if(aa == c && bb == a && cc == b){
        return 5;
    }
    if(aa == c && bb == b && cc == a){
        return 6;
    }

}

bool isPutDown(int x,int y,int aa,int bb){
    int right = y + aa;
    int down = x + bb;
    int i,j;
    for(i=x;i<down;i++){
        for(j=y;j<right;j++){
            if(map[i][j] == R)return false;
        }
    }
    return true;
}

int putDown(int x,int y,int aa,int bb){
    int sum = 0;
    int right = y + aa;
    int down = x + bb;
    int i,j;
    for(i=x;i<down;i++){
        for(j=y;j<right;j++){
            if(map[i][j] == B){
                map[i][j] = OTHER;
                sum++;
            }
        }
    }
    return sum;
}

void getTmp(int state){
    if(state == 1){
        tmp.init(now.x - now.c, now.y, now.a, now.c, now.b);
    }else if(state == 2){
        tmp.init(now.x + now.b, now.y, now.a, now.c, now.b);
    }else if(state ==3){
        tmp.init(now.x , now.y- now.c, now.c, now.b, now.a);
    }else{
        tmp.init(now.x , now.y+ now.a, now.c, now.b, now.a);
    }
}

int main() {

    int cas,n,m,i,j,ans;

    scanf("%d",&cas);
    while(cas--){
        scanf("%d%d%d",&b,&a,&c);
        scanf("%d%d",&n,&m);

        memset(map,R,sizeof(map));
        memset(isVisited,false,sizeof(isVisited));
        while(!que.empty())que.pop();

        ans = 0;

        for(i=XY;i<XY+n;i++){
            scanf("%s",map[i]+XY);
            map[i][XY+m] = R;
        }
        now.init(XY,XY,a,b,c);
        if(isPutDown(now.x, now.y, now.a, now.b)){
            ans += putDown(now.x, now.y, now.a, now.b);
            que.push(now);
            isVisited[now.x][now.y][getState(now.a, now.b, now.c)] = true;
            while(!que.empty()){
//                printf("---\n");
                now = que.front();que.pop();
//                printf("---x=%d y=%d a=%d b=%d c=%d\n",now.x,now.y,now.a,now.b,now.c);
                for(i=1;i<=4;i++){
                    getTmp(i);
                    if(!isVisited[tmp.x][tmp.y][getState(tmp.a, tmp.b, tmp.c)] && isPutDown(tmp.x, tmp.y, tmp.a, tmp.b)){
                        ans += putDown(tmp.x, tmp.y, tmp.a, tmp.b);
                        que.push(tmp);
                        isVisited[tmp.x][tmp.y][getState(tmp.a, tmp.b, tmp.c)] = true;
                    }
                }
            }
        }
        printf("%d\n",ans);

    }

    return 0;
}
