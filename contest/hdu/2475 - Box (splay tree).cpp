#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#pragma comment(linker, "/STACK:16777216")
using namespace std;

#define N 100005
int n , m , pre[N] , mcnt , ncnt;
struct edge
{
    int x , next;
}e[N];
int A[N] , ca;

struct SplayTree
{

    //没有pushdown的时候可以去掉stack简化代码
    int  type[N] , parent[N] , childs[N][2];
    //addtional data

    void clear()
    {

    }

    int malloc(int x)
    {
        type[x] = -1 , parent[x] = 0;
        childs[x][0] = childs[x][1] = 0;
        return x;
    }

    void pushup(int x)
    {

    }
    void rotate(int x)
    {
        int t = type[x] , y = parent[x] , z = childs[x][1 - t];
        type[x] = type[y];
        parent[x] = parent[y];
        if (~type[x])
            childs[parent[x]][type[x]] = x;
        type[y] = 1 - t;
        parent[y] = x;
        childs[x][1 - t] = y;
        if (z)
            type[z] = t , parent[z] = y;
        childs[y][t] = z;
        pushup(y);
    }
    void splay(int x , int P = 0)
    {
        while (parent[x] != P)
        {
            int y = parent[x];
            if (parent[y] != P && type[y] == type[x])
                rotate(y);
            else
                rotate(x);
            if (parent[x] != P)
                rotate(x);
        }
        pushup(x);
    }
    int Build(int l , int r)
    {
        int mid = (l + r) >> 1;
        int x = malloc(A[mid]);
        if (l <= mid - 1) childs[x][0] = Build(l , mid - 1) , parent[childs[x][0]] = x , type[childs[x][0]] = 0;
        if (mid + 1 <= r) childs[x][1] = Build(mid + 1 , r) , parent[childs[x][1]] = x , type[childs[x][1]] = 1;
        pushup(x); return x;
    }
    void print(int x)
    {
        if (childs[x][0]) print(childs[x][0]);
        printf("%d " , x);
        if (childs[x][1]) print(childs[x][1]);
    }
};
SplayTree T;
char s[10];

void dfs(int x)
{
    A[++ ncnt] = x;
    for (int i = pre[x] ; ~i ; i = e[i].next)
        dfs(e[i].x);
    A[++ ncnt] = x + n;
}

void work()
{
    int i , j , x , y , a , b , c;
    memset(pre , -1 , sizeof(pre));
    mcnt = ncnt = 0;
    if (ca ++) puts("");
    for (i = 1 ; i <= n ; ++ i)
    {
        scanf("%d",&x);
        e[mcnt].x = i , e[mcnt].next = pre[x] , pre[x] = mcnt ++;
    }
    T.clear();
    for (i = pre[0] ; ~i ; i = e[i].next)
    {
        ncnt = 0;
        dfs(e[i].x);
        T.Build(1 , ncnt);
    }

    scanf("%d" , &m);
    while (m --)
    {
        //T.splay(1);
        //T.print(1);printf("\n");
        scanf("%s" , s);
        if (*s == 'M')
        {
            scanf("%d%d",&x,&y);
            if (x == y) continue;
            T.splay(x);
            T.splay(x + n , x);
            for (j = y ; j ; j = T.parent[j])
                if (T.childs[x + n][0] == j)
                    break;
            if (j) continue;

            a = T.childs[x][0] , b = T.childs[x + n][1];
            T.childs[x][0] = T.childs[x + n][1] = 0;
            if (a && b){
            T.type[a] = -1 , T.parent[a] = T.parent[b] = 0;
            for (c = a ; T.childs[c][1] ; c = T.childs[c][1]) ;
            T.splay(c) , T.childs[c][1] = b , T.parent[b] = c;}

            if (!y) continue;
            T.splay(y);
            for (c = T.childs[y][1] ; T.childs[c][0] ; c = T.childs[c][0]) ;
            T.splay(c , y);

            T.childs[c][0] = x;
            T.parent[x] = c;
            T.type[x] = 0;
        }
        else
        {
            scanf("%d",&x);
            T.splay(x);
            for (y = x ; T.childs[y][0] ; y = T.childs[y][0]);
            printf("%d\n" , y);
        }
    }
}

int main()
{
    freopen("~input.txt" , "r" , stdin);
    //while (~scanf("%d%d",&n,&m) , ~n || ~m)
    while (~scanf("%d",&n))
        work();
    return 0;
}
