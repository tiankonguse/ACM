#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
#define N 100009
using namespace std;
int n;
int arr[N];//原数据,下标从1开始
int sortedPos[N];//排序后
int lfnum[20][N];//元素所在区间的当前位置进入左孩子的元素的个数
int val[20][N];//记录第k层当前位置的元素的值
bool cmp(const int &x,const int &y) {
    return arr[x]<arr[y];
}
void build(int l,int r,int d) {
    if(l==r) return;
    int mid=(l+r)>>1,p=0;
    for(int i=l; i<=r; i++) {
        if(val[d][i]<=mid) {
            val[d+1][l+p]=val[d][i];
            lfnum[d][i]=++p;
        } else {
            lfnum[d][i]=p;
            val[d+1][mid+i+1-l-p]=val[d][i];
        }
    }
    build(l,mid,d+1);
    build(mid+1,r,d+1);
}
//求区间[s,e]第k大的元素
int query(int s,int e,int k,int l=1,int r=n,int d=0) {
    if(l==r) return l;
    int mid=(l+r)>>1,ss,ee;
    ss=(s==l?0:lfnum[d][s-1]);
    ee=lfnum[d][e];
    if(ee-ss>=k) return query(l+ss,l+ee-1,k,l,mid,d+1);
    return query(mid+1+(s-l-ss),mid+1+(e-l-ee),k-(ee-ss),mid+1,r,d+1);
}
int main() {
    int cas=0,m,l,r,k;
    while(scanf("%d%d",&n,&m)!=EOF) {
        for(int i=1; i<=n; i++){
            scanf("%d",arr+i),sortedPos[i]=i;
        }
        sort(sortedPos+1,sortedPos+n+1,cmp);
        for(int i=1; i<=n; i++){
            val[0][sortedPos[i]]=i;
        }

        for(int i=1;i<=n;i++){
            printf("%d ",sortedPos[i]);
        }
        puts("");
        for(int i=1;i<=n;i++){
            printf("%d ",val[0][i]);
        }
        puts("");

        build(1,n,0);
        while(m--) {
            scanf("%d%d%d",&l,&r,&k);
            printf("%d\n",arr[sortedPos[query(l,r,k)]]);
        }
    }
}
/*
7 4
1 6 2  3 9 3 1

7 4
1 6 2  3 9 3 1  // input
1 7 3 4 6 2 5   //sortedPos input的第几个位置的值应该在当前位置
1 6 3 4 7 5 2  //val  input的当前值应该在那个位置
*/
