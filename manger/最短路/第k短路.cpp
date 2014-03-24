#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define MAXN 1001
using namespace std;
struct node {
    int p,g,h;
    bool operator < (node a) const {
        return a.g+a.h<g+h;
    }
};
struct node1 {
    int x,y,w,next;
} line[MAXN*100],line1[MAXN*100];



int n,m,i,link[MAXN],link1[MAXN],g[MAXN],s,e,k;
bool used[MAXN];
priority_queue<node> myqueue;
void djikstra() {
    int i,k,p;
    memset(used,0,sizeof(used));
    memset(g,0x7F,sizeof(g));
    g[e]=0;
    for (p=1; p<=n; p++) {
        k=0;
        for (i=1; i<=n; i++)
            if (!used[i] && (!k || g[i]<g[k]))
                k=i;
        used[k]=true;
        k=link1[k];
        while (k) {
            if (g[line1[k].y]>g[line1[k].x]+line1[k].w)
                g[line1[k].y]=g[line1[k].x]+line1[k].w;
            k=line1[k].next;
        }
    }
    return ;
}
int Astar() {
    int t,times[MAXN];
    node h,temp;
    while (!myqueue.empty()) myqueue.pop();
    memset(times,0,sizeof(times));
    h.p=s;
    h.g=0;
    h.h=0;
    myqueue.push(h);
    while (!myqueue.empty()) {
        h=myqueue.top();
        myqueue.pop();
        times[h.p]++;
        if (times[h.p]==k && h.p==e) return h.h+h.g;
        if (times[h.p]>k) continue;
        t=link[h.p];
        while (t) {
            temp.h=h.h+line[t].w;
            temp.g=g[line[t].y];
            temp.p=line[t].y;
            myqueue.push(temp);
            t=line[t].next;
        }
    }
    return -1;
}
int main() {
    scanf("%d%d",&n,&m);
    memset(link,0,sizeof(link));
    memset(link1,0,sizeof(link1));
    for (i=1; i<=m; i++) {
        scanf("%d%d%d",&line[i].x,&line[i].y,&line[i].w);
        line[i].next=link[line[i].x];
        link[line[i].x]=i;
        line1[i].x=line[i].y;
        line1[i].y=line[i].x;
        line1[i].w=line[i].w;
        line1[i].next=link1[line1[i].x];
        link1[line1[i].x]=i;
    }
    scanf("%d%d%d",&s,&e,&k);
    if (s==e) k++;
    djikstra();
    printf("%d\n",Astar());
    return 0;
}
