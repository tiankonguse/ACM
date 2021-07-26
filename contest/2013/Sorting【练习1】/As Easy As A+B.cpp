/*************************************************************************
    > File Name: As Easy As A+B.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/16 16:00:52
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
typedef long long LL;
vector<LL>vec;
int main() {
   int n,cas,i;
   LL tmp;
   scanf("%d",&cas);
   while(cas--){
        scanf("%d",&n);
        vec.clear();
        for(i=0;i<n;i++){
            scanf("%lld",&tmp);
            vec.push_back(tmp);
        }
        sort(vec.begin(),vec.end());
        for(i=0;i<n;i++){
            if(i)putchar(' ');
            printf("%lld",vec[i]);
        }
        puts("");
   }
    return 0;
}
