#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
#define maxn 2000100
using namespace std;
char str[maxn];
bool check(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == ' ';
}
void print(char c) {
    if (c == ' ' || c == '$') {
        return;
    }
    else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
        printf("<i>%c</i>", c);
    }
    else if (c == '(' || c == ')' || (c >= '0' && c <= '9')) putchar(c);
    else if (c == '+' || c == '-' || c == '*' || c == '/') {
        printf("&nbsp;%c&nbsp;", c);
    }
}

int len;
void dfs(int &pos) {
    char ch;
    for (; pos < len; ++pos) {
        ch = str[pos];
        if (ch == '}') {
            return;
        }
        if (ch == '_') {
            ++pos;
            if (str[pos] == '{') {
                printf("<sub>");
                dfs(++pos);
                printf("</sub>");
            }
            else {
                printf("<sub>");
                ch = str[pos];
                print(ch);
                printf("</sub>");
            }
        }
        else if (ch == '^') {
                ++pos;
                if (str[pos] == '{') {
                    printf("<sup>");
                    dfs(++pos);
                    printf("</sup>");
                }
                else {
                    printf("<sup>");
                    ch = str[pos];
                    print(ch);
                    printf("</sup>");
                }
        }
        else if (check(ch) && ch != ' ') {
            printf("<i>");
            if (ch != ' ') putchar(ch);
            while (check( ch = str[++pos] )) if (ch != ' ') putchar(ch);
            printf("</i>");
            --pos;
        }
        else print(ch);
    }
}
int main() {
    while (gets(str)) {
        len = strlen(str);
        int p = 0;
        dfs(p);
        puts("");
    }
    return 0;
}

