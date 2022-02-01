/*************************************************************************
    > File Name: 11729.cpp
    > Author: tiankonguse
    > Mail: i@tiankonguse.com
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

const int N = 1010;
struct T{
    int b,j;
    bool operator<(const T o)const{
        return this->j > o.j;
    }
}str[N];

int main() {


    int n,sum,now,cas=0;
    while(~scanf("%d",&n),n){
        for(int i=0;i<n;i++){
            scanf("%d%d",&str[i].b, &str[i].j);
        }
        sort(str, str+n);
        sum = 0;
        now = 0;
        for(int i=0;i<n;i++){
            now += str[i].b;
            sum = max(sum, now+str[i].j);
        }
        printf("Case %d: %d\n",++cas,sum);

    }

    return 0;
}
