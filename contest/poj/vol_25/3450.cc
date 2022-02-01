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

#define MAXL 1001000
#define MAXC 256
#define MAXN 4010
#define MAXS 210
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
char str[MAXL], st[MAXS];
int group[MAXL];

struct result{
    int h, p;
    bitset<MAXN> bit;
    friend bool operator<(result a,result b){
        if(a.h == b.h) return r[a.p] < r[b.p];
        else return a.h > b.h;
    }
    result(){}
    result(int _h, int _p){ h = _h, p = _p;}
}res[MAXS], ans;

int main(){
    int N, len, lt, top;
    while(scanf("%d", &N) && N){
        len = 0;
        for(int i=0;i<N;i++){
            scanf("%s", st);
            lt = strlen(st);
            for(int j=0;j<lt;j++){
                str[len] = st[j];
                group[len++] = i;
            }
            str[len] = '#';
            group[len++] = -1;
        }
     //   puts(str); for(int i=0;i<len;i++)printf("%d ",group[i]);puts("");
        sa_init(str, len), h_init(str, len);
     //   for(int i=0;i<len;i++)printf("%d ",h[i]); puts(""); system("pause");
        ans = result(0, 0);
        res[ top = 0 ] = ans;
        for(int i=0;i<len;i++){
          //  cout<<i<<","<<res[top].h<<":"<<group[sa[i]]<<endl; system("pause");
            if(h[i] > res[top].h){
                res[++top].h = h[i];
                res[top].p = sa[i];
                res[top].bit.reset();
                if(group[sa[i]] != -1) res[top].bit[ group[sa[i]] ] = 1;
            }
            else if(h[i] == res[top].h){
                if(group[sa[i]] != -1) res[top].bit[ group[sa[i]] ] = 1;
            }
            else{
                if(group[sa[i]] != -1) res[top].bit[ group[sa[i]] ] = 1;
                while(h[i] != res[top].h){
                    if(res[top].bit.count() == N) ans = min(ans, res[top]);
                    if(res[top - 1].h < h[i]){
                        res[top].h = h[i];
                     //   if(group[sa[i]] != -1) res[top].bit[ group[sa[i]] ] = 1;
                    }
                    else{
                        res[top - 1].bit |= res[top].bit;
                        top--;
                    }
                }
            }
        }
        if(ans.h == 0) puts("IDENTITY LOST");
        else{
            for(int i=0;i<ans.h;i++){
                printf("%c", str[ans.p + i]);
            }
            puts("");
        }
    }
    return 0;
}
