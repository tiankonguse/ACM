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
#define maxn 2510
#define maxl 35
using namespace std;
struct books{
    int value, len;
    char str[maxl];
    friend bool operator<(books a, books b){
        return strcmp(a.str, b.str) < 0;
    }
}book[maxn];
bool check(int i, int j){
    int p1 = 0, p2 = 0;
    while(p1 < book[i].len && p2 < book[j].len){
        while(!( book[i].str[p1] >='A' && book[i].str[p1] <= 'Z') &&
              !( book[i].str[p1] >='a' && book[i].str[p1] <= 'z')){
                p1++;
              }
        if(p1 >= book[i].len) return true;
        while(!( book[j].str[p2] >='A' && book[j].str[p2] <= 'Z') &&
              !( book[j].str[p2] >='a' && book[j].str[p2] <= 'z')){
                p2++;
              }
        if(p2 >= book[j].len) return true;
        if(tolower(book[i].str[p1]) == tolower(book[j].str[p2])) return false;
        else{
            p1++, p2++;
        }
    }
    return true;
}
struct node{
    int p, v;
    friend bool operator<(node a, node b){
        return a.v > b.v;
    }
    node(int _p, int _v){ p = _p, v = _v;}
    node(){}
};
multiset<node> st[11];
int stk[15];
int pre[11][maxn];
int main(){
    int n;
    while(~scanf("%d", &n)){
        getchar();
        for(int i=0;i<n;i++){
            scanf("%d ", &book[i].value);
            gets(book[i].str);
            book[i].len = strlen(book[i].str);
        }
        sort(book, book + n);
       // puts(""); for(int i=0;i<n;i++) puts(book[i].str);
        for(int i=0;i<=10;i++) st[i].clear();
        memset(pre, 0xff, sizeof(pre));
        for(int i=0;i<n;i++){
            for(int j=9;j>=1;j--){
                if(st[j].empty()) continue;
                for(multiset<node>::iterator it=st[j].begin();it!=st[j].end();it++){
                    if(check(i, (*it).p)){
                       // printf("i = %d, j = %d, p = %d, value = %d\n", i, j, (*it).p, (*it).v);
                        st[j+1].insert(node(i, book[i].value + (*it).v));
                        pre[j+1][i] = (*it).p;
                        break;
                    }
                }
            }
            st[1].insert(node(i, book[i].value));
        }
        int r1, r2, mx = -inf;
        for(int i=1;i<=10;i++){
            if(!st[i].empty() && (*st[i].begin()).v > mx){
                mx = (*st[i].begin()).v;
                r1 = i;
                r2 = (*st[i].begin()).p;
            }
        }
        if(mx < 0){ puts("0\n0"); continue;}
        printf("%d\n%d\n", r1, mx);
        int top = 0;
        while(r2 != -1){
            stk[top++] = r2;
            r2 = pre[r1--][r2];
        }
        for(int i=top-1;i>=0;i--) puts(book[stk[i]].str);
    }
    return 0;
}
