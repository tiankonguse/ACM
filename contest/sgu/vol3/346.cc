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
int arr[10];
char str[10];
int main() {
    for (int i = 0; i < 7; ++i) scanf("%d", &arr[i]);
    scanf(" %s", str);
    int ret = 0;
    if (str[0] == 'C' || str[0] == 'N') {
        int ret = 0;
        int mx = -1;
        for (int i = 6; i > 0; --i) {
            if (arr[i]) {
                mx = i;
                break;
            }
        }
        if (mx == -1) ret = arr[0];
        else ret += (1 + mx + 1) * arr[0];
        for (int i = 1; i < 7; ++i) if (arr[i]) ret += i + 1;
        printf("%d\n", ret);
    }
    else if (str[0] == 'R') {
        int ret = 0;
        int mx = -1;
        for (int i = 6; i > 0; --i) {
            if (arr[i]) {
                mx = i;
                break;
            }
        }
        if (mx == -1) ret = arr[0];
        else ret += (1 + mx + 1) * arr[0] + 1 + mx;
        for (int i = 1; i < 7; ++i) if (arr[i]) ret += i + 1;
        printf("%d\n", ret);
    }
    return 0;
}
