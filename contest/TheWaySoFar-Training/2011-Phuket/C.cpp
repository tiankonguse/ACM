#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>
#include <stack>
#include <cmath>
using namespace std;
typedef long long LL;
#define N 205

int n , m , a[111];
char s[N];
void work()
{
    int i , j , k , x , y;
    char ch;
    scanf("%d%d",&n,&m); getchar();
    for (i = 0 ; i < m ; ++ i) {
        a[i] = 0;
        gets(s);
        for (j = 0 ; s[j] ; ++ j) {
            if (isdigit(s[j])) {
                x = 0 , k = j;
                while (isdigit(s[k]))
                    x *= 10 , x += s[k] - '0' , ++ k;
                a[i] |= (1 << x - 1) , j = k - 1;
                //printf("%d " , x);
            }
        }
        //printf("\n");
    }
    for (i = 0 ; i < 1 << n ; ++ i) {
        x = 0;
        for (j = 0 ; j < m ; ++ j) {
            if (((i & a[j]) == a[j]) || ((i & a[j]) == 0))
                break;
        }
        if (j >= m)
            break;
    }
    putchar(i < 1 << n ? 'Y' : 'N');
}

int main()
{
    int _; scanf("%d",&_); while (_ --)
        work();
    return 0;
}
