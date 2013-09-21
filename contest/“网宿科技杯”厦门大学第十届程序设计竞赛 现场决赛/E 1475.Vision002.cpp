/*************************************************************************
    > File Name: E 1475.Vision002.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/13 10:35:14
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<stack>
#include<functional>
#include<algorithm>
using namespace std;
const int N = 10000000;
const double esp = 1e-6;
double bottom[N];
double height[N];
double q_height;
int n;

struct Point{
    double x,y;
    Point(){}
    Point(double x, double y):x(x), y(y){}
    void init(double x, double y){this->x = x; this->y = y;}
}point_second_top, point_first_top, now_point;
stack<Point>sta;


double getBottom(double const &x1, double const &y1, double const &x2, double const &y2){
    return (x1*y2-y1*x2)/(x1-x2);
}

double getBottom(Point const &a, Point const &b){
    return getBottom(a.x, a.y, b.x, b.y);
}

bool isGreate(double val){
    return val >= -esp;
}

bool iseq(double val){
    return val >= -esp && val <= esp;
}


int find(double val,int left,int right){
    int mid;
    while(left <=right){
        mid = (left+right)>>1;
//        printf("--left=%d  mid=%d  right=%d\n",left,mid,right);
        if(isGreate(val-bottom[mid]) && !iseq(val-bottom[mid])){
//            printf(">>>>>>>=\n");
            left = mid + 1;
        }else{
//            printf("<<<<<<<<<<<<\n");
            right = mid - 1;
        }
    }

    return right + 1;
}

bool shouldPop(Point const& second, Point const& first, Point const& now){
    return  isGreate((now.y - first.y)*(now.x - second.x) - (now.y - second.y) * (now.x - first.x));
}

int main() {
    int m,i,size;
    double now_height;
    int pos;
    while(~scanf("%d",&n)){

        while(!sta.empty()){
            sta.pop();
        }

        for(i=0;i<n;i++){
            scanf("%lf",&now_height);
            now_point.init(i + 1, now_height);
            size = sta.size();
            if(size == 0){
                bottom[i] = -1;
                sta.push(now_point);
            }else if(size == 1){
                point_first_top = sta.top();
//                printf("-----%d %lf %lf %lf\n",i+1,now_height,point_first_top.x,point_first_top.y);
                sta.push(now_point);
                bottom[i] = getBottom(point_first_top, now_point);
            }else{
                point_first_top = sta.top();sta.pop();
//                printf("-----%d %lf %lf %lf\n",i+1,now_height,point_first_top.x,point_first_top.y);
                point_second_top = sta.top();

                while(shouldPop(point_second_top, point_first_top, now_point)){
                    point_first_top = sta.top();sta.pop();
//                    printf("-----%d %lf %lf %lf\n",i+1,now_height,point_first_top.x,point_first_top.y);

                    if(sta.empty()){
                        break;
                    }else{
                        point_second_top = sta.top();
                    }
                }
                sta.push(point_first_top);
//                printf("top-----%d %lf %lf %lf\n",i+1,now_height,point_first_top.x,point_first_top.y);
                sta.push(now_point);
                bottom[i] = getBottom(point_first_top, now_point);
            }
        }
        bottom[n++] = 1000000010;
        sort(bottom,bottom+n);
//
//        printf("---%d \n",n);
//        for(i=0;i<n;i++){
//            printf("--%d  %lf\n",i,bottom[i]);
//        }

        scanf("%d",&m);
        for(i=0;i<m;i++){
            scanf("%lf",&q_height);
            printf("%d\n",find(q_height,0,n-1));
        }




    }

    return 0;
}
