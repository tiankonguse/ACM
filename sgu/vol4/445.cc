#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
#define maxn 3222
#define maxm 101000
using namespace std;
struct node {
    double x, y;
} pnt[maxn];

struct edges{
   int u, next;
   double c;
}e[maxm];
int p[maxn], idx;
//addedge
void addedge(int u,int v,double c){
    e[idx].u=v;
    e[idx].c=c;
    e[idx].next=p[u];
    p[u]=idx++;
}

double dist(node p1, node p2) {
    return sqrt( (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y) );
}
double dist2(double x1, double y1, double x2, double y2) {
    return sqrt( (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
void init(){
    idx = 0;
    memset(p, 0xff, sizeof(p));
}

queue<int> q;
double dis[maxn];
bool used[maxn];

void spfa(int s, int n){
    int t,u;
    double w;
    while(!q.empty())q.pop();
    memset(used,false,sizeof(used));
    for(int i=0;i<n;i++)dis[i]=1e10;
    dis[s]=0;
    q.push(s);
    while(!q.empty()){
        t=q.front();
        q.pop();
        used[t]=false;
        for(int i=p[t];i!=-1;i=e[i].next){
            u=e[i].u;
            w=e[i].c;
            if(dis[t]+w<dis[u]){
                dis[u]=dis[t]+w;
                if(!used[u]){
                    used[u]=true;
                    q.push(u);
                }
            }
        }
    }
}
int main() {
    int n;
    double w, c;
    while (~scanf("%d", &n)) {
        scanf(" %lf %lf", &w, &c);
        for (int i = 0; i < n; ++i) {
            scanf("%lf %lf", &pnt[i].x, &pnt[i].y);
        }
        init();
        for (int i = 0; i + 1 < n; ++i) {
            addedge(i, i + 1, dist(pnt[i], pnt[i + 1]) / w);
        }
        int end = n - 1;
        int cnt = n;

        double x, y, x1, y1, x2, y2;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (pnt[j].y <= pnt[i].y) {
                    if (pnt[j - 1].y > pnt[i].y) {
                        y = pnt[i].y;
                        x1 = pnt[j - 1].x, y1 = pnt[j - 1].y;
                        x2 = pnt[j].x, y2 = pnt[j].y;
                        x = x1 + (x2 - x1) * (y1 - y) / (y1 - y2);
                        addedge(i, cnt, (x - pnt[i].x) / c);
                        addedge(cnt, j, dist2(x, y, pnt[j].x, pnt[j].y) / w);
                        ++cnt;
                    }
                    break;
                }
            }
        }
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i - 1; j >= 0; --j) {
                if (pnt[j].y <= pnt[i].y) {
                    if (pnt[j + 1].y > pnt[i].y) {
                        y = pnt[i].y;
                        x1 = pnt[j + 1].x, y1 = pnt[j + 1].y;
                        x2 = pnt[j].x, y2 = pnt[j].y;
                        x = x1 + (x2 - x1) * (y1 - y) / (y1 - y2);
                        addedge(cnt, i, (pnt[i].x - x) / c);
                        addedge(j, cnt, dist2(x, y, pnt[j].x, pnt[j].y) / w);
                        ++cnt;
                    }
                    break;
                }
            }
        }
        spfa(0, cnt);
        printf("%.10lf\n", dis[end]);
    }
    return 0;
}
