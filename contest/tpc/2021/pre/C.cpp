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

vector<int> one(100011, 0);
vector<int> two(100011, 0);
vector<int> pre(100011, 0);

int main() {
#ifndef ONLINE_JUDGE
  freopen("./in.txt", "r", stdin);
  freopen("./out.txt", "w", stdout);
#endif

  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d", &one[i]);
    }
    for (int i = 0; i < n; i++) {
      scanf("%d", &two[i]);
    }

    if (one[0] != two[0]) {
      printf("No\n");
      continue;
    }

    int root = 0;

    int onePos = 0;
    int twoPos = 0;
    unordered_set<int> oneSet;
    unordered_set<int> twoSet;
    for (int i = 0; i < n;) {
      onePos = twoPos = i;
      int tmpRoot = one[onePos];
      oneSet.clear();
      twoSet.clear();

      do {
        // printf("%d %d\n", onePos, twoPos);
        int tmpVal = one[onePos];
        pre[tmpVal] = root;

        oneSet.insert(tmpVal);
        if (twoSet.count(tmpVal)) {
          onePos++;
          continue;
        }

        while (twoPos < n && two[twoPos] != tmpVal) {
          twoSet.insert(two[twoPos]);
          twoPos++;
        }
        if (twoPos < n && two[twoPos] == tmpVal) {
          twoSet.insert(two[twoPos]);
          twoPos++;
        }
      } while (oneSet.size() != twoSet.size());
      i = twoPos;
      root = tmpRoot;
      // printf("root=%d\n", root);
    }

    printf("Yes\n");
    for (int i = 1; i <= n; i++) {
      printf("%d%c", pre[i], i < n ? ' ' : '\n');
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
2
8
3 4 8 1 5 6 7 2
3 1 8 4 2 7 5 6
2
1 2
2 1

output:
Yes
3 1 0 3 4 4 8 3
No
*/