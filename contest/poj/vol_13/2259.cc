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
#define maxn 1000100
using namespace std;
int const mod = 1010;
int parents[maxn];

char str[11];

int Q[200010]; bool mark[1010];

struct node {
    int q[1010], l, h;
} que[1010];

inline int nextInt() {
    char c;c=getchar();
    while(c!='-'&&(c<'0'||c>'9'))c=getchar();
    int n=0,s=1;if(c=='-')s=-1,c=getchar();
    while(c>='0'&&c<='9')n*=10,n+=c-'0',c=getchar();
    return n*s;
}
int A[20],k;
inline void print_int(int x)
{
    if(x<0)putchar('-'),x=-x;
    else if(x == 0){putchar('0'); putchar('\n'); return;}
    k=0;while(x)A[k++]=x%10,x/=10;
    for(int i=k-1;i>=0;i--)putchar('0'+A[i]);
    putchar('\n');
}
int main() {
    int t, n, a, b;
    int _ca = 1;

    while (t = nextInt()) {
        for (int i = 0; i < t; ++i) {
            for (n = nextInt(); n--; ) {
                a = nextInt();
                parents[a] = i;
            }
        }
        int L = 0, H = 0;
        printf("Scenario #%d\n", _ca++);
        memset(mark, false, sizeof mark);
        while (scanf(" %s", str)) {
            if (str[0] == 'S') break;
            else if (str[0] == 'E') {
                a = nextInt();
                b = parents[a];
                if (!mark[b]) {
                    Q[H++] = b;
                    mark[b] = true;
                    que[b].l = que[b].h = 0;
                    que[b].q[ que[b].h++ ] = a;
                }
                else {
                    que[b].q[ que[b].h++ ] = a;
                }
                que[b].h %= mod;
            }
            else {
                b = Q[L];
                a = que[b].q[ que[b].l++ ];
                print_int(a);
                que[b].l %= mod;
                if (que[b].l == que[b].h) {
                    mark[b] = false;
                    ++L;
                }
            }
        }
        putchar(10);
    }
    return 0;
}
