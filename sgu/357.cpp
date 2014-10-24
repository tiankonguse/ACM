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
#define N 100
#define M 100005

int E[N];
int d[N] , X , Y;
bool f[N];
queue<int> Q;

void update(int x , int w) {
    if (d[x] > w) {
        d[x] = w;
        if (!f[x]) {
            f[x] = 1;
            Q.push(x);
        }
    }
}

void work()
{
    scanf("%d%d%d%d",&E[1],&E[2],&E[3],&E[12]);
    scanf("%d%d%d%d",&E[4],&E[5],&E[6],&E[11]);
    scanf("%d%d%d",&E[7],&E[8],&E[9]);
    scanf("%d%d",&E[10],&E[0]);
    scanf("%d%d",&X , &Y);
    memset(d , 63 , sizeof(d));
    Q.push(X) , f[X] = 1 , d[X] = 0;
    while (!Q.empty()) {
        int x = Q.front() ; Q.pop(); f[x] = 0;
        if (E[12]) update((x + 1) % 100 , d[x] + 1);
        if (E[11]) update((x + 99) % 100 , d[x] + 1);
        for (int i = 0 ; i < 10 ; ++ i)
            if (E[i])
                update(i , d[x] + 1);
        if (!E[10]) continue;
        for (int i = 10 ; i < 100 ; ++ i)
            if (E[i / 10] && E[i % 10])
                update(i , d[x] + 3);
    }
    if (d[Y] == 0x3F3F3F3F)
        puts("-1");
    else
        printf("%d\n" , d[Y]);
}

int main()
{
    freopen("1.txt" , "r" , stdin);
    work();
    return 0;
}

