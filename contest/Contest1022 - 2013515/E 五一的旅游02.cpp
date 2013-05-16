/*************************************************************************
    > File Name: E 五一的旅游02.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/16 12:28:25
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string.h>
#include<cstdlib>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<functional>
#include<algorithm>
using namespace std;

const int maxn = 3003;
const int E = 500000;
bool have[maxn][maxn];

struct Heap_Dijkstra{
    int array[maxn];
    void bulid();
    void insert(int node,int v);
    void alter(int node,int v);
    void swap_node(int pos1,int pos2);
    int top_val();
    int top_node();
    void pop();
    bool empty();

    private:
    int size;
    int pos[maxn];
    int val[maxn];
    void push_down(int pre);
    void push_up(int son);
    bool compare(int pre,int son);
}heap;

bool Heap_Dijkstra::compare(int pre,int son){
    return val[array[pre]] <= val[array[son]];
}

void Heap_Dijkstra::bulid(){
    size = 0;
    memset(pos,-1,sizeof(pos));
}

void Heap_Dijkstra::insert(int node, int v){
    if(pos[node] != -1){
        alter(node,v);
    }else{
        array[++size] = node;
        val[node] = v;
        pos[node] = size;
        push_up(size);
    }
}

int Heap_Dijkstra::top_val(){
    return val[array[1]];
}
int Heap_Dijkstra::top_node(){
    return array[1];
}

void Heap_Dijkstra::swap_node(int pos1,int pos2){
    swap(pos[array[pos1]],pos[array[pos2]]);
    swap(array[pos1],array[pos2]);
}

void Heap_Dijkstra::pop(){
    swap_node(1,size);
    pos[array[size--]] = -1;
    push_down(1);
}

bool Heap_Dijkstra::empty(){
    return size == 0;
}

void Heap_Dijkstra::push_down(int pre){
   if((pre<<1|1) <= size && compare(pre<<1|1,pre) && compare(pre<<1|1,pre<<1)){
        swap_node(pre,pre<<1|1);
        push_down(pre<<1|1);
    }else if((pre<<1) <= size && compare(pre<<1,pre)){
        swap_node(pre,pre<<1);
        push_down(pre<<1);
    }
}

void Heap_Dijkstra::push_up(int son){
    if(son == 1)return ;
    if(!compare(son>>1,son)){
        swap_node(son,son>>1);
        push_up(son>>1);
    }
}

void Heap_Dijkstra::alter(int node,int v){
    if(val[node] == v)return ;

    if(val[node] > v){
        val[node] = v;
        push_up(pos[node]);
    }else{
        val[node] = v;
        push_down(pos[node]);
    }

}
typedef long long LL;
int head[E],cost[E],next[E],pnt[E],e;
set<LL>Set;
LL ll=maxn;

void init(){
    e = 0;
    memset(head,-1,sizeof(head));
}

void addEdge(int u,int v,int c){
    pnt[e] = v;
    cost[e] = c;
    next[e] = head[u];
    head[u] = e++;
}

bool vis[maxn];
int lowc[maxn];
int pre[maxn];

int prim(int n,int from,int to){
    memset(vis,0,sizeof(vis));
    memset(pre,0,sizeof(pre));
    memset(lowc,0x3f3f,sizeof(lowc));
    heap.bulid();
    vis[from] = 1;
    int tmp = head[from],v;
//    printf("--\n");
    while(tmp != -1){
        if(pnt[tmp] == to){
            return 1;
        }
        pre[pnt[tmp]] = from;
        lowc[pnt[tmp]] = cost[tmp];
        heap.insert(pnt[tmp],cost[tmp]);
//        printf("--%d -> %d  %d %d\n",from,pnt[tmp],cost[tmp],lowc[pnt[tmp]]);
//        printf("---%d\n",tmp);
        tmp = next[tmp];
    }
//    printf("--\n");
    while(1){
//        printf("--\n");
        if(heap.empty())return -1;
        from = heap.top_node();heap.pop();
        printf("--%d\n",from);
        if(from == to)return lowc[to];
        tmp = head[from];
        while(tmp != -1){
            if(vis[pnt[tmp]]==0 && lowc[pnt[tmp]] > lowc[from] + cost[tmp] && Set.find(pre[from]*ll*ll + from*ll + pnt[tmp]) == Set.end()){
                pre[pnt[tmp]] = from;
                heap.insert(pnt[tmp],lowc[pnt[tmp]] =lowc[from] + cost[tmp]);
            printf("--%d -> %d  %d  %d\n",from,pnt[tmp],cost[tmp] , lowc[from]+cost[tmp]);
            }
            tmp = next[tmp];
        }

    }

}

int main() {
    int n,m,k,from,mid,to;
    while(~scanf("%d%d%d",&n,&m,&k)){
        init();
        memset(have,false,sizeof(have));
        while(m--){
            scanf("%d%d",&from,&to);
            have[from][to] = have[to][from] = true;
            addEdge(from,to,1);
            addEdge(to,from,1);
        }

//        for(int i=0;i<e;i++){
//            printf("--pnt=%d cost=%d  netx=%d\n",pnt[i],cost[i],next[i]);
//        }
        Set.clear();
        while(k--) {
            scanf("%d%d%d",&from,&mid,&to);
            if(have[from][mid] && have[mid][to]){
                Set.insert(from*ll*ll+mid * ll + to);
            }

        }
        printf("%d\n",prim(n,1,n));
    }

    return 0;
}
