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
#define MAXC 1000100
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
        if(str[i] == -1 || r[i] == len-1) h[r[i]] = d = 0; //'#' = 35
        else{
            if(d) d--;
            j = sa[r[i] + 1];
            while(str[i+d] != -1 && str[j+d] != -1 && str[i+d] == str[j+d]) d++;
            h[r[i]] = d;
        }
    }
}

int str[MAXL];
int st[MAXL], ct[MAXL];
int getint(){
    int ret=0;
  char tmp;
    while(!isdigit(tmp=getchar()));
    do{
		ret=(ret<<3)+(ret<<1)+tmp-'0';
    }while(isdigit(tmp=getchar()));
    return ret;
}
int main(){
    int N,K;
    while(~scanf("%d%d",&N,&K)){
        for(int i=0;i<N;i++) str[i] = getint();
        str[N] = -1;
        sa_init(str, N), h_init(str, N);
        int top = 0;
        st[0] = 0;
        int res = 0;
        for(int i=0;i<N;i++){
            if(h[i] > st[top]){
                st[++top] = h[i];
                ct[top] = 1;
            }
            else{
                ct[top]++;
                while(st[top] != h[i]){
                    if(ct[top] >= K) res = max(res, st[top]);
                    if(st[top - 1] < h[i]){
                        st[top] = h[i];
                    }
                    else{
                        ct[top - 1] += ct[top];
                        st[top] = ct[top] = 0;
                        top--;
                    }
                }
            }
        }
        printf("%d\n", res);
    }
    return 0;
}
