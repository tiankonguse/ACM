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
const int maxn = 1111;

int maxNM;

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

SegTree lineSegTree;

int main() {
  memset(lineSegTree.str, 0, sizeof(lineSegTree.str));
  lineSegTree.update(1, 12, -3);
  lineSegTree.bulid();
  int nowVal = lineSegTree.queryMin(3, 5);
  return 0;
}
