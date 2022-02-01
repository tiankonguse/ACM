#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <cmath>
#include <cassert>
using namespace std;
typedef long long LL;

#define N 105
int n , m;
set<string> h , p;
char s[N];
int cnt[5] , sum;
void work() {
    int i , j , l , x;
    m = 0 , h.clear() , p.clear();
    memset(cnt , 0 , sizeof(cnt)) , sum = 0;
    while (n --) {
        j = 0;
        scanf("%s" , s);
        l = strlen(s);
        for (i = 0 ; s[i] ; ++ i)
            if (s[i] == ':')
                break;
        if (i == l - 2 && s[l - 1] >= '1' && s[l - 1] <= '4')
            x = s[l - 1] - '0';
        else
            x = 0;
        s[i] = 0 , l = i;
        string S = "";
        char *t = s;

        if (*t == '+') {
            ++ t;
            while (*t) {
                if (*t != '(' && *t != ')' && *t != '-')
                    S += *t;
                //if (*t == '(')
                //    S += "0";
                ++ t;
            }
        } else
            S += "98";
        if (*t == '0' || *t == '(') {
            //S += "0" ;
             ++ t;
            while (*t) {
                if (*t != '(' && *t != ')' && *t != '-')
                    S += *t;
                ++ t;
            }
        } else if (*t)
            S += "21";
        while (*t) {
            if (*t != '(' && *t != ')' && *t != '-')
                S += *t;
            ++ t;
        }
        //cout << S << ' ' << x << endl;


        if (h.count(S)) continue;
        h.insert(S) ;
        if (!p.count(S))
            ++ m;
        if (!x) {
            h.erase(S);
            p.insert(S);
            continue;
        }
        ++ cnt[x] , ++ sum;
    }
    for (i = 1 ; i <= 4 ; ++ i)
        printf("%d%%\n" , cnt[i] * 100 / sum);
    printf("Participants:%d\n" , m);
}

int main(){
    //freopen("1.txt" , "r" , stdin);
    while (scanf("%d",&n) , n)
        work();
    return 0;
}
