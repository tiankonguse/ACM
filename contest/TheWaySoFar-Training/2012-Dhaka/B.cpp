#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <cmath>
#include <cassert>
using namespace std;
typedef long long LL;

#define N 30
int cnt[N] , ca;
char s[N*10];

void work(int X , int l , int r) {
    ++ cnt[X];
    if (l > r) return;
    for (int i = l , j ; i <= r ; ++ i) {
        for (j = i + 1 ; j <= r ; ++ j)
            if (s[i] == s[j])
                break;
        ++ cnt[X];
        work(s[i] - 'A' , i + 1 , j - 1);
        i = j;
    }
}


int main(){
    //freopen("1.txt","r",stdin);
    int T;
    scanf("%d",&T);
    for (;T;--T){
        scanf("%s" , s);
        memset(cnt , 0 , sizeof(cnt));
        int L = strlen(s) ;
        work(*s - 'A' , 1 , L - 2);
        -- cnt[*s - 'A'];
        printf("Case %d\n" , ++ ca);
        for (int i = 0 ; i < 26 ; ++ i) {
            if (cnt[i]) {
                printf("%c = %d\n" , 'A' + i , cnt[i]);
            }
        }
    }
}
