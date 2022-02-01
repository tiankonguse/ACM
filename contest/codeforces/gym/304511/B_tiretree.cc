
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

const int kind = 2, N = max5;

class TireTree {
 public:
  int tire[N][kind], word[N], tireVal[N];
  int num = 0;

  void init() {
    memset(tire[0], 0, sizeof(tire[0]));
    memset(tire[1], 0, sizeof(tire[1]));
    tireVal[1] = 1;
    num = 2;
  }
  void insert(ll n, ll val) {
    int p = 1;
    while (n) {
      int i = n % 2;
      if (!tire[p][i]) {
        memset(tire[num], 0, sizeof(tire[num]));
        word[num] = 0;
        tireVal[num] = tireVal[p] * 2 + i;
        tire[p][i] = num++;
      }
      p = tire[p][i];
      n = n / 2;
    }
    word[p] = val;
  }
};

TireTree tireTreeAll;
TireTree tireTreeOne;

ll nums1[max5], nums2[max5], nums3[max5];

struct State {
  ll n;
  int pAll, pOne;
  int flag;
  int pathAll;
  State(ll n, int pAll, int pOne, int flag = 0, int pathAll = 0)
      : n(n), pAll(pAll), pOne(pOne), flag(flag), pathAll(pathAll) {}
};

queue<State> que;

int check(ll val) {
  int ans = 0;

  int pAll = 1, pOne = 1;

  while (!que.empty()) que.pop();
  que.push({val, pAll, pOne});

  printf("val=%lld pAll=%d v[%d] pOne=%d v[%d]\n", val, pAll,
         tireTreeAll.tireVal[pAll], pOne, tireTreeOne.tireVal[pOne]);

  while (!que.empty()) {
    State state = que.front();
    que.pop();

    ll n = state.n;
    int pAll = state.pAll;
    int pOne = state.pOne;
    int flag = state.flag;
    printf("n=%d pAll=%d v[%d] pOne=%d v[%d]\n", n, pAll,
           tireTreeAll.tireVal[pAll], pOne, tireTreeOne.tireVal[pOne]);

    int i = n % 2;
    n = n / 2;

    for (int j = 0; j < kind; j++) {
      int v = j ^ i;
      int newPone = tireTreeOne.tire[pOne][j];
      int newPall = tireTreeAll.tire[pAll][v];

      if (newPone == 0) {
        if (j == 0 && flag) {
          // 标记情况下，可以去左下角
          newPone = pOne;
        } else {
          continue;  // one 父节点非空，其中一个子树不存在
        }
      }
      if (newPall == 0) continue;  //异或后不存在
      printf("match j=%d  newPone=%d v[%d] v=%d  newPall=%d v[%d] \n", j,
             newPone, tireTreeOne.tireVal[newPone], v, newPall,
             tireTreeAll.tireVal[newPall]);

      if (n == 0) {
        //查询结束
        if (tireTreeAll.word[newPall] != 0) {  //数据存在
          ans++;
        }
      } else {
        int newFlag = flag;
        if (tireTreeAll.word[newPone] != 0) {
          newFlag = 1;
        }
        que.push({n, newPall, newPone, newFlag});
      }
    }
  }

  return ans;
}

int main() {
  int n;

  tireTreeAll.init();
  tireTreeOne.init();

  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    ll v;
    scanf("%lld", &v);
    nums1[i] = v;
    nums3[i] = v;
  }

  for (int i = 0; i < n; i++) {
    ll v;
    scanf("%lld", &v);
    nums2[i] = v;
    nums3[n + i] = v;
  }
  sort(nums1, nums1 + n);
  sort(nums2, nums2 + n);
  sort(nums3, nums3 + n * 2);
  for (int i = 0; i < n; i++) {
    tireTreeOne.insert(nums1[i], nums1[i]);
  }
  for (int i = 0; i < 2 * n; i++) {
    tireTreeAll.insert(nums3[i], nums3[i]);
  }

  ll ans = 0;

  for (int i = 0; i < n; i++) {
    ans += check(nums2[i]);
    printf("i=%d ans=%lld\n", i, ans);
  }
  printf("%s\n", ans % 2 == 1 ? "rkmdsxmds Keai" : "Zhuangzhuang Mei Mei Mei");

  return 0;
}