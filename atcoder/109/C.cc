
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long long LL;
typedef unsigned long long ull;
typedef unsigned long long ULL;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
// const int mod = 1e9 + 7;

template <class T>
using min_queue = priority_queue<T, vector<T>, greater<T> >;
template <class T>
using max_queue = priority_queue<T>;

const LL INF = 0x3f3f3f3f3f3f3f3fll;
const double PI = acos(-1.0), eps = 1e-7;
const int inf = 0x3f3f3f3f, ninf = 0xc0c0c0c0, mod = 1000000007;
const int max3 = 2100, max4 = 11100, max5 = 200100, max6 = 2000100;

char str[max3];
string first, second;

char check(char a, char b) {
  if (a == b) {
    return a;
  }
  if (a == 'R' && b == 'S' || b == 'R' && a == 'S') return 'R';
  if (a == 'S' && b == 'P' || b == 'S' && a == 'P') return 'S';
  if (a == 'P' && b == 'R' || b == 'P' && a == 'R') return 'P';
  return a;
}

char solver(int k) {
  while (true) {
    if (k == 0 || first.size() == 1) {
      return first[0];
    }

    if (first.size() % 2 == 1) {
      first = first + first;
    }
    second.clear();
    for (int i = 0; i < first.size(); i += 2) {
      char a = first[i];
      char b = first[i + 1];
      second.push_back(check(a, b));
    }
    first.swap(second);
    k--;
  }
  return 'P';
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  // freopen("out_std.txt", "w", stdout);
#endif
  int n, k;
  while (~scanf("%d%d%s", &n, &k, str)) {
    first = str;
    printf("%c\n", solver(k));
  }

  return 0;
}
