#include<iostream>
#include<cstdio>
#include<set>
#include<cstring>
#include<cstdlib>
#include<functional>
#include<functional>
#include<algorithm>
using namespace std;

const int N = 100000;


int maxVal;

int pre[N], rank[N], sz, val[N];

void makeset(int n){
    sz = n;
    for(int i = 0; i < n; i++){
        pre[i] = i;
        rank[i] = 0;
        val[i] = 0;
    }
}

int find(int x){
    return pre[x] = (x != pre[x]) ? find(pre[x]) : pre[x];
}

void merge(int x, int y, int w){
    if(rank[x] > rank[y]){
        pre[y] = x;
        val[x] += val[y] + w;
        maxVal = max(maxVal, val[x]);
    }else{
        pre[x] = y;
        val[y] += val[x] + w;
    }

    if(rank[x] == rank[y]){
        rank[y]++;
        maxVal = max(maxVal, val[y]);
    }
}

int main() {

    int n, m, star, end, w, starRoot, endRoot;

    bool yes;
    while(scanf("%d%d",&n,&m) != EOF) {

        yes = false;

        maxVal = -1;

        makeset(n);

        for(int i = 0; i < m; i++){
            scanf("%d%d%d",&star, &end, &w);
            starRoot = find(star);
            endRoot = find(end);

            if(!yes && starRoot != endRoot){
                merge(starRoot, endRoot, w);
            }else{
                yes = true;
            }
        }

        if( yes) {
            printf("YES\n");
        } else {
            printf("%d\n",maxVal);
        }
    }
    return 0;
}
