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
#define maxn 55
using namespace std;
int start[256], color[256], value[256];
char mcolor[256], mvalue[256];
struct cards{
    int c, v;
    friend bool operator<(cards a, cards b){
        if(a.c == b.c) return a.v < b.v;
        else return a.c < b.c;
    }
    cards(int _c, int _v){ c = _c, v = _v;}
    cards(){}
}card[4][maxn];
char str[2][110], op;
int cnt[4];
void output(int p){
    switch(p){
        case 0: puts("North player:"); break;
        case 1: puts("East player:"); break;
        case 2: puts("South player:"); break;
        case 3: puts("West player:"); break;
    }
    for(int i=0;i<13;i++) printf("+---"); puts("+");
    for(int i=0;i<13;i++) printf("|%c %c", mvalue[ card[p][i].v ], mvalue[ card[p][i].v ]); puts("|");
    for(int i=0;i<13;i++) printf("| %c ", mcolor[ card[p][i].c ]); puts("|");
    for(int i=0;i<13;i++) printf("|%c %c", mvalue[ card[p][i].v ], mvalue[ card[p][i].v ]); puts("|");
    for(int i=0;i<13;i++) printf("+---"); puts("+");
}
int main(){
    start['N'] = 0, start['E'] = 1, start['S'] = 2, start['W'] = 3;
    color['C'] = 0, color['D'] = 1, color['S'] = 2, color['H'] = 3;
    mcolor[0] = 'C', mcolor[1] = 'D', mcolor[2] = 'S', mcolor[3] = 'H';
    for(int i=2;i<=9;i++){
        value['0' + i] = i;
        mvalue[i] = '0' + i;
    }
    value['T'] = 10, value['J'] = 11, value['Q'] = 12, value['K'] = 13, value['A'] = 14;
    mvalue[10] = 'T', mvalue[11] = 'J', mvalue[12] = 'Q', mvalue[13] = 'K', mvalue[14] = 'A';
    int pos;
    bool first = true;
    while(scanf(" %c", &op) && op != '#'){
        memset(cnt, 0, sizeof(cnt));
        pos = (start[op] + 1) % 4;
        scanf(" %s %s", str[0], str[1]);
        for(int k=0;k<2;k++){
            for(int i=0;i<52;i+=2){
                card[pos][ cnt[pos]++ ] = cards(color[str[k][i]], value[str[k][i+1]]);
                pos = (pos + 1) % 4;
            }
        }
        if(!first) puts("");
        first = false;
        for(int i=2;i<6;i++){
            sort(card[i % 4], card[i % 4] + 13);
            output(i % 4);
        }
    }
    return 0;
}
