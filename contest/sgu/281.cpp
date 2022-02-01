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
#define N 105
int n;
map<string , int> hash;
string s[50005];
char str[N];
int rank[50005];
void work()
{
    int i , j , k;
    scanf("%d",&n);
    for (i = 0 ; i < n ; ++ i) {
        scanf("%s" , str);
        s[i] = str;
        hash[str] = i;
    }
    for (i = 0 ; i < n ; ++ i) {
        scanf("%s" , str);
        rank[i] = hash[str];
    }
    k = 0 , j = 0;
    for (i = 0 ; i < n ; ++ i) {
        k = max(k , rank[i]);
        if (k == i) {
            sort(s + j , s + i + 1);
            j = i + 1;
        }
    }
    for (i = 0 ; i < n ; ++ i)
        puts(s[i].c_str());
}

int main()
{
    work();
    return 0;
}

