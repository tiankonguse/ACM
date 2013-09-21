/*************************************************************************
    > File Name: [C] Elise.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/18 16:18:24
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<vector>
#include<map>
#include<functional>
#include<algorithm>
using namespace std;
const int N=200;
const int E = N*N;

vector<int>vec[E];
bool str[N][N];

int pre[N],rank[N];

map<string,int>Map;
int Map_num;

struct Edge {
    int from,to;
    void init(int from,int to) {
        this->from = from;
        this->to = to;
    }
} edge[E];
int e;

void addEdge(int from,int to) {
    str[from][to] = str[to][from] = true;
    edge[e++].init(from,to);
}

void init(int n) {
    for(int i=0; i<n; i++) {
        pre[i] = i, rank[i] = 0;
    }
}

int find_pre(int node) {
    if(pre[node] != node) {
        pre[node] = find_pre(pre[node]);
    }
    return pre[node];
}

void merge_pre(int from, int to) {
    from = find_pre(from);
    to = find_pre(to);

    if(from != to) {
        if(rank[from] > rank[to]) {
            pre[to] = from;
        } else {
            pre[from] = to;
            if(rank[from] == rank[to]) {
                ++rank[to];
            }
        }
    }

}

int find_map(char*p) {
    if(Map.find(p) == Map.end()) {
        Map[p] = Map_num;
        Map_num++;
    }
    return Map[p];
}



int main() {
    int n,m,i,from,len,j,to,pos,find_edge ;
    char tmp[330];
    while(~scanf("%d",&n)) {

        Map.clear();
        Map_num = 0;

        memset(str,false,sizeof(str));
        for(i=0; i<E; i++) {
            vec[i].clear();
        }


        e = 0;
        for(i=0; i<n; i++) {
            scanf("%d",&m);
            from = i;
            while(m--) {
                scanf("%s",tmp);

                pos = find_map(tmp);

                len = vec[pos].size();

                for(j=0; j<len; j++) {
                    to = vec[pos][j];
                    if(str[from][to] == false) {
                        addEdge(from,to);
                    }
                }
                vec[pos].push_back(from);
            }
        }

        find_edge  = 0;
        init(n);
        for(i=0; i<e; i++) {
            from = find_pre(edge[i].from);
            to = find_pre(edge[i].to);
            if(from == to) {
                continue;
            }
            merge_pre(from, to);
            find_edge++;
            if(find_edge + 1 == n)break;
        }
        printf("%d\n",n-1-find_edge);
    }
    return 0;
}
