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
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define Rep(i, n) for (int i = 1; i <= (n); ++i)
#define clr(x, a) memset(x, (a), sizeof x)
using namespace std;
typedef long long ll;
int const N = 1010;
struct Node {
  int l, r;
} p[N];

int main() {
  int n = 0;
  char op[2]; int a, b;
  while (~scanf(" %s %d %d", op, &a, &b)) {
    if (op[0] == '+') {
      int ret = 0;
      rep(i, n) if (p[i].l >= a && p[i].r <= b) {
        ++ret;
      }
      p[n].l = a, p[n].r = b, ++n;
      printf("%d\n", ret);
    } else {
      rep(i, n) if (p[i].l == a && p[i].r == b) {
        swap(p[i], p[--n]);
        break;
      }
    }
  } 
  return 0;
}

