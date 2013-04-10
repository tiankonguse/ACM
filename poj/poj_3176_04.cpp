/**************************************************************************
 **      File Name: poj_3176.cpp
 **      Author: tiankonguse
 **      Mail: shen10000shen@gmail.com
 **      Created Time: 2013/4/9 9:31:23
/**************************************************************************/
/**
金字塔，每个节点有个权值,可能为负数
从顶部出发，在每个节点可以选择向左走或是向右走，一直走到底层，要求找出一条路径，使路径上的值最大。

空间优化2
我们发现ans数组，我们也是用上了上一个和左上那个。
可不可以只用一个一维数组呢？
我们来试试。
样例数据都没过。为什么呢？
仔细看看，当处理[i,j]时，我们需要[i-1,j]和[i-1,j-1].使用一个一维数组后，即使
当处理[j]时，我们需要[j]和[j-1]了。
但是我们在处理[i,j-1]时可能更新[i,j-1],对应的，[j-1]的值已经不是原来的值了。
怎么办呢？我真的不想开那个二维数组。
仔细看看，在处理[i,j-1]时可能更新[i,j-1]，而[i,j]需要[i,j-1]的旧值，如果我们在更新[i,j-1]之前计算[i,j]不就OK了吗？
这样更新[i,1]需要先更新[i,2],递推下去就是从后向前更新了。
但是我们是从前向后输入的?怎么办呢？
再开个一维数组吧。
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
int tmp[maxn];
int main(){
    int n,i,j,maxans;

    while(scanf("%d",&n)!=EOF){
        memset(ans,0X81,sizeof(ans));
        ans[0] = 0;
        maxans = 0;
        for(i=1;i<=n;i++){
            for(j=1;j<=i;j++){
                scanf("%d",&tmp[j]);
            }
             for(j=i;j>0;j--){
                ans[j] = tmp[j] + max(ans[j],ans[j-1]);
                maxans = max(maxans,ans[j]);
            }
        }
        printf("%d\n",maxans);
    }

    return 0;
}

