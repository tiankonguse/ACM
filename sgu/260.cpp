#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <cassert>
using namespace std;
typedef long long LL;
#define N 205
int n , p[N][N];
int a[N][N];

void print(int w[N][N]) {
    for (int i = 0 ; i < n ; ++ i) {
        for (int j = 0 ; j <= n ; ++ j)
            printf("%d " , w[i][j]);
        puts("");
    }
}

void work()
{
    int i , j , k , x;
    scanf("%d",&n);
    for (i = 0 ; i < n ; ++ i) {
        scanf("%d",&j);
        while (j --) {
            scanf("%d",&x) , p[x - 1][i] ^= 1;
        }
    }
    for (i = 0 ; i < n ; ++ i) {
        scanf("%d" , &p[i][n]);
    }
    memcpy(a , p , sizeof(a));
    int rank = 0;
    for (i = 0 ; i <= n ; ++ i) {
        int pivot = rank;
        while (pivot < n && !a[pivot][i])
            ++ pivot;
        if (pivot >= n) continue;
        for (j = 0 ; j <= n ; ++ j)
            swap(a[rank][j] , a[pivot][j]);
        for (k = 0 ; k < n ; ++ k) {
            if (k != rank && a[k][i])
                for (j = 0 ; j <= n ; ++ j) {
                    a[k][j] ^= a[rank][j];
                }
        }
        ++ rank;
    }
    for (i = 0 ; i < n ; ++ i) {
        if (!a[i][n]) continue;
        for (j = 0 ; j < n ; ++ j)
            if (a[i][j])
                break;
        if (j >= n) break;
    }
    if (i >= n) {
        vector<int> res;
        for (i = 0 ; i < n ; ++ i) {
            if (!a[i][n]) continue;
            for (j = 0 ; j < n ; ++ j)
                if (a[i][j])
                    break;
            res.push_back(j + 1);
        }
        printf("%d\n" , res.size());
        for (i = 0 ; i < res.size() ; ++ i)
            printf("%d%c" , res[i] , " \n"[i + 1 == res.size()]);
        return;
    }
    for (i = 0 ; i < n ; ++ i) {
        p[i][n] ^= 1;
    }
    memcpy(a , p , sizeof(a));
    rank = 0;
    for (i = 0 ; i <= n ; ++ i) {
        int pivot = rank;
        while (pivot < n && !a[pivot][i])
            ++ pivot;
        if (pivot >= n) continue;
        for (j = 0 ; j <= n ; ++ j)
            swap(a[rank][j] , a[pivot][j]);
        for (k = 0 ; k < n ; ++ k) {
            if (k != rank && a[k][i])
                for (j = 0 ; j <= n ; ++ j) {
                    a[k][j] ^= a[rank][j];
                }
        }
        ++ rank;
    }
    for (i = 0 ; i < n ; ++ i) {
        if (!a[i][n]) continue;
        for (j = 0 ; j < n ; ++ j)
            if (a[i][j])
                break;
        if (j >= n) break;
    }
    if (i >= n) {
        vector<int> res;
        for (i = 0 ; i < n ; ++ i) {
            if (!a[i][n]) continue;
            for (j = 0 ; j < n ; ++ j)
                if (a[i][j])
                    break;
            res.push_back(j + 1);
        }
        printf("%d\n" , res.size());
        for (i = 0 ; i < res.size() ; ++ i)
            printf("%d%c" , res[i] , " \n"[i + 1 == res.size()]);
        return;
    }
    puts("-1");
}

int main()
{
    freopen("1.txt" , "r" , stdin);
    work();
    return 0;
}

