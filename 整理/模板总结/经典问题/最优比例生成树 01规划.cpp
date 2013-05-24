/*
设x[i]等于1或0, 表示边e[i]是否属于生成树.
则我们所求的比率 r = ∑(benifit[i] * x[i]) / ∑(cost[i] * x[i]), 0≤i<m .
为了使 r 最大, 设计一个子问题
让 z = ∑(benifit[i] * x[i]) - l * ∑(cost[i] * x[i]) = ∑(d[i] * x[i]) 最大 
   (d[i] = benifit[i] - l * cost[i]) , 并记为z(l). 
我们可以z(l)看做以d为边权的最大生成树的总权值.

然后明确两个性质:
　1.  z单调递减
　2.  z( max(r) ) = 0
*/

#include<cstdio>
#include<cmath>
const double eps=1e-6,inf=100000000;
const int N =1010;
struct Node
{
       double x,y,z;
}p[N];
int n;
double d[N];
int v[N],pre[N];
double f(int a,int b,double x)
{
       return fabs(p[a].z-p[b].z) - x *
              sqrt( (p[a].x - p[b].x)*(p[a].x - p[b].x) +
                    (p[a].y - p[b].y)*(p[a].y - p[b].y));
}
double prim(double x)
{
     for(int i=1;i<n;i++)
     {
          v[i]=0;
          d[i]=f(0,i,x);
          pre[i]=0;
     }
     d[0]=0,v[0]=1;
     double cost=0,len=0;
     while(1)
     {
          double min=inf;
          int u=-1;
          for(int i=1;i<n;i++)
             if(!v[i] && min>d[i])
                  min=d[i],u=i;
          if(u==-1) break;
          v[u]=1;
          cost+=fabs(p[u].z-p[pre[u]].z);
          len +=sqrt((p[u].x - p[pre[u]].x)*(p[u].x - p[pre[u]].x) +
                     (p[u].y - p[pre[u]].y)*(p[u].y - p[pre[u]].y));
          for(int i=1;i<n;i++)
          {
               double val=f(u,i,x);
               if(!v[i]&&d[i]>val)
               {
                   d[i]=val;
                   pre[i]=u;
               }
          }
     }
     return cost/len;
}
int main()
{
    while(scanf("%d",&n),n)
    {
         for(int i=0;i<n;i++)
              scanf("%lf%lf%lf",&p[i].x,&p[i].y,&p[i].z);
         double a=0,b;
         while(1)
         {
              b=prim(a);
              if(fabs(b-a)<eps) break;
              a=b;
         }
         printf("%.3f\n",a);
    }
}
