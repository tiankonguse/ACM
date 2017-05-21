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

    while (gets(str)) {
        int len = strlen(str);
        bool over = false;
        for (int i = 0; i < len; ++i) {
            if (i + 3 <= len && str[i] == 'E' && str[i + 1] == 'O' && str[i + 2] == 'F') {
                over = true;
                break;
            }
            if (i + 2 <= len && str[i] == 'd' && str[i + 1] == 'd') {
                putchar('p');
                ++i;
            }
            else if (i + 4 <= len && str[i] == 'p' && str[i + 1] == 'i' && str[i + 2] == 'n' && str[i + 3] == 'k') {
                printf("floyd");
                i += 3;
            }
            else if (i + 2 <= len && str[i] == 'e' && str[i + 1] == 'i') {
                if (i > 0 && str[i - 1] == 'c') {
                    putchar('e');
                    continue;
                }
                printf("ie");
                ++i;
            }
            else if (islower(str[i]) || str[i] == ' ') putchar(str[i]);
        }
        if (over) break;
        puts("");
    }
    return 0;
}
