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
#define maxn 100100
using namespace std;
bool mark[maxn];
int list[maxn];
char res[20];
int main(){
    int a, b, c, s, cnt;
    bool f1, f2;
    while(scanf("%d", &a) && a){
        cnt = 0;
        memset(mark, false, sizeof(mark));
        for(scanf("%d%d%d", &b, &c, &s);!mark[s];s=(a*s+b)%c){
            list[cnt++] = s;
            mark[s] = true;
        }
        for(int i=0;i<16;i++){
            f1 = f2 = false;
            for(int j=0;j<cnt;j++){
                if((list[j] & (1 << i)) == 0) f1 = true;
                else f2 = true;
            }
            if(f1 && f2) res[15 - i] = '?';
            else if(f1) res[15 - i] = '0';
            else res[15 - i] = '1';
        }
        res[16] = 0;
        puts(res);
    }
    return 0;
}
