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
#define maxn 18
using namespace std;
int n, cnt;
char res[maxn];
void dfs(int d, int s, int p){
   // printf("dfs(%d, %d, %d)\n", d, s, p); system("pause");
    if(d == n){
        if(s == 0){
            if(cnt < 20){
                putchar('1');
                for(int i=1;i<n;i++){
                     printf(" %c %d", res[i], i + 1);
                }
                puts("");
            }
            cnt++;
        }
        return;
    }
    res[d] = '+';
    dfs(d + 1, s + d + 1, d + 1);
    res[d] = '-';
    dfs(d + 1, s - d - 1, - d - 1);
    res[d] = '.';
    int t, k;
    if(p < 0) k = - d - 1;
    else k = d + 1;
    if(d >= 9) t = p * 100 + k;
    else t = p * 10 + k;
    dfs(d + 1, s - p + t, t);
}
int main(){
    while(~scanf("%d", &n)){
        cnt = 0;
        dfs(1, 1, 1);
        printf("%d\n", cnt);
    }
    return 0;
}
