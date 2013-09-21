/*************************************************************************
    > File Name: L.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/4/30 14:34:38
 ************************************************************************/

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

struct Point {
    int x,y;
    int pos;
    void init(int x,int y,int pos){
        this->x=x;
        this->y = y;
        this->pos = pos;
    }
}p[4];
bool esp(double a){
    return a <= 1e-6 && a >= -1e-6;
}



int main() {

    double xl,yl,xr,yr,a,b,c,htop,hbottom,wleft,wright;
    int cas;
    scanf("%d",&cas);
    while(cas--){
        scanf("%lf%lf%lf%lf%lf%lf%lf",&xl,&yl,&xr,&yr,&a,&b,&c);
        double sum = (yr-yl)*(xr-xl),s1,s2;
        if(esp(a)){
            s1 = (yr - (-c*1.0/b))*(xr-xl);
            s2 = sum -s1;

            printf("%.3f\n",min(s1,s2));
            continue;
        }

        if(esp(b)){
            s1 = (xr - (-c*1.0/a))*(yr-yl);
            s2 = sum -s1;

            printf("%.3f\n",min(s1,s2));
            continue;
        }


        int now = 0;

        double xx,yy;

        yy = (-c - a*xl)/b;

        if(yy >= yl && yy <= yr){
            p[now++].init(xl,yy,1);
        }

        xx = (-c - b*yl)/a;

        if(xx >= xl && xx <= xr){
            p[now++].init(xx,yl,2);
            if(now == 2){
                if(esp(p[0].x-p[1].x) && esp(p[0].y-p[1].y))now--;
            }
        }

        if(now != 2){
            yy = (-c - a*xr)/b;

            if(yy >= yl && yy <= yr){
                p[now++].init(xr,yy,3);
                if(now == 2){
                    if(esp(p[0].x-p[1].x) && esp(p[0].y-p[1].y))now--;
                }
            }

            if(now != 2){
                xx = (-c - b*yr)/a;

                if(xx >= xl && xx<= xr){
                    p[now++].init(xx,yr,4);
                    if(now == 2){
                        if(esp(p[0].x-p[1].x) && esp(p[0].y-p[1].y))now--;
                    }
                }
            }
        }



        if(p[0].pos == 1){
            if(p[1].pos == 2){
                printf("%.3f\n",(p[0].y - yl)*(p[1].x-xl)/2);
            }else if(p[1].pos == 3){
                s1 = (p[0].y - yl + p[1].y - yl)*(xr-xl)/2;
                s2 = sum - s1;
                printf("%.3f\n",min(s1,s2));
            }else{
                printf("%.3f\n",(yr-p[0].y) *(p[1].x - xl)/2);
            }
        }else if(p[0].pos == 2){
            if(p[1].pos == 3){
                printf("%.3f\n",(xr-p[0].x)*(p[1].y-yl)/2);
            }else{
                s1 = (xr - p[0].x + xr - p[1].x)*(yr-yl)/2;
                s2 = sum - s1;
                printf("%.3f\n",min(s1,s2));
            }
        }else{
            printf("%.3f\n",(xr-p[0].y)*(xr-p[1].x)/2);
        }




    }


    return 0;
}
