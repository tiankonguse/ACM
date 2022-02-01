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
#define maxn 110
using namespace std;
char key[maxn], str[maxn];
int se[maxn];
int main(){
    while(scanf("%s", key) && strcmp(key, "THEEND") != 0){
        scanf("%s", str);
        int n = strlen(key), len = strlen(str), m = len / n;
        int p = 0;
        for(char c='A';c<='Z';c++){
            for(int i=0;i<n;i++){
                if(key[i] == c){
                    se[i] = p++;
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                printf("%c", str[m*se[j] + i]);
            }
        }
        puts("");
    }
    return 0;
}
