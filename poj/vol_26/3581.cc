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

#define MAXL 400400
#define MAXC 200200
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
        for(int i=len-1;i>=0;i--) if(sa[i] >= k) ta[ --cnt[ r[sa[i] - k] ] ] = sa[i] - k;
        for(int i=len-k;i<len;i++) ta[ --cnt[r[i]] ] = i;
        tr = sa, sa = ta, tr[sa[0]] = 0;
        for(int i=1;i<len;i++) tr[sa[i]] = tr[sa[i-1]] + (r[sa[i]] != r[sa[i-1]] || sa[i-1]+k >= len || r[sa[i]+k] != r[sa[i-1]+k]);
        ta = r, r = tr;
    }
}
void h_init(int *str, int len){
    for(int i=0,d=0,j;i<len;i++){
        if(str[i] == -1 || r[i] == len-1) h[r[i]] = d = 0; //'#' = 35 若为int str[], '#'改为-1 !
        else{
            if(d) d--;
            j = sa[r[i] + 1];
            while(str[i+d] != -1 && str[j+d] != -1 && str[i+d] == str[j+d]) d++;
            h[r[i]] = d;
        }
    }
}
int str[MAXL];
int ori[MAXL], pos[MAXL];
int bsearch(int l, int r, int x){
    int mid;
    while(l <= r){
        mid = (l + r) >> 1;
        if(x == pos[mid]) return mid;
        else if(x > pos[mid]) l = mid + 1;
        else r = mid - 1;
    }
    return mid;
}
int main(){
    int n,m,s1,s2;
    scanf("%d", &n);
    for(int i=0;i<n;i++) scanf("%d", &ori[i]);
    memcpy(pos, ori, sizeof(ori));
    sort(pos, pos + n);
    m = 1;
    for(int i=1;i<n;i++){
        if(pos[i] != pos[i-1]) pos[m++] = pos[i];
    }
    for(int i=0;i<n;i++) str[i] = bsearch(0, m - 1, ori[n - i - 1]);
//        for(int i=0;i<n;i++) printf("%d ",str[i]); printf("\n");
    str[n] = -1;
    sa_init(str, n);
    for(int i=0;i<n;i++){
        if(sa[i] > 1){
            s1 = sa[i];
            break;
        }
    }
    for(int i=s1;i<n;i++) printf("%d\n", pos[str[i]]);
    m = s1 + s1;
    for(int i=s1;i<m;i++){
        str[i] = str[i - s1];
    }
    str[m] = -1;
    sa_init(str, m);
    for(int i=0;i<m;i++){
        if(sa[i] > 0 && sa[i] < s1){
            s2 = sa[i];
            break;
        }
    }
//     cout<<s1<<","<<s2<<endl;
    for(int i=s2;i<s1;i++) printf("%d\n", pos[str[i]]);
    for(int i=0;i<s2;i++) printf("%d\n",pos[str[i]]);

    return 0;
}
