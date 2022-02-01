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
int a[maxn];
int main(){
    int n;
    while(~scanf("%d", &n) && n){
        for(int i=0;i<n;i++){
            scanf("%d", &a[i]);
        }
        printf("%d ", a[0]);
        for(int i=1;i<n;i++){
            if(a[i] != a[i - 1]) printf("%d ", a[i]);
        }
        puts("$");
    }
    return 0;
}
