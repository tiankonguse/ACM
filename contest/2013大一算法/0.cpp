/*************************************************************************
    > File Name: 0.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/6/11 17:07:57
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<functional>
#include<algorithm>
using namespace std;


char str[5][5];
char x[255];
char y[255];

int x0,y0;

void init() {
    x['U'] = -1;
    y['U'] = 0;

    x['D'] = 1;
    y['D'] = 0;

    x['L'] = 0;
    y['L'] = -1;

    x['R'] = 0;
    y['R'] = 1;
}
void getPos() {
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(str[i][j] == '#') {
                x0 = i, y0 = j;
                return ;
            }
        }
    }
}

bool move(int x1, int y1) {
    if(x1 == -1 || x1 == 3 || y1 == -1 || y1 == 3) {
        return false;
    } else {
        str[x0][y0] = str[x1][y1];
        str[x1][y1] = '#';
        x0 = x1,y0=y1;
        return true;
    }

}

bool getAns(char*op) {
    getPos();
    while(*op) {
        if(!move(x0 + x[*op], y0 + y[*op])) {
            return false;
        }
        op++;
    }
    return true;
}

int main() {
    char op[111];
    freopen("eight.in","r",stdin);
    freopen("eight.txt","w",stdout);

    init();
    while(~scanf("%s",str[0])) {
        scanf("%s",str[1]);
        scanf("%s",str[2]);
        scanf("%s",op);
        if(getAns(op)) {
            printf("%s\n",str[0]);
            printf("%s\n",str[1]);
            printf("%s\n",str[2]);
        } else {
            printf("Error\n");
        }
        puts("");
    }

    return 0;
}
