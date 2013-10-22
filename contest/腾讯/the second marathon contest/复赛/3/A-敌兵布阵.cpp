#include<stdio.h>
#include<queue>
#define MAX 51
#include<string.h>
using namespace std;
struct Point {
    int x,y,z;
};
typedef struct Point point;

point start,p,s,t;

int squre,line,every,timee,T;

int map[MAX][MAX][MAX],step[MAX][MAX][MAX];

int xx[6][3]= {{1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1}};

queue<Point>que;

void deal(point p) {
    int i;
    que.push(p);
    step[p.x][p.y][p.z]=0;
    while(!que.empty()) {

        s=que.front();que.pop();
        printf("%d %d %d\n",s.x,s.y,s.z);
        for(i=0; i<6; i++) {
            t.x=s.x+xx[i][0];
            t.y=s.y+xx[i][1];
            t.z=s.z+xx[i][2];
            if(t.x>=0 && t.x<squre && t.y>=0 && t.y<line && t.z>=0 && t.z<every) {
                if(map[t.x][t.y][t.z]==0 && step[t.x][t.y][t.z] == -1) {
                    que.push(t);
                    step[t.x][t.y][t.z] = step[s.x][s.y][s.z] + 1;
                    if(t.x +1 == squre && t.y+1==line && t.z+1==every)return;
                }
            }
        }

    }
}

int main() {
    int i,j,k,m,temp;
    scanf("%d",&T);
    for(i=0; i<T; i++) {
        while(!que.empty())que.pop();
        memset(step,-1,sizeof(step));
        scanf("%d %d %d %d",&squre,&line,&every,&timee);
        for(j=0; j<squre; j++) {
            for(k=0; k<line; k++) {
                for(m=0; m<every; m++) {
                    scanf("%d",&map[j][k][m]);
                }
            }
        }

        if(squre+line+every-3>timee) {
            printf("-1\n");
            continue;
        }

        if(map[squre-1][line-1][every-1]==1) {
            printf("-1\n");
            continue;
        }

        start.x=0;
        start.y=0;
        start.z=0;
        printf("begin\n");
        deal(start);
        printf("end\n");
        temp=step[squre-1][line-1][every-1];
        if(temp>=0&&temp<=timee) {
            printf("%d\n",temp);
        } else {
            printf("-1\n");
        }
    }
    return 0;
}
