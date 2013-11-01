#include<cstdio>
#include<cstdlib>
#include<math.h>
#include<cstring>
#include<ctype.h>
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

    将递归与序列seq结合起来，对子树1-N的递归，也是对序列setree[1-N]的递归
    所以存一下要递归的序列setree[]
    由于要对很多棵子树进行递归，用一个队列存每次扩展到的子树序列的头尾指针

    这里还有个问题，就是根的选择，选择的不好的话，某些数据就会效率特别低。
    所以，我们要找到树的重心，这样就可以把复杂度均摊到log(n)了。



*/
const int MAXN = 10005;

struct Node {
    int w,v,next;
} nodes[MAXN*2];
int head[MAXN];
int size;

int dist[MAXN];
int n,k;

int setree[MAXN];
int len;
int ret;

int tree[MAXN][2],front,tail;
bool vi[MAXN];

int best_size, center;

void add(int u,int v,int w) {
    nodes[size].v=v,nodes[size].w=w;
    nodes[size].next=head[u];
    head[u]=size++;
}


int count(int* first, int *last, int now_dist=0) {
    int ret = 0;
    int kk = k + (now_dist<<1);
    sort(first,last);
    last--;
//    printf("kk=%d\n",kk);
    while(first<last) {
        if(*first + *last <= kk) {
            ret+=last-first;
            first++;//last行，则last之前肯定也行，统计first+1到last的个数
        } else {
            last--;
        }
    }
    return ret;
}

int centerOfGravity(int u,int p) {
    int max_sub = 0,size = 1;
    for(int son=head[u]; son!=-1; son=nodes[son].next) {
        int v=nodes[son].v;
        if(v==p||!vi[v])continue;
        int t = centerOfGravity(v,u);
        size += t;
        if(t>max_sub)max_sub = t;
    }
    max_sub = max(max_sub, tree[front][1]-tree[front][0]-size);

    if(max_sub < best_size) {
        center = u;
        best_size = max_sub;
    }
    return size;
}

void find(int u, int p, int now_dist) {
    int pre_begin , pre_end, child_begin, child_end,v,w;

    setree[len] = u;
    dist[len++] = now_dist;
    pre_begin = len;

    for(int son=head[u]; son!=-1; son=nodes[son].next) {
        v = nodes[son].v;
        w=nodes[son].w;
        if(!vi[v]||v==p)continue;
        child_begin = len;
        find(v,u,now_dist+w);
        child_end = len;
        if(p==-1) { //为根时
            tree[tail][0]=child_begin, tree[tail][1]=child_end;//存扩展的子树，在setree[last,len)
            tail++;
            ret-=count(dist+child_begin,dist+child_end);
        }
    }
    pre_end = len;
}
inline int get_int() {
    int ret=0;
    char c;
    while(!isdigit(c=getchar()));
    do {
        ret = (ret<<3)+(ret<<1)+c-'0';
    } while(isdigit(c=getchar()));
    return ret;
}
int main() {
    int w,v,u,i;
    memset(vi,0,sizeof(vi));
    while(scanf("%d%d",&n,&k),n) {

        memset(head+1,-1,sizeof(int)*n);

        size = 0;
        for(i=1; i<n; i++) {
            u =get_int();
            v =get_int();
            w =get_int();
//            scanf("%d%d%d",&u,&v,&w);
            add(u,v,w);
            add(v,u,w);
        }

        //假设1为根

        len = 0;
        ret = 0;

        front=0;
        tail=1;
        for(int i=1; i<=n; i++)setree[i]=i;
        for(tree[front][0]=1,tree[front][1]=n+1; front!=tail; front++) {
            for(int i=tree[front][0]; i<tree[front][1]; i++)vi[setree[i]]=1;

            best_size=n+1;
            center  = setree[tree[front][0]];
            centerOfGravity(setree[tree[front][0]],-1);

            len = tree[front][0];
            find(center,-1,0);
            ret+=count(dist+tree[front][0],dist+tree[front][1]);

            for(int i=tree[front][0]; i<tree[front][1]; i++)vi[setree[i]]=0;
        }

        printf("%d\n",ret);
    }
    return 0;
}







