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
#define maxn 5
using namespace std;
int mat[3][3];
int a[3];

int main() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            scanf("%d", &mat[i][j]);        
        }
        sort(mat[i], mat[i] + 3);
        a[i] = mat[i][1];
    }  
    sort(a, a + 3);
    printf("%d\n", a[1]);
    //system("pause");
    return 0;
}
