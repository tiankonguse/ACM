
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

#define MAXL 200100
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
        if(str[i] == '#' || r[i] == len-1) h[r[i]] = d = 0; //'#' = 35 若为int str[], '#'改为-1 !
        else{
            if(d) d--;
            j = sa[r[i] + 1];
            while(str[i+d] != '#' && str[j+d] != '#' && str[i+d] == str[j+d]) d++;
            h[r[i]] = d;
        }
    }
}
char str[MAXL], s2[MAXL>>1];

struct node{
    int h, c1, c2;
    node(int _h, int _c1, int _c2){ h = _h, c1 = _c1, c2 = _c2;}
    node(){}
}st[MAXL>>1];
int main(){
    int K, l1, l2, len, top;
    __int64 res;
    while(scanf("%d",&K) && K){
        scanf(" %s%s", str, s2);
        l1 = strlen(str), l2 = strlen(s2);  str[l1] = '#';
        memcpy(str + l1 + 1, s2, sizeof(s2));
        len = l1 + l2 + 1;  str[len] = '\0';
        sa_init(str, len), h_init(str, len);
        res = 0;
        st[top = 0] = node(0, 0, 0);
    //   puts(str); for(int i=0;i<len;i++)printf("%d %d\n", h[i], sa[i]);
        for(int i=0;i<len;i++){
            if(h[i] > st[top].h){
                st[++top].h = h[i];
                st[top].c1 = st[top].c2 = 0;
                if(sa[i] < l1) st[top].c1++; else st[top].c2++;
            }
            else{
                if(sa[i] < l1) st[top].c1++; else st[top].c2++;
                while(h[i] != st[top].h){
                    if(st[top].h >= K){
                     //   printf("res += (%d - max(%d,%d)) * %d * %d\n", st[top].h, st[top-1].h, h[i], st[top].c1, st[top].c2);
                     //   printf("h = %d\n", st[top].h);
                     //   if(max(h[i], st[top - 1].h) < K) res += 1LL * (st[top].h - K + 1) * st[top].c1 * st[top].c2;
                     //   else{
                            res += 1LL * (st[top].h - max(K - 1, max(h[i], st[top - 1].h))) * st[top].c1 * st[top].c2;
                     //   }
                    }
                    if(st[top - 1].h < h[i]){
                        st[top].h = h[i];
                    }
                    else{
                        st[top - 1].c1 += st[top].c1;
                        st[top - 1].c2 += st[top].c2;
                        top--;
                    }
                }
            }
        }
        printf("%I64d\n", res);
    }
    return 0;
}
