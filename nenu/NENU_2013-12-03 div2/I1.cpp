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
using namespace std;
#ifdef __int64
typedef __int64 LL;
#else
typedef long long LL;
#endif
const int N = 101000;
int str[N];
int sum[N];
int t[N];


int main() {

    int i,j,k,n,m;
    int now;
    int ans;
    int tmp;

    while(~scanf("%d%d",&n,&m,&k)) {
        sum[0] = 0;
        for(i=1; i<=n; i++) {
            scanf("%d",&str[i]);
            sum[i]  = sum[i-1] + str[i];
        }
        for(i=1; i<=m; i++) {
            scanf("%d",&t[i]);
        }
        now = 0;
        ans = 0;
        for(i=1; i<=m; i++) {
            tmp = t[i] - t[i-1] - 1; // 这一秒前，经历了多少秒
            now += tmp ; //上一秒结束扔上去的石头的数量
            ans += tmp ; //上一秒结束用花费的时间
            if(now >= n) {
                ans += (now - n);//时间多用了，时光倒流
                now = -1;//标记找到答案了
                break;
            }

            //这一秒没心情扔石头了
            ans++;

            if(now == 0 || now == 1 || sum[now] <= k || sum[now] - sum[1] <k) {
                now = 0;
                continue;
            }




        }




    }

    return 0;
}
