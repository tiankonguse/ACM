/**************************************************************************
 **      File Name: A.cpp
 **      Author: tiankonguse
 **      Mail: shen10000shen@gmail.com
 **      Created Time: 2013/3/31 12:08:04
/**************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<functional>
#include<algorithm>
using namespace std;

const int N = 100003;

vector<int>g[N];
bool have[N];
bool mark[N];
int  childCount[N];
int  oneCount[N];
int preNode[N];


int query(int node) {

    bool markNum = 0;
    int pre = preNode[node];
    while(pre != 0){
        if(mark[pre])markNum = !markNum;
        pre = preNode[pre];

    }

    if(markNum){
        return childCount[node] - oneCount[node];
    }
/*
//    int ans = 0,len,i,child;
//    if(mark[node]) {
//        mark[node] = false;
//        have[node] = !have[node];
//        if(have[node])ans ++;
//        len = g[node].size();
//        for(i=0; i<len; i++) {
//            child = g[node][i];
//            mark[child] = !mark[child];
//            ans += query(child);
//        }
//    } else {
//        if(have[node])ans ++;
//        len = g[node].size();
//        for(i=0; i<len; i++) {
//            child = g[node][i];
//            ans += query(child);
//        }
//    }

//    return ans;
 */

   return oneCount[node];

}

int findChildCount(int node) {

    int ans = 1,len,i;
    len = g[node].size();
    for(i=0; i<len; i++) {
        childCount[g[node][i]] = findChildCount(g[node][i]);
        ans += childCount[g[node][i]];
    }

    return ans;
}

void update(int node,int val) {

    if(node == 0)return ;

    int oldoneCount;
    oldoneCount = oneCount[node];

    oneCount[node] = oldoneCount + val;

    update(preNode[node],oneCount[node] - oldoneCount);
}

int main() {
    int n,m,i,j,p,node,oldoneCount;
    char s[2];
    while(scanf("%d%d",&n,&m)!=EOF) {

        for(i=1; i<=n; i++) {
            g[i].clear();
        }

        memset(have,0,sizeof(have));
        memset(mark,0,sizeof(mark));
        memset(childCount,0,sizeof(childCount));
        memset(oneCount,0,sizeof(oneCount));
        preNode[1] = 0;


        for(i=2; i<=n; i++) {
            scanf("%d",&p);
            preNode[i] = p;
            g[p].push_back(i);
        }


        childCount[1] = findChildCount(1);

        while(m--) {
            scanf("%s%d",&s,&node);
            if(s[0] == 'o') {
                mark[node] = !mark[node];
                oldoneCount = oneCount[node];
                oneCount[node] = childCount[node] - oldoneCount;
                update(preNode[node],oneCount[node] - oldoneCount);
//                for(i=1;i<=n;i++){
//                    printf("%d--->%d\n",i,oneCount[i]);
//                }

                //puts("");
            } else {
                printf("%d\n",query(node));
            }
        }
    }
    return 0;
}
/*
3 2
1 1
o 2
q 1

5 2
1 1 2 2
o 2
q 1

5 2
1 1 2 2
o 2
q 2

5 2
1 1 2 2
o 2
q 3

5 2
1 1 2 2
o 2
q 4

5 2
1 1 2 2
o 2
q 5

*/
