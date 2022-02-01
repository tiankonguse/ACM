#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
#define M 400005
struct Trie
{
    int cnt;
    int ch[M][26] , num[26];
    int newnode()
    {
        memset(ch[cnt] , 0 , sizeof(ch[cnt]));
        return cnt ++;
    }
    void clear()
    {
        cnt = 0;
        memset(num , 0 , sizeof(num));
        newnode();
    }
    void insert(char *str)
    {
        int x = 0;
        for (char *i = str ; *i ; ++ i)
        {
            int c = *i - 'a';
            if (!ch[x][c])
            {
                if (i != str)
                    ++ num[c];
                ch[x][c] = newnode();
            }
            x = ch[x][c];
        }
    }
}Pre , Suf;
int n ;
char s[10000][50];
void work()
{
    int i , j; bool f[26] = {};
    Pre.clear() , Suf.clear();
    for (i = 0 ; i < n ; ++ i)
        scanf("%s" , s[i]) , Pre.insert(s[i]);
    LL ans = 0;
    for (i = 0 ; i < n ; ++ i)
    {
        j = strlen(s[i]);
        reverse(s[i] , s[i] + j) , Suf.insert(s[i]);
        if (j == 1 && !f[*s[i] - 'a'])
            ++ ans , f[*s[i] - 'a'] = 1;
    }
    ans += (LL)(Pre.cnt - 1) * (Suf.cnt - 1);
    //cout << ans << endl;
    for (i = 0 ; i < 26 ; ++ i)
        ans -= (LL)Pre.num[i] * Suf.num[i];
    cout << ans << endl;

}
int main()
{
    freopen("~input.txt" , "r" , stdin);
//    int _; scanf("%d",&_); while (_ --)
    while (~scanf("%d",&n))
        work();
    return 0;
}
