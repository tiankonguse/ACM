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

int seq[MAXN];
int len;
int ret;

void add(int u,int v,int w) {
    nodes[size].v=v,nodes[size].w=w;
    nodes[size].next=head[u];
    head[u]=size++;
}


int count(int* first, int *last, int now_dist) {
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


int countRoot(int* first, int *last, int now_dist) {
    int ret = 0;
    int kk = k + now_dist<<1;
    sort(first,last);
    while(first<last) {
        if(*first <= kk) {
            ret++;
        } else {
            break;
        }
        first++;
    }
    return ret;
}
void find(int u, int p, int now_dist) {
    int pre_begin , pre_end, child_begin, child_end,v,w;

    dist[len++] = now_dist;

    pre_begin = len;

    for(int son=head[u]; son!=-1; son=nodes[son].next) {
        v = nodes[son].v;
        w=nodes[son].w;
        if(v==p)continue;
        child_begin = len;
        find(v,u,now_dist+w);
        child_end = len;
        if(child_begin + 1 != child_end) {
            ret -= count(dist+child_begin, dist+child_end, now_dist);
        }
    }
    pre_end = len;

//    printf("p=%d u=%d -- %d  b=%d  e=%d now_dist=%d\n",p,u,ret, pre_begin, pre_end,now_dist);

    if(pre_begin != pre_end && pre_begin + 1 != pre_end) {
//        if(p == -1) {
//            for(int son=pre_begin; son<pre_end; son++) {
//                printf("%d ",dist[son]);
//            }
//            puts("");
//        }
        ret += count(dist+pre_begin,dist+pre_end, now_dist);
    }
//    printf("p=%d u=%d -- %d  b=%d  e=%d now_dist=%d\n",p,u,ret, pre_begin, pre_end,now_dist);

    if(pre_begin != pre_end) {
        ret += countRoot(dist+pre_begin,dist+pre_end, now_dist);
    }

//    printf("");
//    printf("p=%d u=%d -- %d  b=%d  e=%d now_dist=%d\n",p,u,ret, pre_begin, pre_end,now_dist);

}

int main() {
    int w,v,u,i;
    while(scanf("%d%d",&n,&k),n) {

        memset(head+1,-1,sizeof(int)*n);
        size = 0;
        for(i=1; i<n; i++) {
            scanf("%d%d%d",&u,&v,&w);
            add(u,v,w);
            add(v,u,w);
        }

        //假设1为根

        len = 0;
        ret = 0;
        find(1,-1,0);



        printf("%d\n",ret);
    }
    return 0;
}







