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

#define MAXL 60010
#define MAXC 256
using namespace std;
int arr[3][MAXL], cnt[MAXL], mc[MAXC], *a, *ta, *r, *tr, sz;
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
char str[MAXL];
int main(){
    int n, len; char ch;
    while(~scanf("%d", &n)){
        for(int i=0;i<n;) if((ch = getchar()) != '\n') str[i++] = ch;
        str[n] = '#';
        len = n + n + 1;
        for(int i=n+1;i<len;i++) str[i] = str[len - i - 1];
        str[len] = '\0';
        sa_init(str, len);
        int p = 0, q = n + 1;
        for(int i=1;i<=n;i++){
            if(r[p] < r[q]) putchar(str[p++]);
            else putchar(str[q++]);
            if(i % 80 == 0)puts("");
        }
        if(n % 80 != 0)puts("");
    }
    return 0;
}
