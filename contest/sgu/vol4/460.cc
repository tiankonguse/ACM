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

using namespace std;
char str[111];
int main() {
    int T;
    for (scanf("%d", &T); T--; ) {
        scanf(" %s", str);
        int len = strlen(str);
        if ((len >= 2 && str[len - 1] == 'h' && str[len - 2] == 'c') ||
            (str[len - 1] == 'x') ||
            (str[len - 1] == 's') ||
            (str[len - 1] == 'o') ) {
                printf("%ses\n", str);
            }
        else if (str[len - 1] == 'f') {
            str[len - 1] = 0;
            printf("%sves\n", str);
        }
        else if( len >= 2 && str[len - 1] == 'e' && str[len - 2] == 'f') {
            str[len - 2] = 0;
            printf("%sves\n", str);
        }
        else if (str[len - 1] == 'y') {
            str[len - 1] = 0;
            printf("%sies\n", str);
        }
        else printf("%ss\n", str);
    }
    return 0;
}
