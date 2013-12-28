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
//typedef int LL;
/*
tiankonguse 很早就听说过 3n+1 问题。
100年后的今天，他在研究一个更复杂的问题。

tiankonguse 对一个数字定义了一个规则：

1.如果值是1，结束规则。
2.如果是偶数，除以2，如果是3的倍数,除以3,否则乘以3再加1
3.重新执行这个规则

tiankonguse 现在在想：对于一个数字，需要执行多少次规则才能停止呢？

后来 tiankonguse 对100000000以内的正整数的执行次数想到一个规律， 他想去验证一下这个规律对不对。

但是对于一个规律需要有正确的次数才行。

所以求一个正确的次数的任务就交给你了。

后来他又想了想，补了一句"如果那个数字不可能执行到1的话，执行次数就算-1吧！虽然这是不可能存在的。"


输入描述
每行一个整数n (1<=n<=1000000)，直到文件结尾。

输出描述
对于每一个n,输出n执行的次数。如果不可能到达1的话，输出-1.


样例输入
1
2
3
10
10000
1024

样例输出
1
2
2
7
30
11


*/
const int N = 1000010;
int str[N];

int dfs(int n) {

	if(n < N && str[n]!= -1){
		return str[n];
	}

	int ans;
    if(n == 1) {
        ans = 1;
    } else if(n%2 == 0) {
        ans = dfs(n/2) + 1;
    } else if(n%3==0) {
        ans = dfs(n/3) + 1;
    } else {
        ans = dfs(3*n + 1) + 1;
    }
    if(n < N){
		str[n] = ans;
    }
    return ans;
}
int main() {

    int n;
    memset(str,-1,sizeof(str));
//    freopen("Recursion.in","r",stdin);
//    freopen("Recursion.out","w",stdout);
////	n = 113383;
    while(~scanf("%d",&n)) {
        printf("%d\n",dfs(n));
    }
//    printf("1\n2\n2\n7\n30\n11\n");

    return 0;
}
