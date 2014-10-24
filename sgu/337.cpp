#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <vector>
#include <queue>
#include <cmath>
#include <cassert>
using namespace std;
typedef long long LL;

#define N 2005
int n , m;
char s[N + N];
char ans[N];
int sum[N + N];
void work() {
    int i , j;
    scanf("%d%s" , &m , s);
    n = strlen(s);
    for (i = n ; i < n + n ; ++ i)
        s[i] = s[i - n];
    ans[0] = '{';
    for (j = n / 2 ; j >= 0 ; -- j) {
        for (i = 0 ; i + j < n + n ; ++ i)
            sum[i + 1] = sum[i] + (s[i] != s[i + j]);
        bool found = 0;
        for (i = j ; i < j + n ; ++ i) {
            if (sum[i] - sum[i - j] <= m) {
                char t = s[i + j];
                s[i + j] = 0;
                if (strcmp(s + i - j , ans) < 0)
                    strcpy(ans , s + i - j);
                s[i + j] = t;
                found = 1;
            }
        }
        if (found)
            break;
    }
    puts(ans);
}

int main(){
    freopen("1.txt" , "r" , stdin);
        work();
    return 0;
}
