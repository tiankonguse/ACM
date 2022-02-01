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

#define MAXL 200200
#define MAXC 256
using namespace std;
int arr[3][MAXL], cnt[MAXL], mc[MAXC], h[MAXL], *a, *ta, *r, *tr, sz;
void sa_init(char *str, int len){
    a = arr[0], ta = arr[1], r = arr[2], sz = 0;
    for(int i=0;i<len;i++) ta[i] = str[i];
    sort(ta, ta + len);
    for(int i=1;i<=len;i++) if(ta[i] != ta[i-1] || i == len) cnt[ mc[ ta[i-1] ] = sz++ ] = i;
    for(int i=len-1;i>=0;i--) a[ --cnt[ r[i] = mc[ str[i] ]]] = i;
    for(int k=1;k<len && r[a[len-1]]<len-1;k<<=1){
        for(int i=0;i<len;i++) cnt[r[a[i]]] = i + 1;
        for(int i=len-1;i>=0;i--) if(a[i] >= k) ta[ --cnt[ r[a[i] - k] ] ] = a[i] - k;
        for(int i=len-k;i<len;i++) ta[ --cnt[r[i]] ] = i;
        tr = a, a = ta, tr[a[0]] = 0;
        for(int i=1;i<len;i++) tr[a[i]] = tr[a[i-1]] + (r[a[i]] != r[a[i-1]] || a[i-1]+k >= len || r[a[i]+k] != r[a[i-1]+k]);
        ta = r, r = tr;
    }
}
void h_init(char *str, int len){
    for(int i=0,d=0,j;i<len;i++){
        if(str[i] == '#' || r[i] == len-1) h[r[i]] = d = 0;
        else{
            if(d) d--;
            j = a[r[i] + 1];
            while(str[i+d] != '#' && str[j+d] != '#' && str[i+d] == str[j+d]) d++;
            h[r[i]] = d;
        }
    }
}
char s1[MAXL], s2[MAXL];
int main(){
    int len, sp, sq, x, y, ans;
    while(~scanf(" %s%s", s1, s2)){
        sp = strlen(s1), sq = strlen(s2);
        s1[sp] = '#';
        memcpy(s1 + sp + 1, s2, sizeof(s2));
        len = sp + sq + 1;
        s1[len] = '\0';
        sa_init(s1, len), h_init(s1, len);
        ans = 0;
        for(int i=0;i<len-1;i++){
            x = a[i], y = a[i+1];
            if((x < sp && y > sp) || (x > sp && y < sp)){
                ans = max(ans, h[i]);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
