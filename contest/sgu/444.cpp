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
#define N 205
int x , y;
int d[1000000];
void work()
{
    int cnt = 0;
    memset(d , -1 , sizeof(d));
    x %= y;
    d[x] = cnt ++;
    while (1) {
        x *= 10;
        //printf("%d" , x / y);
        x %= y;
        if (~d[x]) {
            printf("%d %d\n" , d[x] , cnt - d[x] - (x == 0));
            break;
        }
        d[x] = cnt ++;
    }
}

int main()
{
    //freopen("1.txt" , "r" , stdin);
    while (cin >> x >> y)
        work();
    return 0;
}

