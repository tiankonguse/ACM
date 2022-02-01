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
#define N 5005
#define M 100005

pair<int , int> a[N];
int cnt , n;

void work()
{
    int L , R , i , j;
    char str[5];
    while (~scanf("%s%d%d",str , &L , &R)) {
        if (*str == '+') {
            cnt = 0;
            for (i = 0 ; i < n ; ++ i)
                if (L <= a[i].first && a[i].second <= R)
                    ++ cnt;
            printf("%d\n" , cnt);
            a[n ++] = make_pair(L , R);
        } else {
            for (i = 0 ; i < n ; ++ i)
                if (a[i].first == L && a[i].second == R)
                    break;
            if (i < n) {
                for ( ; i + 1 < n ; ++ i)
                    a[i] = a[i + 1];
                -- n;
            }
        }
    }
}

int main()
{
    freopen("1.txt" , "r" , stdin);
    work();
    return 0;
}

