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


int g,b,s;
int _str[32][20];
int str[32];
int color[20];

void set(int pos, int val) {
    for(int i=1; i<=_str[pos][0]; i++) {
//    	printf("%d++\n",_str[pos][i]);
        color[_str[pos][i]] += val;
    }
}

int getOnePos() {
    int pos = -1;
    for(int i=1; i<=g; i++) {
        if(color[i] >= s) {
            pos = i;
            break;
        }
    }
    return pos;
}

int getStone() {
    int ans = 0;
    for(int i=1; i<=g; i++) {
        ans += color[i]/s;
    }
    return ans;
}

void printColor() {
    for(int i=1; i<=g; i++) {
        printf("%d ",color[i]);
    }
    puts("");
}

int dfs(int who, int n, int AliceStone, int BobStone, int begin) {
    if(n == 0) {
        return AliceStone - BobStone + (who ?   getStone() : -getStone()) ;
    }

    int ans = who ? -2100 : 2100;
    int tmp;
    int pos;
    bool ok = false;

    for(int i=0; i<n; i++) {
        set(str[i], 1);
        pos = getOnePos();
        if(pos != -1) {
            color[pos] -= s;
            who ? AliceStone++:BobStone++;
            swap(str[i],str[n-1]);
            ans = dfs(who,n-1,AliceStone,BobStone,0);
            swap(str[i],str[n-1]);
            who ? AliceStone--:BobStone--;
            color[pos] += s;
            ok = true;
        }
        set(str[i], -1);
        if(ok) {
            break;
        }
    }
    if(ok) {
        return ans;
    }


    for(int i=begin; i<n; i++) {
        set(str[i], 1);
        swap(str[i],str[n-1]);
        tmp = dfs(!who,n-1,AliceStone,BobStone,i);
        if(tmp != 2100 && tmp != -2100) {
            ans = who ? max(ans,tmp) : min(ans,tmp);
        }
        swap(str[i],str[n-1]);
        set(str[i], -1);
    }

    return ans;
}
/*
1 1 0
1 1

*/
int main() {
    int ans,i,j;
    int sum = 0;
    while(~scanf("%d%d%d",&g,&b,&s),g||b||s) {
        for(i=0; i<b; i++) {
            str[i] = i;
            scanf("%d",&_str[i][0]);
            for(j=1; j<=_str[i][0]; j++) {
                scanf("%d",&_str[i][j]);
                sum += _str[i][j];
            }
        }
        memset(color, 0 ,sizeof(color));

        if(s <= 0) {
            ans = sum;
        } else {
            ans = dfs(1,b,0,0,0);
        }

        printf("%d\n",ans);
    }

    return 0;
}

