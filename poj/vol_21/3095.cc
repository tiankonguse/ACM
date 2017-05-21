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
char str[maxn];
int a[maxn];
int main(){
    int n, p, s;
    while(gets(str) && str[0] != '#'){
        n = strlen(str);
        for(int i=0;i<n;i++){
            if(str[i] == '.') a[i] = 100;
            else if(str[i] == '_') a[i] = 0;
            else if(str[i] == '/'){
                p = i - 1;
                while(p >= 0 && str[p] == '_'){
                    p--;
                }
                if(p == -1 || str[p] == '.'){
                    a[i] = 100;
                }
                else a[i] = 0;
            }
            else if(str[i] == '\\'){
                p = i + 1;
                while(p < n && str[p] == '_'){
                    p++;
                }
                if(p == n || str[p] == '.'){
                    a[i] = 100;
                }
                else a[i] = 0;
            }
            else{
                a[i] = 0;
                p = i - 1;
                while(p >= 0 && str[p] == '_'){
                    p--;
                }
                if(p == -1 || str[p] == '.'){
                    a[i] += 50;
                }
                p = i + 1;
                while(p < n && str[p] == '_'){
                    p++;
                }
                if(p == n || str[p] == '.'){
                    a[i] += 50;
                }
            }
        }
        s = 0;
        for(int i=0;i<n;i++){
            s += a[i];
        }
        printf("%d\n", s / n);
    }
    return 0;
}
