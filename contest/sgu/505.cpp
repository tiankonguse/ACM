#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <queue>
#include <stack>
#include <set>
#include <map>
typedef long long LL;
using namespace std;

#define N 100005
int n , Q , a[N] , b[N];
int A[N];
char s[N << 1];
char str[N << 1] , rts[N << 1];

int check(char *S , char *T) {
    int i;
    for (i = 0 ; S[i] && T[i] ; ++ i)
        if (S[i] != T[i])
            return T[i] - S[i];
    return -S[i];
}

int lower_bound(char *P , int *D , char *t) {
    int l = 0 , r = n , m;
    while (l < r) {
        m = (l + r) >> 1;
        if (check(t , P + A[D[m]]) >= 0)
            r = m;
        else
            l = m + 1;
    }
    return l;
}
int upper_bound(char *P , int *D , char *t) {
    int l = 0 , r = n , m;
    while (l < r) {
        m = (l + r) >> 1;
        if (check(t , P + A[D[m]]) > 0)
            r = m;
        else
            l = m + 1;
    }
    return l;
}
int t[N * 20] , ch[N * 20][2] , root[N] , cnt;
#define MID int mid = (l + r) >> 1
#define Left l , mid
#define Right mid + 1 , r

void insert(int& p , int q , int l , int r , int x) {
    if (!p) {
        p = ++ cnt;
        t[p] = t[q];
    }
    if (l >= r) {++ t[p];return;} MID;
    if (x <= mid)
        insert(ch[p][0] , ch[q][0] , Left , x) , ch[p][1] = ch[q][1];
    else
        insert(ch[p][1] , ch[q][1] , Right , x) , ch[p][0] = ch[q][0];
    t[p] = t[ch[p][0]] + t[ch[p][1]];
}

int query(int p , int l , int r , int top , int bot) {
    if (top <= l && r <= bot)
        return t[p];
    MID; int ans = 0;
    if (top <= mid)
        ans += query(ch[p][0] , Left , top , bot);
    if (bot > mid)
        ans += query(ch[p][1] , Right , top , bot);
    return ans;
}

bool cmpA(int x , int y) {
    return strcmp(str + A[x] , str + A[y]) < 0;
}
bool cmpB(int x , int y) {
    return strcmp(rts + A[x] , rts + A[y]) < 0;
}

void work()
{
    int i , j , k;
    scanf("%d",&n);
    k = 0;
    for (i = 0 ; i < n ; ++ i) {
        scanf("%s" , s) , j = strlen(s);
        strcpy(str + k , s);
        reverse(s , s + j);
        strcpy(rts + k , s);
        A[i] = k ;
        k += j + 1;
        a[i] = b[i] = i;
    }
    sort(a , a + n , cmpA);
    sort(b , b + n , cmpB);
    for (i = n - 1 ; i >= 0 ; -- i) {
        strcpy(s , str + A[a[i]]);
        reverse(s , s + strlen(s));
        int l = 0 , r = n - 1 , m;
        while (l <= r) {
            m = (l + r) >> 1;
            j = strcmp(s , rts + A[b[m]]);
            if (j == 0) {
                j = m;
                break;
            } else if (j < 0)
                r = m - 1;
            else
                l = m + 1;
        }
        insert(root[i] , root[i + 1] , 0 , n , j);
    }
    scanf("%d",&Q);
    while (Q --) {
        scanf("%s" , s);
        int l1 = lower_bound(str , a , s);
        int r1 = upper_bound(str , a , s);
        scanf("%s" , s);
        reverse(s , s + strlen(s));
        int l2 = lower_bound(rts , b , s);
        int r2 = upper_bound(rts , b , s);
        if (l1 >= r1 || l2 >= r2) {
            puts("0");
        } else
            printf("%d\n" , query(root[l1] , 0 , n , l2 , r2 - 1) - query(root[r1] , 0 , n , l2 , r2 - 1));
    }
}

int main()
{
    work();
    return 0;
}

