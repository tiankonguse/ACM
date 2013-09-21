/**************************************************************************
 **      File Name: poj_3176.cpp
 **      Author: tiankonguse
 **      Mail: shen10000shen@gmail.com
 **      Created Time: 2013/4/9 9:31:23
/**************************************************************************/
/**
金字塔，每个节点有个权值,可能为负数
从顶部出发，在每个节点可以选择向左走或是向右走，一直走到底层，要求找出一条路径，使路径上的值最大。

空间优化3
上一节里，我们将空间从二维数组优化到两个一维数组。
如果我只想开一个一维数组怎么办呢？
什么题呀？这么苛刻，两个一维数组都不能开？
那只好使用函数递归了。
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
int ans[maxn];
int maxans;

void input(int j,int i){
    int tmp;
    scanf("%d",&tmp);
    if(i!=j){
        input(j+1,i);
    }
    ans[j] = tmp + max(ans[j],ans[j-1]);
    maxans = max(maxans,ans[j]);
}

int main(){
    int n,i;

    while(scanf("%d",&n)!=EOF){
        memset(ans,0X81,sizeof(ans));
        ans[0] = 0;
        maxans = 0;
        for(i=1;i<=n;i++){
            input(1,i);
        }
        printf("%d\n",maxans);
    }

    return 0;
}

