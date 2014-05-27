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

const int N=1000;
const int inf = 0x3fffffff;
bool vis[N];
int lowc[N],pre[N];
int cost[N][N];
int n;


void printGr();

void trim(char* line);

void readEdge();

int prim(int begin, int end, int band);

void init() {
    memset(cost, 0x3f ,sizeof(cost));
}

void printPath(int p) {
    if(pre[p]) {
        printPath(pre[p]);
    }
    printf("%d ",p);
}

void solver() {
    scanf("%*s");
    int u,v,b,ret;
    char line[100];
    while(~scanf("%s",line)) {
        trim(line);
        if(line[0] == '\0')continue;
        sscanf(line,"%d,%d,%d",&u,&v,&b);
        ret = prim(u,v,b);
        if(ret == 1){
			printPath(v);
        }else{
			printf("%d could not go to  %d\n",u,v);
        }

    }
}

int main() {
    init();
    readEdge();
    solver();
    return 0;
}


int prim(int begin, int end, int band) {
    int minc, i, j, pos;
    memset(vis,0,sizeof(vis));

    vis[begin] = 1;
    for(i=1; i<=n; i++) {
        lowc[i] = cost[begin][i];
        pre[i] = begin;
    }
    lowc[begin] = inf;
    pre[begin] = 0;

    for(i = 1; i <= n; i++) {
        minc = inf;
        for(j = 1; j <= n; j++) {
            if(vis[j] == 0 && lowc[j] >= band && minc > lowc[j]) {
                minc = lowc[j];
                pos = j;
            }
        }

        if(inf == minc)return -1;

        vis[pos] = 1;
        if(pos == end)return 1;

        for(j = 1; j <= n; j++) {
            if(vis[j] == 0 && lowc[j] > cost[pos][j]) {
                lowc[j] = cost[pos][j];
                pre[j] = pos;
            }
        }
    }
}


void readEdge() {
    scanf("%*s");
    int u,v,b;
    char line[100];
    n = 0;
    while(~scanf("%s",line)) {
        trim(line);
        if(line[0] == '\0')continue;
        if(line[0] == ';') {
            return;
        }
        sscanf(line,"%d,%d,%d",&u,&v,&b);

        cost[u][v] = cost[v][u] = b;
        n = max(n,u);
        n = max(n,v);
    }

}

void trim(char* line) {
    int i=0,j=0;
    //find first not blank pos
    while(line[i] && (line[i] == ' ' || line[i] == '\t'))i++;
    //move left
    while(line[j++] = line[i++]);
    //delete right blank
    for(j--,j--; j >=0  && (line[j] == ' ' || line[j] == '\t'); line[j--] = '\0');
}

void printGr() {
	puts("\n");
    printf("    ");
    for(int j=0; j<=n; j++) {
        printf("%4d",j);
    }
    puts("");

    for(int i=0; i<=n; i++) {
        printf("%4d",i);
        for(int j=0; j<=n; j++) {
            printf("%4d",cost[i][j]);
        }
        puts("");
    }
    puts("");
}
