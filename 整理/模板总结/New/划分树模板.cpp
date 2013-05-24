#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
const int MaxL=100005,MaxN=100005+35005*3;
struct Node{int t,x,y,z;}q[MaxN];
int n;
int tree[20][MaxL],num[20][MaxL],sorted[MaxL];
void build(int dep,int L,int H)
{
     if(L==H) return ;
     int mid=(L+H)/2,same=0;
     int lp=L,rp=mid+1;
     for(int i=L;i<=H;i++) if(tree[dep][i]<sorted[mid]) same++;
     same=mid-L+1-same;
     for(int i=L;i<=H;i++)
     {
          if(tree[dep][i]<sorted[mid] ) tree[dep+1][lp++]=tree[dep][i];
          else if(tree[dep][i]==sorted[mid] &&same)
                tree[dep+1][lp++]=tree[dep][i],same--;
          else tree[dep+1][rp++]=tree[dep][i];
          num[dep][i]=num[dep][L-1]+lp-L;
     }
     build(dep+1,L,mid);
     build(dep+1,mid+1,H);
}
int get_value(int dep,int L,int H,int l,int r,int k)
{
    if(L==H) return tree[dep][L];
    int mid=L+H>>1,cnt=num[dep][r]-num[dep][l-1];
    int pre=num[dep][l-1]-num[dep][L-1];
    if(cnt>=k) return get_value(dep+1,L,mid,L+pre,L+pre+cnt-1,k);
    pre=l-L-pre;
    return get_value(dep+1,mid+1,H,mid+1+pre,mid+pre+r-l+1-cnt,k-cnt);
}
int get_rank(int dep,int L,int H,int l,int r,int v)
{
    if(l==r) return 1+(tree[dep][l]<v);
    int mid=L+H>>1,cnt=num[dep][r]-num[dep][l-1];
    int pre=num[dep][l-1]-num[dep][L-1];
    if(v<=sorted[mid]) return get_rank(dep+1,L,mid,L+pre,L+pre+cnt-1,v);
    pre=l-L-pre;
    return cnt+get_rank(dep+1,mid+1,H,mid+1+pre,mid+pre+r-l+1-cnt,v);
}
int main()
{
    int T=0;
    while(scanf("%d",&n)==1)
    {
         char s[10];
         int L=0,N=0;
         for(int i=0;i<n;i++)
         {
             scanf("%s",s);
             if(s[0]=='I')
             {
                  scanf("%d",&q[i].x);
                  q[i].t=0;
                  tree[0][++L]=q[i].x;
             }else
             {
                  q[i].t=s[6]-'0';
                  if(q[i].t==1) scanf("%d%d%d",&q[i].x,&q[i].y,&q[i].z);
                  else scanf("%d",&q[i].x);
             }
         }
         for(int i=1;i<=L;i++) sorted[i]=tree[0][i];
         sort(sorted+1,sorted+1+L);
         build(0,1,L);
         LL ret1=0,ret2=0,ret3=0;
         for(int i=0;i<n;i++)
         {
             switch (q[i].t)
             {
                 case 0:++N;break;
                 case 1:ret1+=get_value(0,1,L,q[i].x,q[i].y,q[i].z);break;
                 case 2:ret2+=get_rank (0,1,L,1,N,q[i].x);break;
                 case 3:ret3+=get_value(0,1,L,1,N,q[i].x);
             }
         }
         printf("Case %d:\n%lld\n%lld\n%lld\n",++T,ret1,ret2,ret3);
    }
    return 0;
}
