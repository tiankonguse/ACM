#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;
typedef long long LL;
#define N 200505

struct Treap
{
    int nodecnt;
    int L[N] , R[N] , cnt[N];
    int key[N];
    int Min[N] , add[N] , rev[N];
    void clear() {
        nodecnt = 0;
    }
    Treap () {clear();}
    bool hey(int A , int B) {
        return (LL)rand() * (cnt[A] + cnt[B]) < (LL)cnt[A] * RAND_MAX;
    }
    int newnode(int val) {
        ++ nodecnt , L[nodecnt] = R[nodecnt] = 0;
        cnt[nodecnt] = 1 , Min[nodecnt] = key[nodecnt] = val , rev[nodecnt] = add[nodecnt] = 0;
        return nodecnt;
    }
    void pushup(int x) {
        cnt[x] = 1 , Min[x] = key[x];
        if (L[x]) cnt[x] += cnt[L[x]] , Min[x] = min(Min[x] , Min[L[x]]);
        if (R[x]) cnt[x] += cnt[R[x]] , Min[x] = min(Min[x] , Min[R[x]]);
    }
    void pushdown(int x) {
        if (rev[x]) {
            if (L[x]) rev[L[x]] ^= 1 , swap(L[L[x]] , R[L[x]]);
            if (R[x]) rev[R[x]] ^= 1 , swap(L[R[x]] , R[R[x]]);
            rev[x] = 0;
        }
        if (add[x]) {
            if (L[x]) add[L[x]] += add[x] , Min[L[x]] += add[x] , key[L[x]] += add[x];
            if (R[x]) add[R[x]] += add[x] , Min[R[x]] += add[x] , key[R[x]] += add[x];;
            add[x] = 0;
        }
    }
    void merge(int& p , int x , int y) {
        if (!x || !y)
            p = x | y;
        else if ( hey(x , y) ) // key[x] < key[y]
            pushdown(x) , merge(R[x] , R[x] , y) , pushup(p = x);
        else
            pushdown(y) , merge(L[y] , x , L[y]) , pushup(p = y);
    }
    void split(int p , int& x , int& y , int size) {
        if (!size) {
            x = 0 , y = p;
            return;
        }   pushdown(p);
        if (cnt[L[p]] >= size)
            y = p , split(L[p] , x , L[y] , size) , pushup(y);
        else
            x = p , split(R[p] , R[x] , y , size - cnt[L[p]] - 1) , pushup(x);
    }
    void Build(int *A , int& p , int l , int r) {
        int mid = (l + r) >> 1;
        p = newnode(A[mid]);
        if (l < mid) Build(A , L[p] , l , mid - 1);
        if (mid < r) Build(A , R[p] , mid + 1 , r);
        pushup(p);
    }
};
Treap T;
int n , m , a[N];
void work()
{
    int i , j , k , x , y , z;
    char str[10];
    int root = 0;
    scanf("%d",&n);
    for (i = 1 ; i <= n ; ++ i)
        scanf("%d",&a[i]);
    T.Build(a , root , 1 , n);
    scanf("%d",&m);
    while (m --) {
        scanf("%s" , str);
        if (*str == 'A') {
            scanf("%d%d%d",&j , &k , &z);
            T.split(root , root , x , j - 1);
            T.split(x , x , y , k - j + 1);
            T.add[x] += z , T.key[x] += z , T.Min[x] += z;
            T.merge(x , x , y);
            T.merge(root , root , x);
        }
        if (*str == 'I') {
            scanf("%d%d",&j , &z);
            x = T.newnode(z);
            T.split(root , root , y , j);
            T.merge(root , root , x);
            T.merge(root , root , y);
        }
        if (*str == 'D') {
            scanf("%d",&j);
            T.split(root , root , x , j - 1);
            T.split(x , x , y , 1);
            T.merge(root , root , y);
        }
        if (*str == 'M') {
            scanf("%d%d",&j , &k);
            T.split(root , root , x , j - 1);
            T.split(x , x , y , k - j + 1);
            printf("%d\n" , T.Min[x]);
            T.merge(x , x , y);
            T.merge(root , root , x);
        }
        if (*str == 'R' && *(str + 3) == 'E')
        {
            scanf("%d%d",&j , &k);
            T.split(root , root , x , j - 1);
            T.split(x , x , y , k - j + 1);
            T.rev[x] ^= 1 , swap(T.L[x] , T.R[x]);
            T.merge(x , x , y);
            T.merge(root , root , x);
        }
        if (*str == 'R' && *(str + 3) == 'O')
        {
            scanf("%d%d%d", &j , &k , &z);
            z %= (k - j + 1); if (!z) continue;
            T.split(root , root , x , j - 1);
            T.split(x , x , y , k - j + 1);
            T.split(x , j , k , k - j + 1 - z);
            T.merge(x , k , j);
            T.merge(x , x , y);
            T.merge(root , root , x);
        }
    }
}

int main()
{
    freopen("~input.txt" ,"r" , stdin);
    //while (~scanf("%s" , s))
        work();

    return 0;
}
