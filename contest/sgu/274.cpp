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
using namespace std;
typedef long long LL;

#define N 105
char str[N];
bool isletter(int i) {
    return isalpha(str[i]);
}
bool issymbol(int i) {
    return isletter(i) || isdigit(str[i]) || (str[i] == '-') || (str[i] == '_');
}
int w[N][N];
bool isword(int i , int j) {
    if (i == j) return issymbol(i);
    if (~w[i][j])
        return w[i][j];
    return w[i][j] = isword(i + 1, j) && issymbol(i);
}
int p[N][N];
bool isprefix(int i , int j) {
    if (~p[i][j])
        return p[i][j];
    p[i][j] = isword(i , j);
    for (int k = i + 1 ; k < j ; ++ k)
        if (str[k] == '.')
            p[i][j] |= isprefix(i , k - 1) && isword(k + 1 , j);
    return p[i][j];
}
bool isdomain(int i , int j) {
    if (j - i == 1) {
        return isletter(i) && isletter(j);
    } else if (j - i == 2) {
        return isletter(i) && isletter(j) && isletter(i + 1);
    }
    return 0;
}
bool issuffix(int i , int j) {
    bool res = 0;
    for (int k = i + 1 ; k < j ; ++ k)
        if (str[k] == '.')
            res |= isprefix(i , k - 1) && isdomain(k + 1 , j);
    return res;
}
void work()
{
    gets(str + 1);
    memset(p , -1 , sizeof(p));
    memset(w , -1 , sizeof(w));
    bool res = 0; int len = strlen(str + 1);
    for (int k = 2 ; k < len ; ++ k)
        if (str[k] == '@')
            res |= isprefix(1 , k - 1) && issuffix(k + 1 , len);
    puts(res ? "YES" : "NO");
}


int main()
{
    int _; scanf("%d\n",&_); while (_ --)
        work();
    return 0;
}
