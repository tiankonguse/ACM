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
const int max3 = 2100, max4 = 11100, max5 = 200100, max6 = 2000100;

LL x[max3][max3];
LL kil[max3];
vector<pair<int, LL>> vec[max3];

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, m, a, b;
        scanf("%d %d %d %d", &n, &m, &a, &b);

        memset(kil, 0, sizeof kil);

        for (int i = 1; i <= n; i++) {
            vec[i].clear();
            for (int j = 1; j <= m; j++) {
                scanf("%lld", &x[i][j]);
                //x[i][j] = get_signed_int();
            }
        }
        bool ok = true;
        for (int i = 1; i <= n && ok; i++) {
            int abve = i - a;
            if (abve >= 1) {
                for (int j = 0; j < vec[abve].size(); j++) {
                    int st = vec[abve][j].first;
                    LL val = vec[abve][j].second;
                    kil[st] += val;
                    kil[st + b] -= val;
                }
            }
            LL sum = 0;
            for (int j = 1; j <= m; j++) {
                sum += kil[j];
                LL now = x[i][j] + sum;
                if (now < 0) {
                    ok = false;
                    break;
                } else if (now > 0) {
                    if (i + a - 1 > n || j + b - 1 > m) {
                        ok = false;
                        break;
                    }
                    vec[i].push_back({j, now});
                    // printf("i = %d, %d %d val = %d\n", i, j, j + b - 1, now);
                    kil[j] -= now;
                    kil[j + b] += now;
                    sum -= now;
                    // printf("sum = %d\n", sum);
                }
            }
        }
        if (ok) {
            puts("^_^");
        } else {
            puts("QAQ");
        }
    }
    return 0;
}
