
#include <bits/stdc++.h>

using namespace std;

const int inf = 0x3f3f3f3f;
const int max5 = 200100;

// 1.bulid(); 2.query(a,b) 3.update(a,b)
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
const int maxn = max5;

typedef int LL;
int maxNM = 0;
LL kMaxVal = inf;

struct SegTree {
  LL sign[maxn << 2];  //
  LL minVal[maxn << 2];
  LL maxMal[maxn << 2];

  LL str[maxn];

  void PushUp(int rt) {
    minVal[rt] = min(minVal[rt << 1], minVal[rt << 1 | 1]);
    maxMal[rt] = max(maxMal[rt << 1], maxMal[rt << 1 | 1]);
  }
  void PushDown(int rt) {
    if (sign[rt]) {
      sign[rt << 1] += sign[rt];
      sign[rt << 1 | 1] += sign[rt];

      minVal[rt << 1] += sign[rt];
      minVal[rt << 1 | 1] += sign[rt];

      maxMal[rt << 1] += sign[rt];
      maxMal[rt << 1 | 1] += sign[rt];
      sign[rt] = 0;
    }
  }
  void bulid(int l = 1, int r = maxNM, int rt = 1) {
    sign[rt] = 0;
    if (l == r) {
      minVal[rt] = maxMal[rt] = str[l];
      return;
    }
    int m = (l + r) >> 1;
    bulid(lson);
    bulid(rson);
    PushUp(rt);
  }
  void update(int L, int R, int add, int l = 1, int r = maxNM, int rt = 1) {
    if (L <= l && r <= R) {
      sign[rt] += add;
      minVal[rt] += add;
      maxMal[rt] += add;
      return;
    }
    PushDown(rt);
    int m = (l + r) >> 1;
    if (L <= m) update(L, R, add, lson);
    if (R > m) update(L, R, add, rson);
    PushUp(rt);
  }
  LL queryMin(int L, int R, int l = 1, int r = maxNM, int rt = 1) {
    if (L <= l && r <= R) {
      return minVal[rt];
    }
    PushDown(rt);
    int m = (l + r) >> 1;
    LL ret = kMaxVal;
    if (L <= m) {
      ret = min(ret, queryMin(L, R, lson));
    }
    if (m < R) {
      ret = min(ret, queryMin(L, R, rson));
    }
    return ret;
  }
  LL queryMax(int L, int R, int l = 1, int r = maxNM, int rt = 1) {
    if (L <= l && r <= R) {
      return maxMal[rt];
    }
    PushDown(rt);
    int m = (l + r) >> 1;
    LL ret = -1;
    if (L <= m) {
      ret = max(ret, queryMax(L, R, lson));
    }
    if (m < R) {
      ret = max(ret, queryMax(L, R, rson));
    }
    return ret;
  }
};

SegTree segTree;

int str[max5];
pair<int, int> subfixpMax[max5];
unordered_map<int, int> m;

int n;

int findLast(int val, int minLeft) {
  if (val < str[n] || val > str[minLeft]) {
    return 0;
  }

  // 肯定有答案
  int l = minLeft, r = n;
  while (l < r) {
    int mid = (l + r) / 2;
    if (subfixpMax[mid].first <= val) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  return r - 1;
}

int check(int val, int l) {
  // 答案是最大值已经特殊判断
  // 所以如果可以找到答案，答案一定不是中间的最大值
  // 所以肯定可以找到大于 val 的边界
  //   printf("check: val = %d l = %d r = %d\n", val, l, n);
  if (val >= segTree.queryMax(l, n)) {
    return 0;  //最大值是答案的场景已经特殊判断了
  }
  //此时肯定可以找到一个大于 val 的值
  int r = findLast(val, l);
  //   printf("last > val pos : r = %d\n", r);
  if (r < l) return 0;

  // 此时需要判断中间的最小值
  if (segTree.queryMin(l, r) > val) {
    r++;
    if (r == n) return 0;
    if (segTree.queryMin(l, r) < val) return 0;
  }

  int minVal = segTree.queryMin(l, r);
  int maxVal = segTree.queryMax(r + 1, n);
  if (minVal == val && maxVal == val) {
    return r;  //满足定义
  }
  return 0;
}

pair<int, int> solver() {
  // 初始化线段树
  maxNM = n;
  for (int i = 1; i <= n; i++) {
    segTree.str[i] = str[i];
  }
  segTree.bulid();

  // 初始化数据统计
  m.clear();
  for (int i = 1; i <= n; i++) {
    m[str[i]]++;
  }

  // 计算后缀最大值与个数
  subfixpMax[n + 1] = {0, 0};
  for (int i = n; i >= 1; i--) {
    if (str[i] == subfixpMax[i + 1].first) {
      subfixpMax[i] = {str[i], subfixpMax[i + 1].second + 1};
    } else if (str[i] > subfixpMax[i + 1].first) {
      subfixpMax[i] = {str[i], 1};
    } else {
      subfixpMax[i] = subfixpMax[i + 1];
    }
  }

  //   printf("max: ");
  //   for (int i = 1; i <= n; i++) {
  //     printf("%d ", subfixpMax[i].first);
  //   }
  //   printf("\n");

  if (subfixpMax[1].second >= 3) {
    //最大值有三个，可以直接构造出答案来
    int maxVal = subfixpMax[1].first;
    int num = 0;
    for (int i = 1; i <= n; i++) {
      if (str[i] == maxVal) {
        num++;
        if (num > 1) {
          return {i - 1, i};
        }
      }
    }
  }

  for (int i = 1; i <= n - 2; i++) {
    int v = segTree.queryMax(1, i);
    if (m[v] < 3) continue;  //剪枝

    // printf("v = %d num=%d count=%d\n", v, m[v], m.count(v));
    int pos = check(v, i + 1);
    // printf("v = %d i = %d pos = %d\n", v, i, pos);
    if (pos > i) {
      return {i, pos};
    }
  }

  return {0, 0};
}

int main() {
#ifndef ONLINE_JUDGE
//   freopen("in.txt", "r", stdin);
//   freopen("out.txt", "w", stdout);
// freopen("out_std.txt", "w", stdout);
#endif
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
      scanf("%d", &str[i]);
    }

    pair<int, int> ans = solver();

    if (ans.first == 0) {
      printf("NO\n");
    } else {
      int l = ans.first, r = ans.second;
      printf("YES\n");
      printf("%d %d %d\n", l, r - l, n - r);
    }
  }
  return 0;
}