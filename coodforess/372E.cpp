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
#ifdef __int64
typedef __int64 LL;
#else
typedef long long LL;
#endif
const int mod = 1000000007;

bool isZero(double o){
	return fabs(o) < 1e-8;
}



struct Point {
    double x,y;
    void input() {
        double a,b,c,d,l;
        //得到 x,y两点
        scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
        x = a/b;
        y = c/d;
        //进行反演
        l = x*x+y*y;
        x = x/l;
        y = y/l;
    }
    //初始化点
    Point(double x=0,double y=0):x(x),y(y) {}

    //定义<运算符，在map里需要使用
    bool operator<(Point const& o)const {
        if(isZero(o.x - x)) {
            return o.y < y;
        } else {
            return o.x < x;
        }
    }
    //定于==运算符，用于判断时候是一个中点。
    bool operator == (Point const&o)const {
        return isZero(x -o.x) && isZero(y - o.y);
    }

    Point operator +(Point const&o)const {
        return Point(x+o.x, y+o.y);
    }
    Point operator -(Point const&o)const {
        return Point(x-o.x, y-o.y);
    }
    Point operator /(double o)const {
        return Point(x/o, y/o);
    }

    //单位化一个向量，用于判断是否共线
    Point init() {
        double _x = x, _y = y;
        double l = sqrt(_x*_x + _y*_y);
        if(_x < 0) {
            _x = -_x;
            _y = -_y;
        }
        return Point(_x/l, _y/l);
    }
    void output(){
		printf("%lf %lf\n",x,y);
    }
} point[1111];


struct Pair {
    Point mid;
    Point vec;
    Pair(Point mid, Point vec):mid(mid),vec(vec) {}
    bool operator<(Pair const& o)const {
        if(o.mid == mid) {
            return o.vec < vec;
        } else {
            return o.mid < mid;
        }
    }
};

map<Pair, int>m;
map<Pair, int>::iterator mi,mj;
Pair makePair(Point & a, Point& b) {
    return Pair((a+b)/2, (a-b).init());
}

int main() {
    int n,i,j;
    LL ans,sum,cnt;
    while(~scanf("%d",&n)) {
        m.clear();
        for(i=0; i<n; i++) {
            point[i].input();
        }
        sort(point,point+n);
        for(i=0; i<n; i++) {
            for(j=i+1; j<n; j++) {
                m[makePair(point[i],point[j])]++;
            }
        }
        ans=0;
        for (mi=m.begin(); mi!=m.end(); mi = mj) {
            sum = 1, cnt = 0;
            for(mj= mi; mj!= m.end() && mi->first.mid == mj->first.mid; mj++) {
                sum= sum*(mj->second+1)%mod;
                cnt=(cnt+mj->second)%mod;
            }
            ans=(ans+sum-cnt-1)%mod;
        }
        printf("%lld\n",(ans+mod)%mod);


    }


    return 0;
}
