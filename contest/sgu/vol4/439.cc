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
#define maxn 2001000
using namespace std;

char stra[2001000];
char strb[1001000];
char patb[1001000];

int la, lb;

int fun(){
    int n = lb;
    int i = 0, j = 1, len = 0, x, y;
    while(i < n && j < n && len < n){
        x = i + len; if(x >= n) x -= n;
        y = j + len; if(y >= n) y -= n;
        if(strb[x] == strb[y]) len++;
        else if(strb[x] < strb[y]){
            j += len + 1;
            len = 0;
        }
        else{
            i = j;
            j++;
            len = 0;
        }
    }
    return i;
}



void extkmp(char *str, char *pat, int ext[], int ex[]) {
    int p=0,k=1;
    while(pat[p] == pat[p+1]) p++;
    ext[0] = lb, ext[1] = p;
    for(int i=2;i<lb;i++){
        int x = k + ext[k] - i, y = ext[i - k];
        if (y < x) ext[i] = y;
        else{
            p = max(0, x);
            while (pat[p] == pat[p+i]) p++;
            ext[i] = p;
            k = i;
        }
    }
    p = k = 0;
    while(str[p] && str[p] == pat[p]) p++;
    ex[0] = p;
    for(int i=1;i<la;i++){
        int x = k + ex[k] - i, y = ext[i - k];
        if (y < x) ex[i] = y;
        else{
            p = max(0, x);
            while (pat[p] && pat[p] == str[p+i]) p++;
            ex[i] = p;
            k = i;
        }
    }
}

int ext[maxn];
int ex1[maxn];
int ex2[maxn];
char ss[maxn];

int main() {
    while (~scanf("%d %d", &la, &lb)) {
        scanf(" %s %s", stra, strb);
        int minIdx = fun();
        for (int i = 0; i < lb; ++i) {
            patb[i] = strb[(minIdx + i) % lb];
        }
        patb[lb] = 0;
        puts(patb);
        for (int i = 0; i < la; ++i) {
            stra[i + la] = stra[i];
        }
        int tl = la;
        la <<= 1; stra[la] = 0;
        extkmp(stra, patb, ext, ex1);
        
        memcpy(ss, stra, sizeof stra);
        reverse(stra, stra + la); reverse(patb, patb + lb);  
        extkmp(stra, patb, ext, ex2);
        int best = -1, rpos;
        int mx ;
        for (int i = 0; i < tl; ++i) {
            rpos = la - i - lb;
            if (ex1[i] + ex2[rpos] >= lb - 1) {
                best = i;
                mx = i;
                break;
            }
        }
        for (int i = tl - 1; i >= 0; --i) {
            rpos = la - i - lb;
            if (ex1[i] + ex2[rpos] >= lb - 1) {
                 if (tl - i < mx) {
                    best = i;
                 }
                 break;
            }
        }
        for (int i = best; i < tl; ++i) putchar(ss[i]);
        for (int i = 0; i < best; ++i) putchar(ss[i]);
        puts("");
    }
    return 0;
}

