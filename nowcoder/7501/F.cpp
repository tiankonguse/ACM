// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long LL;

template <class T>
using min_queue = priority_queue<T, vector<T>, greater<T> >;
template <class T>
using max_queue = priority_queue<T>;

template <class A, class B>
ostream& operator<<(ostream& s, pair<A, B> const& a) {
  return s << "(" << get<0>(a) << ", " << get<1>(a) << ")";
}

template <size_t n, typename... T>
typename std::enable_if<(n >= sizeof...(T))>::type print_tuple(
    std::ostream&, const std::tuple<T...>&) {}
template <size_t n, typename... T>
typename std::enable_if<(n < sizeof...(T))>::type print_tuple(
    std::ostream& os, const std::tuple<T...>& tup) {
  if (n != 0) os << ", ";
  os << std::get<n>(tup);
  print_tuple<n + 1>(os, tup);
}
template <typename... T>
std::ostream& operator<<(std::ostream& os, const std::tuple<T...>& tup) {
  os << "(";
  print_tuple<0>(os, tup);
  return os << ")";
}

template <class T>
ostream& print_collection(ostream& s, T const& a) {
  s << '[';
  for (auto it = begin(a); it != end(a); ++it) {
    s << *it;
    if (it != prev(end(a))) s << ", ";
  }
  return s << ']';
}
template <class T, class U>
ostream& operator<<(ostream& s, map<T, U> const& a) {
  return print_collection(s, a);
}
template <class T>
ostream& operator<<(ostream& s, set<T> const& a) {
  return print_collection(s, a);
}
template <class T>
ostream& operator<<(ostream& s, vector<T> const& a) {
  return print_collection(s, a);
}

double __startG = clock();
void resetG() { __startG = clock(); }
double curTime() { return (clock() - __startG) / CLOCKS_PER_SEC; }
bool stopNow(double ttl) { return ttl < curTime(); }

template <typename T = int>
T get_signed_int() {
  char c = getchar();
  T ret = 0, neg = 0;
  while (c != '-' && !isdigit(c)) c = getchar();
  if (c == '-') neg = 1, c = getchar();
  do {
    ret = (ret << 3) + (ret << 1) + c - '0';
  } while (isdigit(c = getchar()));
  return neg ? -ret : ret;
}

template <typename T>
void print_int(T x) {
  static char s[60], *s1;
  s1 = s;
  if (!x) *s1++ = '0';
  if (x < 0) putchar('-'), x = -x;
  while (x) *s1++ = (x % 10 + '0'), x /= 10;
  while (s1-- != s) putchar(*s1);
}

const LL INF = 0x3f3f3f3f3f3f3f3fll;
const double PI = acos(-1.0), eps = 1e-7;
const int inf = 0x3f3f3f3f, ninf = 0xc0c0c0c0, mod = 1000000007;
const int max3 = 4100, max4 = 11100, max5 = 200100, max6 = 2000100;

LL a[max5];
LL l[max5], r[max5];
LL lft[max5];

LL k, L, R;

bool check(LL x) {
    if (x == 0) return true;
    LL must = 0;
    //printf("x = %lld\n", x);
    for (int i = 0; i < k; i++) {
        //printf("i = %d, min = %d have = %d\n", i, l[i] * x, a[i]);
        if (l[i] * x > a[i]) return false;
        must += l[i];
        lft[i] = a[i] - l[i] * x;
    }
    //cout << "must = " << must << endl;
    if (must > R) return false;
    LL mxx = 0;
    for (int i = 0; i < k; i++) {
        mxx += min(lft[i], min(r[i] - l[i], R - must) * x);
    }
    //cout << "mxx = " << mxx << " L * x - must = " << L * x - must << endl;
    if (mxx >= (L - must) * x) return true;
    return false;
}

int main() {
    //cin >> k >> L >> R;
    scanf("%lld%lld%lld", &k, &L, &R);
    for (int i = 0; i < k; i++) {
        scanf("%lld", &a[i]);
    }
    for (int i = 0; i < k; i++) {
        scanf("%lld %lld", &l[i], &r[i]);
    }
    LL a = 0, b = INF;
    LL ans = 0;
    while (a <= b) {
        LL m = (a + b) / 2;
        if (check(m)) {
            ans = m;
            a = m + 1;
        } else {
            b = m - 1;
        }
    }
    cout << ans << endl;
    return 0;
}
/*

 4 20 1000
 4 20 10 6
 1 2
 3 5
 2 4
 6 10

 */
