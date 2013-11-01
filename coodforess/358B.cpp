#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<cmath>
#include<stack>
#include<algorithm>
#include<functional>
#include<stdarg.h>
using namespace std;
typedef long long LL;
const int N = 1010000;
char str[N];
char input[N];
char ans[N];

bool have[256];

void init() {
    memset(have,false,sizeof(have));
    for(int i='0'; i<='9' && (have[i] = true); i++);
    for(int i='a'; i<='z' && (have[i] = true); i++);
    have['<'] = true;
    have['>'] = true;
}

int main() {
    init();
    int n,i,j;
    char *p;
    while(~scanf("%d",&n)) {
        p = str;
        for(i=0; i<n; i++) {
            strcpy(p,"<3");
            p += strlen(p);
            scanf("%s",p);
            p += strlen(p);
        }
        strcpy(p,"<3");
        p += strlen(p);
        scanf("%s",ans);
        p = str;
        bool ok = true;

        for(i = j = 0; str[i] && ans[j];) {
            if(str[i] == ans[j]) {
                i++,j++;
            } else if(have[ans[j]]) {
                j++;
            } else {
                ok = false;
                break;
            }
        }
        if(str[i]) {
            ok = false;
        }

        if(ok && ans[j]) {
            for(; ans[j] && have[ans[j]]; j++);

            if(str[j]) {
                ok = false;
            }
        }
        printf("%s\n",ok?"yes":"no");
    }


    return 0;
}





