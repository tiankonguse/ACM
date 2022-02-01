#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
const int N=105;
int n,m,s,p1,p2;
double sum,r[N][N],c[N][N];



bool ok()
{
    double d[N];
    memset(d,0,sizeof(d));
    d[s]=sum;
    bool v[N];
    memset(v,0,sizeof(v));
    v[s]=1;

    queue<int>que;
    que.push(s);

    while(!que.empty())
    {
        int u=que.front();
        que.pop();
        v[u]=0;

        for(int i=0;i<n;i++)
        {
            double t=(d[u]-c[u][i])*r[u][i];
            if(t>d[i])
            {
                d[i]=t;
                if(!v[i])
                {
                    v[i]=1;
                    if(i==s)return 1;
                    que.push(i);
                }
            }

        }


    }



return d[s]>sum;
}

int main()
{
  memset(r,0X3f,sizeof(r));
  memset(c,0,sizeof(c));

  scanf("%d%d%d%lf",&n,&m,&s,&sum);

  s--;
    for(int i=0;i<m;i++)
    {
      scanf("%d%d",&p1,&p2);

      p1--;
      p2--;

      scanf("%lf%lf%lf%lf",&r[p1][p2],&c[p1][p2],&r[p2][p1],&c[p2][p1]);

    }

    printf("%s\n",ok()?"YES":"NO");

  return 0;
}

