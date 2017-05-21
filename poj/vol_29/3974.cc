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
#define MAXL 2002000
using namespace std;
char str[MAXL],s0[MAXL];
int p[MAXL], len, lt;
int pk(){
    int id, mx = 0, res = 1;
    for(int i=0;i<len;i++){
        if(mx > i) p[i] = min(p[2*id-i], mx-i);
        else p[i] = 1;
        for(;str[i+p[i]]==str[i-p[i]];p[i]++);
        res = max(res, p[i]);
        if(p[i] + i > mx){
            mx = p[i] + i;
            id = i;
        }
    }
    return res;
}
int main(){
    int _case = 1;
    while(gets(s0)){
        if(s0[0] == 'E') break;
        lt = strlen(s0);
        str[len = 0] = '!'; len++;
        for(int i=0;i<lt;i++){
            str[len++] = '#';
            str[len++] = s0[i];
        }
        str[len++] = '#'; str[len] = '\0';

        printf("Case %d: %d\n", _case++, pk() - 1);
    }
    return 0;
}
