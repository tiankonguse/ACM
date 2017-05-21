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
#define maxn 10010
using namespace std;
char str[maxn];
int fun(){
    int n = strlen(str);
    int i = 0, j = 1, len = 0, x, y;
    while(i < n && j < n && len < n){
      //  printf("%d, %d %d\n", i, j, len);
        x = i + len; if(x >= n) x -= n;
        y = j + len; if(y >= n) y -= n;
        if(str[x] == str[y]) len++;
        else if(str[x] < str[y]){
            j += len + 1;
            len = 0;
        }
        else{
            i = j;
            j++;
            len = 0;
        }
    }
    return i;
}
int main(){
    int t;
    for(scanf("%d", &t);t--;){
        scanf(" %s", str);
        printf("%d\n", fun() + 1);
    }
    return 0;
}
