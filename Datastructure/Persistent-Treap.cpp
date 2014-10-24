#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;
typedef long long LL;
#define N 5000005
int root[50005] , c;
struct Treap
{
    int nodecnt;
    int L[N] , R[N] , cnt[N];
    char key[N];
    void clear() {
        nodecnt = 0;
    }
    Treap () {clear();}
    bool hey(int A , int B) {
        return (LL)rand() * (cnt[A] + cnt[B]) < (LL)cnt[A] * RAND_MAX;
    }
    int newnode(char val) {
        ++ nodecnt , L[nodecnt] = R[nodecnt] = 0;
        cnt[nodecnt] = 1 , key[nodecnt] = val;
        return nodecnt;
    }
    int copynode(int A) {
        if (!A) return 0;
        ++ nodecnt , L[nodecnt] = L[A] , R[nodecnt] = R[A];
        cnt[nodecnt] = cnt[A] , key[nodecnt] = key[A];
        return nodecnt;
    }
    void pushup(int x) {
        cnt[x] = 1;
        if (L[x]) cnt[x] += cnt[L[x]];
        if (R[x]) cnt[x] += cnt[R[x]];
    }
    void merge(int& p , int x , int y) {
        if (!x || !y) {
            p = 0;
            if (x) p = copynode(x);
            if (y) p = copynode(y);
        }
        else if ( hey(x , y) ) {
            p = copynode(x);
            merge(R[p] , R[x] , y) , pushup(p);
        }
        else {
            p = copynode(y);
            merge(L[p] , x , L[y]) , pushup(p);
        }
    }
    void split(int p , int& x , int& y , int size) {
        if (!size) {
             x = 0 , y = copynode(p);
             return;
        }
        if (cnt[L[p]] >= size) {
            y = copynode(p);
            split(L[p] , x , L[y] , size) , pushup(y);
        }
        else {
            x = copynode(p);
            split(R[p] , R[x] , y , size - cnt[L[p]] - 1) , pushup(x);
        }
    }
    void Build(char *A , int& p , int l , int r) {
        int mid = (l + r) >> 1;
        p = newnode(A[mid]);
        if (l < mid) Build(A , L[p] , l , mid - 1);
        if (mid < r) Build(A , R[p] , mid + 1 , r);
        pushup(p);
    }
    void print(int p) {
        if (L[p]) print(L[p]);
        putchar(key[p]); c += key[p] == 'c';
        if (R[p]) print(R[p]);
    }
};
Treap T;
int n , m;
char str[100005];
void work()
{
    int i , j , k , x , y , z;
    int version = 0;
    scanf("%d",&n);
    while (n --) {
        scanf("%d",&i);
        if (i == 1) {
            scanf("%d%s" , &j , str) , j -= c;
            T.Build(str , x , 0 , strlen(str) - 1);
            T.split(root[version] , y , z , j);
            T.merge(y , y , x);
            T.merge(root[++ version] , y , z);
        }
        else if (i == 2) {
            scanf("%d%d",&j,&k) , j -= c , k -= c;
            T.split(root[version] , x , y , j - 1);
            T.split(y , y , z , k);
            T.merge(root[++ version] , x , z);
        }
        else {
            scanf("%d%d%d",&i,&j,&k);
            i -= c , j -= c , k -= c;
            T.split(root[i] , x , y , j - 1);
            T.split(y , y , z , k);
            T.print(y);
            puts("");
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
