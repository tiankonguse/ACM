#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX_N = 200000;

int sumTree[2 * MAX_N];
int maxTree[2 * MAX_N];

int n;

void init(int nn) {
    n = 1;
    while (n < nn) {
        n *= 2;
    }

    memset(sumTree, 0, sizeof(sumTree));
    memset(maxTree, 0, sizeof(maxTree));
}

void updateSumTree(int index, int val) {
    // 求叶子节点
    int k = index + n - 1;
    sumTree[k] = val;
    // 向上更新
    while (k > 0) {
        k = (k - 1) / 2;
        sumTree[k] = sumTree[2 * k + 1] + sumTree[2 * k + 2];
    }
}

// 把下表为index的元素值改为val
void updateMaxTree(int index, int val) {
    // 求叶子节点
    int k = index + n - 1;
    maxTree[k] = val;
    // 向上更新
    while (k > 0) {
        k = (k - 1) / 2;
        maxTree[k] = max(maxTree[2 * k + 1], maxTree[2 * k + 2]);
    }
}

// 求区间[a, b)的最大值
// k是节点的编号 节点管理的区间是[l, r)
// 最外层调用queryMaxTree(a, b, 0, 0, n)
int queryMax(int a, int b, int k, int l, int r) {
    // [a, b)与[l, r)不相交
    if (r <= a || b <= l) {
        return -1;
    }
    // 如果[a, b)完全包含[l, r) 则返回当前节点的值
    if (a <= l && r <= b) {
        return maxTree[k];
    } else {
        // 返回两个儿子中较大者
        int val1 = queryMax(a, b, 2 * k + 1, l, (l + r) / 2);
        int val2 = queryMax(a, b, 2 * k + 2, (l + r) / 2, r);
        return max(val1, val2);
    }
}

int querySum(int a, int b, int k, int l, int r) {
    // [a, b)与[l, r)不相交
    if (r <= a || b <= l) {
        return 0;
    }
    // 如果[a, b)完全包含[l, r) 则返回当前节点的值
    if (a <= l && r <= b) {
        return sumTree[k];
    } else {
        // 返回两个儿子的和
        int val1 = querySum(a, b, 2 * k + 1, l, (l + r) / 2);
        int val2 = querySum(a, b, 2 * k + 2, (l + r) / 2, r);
        return val1 + val2;
    }
}

// 编程0-indexed
// 题目1-indexed
int main() {
    int nn, m;
    scanf("%d%d", &nn, &m);
    init(nn);
    for (int i = 0; i < nn; i++) {
        int temp;
        scanf("%d", &temp);
        updateSumTree(i, temp);
        updateMaxTree(i, temp);
    }
    for (int i = 0; i < m; i++) {
        int p, x, y;
        scanf("%d%d%d", &p, &x, &y);
        if (p == 1) {
            // 修改格子x - 1的权值为y
            updateSumTree(x - 1, y);
            updateMaxTree(x - 1, y);
        } else if (p == 2) {
            // 求区间[x - 1, y)的权值和
            printf("%d\n", querySum(x - 1, y, 0, 0, n));
        } else {
            // 求区间[x - 1, y)的最大值
            printf("%d\n", queryMax(x - 1, y, 0, 0, n));
        }
    }
    return 0;
}