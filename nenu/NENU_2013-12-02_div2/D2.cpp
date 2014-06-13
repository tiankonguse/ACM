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


int main() {
    int n;
    int i,pos;
    vector<int>ans;
    int str[5]= {2,3,5,7};
    int num[5];
    while(~scanf("%d",&n)) {

        if(n <= 1) {
            printf("%d\n",n);
            continue;
        }

//		memset(num,0,sizeof(num));
        ans.clear();
        for(i=9; i>1; i--) {
            while(n%i == 0) {
                ans.push_back(i);
                n /= i;
            }
        }

        if(n != 1) {
            puts("-1");
            continue;
        }

        sort(ans.begin(),ans.end());

        for(i=0; i<ans.size(); i++) {
            printf("%d",ans[i]);
        }

        puts("");


    }

    return 0;
}
