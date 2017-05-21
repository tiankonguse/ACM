#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <set>
#include <queue>
#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
#define maxn 111
using namespace std;

int main(){
    int n, a, c, mx, res;
    while(~scanf("%d", &n)){
        mx = 0;
        for(int i=0;i<n;i++){
            c = 0;
            for(int j=0;j<n;j++){
                scanf("%d", &a);
                if(a == 3) c++;
            }
            if(c > mx){
                mx = c;
                res = i + 1;
            }
        }
        printf("%d\n", res);

    }
    return 0;
}
