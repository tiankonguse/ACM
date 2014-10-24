#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <cmath>
using namespace std;
typedef long long LL;
#define N 105
int n , m , K , S , B[N] , A[N];
char s[N] , t[N];
void work()
{
    int i , j , k , x , y , z;
    scanf("%d%d",&n,&m);
    for (i = 1 ; i <= m ; ++ i) {
        scanf("%d",&B[i]);
    }
    int cnt = 0;
    while (n --) {
        getchar();
        gets(s);
        scanf("%d" ,&K);
        for (i = 0 ; i < K ; ++ i)
            scanf("%d",&A[i]);
        int sum = 0;
        for (i = 0 ; i < K ; ++ i) {
            scanf("%d%d%d",&x,&y,&z);
            if (B[A[i]] < x)
                sum += 2;
            else if (B[A[i]] < y)
                sum += 3;
            else if (B[A[i]] < z)
                sum += 4;
            else
                sum += 5;
        }
        scanf("%d" , &K);
        while (K --) {
            getchar();
            gets(t);
            scanf("%d" , &S);
            if (sum >= S) {
                printf("%s %s\n" , s , t);
                ++ cnt;
            }
        }
    }
    if (!cnt) {
        puts("Army");
    }
}

int main()
{
    work();
    return 0;
}
