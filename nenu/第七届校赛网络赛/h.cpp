/*************************************************************************
    > File Name: h.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/4/13 14:07:45
 ************************************************************************/

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

char str[11],*p;

int main() {
        int n,m,i,ans;
        while(~scanf("%d%d",&n,&m)){
            ans = 0;
            while(n--){
                p = str,
                scanf("%s",str);
                while(*p){
                    if(*p == '*')ans++;
                    p++;
                }
            }
            printf("%d\n",ans);
        }
    return 0;
}
