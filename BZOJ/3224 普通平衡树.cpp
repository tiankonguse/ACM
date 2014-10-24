#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;
#define N 100005

int root;
struct Treap
{
    int nodecnt , priority[N] , child[N][2];
    int key[N];
    int Size[N] , cnt[N];
    Treap(){
        clear();
    }
    void clear()
    {
        root = 0 , nodecnt = 1;
        priority[0] =  key[0] = -1 << 30;
        Size[0] = 0;
    }
    int size()
    {
        return Size[root];
    }
    void update(int x)
    {
        Size[x] = Size[child[x][0]] + Size[child[x][1]] + cnt[x];
    }
    void rotate (int& x , int t)
    {
        int y = child[x][t];
        child[x][t] = child[y][t ^ 1];
        child[y][t ^ 1] = x;
        update(x) , update(y);
        x = y;
    }
    void insert(int& x , int k)
    {
        if (x)
        {
            if (key[x] == k)
                ++ cnt[x];
            else
            {
                int t = key[x] < k;
                insert(child[x][t] , k);
                if (priority[child[x][t]] > priority[x])
                    rotate(x , t);
            }
        }
        else
        {
            x = nodecnt ++;
            key[x] = k;
            cnt[x] = 1;
            priority[x] = rand();
            child[x][0] = child[x][1] = 0;
        }
        update(x);
    }
    void erase(int& x , int k)
    {
        if (!x) return;
        if (key[x] == k)
        {
            if (cnt[x] > 1)
                -- cnt[x];
            else
            {
                if (!child[x][0] && !child[x][1])
                {
                    x = 0;
                    return;
                }
                int t = priority[child[x][0]] < priority[child[x][1]];
                rotate(x , t);
                erase(x , k);
            }
        }
        else
            erase(child[x][key[x] < k] , k);
        update(x);
    }
    int Rank(int& x , int k)
    {
        if(!x) return 0;
        if (k < key[x])
            return Rank(child[x][0] , k);
        int Rk = Size[child[x][0]] + cnt[x];
        if (k > key[x])
            Rk += Rank(child[x][1] , k);
        return Rk;
    }
    int getKth(int& x , int k)
    {
        if (k <= Size[child[x][0]])
            return getKth(child[x][0] , k);
        k -= Size[child[x][0]] + cnt[x];
        if (k <= 0)  return key[x];
        return getKth(child[x][1] , k);
    }
    void Pre(int& x , int val , int& ans)
    {
        if (!x) return;
        if (val > key[x])
            ans = max(ans , key[x]) ,
            Pre(child[x][1] , val , ans);
        else
            Pre(child[x][0] , val , ans);
    }
    void Nxt(int& x , int val , int& ans)
    {
        if (!x) return;
        if (val < key[x])
            ans = min(ans , key[x]) ,
            Nxt(child[x][0] , val , ans);
        else
            Nxt(child[x][1] , val , ans);
    }
};

int n , m ;
Treap T;
void work()
{
    int i , x , y;
    scanf("%d",&m);
    while (m --)
    {
        scanf("%d%d",&i,&x);
        if (i == 1)
            T.insert(root , x);
        if (i == 2)
            T.erase(root , x);
        if (i == 3)
            printf("%d\n" , T.Rank(root , x - 1) + 1);
        if (i == 4)
            printf("%d\n" , T.getKth(root , x));
        if (i == 5)
            y = -1 << 30 , T.Pre(root , x , y) , printf("%d\n" , y);
        if (i == 6)
            y = 1 << 30 ,  T.Nxt(root , x , y) , printf("%d\n" , y);
    }
}

int main()
{
    work();
    return 0;
}
