#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<cmath>
#include<stack>
#include<algorithm>
#include<functional>
#include<stdarg.h>
using namespace std;
typedef long long LL;

struct Point{
	double x,y;
	int input(){
		return scanf("%lf %lf",&x,&y);
	}
};

double dis(Point&a, Point&b){
	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

int main() {
	Point a,b;
	while(~a.input()){
		b.input();
		printf("%.2f\n",dis(a,b));
	}

    return 0;
}
