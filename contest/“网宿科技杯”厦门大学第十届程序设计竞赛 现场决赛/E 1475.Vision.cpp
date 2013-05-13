/*************************************************************************
    > File Name: 1475.Vision.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/12 16:34:08
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<map>
#include<cmath>
#include<queue>
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
double getBottom(double x1, double y1, double x2, double y2){
    return (x1*y2-y1*x2)/(x1-x2);
}

bool isGreate(double val){
    return val >= esp;
}

int find(double val,int left,int right){
    int mid;
    while(left <=right){
        mid = (left+right)>>1;
        if(isGreate(val-bottom[mid])){
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }

    if(right == n){
        return n;
    }
    if(right == -1){
        if(fabs(val - bottom[0]) <= esp){
            return 1;
        }else{
            return 0;
        }
    }

    return right + 1;
}

int main() {
    int m,i;
    double max_height;
    int pos;
    while(~scanf("%d",&n)){
        max_height = -100;
        pos = 0;
        for(i=0;i<n;i++){
            scanf("%lf",&height[i]);
        }


        for(i=0;i<n;i++){
            bottom[i] = getBottom(pos*1.0,max_height*1.0,(i+1)*1.0,height[i]*1.0);
            if(isGreate(height[i] - max_height )){
                max_height = height[i];
                pos = i+1;
            }
        }

        sort(bottom,bottom+n);

        scanf("%d",&m);
        for(i=0;i<m;i++){
            scanf("%lf",&q_height);
            printf("%d\n",find(q_height,0,n-1));
        }




    }

    return 0;
}
