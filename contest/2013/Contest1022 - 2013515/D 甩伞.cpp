/*************************************************************************
    > File Name: D 甩伞.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/15 18:03:53
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<cmath>
#include<queue>
#include<stack>
#include<functional>
#include<algorithm>
using namespace std;
const double g = 9.8;
int main() {
    double r,h,w;
    while(cin>>r>>h>>w){
        printf("%.2f\n",sqrt((2*h*w*w+g)*r*r/g));
    }
    return 0;
}
