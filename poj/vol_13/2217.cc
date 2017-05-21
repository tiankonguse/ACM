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
#define MAXL 20200
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
        if(str[i] == 1 || r[i] == len-1) h[r[i]] = d = 0;
        else{
            if(d) d--;
            j = sa[r[i] + 1];
            while(str[i+d] != 1 && str[j+d] != 1 && str[i+d] == str[j+d]) d++;
            h[r[i]] = d;
        }
    }
}
char str[MAXL], s1[MAXL];
int main(){
    int T, l1, l2, len;
    for(scanf("%d ", &T);T--;){
        gets(str), gets(s1);
        l1 = strlen(str), l2 = strlen(s1);
        str[l1] = 1;
        len = l1 + 1;
        for(int i=0;i<l2;i++){
            str[len++] = s1[i];
        }
        str[len] = 0;
        sa_init(str, len), h_init(str, len);
        int res = 0;
        for(int i=2;i<len;i++){
            if((sa[i-1] < l1 && sa[i] > l1) || (sa[i-1] > l1 && sa[i] < l1)){
                res = max(res, h[i-1]);
            }
        }
        printf("Nejdelsi spolecny retezec ma delku %d.\n", res);
    }
    return 0;
}
