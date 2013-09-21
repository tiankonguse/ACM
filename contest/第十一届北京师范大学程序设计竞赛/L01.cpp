#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<functional>
#include<algorithm>
using namespace std;

const double esp = 1e-6;

struct Point {
    double x,y;
    int pos;
    void init(double x,double y,int pos){
        this->x=x;
        this->y = y;
        this->pos = pos;
    }
}p[4];

double sum;
int now;

void myprint(double s){
    printf("%.3f\n",min(s,sum-s));
}

bool isZero(double s){
    return s<=esp && s>=-esp;
}

void insert(double x,double y,int pos){
    p[now++].init(x,y,pos);
    if(now == 2){
        if(isZero(p[0].x-p[1].x) && isZero(p[0].y-p[1].y))now--;
    }
}

int main() {
    double left,bottom,right,top,a,b,c,htop,hbottom,wleft,wright;
    int cas;
    scanf("%d",&cas);
    while(cas--){
        scanf("%lf%lf%lf%lf%lf%lf%lf",&left,&bottom,&right,&top,&a,&b,&c);

        sum = (top-bottom)*(right-left);

        if(isZero(a)){
            myprint((-c/b - bottom)*(right-left));
            continue;
        }

        if(isZero(b)){
            myprint((-c/a - left)*(top-bottom));
            continue;
        }

        now = 0;
        double xx,yy;

        //判断是否和left相交
        yy = (-c - a*left)/b;
        if(yy >= bottom && yy <= top){
            insert(left,yy,1);
        }


        //判断是否和bottom相交
        xx = (-c - b*bottom)/a;
        if(xx >= left && xx <= right){
            insert(xx,bottom,2);
        }

        //判断是否和right相交
        yy = (-c - a*right)/b;
        if(yy >= bottom && yy <= top){
            insert(right,yy,3);
        }

        //判断是否和 top 相交
        xx = (-c - b*top)/a;
        if(xx >= left && xx<= right){
            insert(xx,top,4);
        }


        if(p[0].pos == 1){
            if(p[1].pos == 2){
                myprint((p[0].y - bottom)*(p[1].x-left)/2);
            }else if(p[1].pos == 3){
                myprint((p[0].y - bottom + p[1].y - bottom)*(right-left)/2);
            }else{
                myprint((top-p[0].y) *(p[1].x - left)/2);
            }
        }else if(p[0].pos == 2){
            if(p[1].pos == 3){
                myprint((right-p[0].x)*(p[1].y-bottom)/2);
            }else{
                myprint((right - p[0].x + right - p[1].x)*(top-bottom)/2);
            }
        }else{
            myprint((right-p[1].x)*(top-p[0].y)/2);
        }
    }
    return 0;
}
