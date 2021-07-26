/*************************************************************************
    > File Name: Ignatius and the Princess IV.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/16 15:34:27
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

struct T {
    int val,num;
    bool operator < (const T &m)const {
        return num > m.num;
    }
} str[999999];
map<int,int>Map;
map<int,int>::iterator it;
int main() {

    int n,k;
    while(~scanf("%d",&n)) {
        Map.clear();
        k = 0;
        while(n--) {
            scanf("%d",&str[k].val);
            it = Map.find(str[k].val);
            if(it == Map.end()) {
                str[k].num = 1;
                Map[str[k].val] = k;
                k++;
            } else {
                str[Map[str[k].val]].num++;
            }
        }
        sort(str,str+k);
        printf("%d\n",str[0].val);
    }

    return 0;
}
