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
#define maxl 10100
#define maxn 10010
using namespace std;
char str[maxl];
char word[maxn][85];
int lens[maxn];
int dp[maxn];
int pre[maxn];
int rl[maxn];
int lines[maxn];
int w;

int fun(int s, int num){
    num--;
    if(s + num > w) return -1;
    if(num == 0){
        if(s == w) return 0;
        else return 500;
    }
    s = w - s;
    int a = s / num, b = s % num;
    return b * a * a + (num - b) * (a - 1) * (a - 1);
}
void output(int l, int r, int s, int num){
    num--;
    if(num == 0) { puts(word[l]); return; }
    s = w - s;
    int a = s / num, b = s % num;
    printf("%s", word[l++]);
    for(int i=0;i<num-b;i++){
        for(int j=0;j<a;j++) printf(" ");
        printf("%s", word[l++]);
    }
    for(int i=0;i<b;i++){
        for(int j=0;j<a+1;j++) printf(" ");
        printf("%s", word[l++]);
    }
    puts("");
}

int main(){
    int n, p, l;
    while(scanf("%d", &w) && w){
        lens[n = 0] = 0;
        getchar();
        while(gets(str)){
            if(strlen(str) == 0) break;
            p = 0;
            while(str[p]){
                sscanf(str + p, "%s", word[++n]);
              //  puts(word[n]);
                lens[n] = lens[n - 1] + (l = strlen(word[n]));
                p += l;
                while(str[p] == ' ') p++;
            }
        }
        //cout<<n<<endl;
        memset(dp, 0x3f, sizeof(dp));
        int mx = 0, tmx, v, res = inf, ri, pos;
        dp[0] = 0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=i;j++){
                v = fun(lens[i] - lens[i - j], j);
                if(v == -1) continue;
                if(dp[i - j] + v < dp[i]){
                    dp[i] = dp[i - j] + v;
                    pre[i] = i - j;
                    lines[i] = lines[i - j] + 1;
                }
                else if(dp[i - j] + v == dp[i]){
                    if(lines[i - j] + 1 < lines[i]){
                        lines[i] = lines[i - j] + 1;
                        pre[i] = i - j;
                    }
                }
            }
        }

        ri = 0;
        pos = n;
        rl[0] = 0;
        while(pos){
            rl[++ri] = pos;
            pos = pre[pos];
        }
        rl[ri + 1] = 0;

        int left, right;
        for(int i=ri;i>=1;i--){
            left = rl[i + 1] + 1, right = rl[i];
            output(left, right, lens[right] - lens[left - 1], right - left + 1);
        }
        puts("");
    }
    return 0;
}
