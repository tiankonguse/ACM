#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <stack>
#include <cstring>
#include <cctype>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long LL;

#define N 100005
#define M 1000005

char s[N];
stack<bool> S;

void work()
{
    scanf("%s" , s);
    for (int i = 0 ; s[i] ; ++ i) {
        if (s[i] == '<') {
            ++ i;
            if (s[i] == '/') {
                ++ i;
                if (s[i] == 'U') {
                    S.pop();
                    i += 2;
                } else {
                    S.pop();
                    i += 4;
                }
            } else {
                if (s[i] == 'U') {
                    i += 2;
                    S.push(1);
                } else {
                    i += 4;
                    S.push(0);
                }
            }
        } else {
            if (S.empty())
                putchar(s[i]);
            else if (S.top())
                putchar(toupper(s[i]));
            else
                putchar(tolower(s[i]));
        }
    }
}

int main()
{
    work();
    return 0;
}
