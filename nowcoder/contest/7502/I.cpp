// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

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
    if (n != 0)
        os << ", ";
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
        if (it != prev(end(a)))
            s << ", ";
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
void resetG() {
    __startG = clock();
}
double curTime() {
    return (clock() - __startG) / CLOCKS_PER_SEC;
}
bool stopNow(double ttl) {
    return ttl < curTime();
}

template <typename T = int>
T get_signed_int() {
    char c = getchar();
    T ret = 0, neg = 0;
    while (c != '-' && !isdigit(c))
        c = getchar();
    if (c == '-')
        neg = 1, c = getchar();
    do {
        ret = (ret << 3) + (ret << 1) + c - '0';
    } while (isdigit(c = getchar()));
    return neg ? -ret : ret;
}

template <typename T>
void print_int(T x) {
    static char s[60], *s1;
    s1 = s;
    if (!x)
        *s1++ = '0';
    if (x < 0)
        putchar('-'), x = -x;
    while (x)
        *s1++ = (x % 10 + '0'), x /= 10;
    while (s1-- != s)
        putchar(*s1);
}

const LL INF = 0x3f3f3f3f3f3f3f3fll;
const double PI = acos(-1.0), eps = 1e-7;
const int inf = 0x3f3f3f3f, ninf = 0xc0c0c0c0, mod = 1000000007;
const int max3 = 2100, max4 = 11100, max5 = 200100, max6 = 2000100;

char A[max3];
char B[max3];
int lenA, lenB;

int dp[max3][max3];
int dfs(int a, int b) {
    if(dp[a][b] != -1) {
        return dp[a][b];
    }

    int leftA = lenA - a;
    int leftB = lenB - b;
    int ans = 0;

    if(a == lenA) {
        ans = leftB;    // B 可以随便选
    } else if(b == lenB) {
        ans = 0;       //  A 不能选
    } else if(A[a] < B[b]) {
        ans = leftA + leftB; // 全选
    } else if(A[a] == B[b]) {
        ans = 2 + dfs(a + 1, b + 1);
        ans = max(dfs(a, b + 1), ans);
        ans = max(dfs(a + 1, b    ), ans);
    } else if(A[a] > B[b]) {
        ans = max(dfs(a, b + 1), ans);
        ans = max(dfs(a + 1, b    ), ans);
    }
    //printf("a=%d b=%d ans=%d\n", a,b,ans);
    return dp[a][b] = ans;
}

int main() {
    while (scanf("%s%s", A, B) != EOF) {
        lenA = strlen(A);
        lenB = strlen(B);
        for(int i=0; i<=lenA+2; i++) {
            memset(dp[i], -1, sizeof(int)* (lenB + 2));
        }
        printf("%d\n", dfs(0, 0));
    }
    return 0;
}
