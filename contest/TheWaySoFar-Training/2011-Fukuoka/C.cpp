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
int n , m;
string txt[N] , word[N];
string ans;
int cnt;
int res[26] , tmp[26];

bool cmp(string A , string B) {
    if (A.size() != B.size())
        return A.size() > B.size();
    return A < B;
}

void dfs(int k) {
    if (k >= m) {
        ++ cnt;
        memcpy(res , tmp , sizeof(res));
        return;
    }
    if (cnt > 1) return;
    int i , j , t[26];
    for (i = 0 ; i < n ; ++ i) {
        if (txt[k].size() != word[i].size()) continue;
        memcpy(t , tmp , sizeof(tmp));
        for (j = 0 ; j < txt[k].size() ; ++ j) {
            if (tmp[txt[k][j] - 'A'] != -1 && tmp[txt[k][j] - 'A'] != word[i][j] - 'A') break;
            if (tmp[word[i][j] - 'A'] != -1 && tmp[word[i][j] - 'A'] != txt[k][j] - 'A') break;
            tmp[txt[k][j] - 'A'] = word[i][j] - 'A';
            tmp[word[i][j] - 'A'] = txt[k][j] - 'A';
        }
        if (j >= txt[k].size()) {
            dfs(k + 1);
        }
        if (cnt > 1) return;
        memcpy(tmp , t , sizeof(tmp));
    }
}

void work()
{
    int i;
    for (i = 0 ; i < n ; ++ i) {
        scanf("%s" , str);
        word[i] = str;
    }
    sort(word , word + n , cmp);
    m = 0;
    ans = "";
    while (1) {
        scanf("%s" , str);
        if (str[strlen(str) - 1] == '.') {
            ans += str;
            str[strlen(str) - 1] = 0;
            txt[m ++] = str;
            break;
        }
        ans += str , ans += " ";
        txt[m ++] = str;
    }
    sort(txt , txt + m , cmp);
    cnt = 0;
    memset(tmp , -1 , sizeof(tmp));
    dfs(0);
    if (cnt > 1)
        puts("-.");
    else {
        for (int i = 0 ; i < ans.size() ; ++ i)
            if (isalpha(ans[i]))
                putchar(res[ans[i] - 'A'] + 'A');
            else
                putchar(ans[i]);
        puts("");
    }
}


int main()
{
    freopen("1.txt" , "r" , stdin);
    while (scanf("%d",&n) , n)
        work();
    return 0;
}


