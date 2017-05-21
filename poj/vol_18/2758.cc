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

#define MAXL 55000
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
//lcp
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
char str[MAXL];
int now[MAXL], ori[MAXL], d[MAXL];
int main(){
    int Q, len, tl;
    char op, ch; int a,b,res;
    while(~scanf(" %s", str)){
        len = strlen(str), tl = len;
        memset(d, 0x3f, sizeof(d));
        for(int i=0;i<len;i++) now[i] = ori[i] = i;
        sa_init(str, len), h_init(str, len), init(len);
        scanf("%d",&Q);
        while(Q--){
            scanf(" %c", &op);
            if(op == 'I'){
                scanf(" %c %d", &ch, &a);
                a--;
                if(a >= tl){
                    a = tl;
                    str[tl] = ch;
                    now[tl] = ori[tl] = tl;
                    d[tl] = 0;
                    tl++;
                }
                else{
                    for(int i=tl;i>a;i--){
                        str[i] = str[i-1];
                        now[ori[i-1]] = i;
                        ori[i] = ori[i-1];
                        d[i] = d[i-1];
                    }
                    str[a] = ch;
                    now[tl] = a;
                    ori[a] = tl;
                    d[a] = 0;
                    tl++;
                }
                for(int i=a-1;i>=0 && ori[i]<len;i--){
                    d[i] = a - i;
                }
//                puts(str);
//                for(int i=0;i<tl;i++) printf("%d ",ori[i]); puts("");
//                for(int i=0;i<tl;i++) printf("%d ",now[i]); puts("");
//                for(int i=0;i<tl;i++) printf("%d ",d[i]); puts("");
            }
            else{
                scanf("%d%d", &a, &b);
                a--, b--;
                res = 0;
                int _lcp, md, na, nb; bool flag = false;
                while(1){
                    _lcp = lcp(a, b, len);
                    md = min(d[now[a]], d[now[b]]);
                    if(_lcp < md){ res += _lcp; break; }
                    res += md;
                    na = now[a] + md, nb = now[b] + md;
                   // cout<<na<<","<<nb<<endl;system("pause");
                    while(ori[na] >= len || ori[nb] >= len){
                        if(str[na] != str[nb]){ flag = true; break;}
                        res++, na++, nb++;
                        if(na >= tl || nb >= tl){ flag = true; break;}
                    }
                    if(flag) break;
                    a = ori[na], b = ori[nb];
                }
                printf("%d\n", res);
            }
        }
    }
    return 0;
}
