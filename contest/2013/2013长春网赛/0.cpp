#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <queue>
#include <cstdio>
#include <cmath>
#include <stack>
#define PI acos(-1.0)
#define inf 0x3f3f3f3f
#define E exp(double(1))
#define maxn 110000
using namespace std;
typedef long long  LL;
const int P=1000010;
int next[P];
char str[P];
char pat[P];
//next[i]的意义
//s为匹配串,t为s的前i个字符组成的子串
//t = s[0]s[1]...s[i-1]
//设串s[0]s[1]...s[k]和串s[i-1-k]s[i-1-(k-1)]...s[i-1]相等，
//next[i]就是这样的k的最大值
//

void get_next(char *pat) {
    memset(next,-1,sizeof(next));
    for(int i=1,k; pat[i]; ++i) {
        for(k=next[i-1]; k>=0 && pat[i]!=pat[k+1]; k=next[k]);
        if(pat[k+1] == pat[i])next[i]=k+1;
    }
}

//返回匹配的第一个位置
//返回匹配的个数  ans
int kmp1(char* str, char* pat) {
    get_next(pat);
    int len = strlen(pa);
    int i=0, j=0;
    int ans = 0;
    while(str[i]) {
        if( pat[j] == str[i] ) {
            ++i,++j;
        } else if(j == 0) {
            ++i;
        } else {
            j = next[j-1]+1;
        }
    }
    while(j != -1){
        if()
    }
    printf("%d %d\n",j,next[j-1]+1);
    return j;
}
int main() {
    int n;
    scanf("%d",&n);
    while(n--) {
        scanf("%s",str);
        strcpy(pat,str+1);
        int l = kmp1(pat, str);
//        printf("%d\n",l);
    }
    return 0;
}
