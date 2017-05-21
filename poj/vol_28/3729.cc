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
#define MAXC 10100
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
        if(str[i] == -1 || r[i] == len-1) h[r[i]] = d = 0; //'#' = 35 ÈôÎªint str[], '#'¸ÄÎª-1 !
        else{
            if(d) d--;
            j = sa[r[i] + 1];
            while(str[i+d] != -1 && str[j+d] != -1 && str[i+d] == str[j+d]) d++;
            h[r[i]] = d;
        }
    }
}
int str[MAXL];

struct node{
    int c,h; bool flag;
    node(int _c, int _h, bool _f){ c = _c, h = _h, flag = _f;}
    node(){}
}st[MAXL>>1];
int main(){
    int n,m,k,len,top;
    __int64 res;
    while(~scanf("%d%d%d", &n, &m, &k)){
        for(int i=0;i<n;i++) scanf("%d", &str[i]);
        str[len = n] = -1; len++;
        for(int i=0;i<m;i++) scanf("%d", &str[len++]);
        str[len] = -1;
        sa_init(str, len), h_init(str, len);
//        for(int i=0;i<len;i++){
//            printf("%2d -- %2d,%2d : ",i, h[i],sa[i]);
//            for(int j=sa[i];j<len;j++)printf("%2d ",str[j]);puts("");
//        }
        st[ top = 0 ] = node(0, 0, 0);
        res = 0;
        for(int i=0;i<len;i++){
            if(h[i] > st[top].h){
                st[++top].h = h[i];
                st[top].c = 0;
                st[top].flag = false;
                if(sa[i] < n) st[top].c++; else if(sa[i] > n) st[top].flag = true;
            }
            else{
                if(sa[i] < n) st[top].c++; else if(sa[i] > n) st[top].flag = true;
                while(h[i] != st[top].h){
                    if(st[top].h == k && st[top].flag)  res += st[top].c; //cout<<"res = "<<res<<endl;}
                  //  cout<<i<<","<<res<<":"<<st[top].flag<<endl;
                    //if(st[top].h >= k+1 && st[top].flag) res -= st[top].c;
                    if(st[top - 1].h < h[i]){
                        st[top].h = h[i];
                        if(st[top].flag){
                            st[top].c = 0;//st[top].flag = false;
                          //  if(sa[i] > n) st[top].flag = true;
                        }
                    }
                    else{
                        if(!st[top].flag) st[top - 1].c += st[top].c;
                        st[top - 1].flag |= st[top].flag;
                        top--;
                    }
                }
            }
        }
        printf("%I64d\n", res);
    }
    return 0;
}
