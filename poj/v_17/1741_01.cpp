#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
/*
1741
1.树中点对距离统计

题意
    给出一棵树(n>100000)，统计距离≤K的点对  O(n^2)算法过不了

分治方法
    对root为根的子树，统计 a -> root -> b 的个数，然后再分治对每棵子树都这样统计，就能得到答案了。
    但有一个问题，就是a,b属于root同一个子树的话显然要去掉
    用dist[]表示点到根的距离,disk使用前序或后序储存树，则对于一个子树在一偏连续的数组中
    然后count() 函数头尾指针线性求得 first 到 last 所有数K的个数，实际上求的就是当前子树除了根节点，其他所有节点满足条件的个数。
    ret+=两两子树组成 first + last<=K的个数（其中会包括同一个子树的情况）
    再ret-=同一个子树组成 first + last<=K的个数

    将递归与序列seq结合起来，对子树1-N的递归，也是对序列seq[1-N]的递归
    所以存一下要递归的序列seq[]
    由于要对很多棵子树进行递归，用一个队列存每次扩展到的子树序列的头尾指针



*/
const int MAXN = 10005;

struct Node {
    int w,v,next;
} nodes[MAXN*2];

int G[MAXN];
int Q[MAXN][2],front,tail;
int dist[MAXN],seq[MAXN];
bool vi[MAXN];
int N,L,alloc,M;
int best_size,center,len,ret;

void add(int u,int v,int w) {
    nodes[alloc].v=v,nodes[alloc].w=w;
    nodes[alloc].next=G[u];
    G[u]=alloc++;
}

int count(int *first,int *last) {
    int ret = 0;
    sort(first,last--);
    while(first<last) {
        if(*first+*last<=L)ret+=last-first++;//last行，则last之前肯定也行，统计first+1到last的个数
        else last--;
    }
    return ret;
}

int centerOfGravity(int u,int p) {
    int max_sub = 0,size = 1;
    for(int son=G[u]; son!=-1; son=nodes[son].next) {
        int v=nodes[son].v;
        if(v==p||!vi[v])continue;
        int t = centerOfGravity(v,u);
        size += t;
        if(t>max_sub)max_sub = t;
    }
    if(Q[front][1]-Q[front][0]-size>max_sub)
        max_sub = Q[front][1]-Q[front][0]-size;
    if(max_sub<best_size) {
        center = u;
        best_size = max_sub;
    }
    return size;
}
void find(int u,int p,int now_dist) {
    seq[len] = u;
    dist[len++] = now_dist;
    int last = len;
    for(int son=G[u]; son!=-1; son=nodes[son].next) {
        int v = nodes[son].v,w=nodes[son].w;
        if(!vi[v]||v==p)continue;
        find(v,u,now_dist+w);
        if(p==-1) { //为根时
            Q[tail][0]=last,Q[tail][1]=len;//存扩展的子树，在seq[last,len)
            tail++;
            ret-=count(dist+last,dist+len);
            last = len;
        }
    }
}
int a = 1;
int main() {


    {
        int a = 2;
        printf("%d\n",super::a);
    }

    while(scanf("%d%d",&N,&L),N) {
        memset(G+1,-1,sizeof(int)*N);
        alloc = 0;
        for(int i=1; i<N; i++) {
            int w,v,u;
            scanf("%d%d%d",&u,&v,&w);
            add(u,v,w);
            add(v,u,w);
        }
        ret = 0;
        front=0;
        tail=1;
        for(int i=1; i<=N; i++)seq[i]=i;
        for(Q[front][0]=1,Q[front][1]=N+1; front!=tail; front++) {
            //if(Q[front][0]==Q[front][1])continue;
            for(int i=Q[front][0]; i<Q[front][1]; i++)vi[seq[i]]=1;

            best_size=N+1;
            centerOfGravity(seq[Q[front][0]],-1);//

            len = Q[front][0];
            find(center,-1,0);
            ret+=count(dist+Q[front][0],dist+Q[front][1]);

            for(int i=Q[front][0]; i<Q[front][1]; i++)vi[seq[i]]=0;
        }
        printf("%d\n",ret);
    }
    return 0;
}


