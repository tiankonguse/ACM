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
#include <bitset>

#define MAXL 101000
#define MAXC 256
#define MAXN 110
#define MAXS 1010
using namespace std;
int arr[3][MAXL], cnt[MAXL], mc[MAXC], h[MAXL], *sa, *ta, *r, *tr, sz;
void sa_init(char *str, int len){
    sa = arr[0], ta = arr[1], r = arr[2], sz = 0;
    for(int i=0;i<len;i++) ta[i] = str[i];
    sort(ta, ta + len);
    for(int i=1;i<=len;i++) if(ta[i] != ta[i-1] || i == len) cnt[ mc[ ta[i-1] ] = sz++ ] = i;
    for(int i=len-1;i>=0;i--) sa[ --cnt[ r[i] = mc[ str[i] ]]] = i;
    for(int k=1;k<len && r[sa[len-1]]<len-1;k<<=1){
        for(int i=0;i<len;i++) cnt[r[sa[i]]] = i + 1;
        for(int i=len-1;i>=0;i--) if(sa[i] >= k) ta[ --cnt[ r[sa[i] - k] ] ] = sa[i] - k;
        for(int i=len-k;i<len;i++) ta[ --cnt[r[i]] ] = i;
        tr = sa, sa = ta, tr[sa[0]] = 0;
        for(int i=1;i<len;i++) tr[sa[i]] = tr[sa[i-1]] + (r[sa[i]] != r[sa[i-1]] || sa[i-1]+k >= len || r[sa[i]+k] != r[sa[i-1]+k]);
        ta = r, r = tr;
    }
}
void h_init(char *str, int len){
    for(int i=0,d=0,j;i<len;i++){
        if(str[i] == '#' || r[i] == len-1) h[r[i]] = d = 0; //'#' = 35 若为int str[], '#'改为-1 !
        else{
            if(d) d--;
            j = sa[r[i] + 1];
            while(str[i+d] != '#' && str[j+d] != '#' && str[i+d] == str[j+d]) d++;
            h[r[i]] = d;
        }
    }
}
char str[MAXL], s0[MAXS];
int group[MAXL];

struct result{
    int h, p;
    bitset<MAXN> bit;
    friend bool operator<(result a, result b){
        return r[a.p] < r[b.p];
    }
    result(){}
    result(int _h, int _p){ h = _h, p = _p;}
}st[MAXS], ans[MAXS];
int main(){
    int N, len, lt, top, ant, limit; bool flag = false;
    while(scanf("%d", &N) && N){
        limit = N / 2 + 1;
        len = 0;
        for(int i=0;i<N;i++){
            scanf(" %s", s0);
            lt = strlen(s0);
            for(int j=0;j<lt;j++){
                str[len] = s0[j];
                group[len++] = i;
            }
            str[len] = '#';
            group[len++] = -1;
        }
        sa_init(str, len), h_init(str, len);
        st[top = 0] = result(0, 0);
        ans[ ant = 0] = result(0, 0);
        for(int i=0;i<len;i++){
            if(h[i] > st[top].h){
                st[++top].h = h[i];
                st[top].p = sa[i];
                st[top].bit.reset();
                if(group[ sa[i] ] != -1) st[top].bit[ group[ sa[i] ] ] = 1;
            }
            else{
                if(group[ sa[i] ] != -1) st[top].bit[ group[ sa[i] ] ] = 1;
                while(h[i] != st[top].h){
                    if(st[top].bit.count() >= limit){
                        if(st[top].h > ans[0].h){
                            ans[0].h = st[top].h;
                            ans[0].p = st[top].p;
                            ant = 1;
                        }
                        else if(st[top].h == ans[0].h){
                            ans[ant].h = st[top].h;
                            ans[ant].p = st[top].p;
                            ant++;
                        }
                    }
                    if(st[top - 1].h < h[i]){
                        st[top].h = h[i];
                       // if(group[ sa[i] ] != -1) st[top].bit[ group[ sa[i] ] ] = 1;
                    }
                    else{
                        st[top - 1].bit |= st[top].bit;
                        top--;
                    }
                }
            }
        }
        if(flag) puts(""); flag = true;
        if(ant == 0) puts("?");
        else{
            sort(ans, ans + ant);
            for(int i=0;i<ant;i++){
                for(int j=0;j<ans[i].h;j++){
                    printf("%c", str[ans[i].p + j]);
                }
                puts("");
            }
        }
    }
    return 0;
}
