#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <list>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
//#pragma comment(linker, "/STACK:16777216")
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

#define N 100005
struct SplayTree
{

    //没有pushdown的时候可以去掉stack简化代码
    int nodecnt , root , type[N] , parent[N] , childs[N][2] , size[N] , st[N];
    //addtional data
    int key[N];
    bool rev[N];
    void clear()
    {
        root = 0;
        size[root] = 0;
        nodecnt = 1;
    }

    int malloc(int x)
    {
        type[nodecnt] = 2;
        childs[nodecnt][0] = childs[nodecnt][1] = 0;
        size[nodecnt] = 1;
        key[nodecnt] = x , rev[nodecnt] = 0;
        return nodecnt ++;
    }

    void pushup(int x)
    {
        size[x] = size[childs[x][0]] + 1 + size[childs[x][1]];
    }
    void pushdown(int x)
    {
        if (rev[x])
        {
            swap(childs[x][0] , childs[x][1]);
            type[childs[x][0]] = 0 , type[childs[x][1]] = 1;
            rev[childs[x][0]] ^= 1 , rev[childs[x][1]] ^= 1 , rev[x] ^= 1;
        }
        // 区间翻转时注意type的变化
    }
    void rotate(int x)
    {
        int t = type[x] , y = parent[x] , z = childs[x][1 - t];
        type[x] = type[y];
        parent[x] = parent[y];
        if (type[x] != 2)
            childs[parent[x]][type[x]] = x;
        type[y] = 1 - t;
        parent[y] = x;
        childs[x][1 - t] = y;
        if (z)
            type[z] = t , parent[z] = y;
        childs[y][t] = z;
        pushup(y);
    }
    void splay(int x)
    {
        int scnt = 0;
        st[scnt ++] = x;
        for (int i = x ; type[i] != 2 ; i = parent[i])
            st[scnt ++] = parent[i];
        for (int i = scnt - 1 ; i >= 0 ; -- i)
            pushdown(st[i]);
        while (type[x] != 2)
        {
            int y = parent[x];
            if (type[y] == type[x])
                rotate(y);
            else rotate(x);
            if (type[x] != 2)
                rotate(x);
        }
        pushup(x);
    }

    int getKth(int x , int k)
    {
        while (x)
        {
            pushdown(x);
            if (size[childs[x][0]] + 1 == k)
                break;
            if (k <= size[childs[x][0]])
                x = childs[x][0];
            else k -= size[childs[x][0]] + 1 , x = childs[x][1];
        }
        return x;
    }
    int Rank(int x)
    {
        splay(x) , root = x;
        return size[childs[x][0]];
    }
    void split(int& x , int& y , int a)
    {
        if (a == size[x]) {y = 0;return;}
        //if (a == 0) {y = x ; x = 0;return;}
        y = getKth(x , a + 1);
        splay(y);
        x = childs[y][0];
        type[x] = 2;
        childs[y][0] = 0;
        pushup(y);
    }
    void merge(int& x , int& y)
    {
        if (!x || !y) {x = x | y ; return;}
        x = getKth(x , size[x]);
        splay(x);
        childs[x][1] = y;
        type[y] = 1;
        parent[y] = x;
        pushup(x);
    }
    int Build(int l , int r)
    {
        int mid = (l + r) >> 1;
        int x = malloc(mid);
        if (l <= mid - 1) childs[x][0] = Build(l , mid - 1) , parent[childs[x][0]] = x , type[childs[x][0]] = 0;
        if (mid + 1 <= r) childs[x][1] = Build(mid + 1 , r) , parent[childs[x][1]] = x , type[childs[x][1]] = 1;
        pushup(x);
        return x;
    }
    void print(int x)
    {
        if (!x) return; pushdown(x);
        print(childs[x][0]);printf("%d " , key[x]);print(childs[x][1]);
    }
};
int n , m;
SplayTree T;

void work()
{
    int i , x , y , l , r;
    scanf("%d%d",&n,&m);
    T.clear();
    T.root = T.Build(1 , n);
    while (m --)
    {
        scanf("%d%d",&l,&r);
        T.split(T.root , x , l - 1);
        T.split(x , y , r - l + 1);
        T.rev[x] ^= 1;
        T.merge(x , y);
        T.merge(T.root , x);
    }
    T.print(T.root);
}

int main()
{
    freopen("~input.txt" , "r" , stdin);
    work();
    return 0;
}
