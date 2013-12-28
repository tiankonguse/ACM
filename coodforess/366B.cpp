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
typedef long long LL;
const int N = 101000;
int str[N];

int main() {

    int n,k,i,tmp,ans;
    while(~scanf("%d%d",&n,&k)) {
        memset(str,0,sizeof(int)*(k+1));
        for(i=0; i<n; i++) {
            scanf("%d",&tmp);
            str[i%k] += tmp;
        }
        ans = 0;
        for(i=0; i<k; i++) {
//        	printf("%d %d\n",i,str[i]);
            if(str[i] < str[ans]) {
                ans = i;
            }
        }
        printf("%d\n",ans+1);
    }

    return 0;
}
