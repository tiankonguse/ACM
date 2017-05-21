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
#define maxl 105
using namespace std;
char str[maxl];
int mp[256];
char mpinv[256];
int change(char *s){
    int d = 1, res = 0;
    for(int i=0;s[i];i++){
        if(s[i] >= '2' && s[i] <= '9'){
            d = s[i] - '0';
        }
        else{
            res += d * mp[ s[i] ];
            d = 1;
        }
    }
    return res;
}
int num[5];
void output(int x){
    for(int i=3;i>=0;i--){
        num[i] = x % 10;
        x /= 10;
    }
    for(int i=0;i<4;i++){
        if(num[i] == 1) printf("%c", mpinv[i]);
        else if(num[i] > 1) printf("%d%c", num[i], mpinv[i]);
    }
    puts("");
}
char str1[maxl], str2[maxl];
int main(){
    mp['m'] = 1000, mp['c'] = 100, mp['x'] = 10, mp['i'] = 1;
    mpinv[0] = 'm', mpinv[1] = 'c', mpinv[2] = 'x', mpinv[3] = 'i';
    int n;
    while(~scanf("%d", &n)){
        for(int i=0;i<n;i++){
            scanf(" %s %s", str1, str2);
            output(change(str1) + change(str2));
        }
    }
    return 0;
}
