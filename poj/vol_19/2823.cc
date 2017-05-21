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
#include <ctime>

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL

using namespace std;
int const maxn = 1000010;
int arr[maxn];
int q1[maxn], q2[maxn];
int res[maxn][2];
inline int nextInt() {
    char c;c=getchar();
    while(c!='-'&&(c<'0'||c>'9'))c=getchar();
    int n=0,s=1;if(c=='-')s=-1,c=getchar();
    while(c>='0'&&c<='9')n=(n<<3)+(n<<1)+c-'0',c=getchar();
    return n*s;
}
int A[20],k;
inline void print_int(int x)
{
    if(x<0)putchar('-'),x=-x;
    else if(x == 0){putchar('0'); return;}
    k=0;while(x)A[k++]=x%10,x/=10;
    for(int i=k-1;i>=0;i--)putchar('0'+A[i]);
}
int find1(int l, int r, int x){ // a[res] >= x
    int mid;
    while(l <= r){
        mid = (l + r) >> 1;
        if(arr[q1[mid]] >= x) r = mid - 1;
        else l = mid + 1;
    }
    return l;
}
int find2(int l, int r, int x){ // a[res] <= x
    int mid;
    while (l <= r) {
        mid = (l + r) >> 1;
        if(arr[q2[mid]] > x) l = mid + 1;
        else r = mid - 1;
    }
    return l;
}
int main() {
    int n, m;
    while (~scanf("%d%d", &n, &m)) {
        for (int i = 1; i <= n; ++i) arr[i] = nextInt();
        int l1 = 0, h1 = 0, l2 = 0, h2 = 0;
        for (int i = 1; i <= n; ++i) {
            if (h1 - l1 > 100) h1 = find1(l1, h1 - 1, arr[i]);
            else while (l1 < h1 && arr[q1[h1 - 1]] >= arr[i]) --h1;
            if (h2 - l2 > 100) h2 = find2(l2, h2 - 1, arr[i]);
            else while (l2 < h2 && arr[q2[h2 - 1]] <= arr[i]) --h2;
            q1[h1++] = i;
            q2[h2++] = i;
            if (i >= m) {
                res[i][0] = arr[q1[l1]]; if (i - q1[l1] + 1 == m) ++l1;
                res[i][1] = arr[q2[l2]]; if (i - q2[l2] + 1 == m) ++l2;
            }
        }
        for (int k = 0; k < 2; ++k) {
            for (int i = m; i <= n; ++i) {
                print_int(res[i][k]);
                if (i == n) putchar(10);
                else putchar(32);
            }
        }
    }
    return 0;
}
