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
#define maxn 1010
using namespace std;
char dat[30][10] = {
    "4",
    "|3",
    "(",
    "|)",
    "3",
    "|=",
    "6",
    "#",
    "|",
    "_|",
    "|<",
    "|_",
    "|\\/|",
    "|\\|",
    "0",
    "|0",
    "(,)",
    "|?",
    "5",
    "7",
    "|_|",
    "\\/",
    "\\/\\/",
    "><",
    "-/",
    "2"
};
char str[maxn], enc[maxn];
int ls[30];
int dp[maxn];
bool check(int k, int p){
   // cout<<"ch("<<k<<","<<p<<")\n";
    if(p < 0) return false;
    for(int i=0;i<ls[k];i++){
        if(enc[p + i] != dat[k][i]) return false;
    }
    return true;
}
int main(){
    for(int i=0;i<26;i++) ls[i] = strlen(dat[i]);
    while(~scanf("%s", str)){
        if(str[0] == 'e') break;
        int len = strlen(str);
        int el = 0;
        for(int i=0;i<len;i++){
            memcpy(enc + el, dat[str[i] - 'A'], sizeof(dat[str[i] - 'A']));
            el += ls[str[i] - 'A'];
        }
        enc[el] = '\0';
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
      //  puts(enc);
        for(int i=1;i<=el;i++){
            for(int j=0;j<26;j++){
                if(check(j, i - ls[j])){
                   // cout<<j<<","<<i-ls[j]<<endl;
                    dp[i] += dp[i - ls[j]];
                }
            }
        }
       // for(int i=0;i<=el;i++)printf("%d ",dp[i]);puts("");
        printf("%d\n", dp[el]);
    }
    return 0;
}
