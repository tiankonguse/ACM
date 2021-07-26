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
#define maxn 100010
using namespace std;


const int maxn = 20005;
double f[maxn][2];
int main()
{
    int n,k,i,j;
    double p;
    while(scanf("%d%d%lf",&n,&k,&p)!=EOF)
    {
        f[0][0]=f[0][1]=1;
        for(i=1;i<=n;i++)
        {
            for(j=0;j<=k;j++)
            {
                f[j+1][1]+=f[j][0]*(1-p)+f[j]
            }
        }
    }
}
