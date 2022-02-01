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
long long dat[15] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000, 10000000000LL};
int main(){
    int f, r, c, p;
    int fl, rl, fr, rr;
    while(~scanf("%d-%d", &f, &r)){
        for(p=1;p<=10;p++){
            fl = f / dat[p], fr = f % dat[p];
            rl = r / dat[p], rr = r % dat[p];
            c = rr;
            if(fr < c){
                if(fl == rl) break;
            }
            else{
                if(fl + 1 == rl) break;
            }
        }
        printf("%d-%0*d\n", f, p, c);
    }
    return 0;
}
