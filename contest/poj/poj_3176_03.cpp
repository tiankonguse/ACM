/**************************************************************************
 **      File Name: poj_3176.cpp
 **      Author: tiankonguse
 **      Mail: shen10000shen@gmail.com
 **      Created Time: 2013/4/9 9:31:23
/**************************************************************************/
/**
金字塔，每个节点有个权值,可能为负数
从顶部出发，在每个节点可以选择向左走或是向右走，一直走到底层，要求找出一条路径，使路径上的值最大。

空间优化1
我们发现str我们只在输入时使用了，所以可以不开这个数组
*/
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

const int maxn = 400;
int ans[maxn][maxn];
int main(){
    int n,i,j,maxans,tmp;

    while(scanf("%d",&n)!=EOF){
        memset(ans,0X81,sizeof(ans));
        ans[0][0] = 0;
        maxans = 0;
        for(i=1;i<=n;i++){
            for(j=1;j<=i;j++){
                scanf("%d",&tmp);
                ans[i][j] = tmp + max(ans[i-1][j],ans[i-1][j-1]);
                maxans = max(maxans,ans[i][j]);
            }
        }
        printf("%d\n",maxans);
    }

    return 0;
}
