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
typedef long long LL;

const int N = 22222;
struct T{
	LL t;
	int s,d;
	bool operator < (const T &m)const {
		return t < m.t;
	}
}str[N];
bool have[N];
int n,m;

int main(int argc, char* argv[]) {
	while(~scanf("%d%d",&n,&m)){
		for(int i=0;i<m;i++){
			scanf("%lld%d%d",&str[i].t, &str[i].s, &str[i].d);
		}
		sort(str,str+m);
		memset(have,false,sizeof(have));
		have[1] = true;
		for(int i=0;i<m;i++){
			//printf("--%lld %d %d\n",str[i].t, str[i].s, str[i].d);
			if(have[str[i].s]){
				have[str[i].d] = true;;
			}
		}
		int ans = 0;
		for(int i=1;i<=n;i++){
			if(have[i])ans++;
		}
		printf("%d\n",ans);
	}

    return 0;
}






