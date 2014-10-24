// splay
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
pair<int , int> a[N];
int b[N];
struct SplayTree
{

    //没有pushdown的时候可以去掉stack简化代码
    int nodecnt , root , type[N] , parent[N] , childs[N][2] , size[N] , st[N];
    //addtional data
    bool rev[N];

    void clear()
    {
        root = 0;
        size[root] = 0;
        nodecnt = 1;
    }

    int malloc(int x)
    {
        type[x] = -1;
        childs[x][0] = childs[x][1] = 0;
        size[x] = 1;

        rev[x] = 0 ;
        return x;
    }

    void pushup(int x)
    {
        size[x] = size[childs[x][0]] + 1 + size[childs[x][1]];
    }
    void pushdown(int x)
    {
        // 区间翻转时注意type的变化
        if (rev[x])
        {
            swap(childs[x][0] , childs[x][1]);
            if (childs[x][0]) type[childs[x][0]] = 0 , rev[childs[x][0]] ^= 1;
            if (childs[x][1]) rev[childs[x][1]] ^= 1 , type[childs[x][1]] = 1;
            rev[x] = 0;
        }
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
    void splay(int x)
    {
        int scnt = 0;
        st[scnt ++] = x;
        for (int i = x ; ~type[i] ; i = parent[i])
            st[scnt ++] = parent[i];
        for (int i = scnt - 1 ; i >= 0 ; -- i)
            pushdown(st[i]);
        while (~type[x])
        {
            int y = parent[x];
            if (type[y] == type[x])
                rotate(y);
            else rotate(x);
            if (~type[x])
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
        type[x] = -1;
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
        int x = malloc(b[mid]);
        if (l <= mid - 1) childs[x][0] = Build(l , mid - 1) , parent[childs[x][0]] = x , type[childs[x][0]] = 0;
        if (mid + 1 <= r) childs[x][1] = Build(mid + 1 , r) , parent[childs[x][1]] = x , type[childs[x][1]] = 1;
        pushup(x); return x;
    }
};
SplayTree T;

int n , Q;
void RD(int& x)
{
  x = 0; char c;
  for (c = getchar() ;!isdigit(c) ; c = getchar()); x = c - '0';
  for (c = getchar() ; isdigit(c) ; c = getchar()) x = x * 10 + c - '0';
}

void work()
{
    int i , j , k , l , r , m , x , y , z;
    T.clear();
    for (i = 1 ; i <= n ; ++ i)
        scanf("%d",&a[i].fi) , a[i].se = i;
    sort(a + 1 , a + 1 + n);
    for (i = 1 ; i <= n ; ++ i)
        b[a[i].se] = i;
    T.root = T.Build(1 , n);

    for (i = 1 ; i <= n ; ++ i)
    {
        k = T.Rank(i);
        printf("%d%c" , k + 1 , " \n"[i == n]);
        T.split(T.root , x , k + 1);
        T.split(T.root , y , i - 1);
        T.rev[y] ^= 1;
        T.merge(T.root , y);
        T.merge(T.root , x);
    }
}

int main()
{
    freopen("~input.txt" , "r" , stdin);
    while (scanf("%d\n",&n) , n)
        work();
    return 0;
}
