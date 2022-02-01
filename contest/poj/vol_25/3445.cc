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
void print(int n){
    putchar('{');
    for(int i=0;i<n;i++){
        print(i);
        if(i != n - 1) putchar(',');
    }
    putchar('}');
}
int read(char *s){
    int t = 0, r = 0;
    for(int i=0;s[i];i++){
        if(s[i] == '{') t++;
        else if(s[i] == '}') t--;
        r = max(r, t);
    }
    return r - 1;
}
char str1[maxn];
char str2[maxn];
int main(){
    int T;
    for(scanf("%d\n", &T);T--;){
        gets(str1);
        gets(str2);
        print(read(str1) + read(str2));
        puts("");
    }
    return 0;
}
