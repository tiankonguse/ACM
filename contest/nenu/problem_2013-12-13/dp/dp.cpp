#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<cmath>
#include<stack>
#include<algorithm>
#include<functional>
#include<stdarg.h>
using namespace std;
#ifdef __int64
typedef __int64 LL;
#else
typedef long long LL;
#endif
/*
组队

2113年,第138届ACM国际大学生程序设计竞赛开始比赛了.
时代不同了，做的题也不同了，自然赛制也不同了。
比赛规定一个队至少可以参加一个人，至多可以参加k人。
古老的acmer震惊了，这么多人想要干嘛呢？
你不用管这么多了，已经说过时代不同了。
tiankonguse 来到他的大学后，发现学院刚好有n个acm,这n个小学弟小学妹有强有弱。
于是tiankonguse给他们出了一个字符串转浮点型的题来考察他们，最后讲解体报告时，tiankonguse竟然使用库函数 sscanf 来转化。
sscanf使用方法如下：
假设有一个字符串和一个变量，下面的代码就可以把字符串转化为数字。

char str[100] = "1.230";
double number;
sscanf（str,"%lf",&number）;

考察之后对他们进行了打分，然后发现他们的分数刚好是从1分到n分。

tiankonguse 和学弟学妹短暂的接触后，发现对于分数相邻的两个人是不适合组队的。
现在问题出来了，这n个学弟学妹有多少种适合的组队方式呢？

输入描述
输入有多组数据。
每组数据有两个数 n和k.(1<=k,n<=1000 代表有n个acmer,一个队最多k个人)


输出描述
输出有多少种合适的组队方式。答案模上 1000000007

样例输入
1 1
10 1
10 2
245 21

样例输出
1
10
46
369305584


提示
可以设 str[n][i]为 前n个人挑了i个人组队，则可以讨论第n个人是否挑来分析。


*/
int mod = 1000000007;
const int N = 1111;
int str[N][N];
int main() {
//    freopen("dp.in","r",stdin);
//    freopen("dp.out","w",stdout);
    int n,i,j,k;
    memset(str,0,sizeof(str));
    str[0][0] = 1;
    str[1][0] = 1;
    str[1][1] = 1;

    for(i=2; i<N; i++) {
        str[i][1] = i;
        str[i][0] = 1;
        for(j=2; j<=i; j++) {
            str[i][j] = (str[i-2][j-1] + str[i-1][j])%mod;
        }
    }
    int ans;
    while(~scanf("%d%d",&n,&k)) {
        if(k>n)k=n;
        ans = 0;
        for(i=1; i<=k; i++) {
            ans += str[n][i];
            ans %= mod;
        }
        printf("%d\n",ans);
    }


    return 0;
}
