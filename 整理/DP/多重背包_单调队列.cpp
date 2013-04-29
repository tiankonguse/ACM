/*************************************************************************
    > File Name: 多重背包_单调队列.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/4/29 9:29:11
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<functional>
#include<algorithm>
using namespace std;
//n个物品，v的背包，第i个物品体积为v[i],价值为w[i],共有m[i]件。

int N,W;
const int maxn=100;
const int maxw=40000;
int f[2][maxw+10];
pair <int,int> q[maxw+10];

int main()
{

    scanf("%d%d",&N,&W);
    int now=0,pas=1;

    for (int i=0; i<N; i++)
    {
        swap(now,pas);
        int v,w,m;
        scanf("%d%d%d",&v,&w,&m);
        for (int mod=0; mod<w; mod++)
        {
            int l=0,r=0;
            for (int j=0; mod+j*w<=W; j++)
            {
                while (r>l && (f[pas][mod+j*w]-j*v)>q[r-1].first)
                    r--;
                q[r++]=make_pair(f[pas][mod+j*w]-j*v,j);
                if (r-l>0 && j-q[l].second>m) l++;
                f[now][mod+j*w]=q[l].first+j*v;
            }
        }
    }

    int ans=0;
    for (int i=0; i<=W; i++)
        ans=max(ans,f[now][i]);
    printf("%d\n",ans);
    fclose(stdin);
    fclose(stdout);
return 0;
}
