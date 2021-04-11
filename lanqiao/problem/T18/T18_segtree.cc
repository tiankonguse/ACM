#include <bits/stdc++.h>
using namespace std;

/*
基本功能：单点查询、单点更新
高级功能：区间查询、区间更新、

求面积:
1) 坐标离散化
2) 垂直边按x坐标排序
3) 从左往右用线段树处理垂直边
   累计每个离散x区间长度和线段树长度的乘积

求周长:
1) 坐标离散化
2) 垂直边按x坐标排序, 第二关键字为入边优于出边
3) 从左往右用线段树处理垂直边
   在每个离散点上先加入所有入边, 累计线段树长度变化值
   再删除所有出边, 累计线段树长度变化值
4) 水平边按y坐标排序, 第二关键字为入边优于出边
5) 从上往下用线段树处理水平边
   在每个离散点上先加入所有入边, 累计线段树长度变化值
   再删除所有出边, 累计线段树长度变化值


*/

// 1.bulid(); 2.query(a,b) 3.update(a,b)
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
typedef int LL;
const int maxn = 101000;

int maxNM;

struct SegTree {
  LL sign[maxn << 2];
  LL maxVal[maxn << 2];
  LL sumVal[maxn << 2];

  LL str[maxn];

  void PushUp(int rt) {
    maxVal[rt] = max(maxVal[rt << 1], maxVal[rt << 1 | 1]);
    sumVal[rt] = sumVal[rt << 1] + sumVal[rt << 1 | 1];
  }
  void bulid(int l = 1, int r = maxNM, int rt = 1) {
    sign[rt] = 0;
    if (l == r) {
      sumVal[rt] = maxVal[rt] = str[l];
      return;
    }
    int m = (l + r) >> 1;
    bulid(lson);
    bulid(rson);
    PushUp(rt);
  }
  void update(int L, int R, LL val, int l = 1, int r = maxNM, int rt = 1) {
    if (l == r) {
      sumVal[rt] = maxVal[rt] = str[l] = val;
      return;
    }
    int m = (l + r) >> 1;
    if (L <= m) update(L, R, val, lson);
    if (R > m) update(L, R, val, rson);
    PushUp(rt);
  }
  LL querySum(int L, int R, int l = 1, int r = maxNM, int rt = 1) {
    if (L <= l && r <= R) {
      return sumVal[rt];
    }

    int m = (l + r) >> 1;
    LL ret = 0;
    if (L <= m) {
      ret += querySum(L, R, lson);
    }
    if (m < R) {
      ret += querySum(L, R, rson);
    }
    return ret;
  }
  LL queryMax(int L, int R, int l = 1, int r = maxNM, int rt = 1) {
    if (L <= l && r <= R) {
      return maxVal[rt];
    }
    int m = (l + r) >> 1;
    LL ret = 0;
    if (L <= m) {
      ret = max(ret, queryMax(L, R, lson));
    }
    if (m < R) {
      ret = max(ret, queryMax(L, R, rson));
    }
    return ret;
  }
};

SegTree lineSegTree;

int main() {
  memset(lineSegTree.str, 0, sizeof(lineSegTree.str));
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &lineSegTree.str[i]);
  }
  maxNM = n;

  lineSegTree.bulid(1, n);

  while (m--) {
    int p, x, y;
    scanf("%d%d%d", &p, &x, &y);
    switch (p) {
      case 1:
        lineSegTree.update(x, x, y);
        break;
      case 2:
        printf("%lld\n", lineSegTree.querySum(x, y));
        break;
      case 3:
        printf("%lld\n", lineSegTree.queryMax(x, y));
        break;
      default:
        break;
    }
  }
  return 0;
}
