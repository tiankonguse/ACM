
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
const int max3 = 2100, max4 = 21100, max5 = 200100, max6 = 2000100;

struct NodeIndo {
  vector<int> edges;
  int isLoop;
  int prefixNum;
};
vector<NodeIndo> vecNode;
vector<int> loopNode;

int flag[max5];
ll ans;

// 寻找环
int dfsLoop(int now, int pre) {
  if (flag[now]) {
    // 遇到环，结束循环
    return now;
  }
  flag[now] = 1;

  for (auto v : vecNode[now].edges) {
    if (v == pre) continue;
    int ret = dfsLoop(v, now);
    if (ret != 0) {
      if (ret > 0) {
        vecNode[now].isLoop = 1;
        loopNode.push_back(now);
      }
      if (ret == now) {
        ret = -1;
      }
      return ret;
    }
  }
  return 0;
}

int dfsPrefix(int now, int pre) {
  int num = 1;
  for (auto v : vecNode[now].edges) {
    if (v == pre) continue;
    if (vecNode[v].isLoop) continue;
    num += dfsPrefix(v, now);
  }
  return num;
}

int main() {
  int t;
  ll n;
  scanf("%d", &t);
  while (t--) {
    scanf("%lld", &n);
    vecNode.clear();
    vecNode.resize(n + 1);
    for (int i = 1; i <= n; i++) {
      vecNode[i].isLoop = 0;

      int u, v;
      scanf("%d%d", &u, &v);
      vecNode[u].edges.push_back(v);
      vecNode[v].edges.push_back(u);
    }

    loopNode.clear();
    memset(flag, 0, sizeof(int) * (n + 1));
    dfsLoop(1, 0);

    for (int i = 1; i <= n; i++) {
      if (vecNode[i].isLoop == 0) continue;
      vecNode[i].prefixNum = dfsPrefix(i, 0);
    //   printf("i=%d prefixNum=%d\n", i, vecNode[i].prefixNum);
    }

    ans = n * (n - 1) / 2;
    // printf("n=%lld baseAns=%lld\n", n, ans);

    ll sum = 0;
    for (int i = 1; i <= loopNode.size(); i++) {
      int now = loopNode[i - 1];
      sum += vecNode[now].prefixNum;
    }

    for (int i = 1; i <= loopNode.size(); i++) {
      int now = loopNode[i - 1];
      sum -= vecNode[now].prefixNum;
      ans += vecNode[now].prefixNum * sum;
    }


    printf("%lld\n", ans);
  }
  return 0;
}