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

#define MAXL 10010
#define MAXC 256
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
        if(str[i] == '#' || r[i] == len-1) h[r[i]] = d = 0; 
        else{
            if(d) d--;
            j = sa[r[i] + 1];
            while(str[i+d] != '#' && str[j+d] != '#' && str[i+d] == str[j+d]) d++;
            h[r[i]] = d;
        }
    }
}
char str[MAXL];
char buf[MAXL];
struct node {
    int h, m, s;
    node (int _h, int _m, int _s) { h = _h, m = _m, s = _s; }
    node () {}
} st[MAXL];

int p[MAXL];
// "aaa" -> "!#a#a#a#"
char ss[MAXL]; int sid;
int pk(char *s, int len){

    int id, mx = 0, res = 0;
    for(int i=0;i<len;i++){
        if(mx > i) p[i] = min(p[2*id-i], mx-i);
        else p[i] = 1;
        for(;s[i+p[i]]==s[i-p[i]];p[i]++);
        if (p[i] > res) {
            res = p[i];
            sid = i;
        }
        if(p[i] + i > mx){
            mx = p[i] + i;
            id = i;
        }
    }
    return res - 1;
}
int main() {
    int l1, l2, len, top;

    scanf(" %s", buf);
    l1 = strlen(buf);
    for (int i = 0; i < l1; ++i) str[i] = buf[i];
    str[len = l1] = '#';
    ++len;
    scanf(" %s", buf);
    l2 = strlen(buf);
    for (int i = 0; i < l2; ++i) str[len++] = buf[i];
    str[len] = 0;
    sa_init(str, len), h_init(str, len);

    st[top = 0] = node(0, 0, 0);
    int ret, mx = 0;
    for (int i = 0; i < len; ++i) {
        if (h[i] > st[top].h) {
            st[++top] = node(h[i], 1 << (sa[i] > l1), sa[i]);
        }
        else {
            st[top].m |= (1 << (sa[i] > l1));
            while (h[i] != st[top].h) {
                if (st[top].m == 3) {
                    int lt = 0;
                    ss[lt++] = '!'; ss[lt++] = '#';
                    for (int j = 0; j < st[top].h; ++j) {
                        ss[lt++] = str[ st[top].s + j ];
                        ss[lt++] = '#';
                    }
                    ss[lt] = 0;
                    int ts = pk(ss, lt);
                    if (ts > mx) {
                        mx = ts;
                        if (ts % 2 == 1) {
                            ret = st[top].s + (sid - ts + 1) / 2 - 1;
                        }
                        else {
                            ret = st[top].s + (sid - ts) / 2;
                        }
                    }
                }
                if (st[top - 1].h < h[i]) {
                    st[top].h = h[i];
                }
                else {
                    st[top - 1].m |= st[top].m;
                    top--;
                }
            }
        }
    }
    for (int i = 0; i < mx; ++i) putchar(str[ret + i]); puts("");
    return 0;
}

