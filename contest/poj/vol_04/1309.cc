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
    int n, t;
    bool flag;
    while(~scanf("%d", &n) && n >= 0){
        for(int i = min(n, 20); i >= 1; i--){
            flag = true;
            t = n;
            for(int j = 1; j <= i; j++){
                if(t % i == 1){
                    t = (t - 1) / i * (i - 1);
                }
                else{
                    flag = false;
                    break;
                }
            }
            flag &= (t % i == 0);
            if(flag){
                printf("%d coconuts, %d people and 1 monkey\n", n, i);
                break;
            }
        }
        if(!flag) printf("%d coconuts, no solution\n", n);
    }
    return 0;
}
