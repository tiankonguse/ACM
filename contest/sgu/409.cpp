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
#include <set>
#include <map>
typedef long long LL;
typedef unsigned long long ULL;
using namespace std;
#define N 22
int n , K;
char s[N * N][N * N];
void work() {
    int i , j , k , l;
    cin >> n >> K;
    for (i = 0 ; i < n * n ; ++ i)
        for (j = 0 ; j < n * n ; ++ j)
            s[i][j] = '.';
    for (j = 0 , k = 0 ; j < n * n ; ++ j , k += n , k >= n * n ? k -= n * n - 1 : 0){
        for (i = 0 ; i < K ; ++ i)
            s[j][(k + i) % (n * n)] = '*';
    }
    for (i = 0 ; i < n * n ; ++ i)
        puts(s[i]);
}

int main()
{
    //freopen("~input.txt" , "r" , stdin);
    work();
    return 0;
}

