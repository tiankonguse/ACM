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
#define maxn 10010
using namespace std;
char buf[maxn];
char str[maxn];
int n, m, p;

int fun(int &p){
    if(str[p] == 'V'){ p++; return 1;}
    else if(str[p] == 'F'){ p++; return 0;}
    else if(str[p] == '!'){ p++; return fun(p) ^ 1;}
    else if(str[p] == '('){
        p++;
        int t = fun(p);
        while(str[p] != ')'){
            if(str[p] == '&'){
                p++; t &= fun(p);
            }
            else if(str[p] == '|'){
                p++; t |= fun(p);
            }
        }
        p++;
        return t;
    }
}
int main(){
    int _case = 1, res;
    while(gets(buf)){
        str[0] = '(', n = strlen(buf), m = 1;
        for(int i=0;i<n;i++){
            if(buf[i] != ' ') str[m++] = buf[i];
        }
        str[m++] = ')'; str[m] = 0;
        p = 0;
        printf("Expression %d: %c\n", _case++, fun(p)? 'V' : 'F');
    }
    return 0;
}
