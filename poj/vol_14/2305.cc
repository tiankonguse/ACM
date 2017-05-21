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
#define MAXN 1111
using namespace std;
char p[MAXN],m[MAXN];
int ans[MAXN];
int main(){
    int b;
    while(scanf("%d",&b) && b){
        scanf(" %s %s",p,m);
        long long res = 0, mod = 0;
        int lp = strlen(p), lm = strlen(m), cnt = 0;
        for(int i=0;i<lm;i++){
            mod = mod*b + (m[i]-'0');
        }
        for(int i=0;i<lp;i++){
            res = (res * b + (p[i]-'0')) % mod;
        }
        while(res){
            ans[cnt++] = res % b;
            res /= b;
        }
        if(cnt == 0)printf("0");
        else{
            for(int i=cnt-1;i>=0;i--){
                printf("%d",ans[i]);
            }
        }
        printf("\n");
    }
    return 0;
}
