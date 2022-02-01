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
#define N 605
int n , m , K;
int f[N][N] , B[N];
vector< pair<int , int> > T[N];
vector<int> res;

void print(int i , int j) {
    if (i == 0 && j == 0) return;
    if (f[i - 1][j] == f[i][j]) {
        print(i - 1 , j);
        return;
    }
    for (int k = 0 , x = B[i - 1] ; k < T[i - 1].size() && j - k - 1 >= 0 ; ++ k) {
        x += T[i - 1][k].first;
        if (f[i - 1][j - k - 1] + x == f[i][j]) {
            print(i - 1 , j - k - 1);
            while (k >= 0)
                res.push_back(T[i - 1][k].second) , -- k;
            return;
        }
    }
}

void work()
{
    int i , j , k , x , y;
    scanf("%d%d%d",&n,&m,&K);
    for (i = 0 ; i < m ; ++ i)
        scanf("%d",&B[i]);
    for (i = 1 ; i <= n ; ++ i) {
        scanf("%d%d",&x,&y);
        T[y - 1].push_back(make_pair(x , i));
    }
    memset(f , 63 , sizeof(f));
    f[0][0] = 0;
    for (i = 0 ; i < m ; ++ i) {
        sort(T[i].begin() , T[i].end());
        for (j = 0 ; j <= n ; ++ j) {
            if (f[i][j] >= 0x3F3F3F3F)
                continue;
            f[i + 1][j] = min(f[i + 1][j] , f[i][j]);
            for (k = 0 , x = B[i] ; k < T[i].size() && j + k + 1 <= n ; ++ k) {
                x += T[i][k].first;
                f[i + 1][j + k + 1] = min(f[i + 1][j + k + 1] , f[i][j] + x);
            }
        }
    }
    for (i = n ; i >= 0 ; -- i)
        if (f[m][i] <= K)
            break;
    printf("%d\n" , i);
    print(m , i);
    for (i = 0 ; i < res.size() ; ++ i) {
        printf("%d" , res[i]);
        if (i + 1 < res.size()) putchar(' ');
    }
    puts("");
}

int main()
{
    work();
    return 0;
}

