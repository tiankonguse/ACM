#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<ctime>
#include<stack>
#include<queue>
#include<vector>
#include<cstdlib>
#include<algorithm>
#define PI acos(-1.0)
#define inf 0x3fffffff
#define maxn 110010
using namespace std;
struct Point
{
    double x,y;
    Point(double x=0,double y=0):x(x),y(y){}
};
Point ans[maxn*4],c[maxn*4];
typedef Point Vector;
Vector operator +(Vector A,Vector B)
{
    return Point(A.x+B.x,A.y+B.y);
}
Vector operator -(Vector A,Vector B)
{
    return Point(A.x-B.x,A.y-B.y);
}
Vector operator*(Vector A,double p)
{
    return Point(A.x*p,A.y*p);
}
Vector operator/(Vector A,double p)
{
    return Point(A.x/p,A.y/p);
}
const double eps = 1e-10;
int dcmp(double x)
{
    if(fabs(x)<eps)return 0;
    return x<0?-1:1;
}
bool operator <(const Point &a,const Point &b)
{
   return a.x<b.x||(a.x==b.x&&a.y<b.y);
}
bool operator ==(const Point &a,const Point&b)
{
    return dcmp(a.x-b.x)==0&&dcmp(a.y-b.y)==0;
}
double Cross(Vector A,Vector B)
{
    return A.x*B.y-A.y*B.x;
}
int convexhull(Point *p,int n,Point *ch)
{
    sort(p,p+n);
    int m=0;
    for(int i=0;i<n;i++)
    {
        while(m>1&&Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2])<=0)m--;
        ch[m++]=p[i];
    }
    int k=m;
    for(int i=n-2;i>=0;i--)
    {
        while(m>k&&Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2])<=0)m--;
        ch[m++]=p[i];
    }
    if(n>1)m--;
    return m;
}
double Max(double a,double b)
{
    if(a>b)return a;
    return b;
}
int main()
{
    int i,j,n;
    double a,b;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
        {
            scanf("%lf%lf",&a,&b);
            ans[i*4+0].x=a-1;
            ans[i*4+0].y=b;

            ans[i*4+1].x=a+1;
            ans[i*4+1].y=b;

            ans[i*4+2].x=a;
            ans[i*4+2].y=b-1;

            ans[i*4+3].x=a;
            ans[i*4+3].y=b+1;
        }
        n=n*4;
        int m = convexhull(ans,n,c);
        double sum=0;
        c[m]=c[0];
        for(i=0;i<m;i++)
        {
            double d1 = fabs(c[i].x-c[i+1].x);
            double d2 = fabs(c[i].y-c[i+1].y);
            sum += Max(d1,d2);

        }
        cout<<(int)sum<<endl;
    }
}



/*
1
100 100

5
0 0
0 2
2 2
2 0
1 1

2
0 0
1 1

2
-3 -4
7 11

2
0 0
0 1

4
0 0
1 1
2 2
2 2

2
1 1
1 1
*/
