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
const int N = 150010;
LL str[N];

struct T{
	int pos;
	LL happy;
	T(int pos=0, LL happy=0):pos(pos),happy(happy){
	}
};

int main() {
	int n,m,d,a,i,j;
	LL preT,step,b,t,ans;
	int down;
	while(~scanf("%d%d%d",&n,&m,&d)){
		for(i=0;i<m;i++){
			scanf("%d%lld%lld",&a,&b,&t);
			if(i){
				step = (t - preT)*d;
				deque<T>que;
				down = 0;
				for(j=1;j<=n;j++){
					while(!que.empty() && abs(que.front().pos - j) > step){
						que.pop_front();
					}
					while(down < n && abs(down + 1 - j) <= step){
						down++;
						while(!que.empty() && que.back().happy <= str[down]){
							que.pop_back();
						}
						que.push_back(T(down,str[down]));
					}
					str[j] = que.front().happy + b - abs(a-j);
				}
			}else{
				for(j=1;j<=n;j++){
					str[j] = b - abs(a-j);
				}
			}
			preT = t;
		}
		ans = str[1];
		for(j=2;j<=n;j++){
			ans = max(ans, str[j]);
		}
		printf("%lld\n",ans);
	}


    return 0;
}
