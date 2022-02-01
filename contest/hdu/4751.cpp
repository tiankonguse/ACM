#include<stdio.h>
#include<string.h>
const int N = 111;
int str[N][N];
int mark[N];
int n;

bool dfs(int pos) {
    for(int i=1; i<=n; i++) {
        if(i == pos) {
            continue;
        }

        if(str[pos][i] == 0 || str[i][pos] == 0) {
            if(mark[i] == mark[pos]) {
                return false;
            } else if(mark[i] == -1) {
                mark[i] = !mark[pos];
                if(!dfs(i)) {
                    return false;
                }
            } else if(mark[i] == !mark[pos]) {
                continue;
            }
        }
    }
    return true;
}

bool findAns() {
    for(int i=1; i<=n; i++) {
        if(mark[i] == -1) {
            mark[i] = 1;
            if(!dfs(i)) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int to;
    while(~scanf("%d",&n)) {
        memset(str,0,sizeof(str));
        memset(mark,-1,sizeof(mark));
        for(int i=1; i<=n; i++) {
            while(1) {
                scanf("%d",&to);
                if(to) {
                    str[i][to] = -1;
                } else {
                    break;
                }
            }
        }
        printf("%s\n",findAns()?"YES":"NO");
    }

    return 0;
}

