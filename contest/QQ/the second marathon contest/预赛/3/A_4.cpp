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
int  sunTreeNodeCount[N];
int  sunTreeOneCount[N];
int preNode[N];


int query(int node) {
    bool markNum = 0;
    int pre = preNode[node];
    while(pre != 0){
        if(mark[pre])markNum = !markNum;
        pre = preNode[pre];

    }
    return markNum ? sunTreeNodeCount[node] - sunTreeOneCount[node] : sunTreeOneCount[node];
}

int findSubSreeNodeCount(int node) {
    int len = g[node].size();
    sunTreeNodeCount[node] = 1;
    for(int i=0; i<len; i++) {
        findSubSreeNodeCount(g[node][i]);
        sunTreeNodeCount[node] += sunTreeNodeCount[g[node][i]];
    }
}

void update(int node,int val) {
    while(node != 0){
        sunTreeOneCount[node] += val;
        node = preNode[node];
    }
}

int main() {
    int n,m,i,j,p,node,oldoneCount;
    char s[2];
    while(scanf("%d%d",&n,&m)!=EOF) {

        for(i=1; i<=n; i++) {
            g[i].clear();
        }

        memset(mark,0,sizeof(mark));
        memset(sunTreeOneCount,0,sizeof(sunTreeOneCount));
        preNode[1] = 0;

        for(i=2; i<=n; i++) {
            scanf("%d",&p);
            preNode[i] = p;
            g[p].push_back(i);
        }

        findSubSreeNodeCount(1);

        while(m--) {
            scanf("%s%d",&s,&node);
            if(s[0] == 'o') {
                mark[node] = !mark[node];
                update(node,sunTreeNodeCount[node] - (sunTreeOneCount[node] <<1));
            } else {
                printf("%d\n",query(node));
            }
        }
    }
    return 0;
}
