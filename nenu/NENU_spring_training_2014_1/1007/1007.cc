#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <queue>
#include <cstdio>
#include <cmath>
#include <stack>
#define PI acos(-1.0)
#define inf 0x3f3f3f3f
#define E exp(double(1))
#define maxn 110000
#define eps 1e-7
using namespace std;

#ifdef __int64
    typedef __int64 LL;
#else
    typedef long long LL;
#endif
char str[maxn];
int main(){
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	LL ans;
	int a,b,tmp,i,j;
	while(scanf("%s",str)!=EOF){
        int cnt=1,ans=0;
        for(i=1;str[i];i++){
            if(str[i]==str[i-1]){
                cnt++;
            }else{
                if(cnt%2==0)ans++;
                cnt=1;
            }
        }
        if(cnt%2==0)ans++;
        printf("%d\n",ans);
    }

	return 0;
}
