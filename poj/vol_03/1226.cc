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

#define MAXL 20200
#define MAXC 256
#define MAXN 110
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
        if(str[i] == '#' || r[i] == len-1) h[r[i]] = d = 0; //'#' = 35 若为int str[], '#'改为范围之外的某数（最好不是负数）
        else{
            if(d) d--;
            j = sa[r[i] + 1];
            while(str[i+d] != '#' && str[j+d] != '#' && str[i+d] == str[j+d]) d++;
            h[r[i]] = d;
        }
    }
}
char str[MAXL], s0[MAXN];
int group[MAXL];

struct node{
    int h;
    bitset<MAXN> bit;
    node(int _h){ h = _h;}
    node(){}
}st[MAXN];
int main(){
    int T,N,len,lt,top,res;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &N);
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
            for(int j=0;j<lt;j++){
                str[len] = s0[lt - j - 1];
                group[len++] = i;
            }
            str[len] = '#';
            group[len++] = -1;
        }
//        puts(str);for(int i=0;i<len;i++)printf("%d ",group[i]);puts("");
        sa_init(str, len), h_init(str, len);
        st[top = 0] = node(0);
        res = 0;
        for(int i=0;i<len;i++){
            if(h[i] > st[top].h){
                st[++top].h = h[i];
                st[top].bit.reset();
                if(group[sa[i]] != -1) st[top].bit[group[sa[i]]] = 1;
            }
            else{
                if(group[sa[i]] != -1) st[top].bit[group[sa[i]]] = 1;
                while(h[i] != st[top].h){
                    if(st[top].bit.count() == N) res = max(res, st[top].h);
                    if(st[top - 1].h < h[i]){
                        st[top].h = h[i];
                    }
                    else{
                        st[top - 1].bit |= st[top].bit;
                        top--;
                    }
                }
            }
        }
        printf("%d\n", res);
    }
    return 0;
}
