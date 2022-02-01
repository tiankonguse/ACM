
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
using min_queue = priority_queue<T, vector<T>, greater<T>>;
template <class T>
using max_queue = priority_queue<T>;

const LL INF = 0x3f3f3f3f3f3f3f3fll;
const double PI = acos(-1.0), eps = 1e-7;
const int inf = 0x3f3f3f3f, ninf = 0xc0c0c0c0, mod = 1000000007;
const int max3 = 2100, max4 = 11100, max5 = 200100, max6 = 2000100;

char str[max5];
vector<string> vec;

int main() {
  int n;
  scanf("%d", &n);
  getchar();
  for (int i = 0; i < n; i++) {
    gets(str);
    vec.push_back(str);
  }
  sort(vec.begin(), vec.end());

  int len = 0;
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    string& v = vec[i];
    if (i == 0) {
      len = 1;
    } else {
      string& prev = vec[i - 1];
      int minLen = min(len, (int)v.size());
      int j = 0;
      for (j = 0; j < minLen; j++) {
        if (v[j] != prev[j]) {
          break;
        }
      }
      len = j + 1;
    }
    ans += len;
  }

  printf("%d\n", ans);

  return 0;
}