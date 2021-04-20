#include <bits/stdc++.h>
#include <stdio.h>

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

// lower_bound 大于等于
// upper_bound 大于
// reserve vector预先分配内存
// reverse(v.begin(), v.end()) 反转
// sum = accumulate(a.begin(), a.end(), 0);

const LL INF = 0x3f3f3f3f3f3f3f3fll;
const double PI = acos(-1.0), eps = 1e-7;
const int inf = 0x3f3f3f3f, ninf = 0xc0c0c0c0, mod = 1000000007;
const int max3 = 2100, max4 = 11100, max5 = 200100, max6 = 2000100;

char strT[1111111];
char* nowT;
struct Op {
  char op[5];
  LL pos;
  LL c, a, b;
  char* pt;
};
Op ops[5555];

void input(int& q) {
  nowT = strT;
  scanf("%s", nowT);
  Op* p = ops + 0;
  p->op[0] = '+';
  p->pt = nowT;
  nowT += strlen(nowT) + 1;

  scanf("%d", &q);
  for (int i = 1; i <= q; i++) {
    Op* p = ops + i;
    scanf("%s", p->op);
    if (p->op[0] == '+') {
      scanf("%lld%s", &p->pos, nowT);
      p->pt = nowT;
      nowT += strlen(nowT) + 1;
    } else if (p->op[0] == '!') {
      scanf("%lld%lld%lld%lld", &p->a, &p->b, &p->c, &p->pos);
    } else if (p->op[0] == '?') {
      scanf("%lld", &p->pos);
    }
  }
}

map<int, pair<LL, char>> ans;

int main() {
#ifndef ONLINE_JUDGE
  freopen("./in.txt", "r", stdin);
  freopen("./out.txt", "w", stdout);
#endif

  int t, q;
  scanf("%d", &t);
  while (t--) {
    input(q);
    ans.clear();
    for (int i = q; i >= 0; i--) {
      Op* p = ops + i;
      LL pos = p->pos;

      if (p->op[0] == '?') {
        ans[i].first = pos - 1;
        continue;
      }

      LL len = 0;
      if (p->op[0] == '+') {
        len = strlen(p->pt);
      } else {
        len = (p->b - p->a + 1) * p->c;
      }

      for (auto& kv : ans) {
        auto& pp = kv.second;
        if (pp.first == -1 || pp.first < pos) {
          // do nothing
        } else if (pos <= pp.first && pp.first < pos + len) {
          if (p->op[0] == '+') {
            pp.second = p->pt[pp.first - pos];
            pp.first = -1;
          } else {
            pp.first = p->a - 1 + (pp.first - pos) % (p->b - p->a + 1);
          }
        } else {
          pp.first -= len;
        }
      }
    }
    for (auto& kv : ans) {
      printf("%c\n", kv.second.second);
    }
  }

#ifndef ONLINE_JUDGE
  freopen("./diff.txt", "w", stdout);
  system("diff ./out_std.txt ./out.txt | wc -l");
  system("diff ./out_std.txt ./out.txt");
#endif
  return 0;
}

/*
input:
1
abcdedgh
17
? 5
! 3 5 6 7
? 7
? 8
? 9
? 10
? 26
+ 0 uvw
? 1
? 2
? 3
+ 13 xyz
? 13
? 14
? 15
? 16
? 17

output:
e
g
c
d
e
h
u
v
w
e
x
y
z
c

*/