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
const int max3 = 2100, max4 = 11100, max5 = 55000, max6 = 2000100;

class DiscreteArray {
 public:
  void Add(ll v) { m[v] = 0; }
  void Build() {
    index = 0;
    for (auto& p : m) {
      p.second = ++index;
    }
  }
  int Get(ll v) { return m[v]; }
  int Size() { return index; }
  int Lower(ll v) {
    auto it = m.lower_bound(v);
    if (it == m.end()) {
      return index + 1;
    }
    return it->second;
  }
  int Upper(ll v) {
    auto it = m.upper_bound(v);
    if (it == m.end()) {
      return index + 1;
    }
    return it->second;
  }
  void Reset() { m.clear(); }

 private:
  int index;
  map<ll, int> m;
};

int main() {
  DiscreteArray discreteArray;
  discreteArray.Reset();
  for (int i = 0; i < 10; i++) {
    discreteArray.Add(i * i);
  }
  discreteArray.Build();
  for (int i = 0; i < 10; i++) {
    printf("v=%d index=%d\n", i * i, discreteArray.Get(i * i));
  }
  for (int i = 0; i < 10; i++) {
    printf("v=%d Lower=%d\n", i, discreteArray.Lower(i));
  }
  for (int i = 0; i < 10; i++) {
    printf("v=%d Upper=%d\n", i, discreteArray.Upper(i));
  }

  return 0;
}