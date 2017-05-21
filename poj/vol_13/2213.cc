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
#define maxn 33
using namespace std;
char str[maxn];

int main(){
    int T, k, pos;
    scanf("%d", &T);
    for(int _t = 1; _t <= T; _t++) {
        scanf("%d %s", &k, str);
        pos = 0;
        for(int i = 0; i < k; i++) {
            if(str[k - i - 1] == '1'){
                pos = (1 << i) - pos + (1 << i) - 1;
            }
        }
        printf("Poslanec %d se posadi na sedadlo cislo %d.\n", _t, pos + 1);
    }
    return 0;
}
