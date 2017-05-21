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

int main(){
    int m, n;
    while(~scanf("%d%d", &m, &n)){
        if(n > m) swap(n, m);
        if(n == 1) printf("%d\n", (m + 1) >> 1);
        else if(n == 2){
            switch(m % 3){
                case 0: puts("2"); break;
                case 1:
                case 2: puts("1"); break;
            }
        }
        else if(n % 3 == 0 || m % 3 == 0) puts("2");
        else puts("1");
    }
    return 0;
}
