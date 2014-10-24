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

int n , m , K;
deque<string> Q , S;
bool rev;
char str[20];
void work()
{
    int i;
    scanf("%d%d%d",&n,&m,&K);
    if (n > K) {
        for (i = 1 ; i <= K ; ++ i)
            scanf("%s" , str) , Q.push_back(str);
        for (i = K + 1 ; i <= n ; ++ i)
            scanf("%s" , str) , S.push_back(str);
    } else {
        for (i = 1 ; i <= n ; ++ i)
            scanf("%s" , str) , Q.push_back(str);
    }
    while (m --) {
        scanf("%s" , str);
        if (*str == 'A') {
            str[strlen(str) - 1] = 0;
            if (!rev) {
                if (Q.size() < K)
                    Q.push_front(str + 4);
                else {
                    if (!K) {
                        S.push_front(str + 4);
                    } else {
                        S.push_front(Q.back()) , Q.pop_back();
                        Q.push_front(str + 4);
                    }
                }
            } else {
                if (Q.size() < K)
                    Q.push_back(str + 4);
                else {
                    if (!K) {
                        S.push_front(str + 4);
                    } else {
                        S.push_front(Q.front()) , Q.pop_front();
                        Q.push_back(str + 4);
                    }
                }
            }
        }
        else
            rev ^= 1;
    }
    if (rev) {
        while (!Q.empty())
            puts(Q.back().c_str()) , Q.pop_back();
        while (!S.empty())
            puts(S.front().c_str()) , S.pop_front();
    } else {
        while (!Q.empty())
            puts(Q.front().c_str()) , Q.pop_front();
        while (!S.empty())
            puts(S.front().c_str()) , S.pop_front();
    }
}

int main()
{
    freopen("1.txt" , "r" , stdin);
    work();
    return 0;
}


