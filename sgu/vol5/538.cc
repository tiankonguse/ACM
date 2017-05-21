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
#include <ctime>
#include <map>

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define Rep(i, n) for (int i = 1; i <= (n); ++i)
#define clr(x, a) memset(x, (a), sizeof x)
using namespace std;
typedef long long ll;
int const N = 100100;
char s[N];

int main() {
  gets(s);
  int n = strlen(s);
  int t = 0, ans = 0;
  rep(i, n) {
    if(s[i] == '(') {
      ++t;
    } else if (s[i] == ')') {
      if (t > 0) {
        --t;
        ans += t;
        t = 0;
      } else {
        ++ans;
      }
    } else if (!islower(s[i]) && !isupper(s[i]) && s[i] != ' ') {
      ans += t;
      t = 0;
    }
  }
  ans += t;
  printf("%d\n", ans);
  return 0;
}

