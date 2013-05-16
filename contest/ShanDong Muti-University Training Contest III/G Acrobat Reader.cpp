/*************************************************************************
    > File Name: G Acrobat Reader.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/16 18:59:42
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<cmath>
#include<functional>
#include<algorithm>
using namespace std;
struct Point
{
    double x,y;
    Point(double x=0,double y=0):x(x),y(y){}
}s[422],start,end,tmp;
typedef Point Vector;
vector<int>gra[422];
Vector operator + (Vector A,Vector B)
{
    return Vector(A.x+B.x,A.y+B.y);
}
Vector operator - (Vector A,Vector B)
{
    return Vector(A.x-B.x,A.y-B.y);
}
Vector operator *(Vector A,double p)
{
    return Vector(A.x*p,A.y*p);
}
Vector operator /(Vector A,double p)
{
    return Vector(A.x/p,A.y/p);
}
bool operator < (const Point &a,const Point &b)
{
    return a.x<b.x||(a.x==b.x&&a.y<b.y);
}
const double eps = 1e-10;
int dcmp(double x)
{
    if(fabs(x)<eps)return 0;
    else return x<0?-1:1;
}
bool operator == (const Point &a,const Point &b)
{
    return dcmp(a.x-b.x)==0&&dcmp(a.y-b.y)==0;
}
double Cross(Vector A,Vector B)
{
    return A.x*B.y-A.y*B.x;
}
bool SegmentIntersection(Point a1,Point a2,Point b1,Point b2)
{
    double c1 = Cross(a2-a1,b1-a1),c2 = Cross(a2-a1,b2-a1),
        c3 = Cross(b2-b1,a1-b1),c4 = Cross(b2-b1,a2-b1);
    return dcmp(c1)*dcmp(c2)<0&&dcmp(c3)*dcmp(c4)<0;
}
double dis[422];
int vis[422];
const double inf = 1.0*0x3fffffff;
queue<int>q;
double Dis(Point a,Point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int main() {
    int i,j,n,t;
    scanf("%d",&t);
    while(t--)
    {
        int k=0;
        scanf("%lf%lf%lf%lf",&start.x,&start.y,&end.x,&end.y);
        s[k++]=start;s[k++]=end;
        scanf("%d",&n);
        for(i=0;i<n*2+2;i++)gra[i].clear();
        for(i=0;i<n;i++)
        {
            scanf("%lf%lf",&tmp.x,&tmp.y);
            s[k++]=tmp;
            scanf("%lf%lf",&tmp.x,&tmp.y);
            s[k++]=tmp;
        }
        for(i=0;i<k;i++)
        {
            for(j=i+1;j<k;j++)
            {
                int flag=0;
                for(int g=0;g<n;g++)
                {
                    if(SegmentIntersection(s[i],s[j],s[g*2+2],s[g*2+3]))
                    {
                        flag=1;break;
                    }
                }
                //cout<<i<<" "<<j<<" "<<flag<<endl;
                if(flag==0)
                {
                    gra[i].push_back(j);
                    gra[j].push_back(i);
                }
            }
        }
        //for(i=0;i<n*2+2;i++)
        {
           // cout<<i<<" "<<gra[i].size()<<endl;
        }
        for(i=0;i<n*2+2;i++)
        {
            vis[i]=0;dis[i]=inf;
        }
        dis[0]=0;vis[0]=1;
        while(!q.empty())q.pop();
        q.push(0);
        while(!q.empty())
        {
            int u = q.front();q.pop();
            vis[u]=0;
            for(i=0;i<gra[u].size();i++)
            {
                int v=gra[u][i];
                double d = Dis(s[u],s[v]);
                if(dis[v]>dis[u]+d)
                {
                    dis[v]=dis[u]+d;
                    if(vis[v]==0)
                    {
                        vis[v]=1;q.push(v);
                    }
                }
            }
        }
        printf("%.6f\n",dis[1]);
        //cout<<dis[1]<<endl;
    }
    return 0;
}
