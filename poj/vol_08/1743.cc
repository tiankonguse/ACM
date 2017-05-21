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

#define MAXL 20020
#define MAXC 256
using namespace std;
int arr[3][MAXL], cnt[MAXL], mc[MAXC], h[MAXL], *sa, *ta, *r, *tr, sz;
void sa_init(int *str, int len){
    sa = arr[0], ta = arr[1], r = arr[2], sz = 0;
    for(int i=0;i<len;i++) ta[i] = str[i];
    sort(ta, ta + len);
    for(int i=1;i<=len;i++) if(ta[i] != ta[i-1] || i == len) cnt[ mc[ ta[i-1] ] = sz++ ] = i;
    for(int i=len-1;i>=0;i--) sa[ --cnt[ r[i] = mc[ str[i] ]]] = i;
    for(int k=1;k<len && r[sa[len-1]]<len-1;k<<=1){
        for(int i=0;i<len;i++) cnt[r[sa[i]]] = i + 1;
        for(int i=len-1;i>=0;i--) if(sa[i] >= k) ta[ --cnt[ r[sa[i] - k]]] = sa[i] - k;
        for(int i=len-k;i<len;i++) ta[ --cnt[r[i]]] = i;
        tr = sa, sa = ta, tr[sa[0]] = 0;
        for(int i=1;i<len;i++) tr[sa[i]] = tr[sa[i-1]] + (r[sa[i]] != r[sa[i-1]] ||
        sa[i-1] + k >= len || r[sa[i]+k] != r[sa[i-1]+k]);
        ta = r, r = tr;
    }
}
void h_init(int *str, int len){
    for(int i=0,d=0,j;i<len;i++){
        if(str[i] == -1 || r[i] == len-1) h[r[i]] = d = 0;
        else{
            if(d) d--;
            j = sa[r[i] + 1];
            while(str[i+d] != -1 && str[j+d] != -1 && str[i+d] == str[j+d]) d++;
            h[r[i]] = d;
        }
    }
}
int str[MAXL];
int getint(){
    int ret=0;
  char tmp;
    while(!isdigit(tmp=getchar()));
    do{
		ret=(ret<<3)+(ret<<1)+tmp-'0';
    }while(isdigit(tmp=getchar()));
    return ret;
}
struct node{
    int h, l, r;
    node(int _h, int _l, int _r){
        h = _h, l = _l, r = _r;
    }
    node(){}
}st[MAXL];
int main(){
    int n,p,a;
    while(scanf("%d",&n) && n){
        p = getint(); n--;
        for(int i=0;i<n;i++){
            a = getint();
            str[i] = a - p + 100;
            p = a;
        }
        str[n] = -1;
        sa_init(str, n), h_init(str, n);
       // for(int i=0;i<n;i++)printf("%d ",h[i]);
        int top = 0;
        st[0] = node(0,0,0);
        int res = 0;
        for(int i=0;i<n;i++){
            if(h[i] > st[top].h){
                st[++top] = node(h[i], sa[i], sa[i]);
            }
            else{
                st[top].l = min(st[top].l, sa[i]);
                st[top].r = max(st[top].r, sa[i]);
                while(h[i] != st[top].h){
                    if(st[top].h >= 4 && st[top].r - st[top].l > st[top].h){
                        res = max(res, st[top].h + 1);
                    }
                    if(st[top - 1].h < h[i]){
                        st[top].h = h[i];
                        st[top].l = min(st[top].l, sa[i]);
                        st[top].r = max(st[top].r, sa[i]);
                    }
                    else{
                        st[top - 1].l = min(st[top - 1].l, st[top].l);
                        st[top - 1].r = max(st[top - 1].r, st[top].r);
                        top--;
                    }
                }
            }
        }
        printf("%d\n", res);
    }
    return 0;
}
