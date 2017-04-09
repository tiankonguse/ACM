/*
 * 10.cpp
 *
 *  Created on: 2017年4月9日
 *      Author: skyyuan
 *        desc: 震惊，某世界一流大学学生竟然玩这个…
 *         url: http://oj.xjtuacm.com/problem/10/
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;
typedef long long LL;
const int MAX_POS = 210000;

const int mydebug = 0;

struct Node {
	Node() {
		pos = 0;
		val = 0;
		ai = 0;
	}
	Node(int val) :
			val(val) {
		pos = 0;
		ai = 0;
	}
	int ai;
	int pos;
	int val;
	bool operator<(const Node &t2) const {
		return this->val < t2.val;
	}
};

class Work {
	enum DIR {
		DOWM = 0, //
		UP = 1
	};
public:

	Work(int n) :
			n(n) {
	}
	/*
	 * 这里暂且假设出入是递增的
	 */
	void read() {
		for (int i = 0; i < n; i++) {
			scanf("%d", &node[i].val);
			node[i].pos = i + 1;
		}
	}
	void bulid() {
		std::sort(node, node + n);

		for (int i = 0; i < n; i++) {
			pos[node[i].pos] = i;
		}

		for (int i = 0; i < n; i++) {
			node[i].ai = i;
		}

		if (mydebug) {
			for (int i = 0; i < n; i++) {
				printf("i=%d pos=%d val=%d\n", i, node[i].pos, node[i].val);
			}
		}
	}

	/*
	 * ai: 当前位置
	 * li: 剩余长度
	 * 方向: 规定永远朝下
	 * 注意: 两种情况会结束
	 * 	1. 恰好长度为0, 为0那个位置为答案
	 * 	2. 永远不会遇到其他位置了, 单点打转
	 *
	 * 转圈规则:
	 *  0. 起始位置为A
	 * 	1. 朝下转, 遇到折点B
	 * 	2. 如果还没有结束, 朝上转, 遇到折点C
	 * 	3. 如果A与C相同, 说明朝下朝上都是这两个点, 则需要取模, 取模长度为 AB+BC, 否则直接减去AB+BC进行递归
	 */
	int recursive(const int ai, const int li) {
		if (mydebug) {
			printf("in=> ai[%d] li[%d]\n", ai, li);
		}
		//边界1
		if (li == 0) {
			if (mydebug) {
				printf("end 0 => [%d]\n", ai);
			}

			return ai;
		}

		int nowVal = node[ai].val;

		//找到朝下的折点, 有可能就是自己
		const Node* pDownVal = std::lower_bound(node, node + n, nowVal + li);
		if (pDownVal == node + n) {
			pDownVal--;
		}
		if (pDownVal->val > nowVal + li) {
			pDownVal--;
		}
		int downVal = pDownVal->val;
		if (mydebug) {
			printf("down find ai[%d] val[%d]\n", pDownVal->ai, pDownVal->val);
		}

		int downLeft = li - (downVal - nowVal);
		//边界1
		if (downLeft == 0) {
			if (mydebug) {
				printf("end 1 => [%d]\n", pDownVal - node);
			}
			return pDownVal - node;
		}

		//此时该朝上转了
		const Node* pUpVal = std::lower_bound(node, node + n,
				downVal - downLeft);
		int upVal = pUpVal->val;
		if (mydebug) {
			printf("up find ai[%d] val[%d]\n", pUpVal->ai, pUpVal->val);
		}

		int oneLoopLen = (downVal - nowVal) + (downVal - upVal);

		//边界2: 向下向上都没有遇到其他折点
		if (oneLoopLen == 0) {
			if (mydebug) {
				printf("end 2 => [%d]\n", pDownVal - node);
			}
			return pDownVal - node;
		}

		//不需要原地打转, 进行递归
		if (nowVal != upVal) {
			if (mydebug) {
				printf("go => [%d]\n", pUpVal->ai);
			}
			return recursive(pUpVal->ai, li - oneLoopLen);
		}

		//转了一圈回到原点的, 可能会转很多圈, 需要取模
		if (mydebug) {
			printf("loop go => [%d]\n", pUpVal->ai);
		}
		return recursive(pUpVal->ai, li - (li / oneLoopLen) * oneLoopLen);
	}

	/*
	 * 根据测试样例
	 * 可以知道序号是从1开始: ai: [1, n]
	 * li 可能很大, 需要取模
	 */
	int getAns(int ai, int li) {
		//特殊处理
		if (n == 1) {
			return ai;
		}

		//第一步, ai位置映射
		ai = pos[ai];

		//第二步递归求值
		int ans = recursive(ai, li);

		//第三部映射位置
		return node[ans].pos;
	}
private:
	int n;
	Node node[MAX_POS];
	int pos[MAX_POS];
};

void test() {
	int a[5] = { 5 * 2, 4 * 2, 3 * 2, 2 * 2, 1 * 2 };
	std::sort(a, a + 5);
	for (int i = 0; i < 5; i++) {
		printf("i=%d %d [%p]\n", i, a[i], a + i);
	}
	printf("a[%p] a+4[%p] a+5[%p]\n", a, a + 4, a + 5);

	int val;
	while (~scanf("%d", &val)) {
		int* p = std::lower_bound(a, a + 5, val);
		if (p == a + 5) {
			printf("last\n");
		} else {
			printf("%p %d\n", p, *p);
		}
	}

}

int main() {
	//test();
	int n, m;
	int ai;
	int li;
	while (~scanf("%d", &n)) {
//		scanf("%d", &n);
		scanf("%d", &m);
		Work work(n);
		work.read();
		work.bulid();
		while (m--) {
			scanf("%d%d", &ai, &li);
			printf("%d\n", work.getAns(ai, li));
		}
	}
	return 0;
}

/*
 *
 * n:6
 * pos: 0 1  50 51  99 100
 *
 * 1. 上区间循环
 *   q: (1 0) (1 1) (1 2) (1 3)  ... (1 49)
 *      (1 199) ... (1 200)
 *
 * 2. 中间区间循环
 * 	 q: (1 50) (1 51) (1 52) (1 53) ... (1 98)
 * 	    (1 149)  ... (1 198)
 *
 * 3. 下区间循环
 *   q: (1 99) (1 100) (1 101) ... (1 148)
 *
 *
 *
 *
 *
 */
