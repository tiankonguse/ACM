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
#define MAXL 100100
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
char str[MAXL];

int dpm[MAXL][20];
void init(int N){
    for(int i=1;i<=N;i++){dpm[i][0]=h[i-1];}
    for(int j=1;(1<<j)<=N;j++){
        for(int i=1;i+(1<<j)-1<=N;i++){
            dpm[i][j]=min(dpm[i][j-1],dpm[i+(1<<(j-1))][j-1]);
        }
    }
}
int getm(int a,int b){
    a++, b++;
    int k=(int)(log((double)(b-a+1))/log(2.0));
    return min(dpm[a][k],dpm[b-(1<<k)+1][k]);
}
int lcp(int a,int b, int len){
    if(a == b) return len - a;
    a = r[a], b = r[b];
    if(a > b) swap(a, b);
    return getm(a, b - 1);
}
struct result{
    int t,p,l;
    friend bool operator<(result a, result b){ return r[a.p] < r[b.p];}
    result(int _t, int _l){ t = _t, l = _l;}
    result(){}
}res[MAXL];
int rt;

int main(){
    int _case = 1, len;
    while(gets(str)){
        if(str[0] == '#') break;
        len = strlen(str);
        sa_init(str, len), h_init(str, len), init(len);
        int limit = 0;
        for(int i=0;i<len;i++)limit = max(limit, h[i]);
        res[ rt = 0 ] =result(1,1); rt++;
        int mm = 'z';
        for(int i=0;i<len;i++){
            if(str[i] < mm){
                mm = str[i];
                res[0].p = i;
            }
        }
        int k, q, p, o, o2;
        limit = min(limit, len>>1);
        for(int i=1;i<=limit && i*res[0].t<=len;i++){
            for(int j=0;j+i<len;j+=i){
                k = lcp(j, j + i, len);
                p = k / i + 1;
                o = j;

                if(p > res[0].t){
                    res[rt = 0].t = p;
                    res[0].p = o;
                    res[0].l = i;
                    rt++;
                }
                else if(p == res[0].t){
                    res[rt].t = p;
                    res[rt].l = i;
                    res[rt++].p = o;
                }
                int tk = min(k, i);
                o = max(0, j - i) + tk - 1;
                for(int z=0;z<tk;z++){
                    o2 = o - z;
                    k = lcp(o2, o2 + i, len);
                    if(k == 0) break;
                    p = k / i + 1;
                    if(p > res[0].t){
                        res[rt = 0].t = p;
                        res[0].p = o2;
                        res[0].l = i;
                        rt++;
                    }
                    else if(p == res[0].t){
                        res[rt].t = p;
                        res[rt].l = i;
                        res[rt++].p = o2;
                    }
                }
            }
        }
        k = 0;
        for(int i=1;i<rt;i++){
            if(res[i] < res[k]) k = i;
        }
        printf("Case %d: ", _case++);
        for(int i=0;i<res[k].t;i++){
            for(int j=0;j<res[k].l;j++){
                printf("%c", str[res[k].p + j]);
            }
        }
        puts("");
    }
    return 0;
}
