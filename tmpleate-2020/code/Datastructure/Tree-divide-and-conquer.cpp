#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <cmath>
//#pragma comment(linker, "/STACK:16777216")
using namespace std;
typedef long long LL;
#define N 50005
int n , K , pre[N] , mcnt;
struct edge {
    int x , next;
}e[N << 1];
LL fac[30] , a[N] , power[30];
int s[N]; bool f[N];
void init() {
    power[0] = 1;
    for (int i = 1 ; i < 30 ; ++ i)
        power[i] = power[i - 1] * 3;
}

pair<int , int> Find(int x , int fa , int cnt)
{
    s[x] = 1; int m = 0;
    pair<int , int> res = make_pair(1 << 30 , -1);
    for (int i = pre[x] ; ~i ; i = e[i].next)
        if (!f[e[i].x] && e[i].x != fa) {
            res = min(res , Find(e[i].x , x , cnt));
            m = max(s[e[i].x] , m);
            s[x] += s[e[i].x];
        }
    m = max(m , cnt - s[x]);
    return min(res , make_pair(m , x));
}
LL ans , w , S[N];
int size;
map<LL , int> hash;
LL add(LL A , LL B) {
    LL C = 0;
    for (int i = 0 ; i < K ; ++ i) {
        C += power[i] * ((A % 3 + B % 3) % 3);
        A /= 3 , B /= 3;
    }
    return C;
}
LL sub(LL A , LL B) {
    LL C = 0;
    for (int i = 0 ; i < K ; ++ i) {
        C += power[i] * ((A % 3 + 3 - B % 3) % 3);
        A /= 3 , B /= 3;
    }
    return C;
}

void Getdis(int x , int fa , LL d) {
    S[size ++] = d;
    ans += hash[sub(w , d)];
    for (int i = pre[x] ; ~i ; i = e[i].next) {
        int y = e[i].x;
        if (!f[y] && y != fa)
            Getdis(y , x , add(d , a[y]));
    }
}


void divide(int x , int cnt)
{
    x = Find(x , 0 , cnt).second;
    f[x] = 1 , w = sub(0 , a[x]) , hash.clear();
    ++ hash[0]; if (w == 0) ++ ans;
    for (int i = pre[x] ; ~i ; i = e[i].next) {
        int y = e[i].x;
        if (!f[y]) {
            Getdis(y , x , a[y]);
            s[y] = size;
            while (size)
                ++ hash[S[-- size]];
        }
    }
    for (int i = pre[x] ; ~i ; i = e[i].next) {
        int y = e[i].x;
        if (!f[y])
            divide(y , s[y]);
    }
}

void work() {
    int i , j , x , y;
    for (i = 0 ; i < K ; ++ i) {
        scanf("%I64d" , &fac[i]);
    }
    for (i = 1 ; i <= n ; ++ i) {
        LL val; a[i] = 0;
        scanf("%I64d",&val);
        for (j = 0 ; j < K ; ++ j) {
            x = 0;
            while (val % fac[j] == 0)
                val /= fac[j] , ++ x;
            a[i] += (x % 3) * power[j];
        }
    }
    memset(pre , -1 , sizeof(pre)) , mcnt = 0;
    for (i = 1 ; i < n ; ++ i) {
        scanf("%d%d",&x,&y);
        e[mcnt].x = y , e[mcnt].next = pre[x] , pre[x] = mcnt ++;
        e[mcnt].x = x , e[mcnt].next = pre[y] , pre[y] = mcnt ++;
    }
    memset(f , 0 , sizeof(f));
    ans = 0;
    divide(1 , n);
    printf("%I64d\n" , ans);
}

int main()
{
    freopen("1.txt" , "r" , stdin);
    init();
    while (~scanf("%d%d",&n,&K))
        work();
    return 0;
}
