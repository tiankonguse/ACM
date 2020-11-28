/*
 * 2.cpp
 *
 *  Created on: 2017年4月9日
 *      Author: skyyuan
 *        desc: 靠运气AC
 *         url: http://oj.xjtuacm.com/problem/2/
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;
typedef long long LL;

const int mydebug = 0;

#define myprintf(fmt, args...) \
	do { \
		if (mydebug){ \
			printf(fmt, ##args); \
		} \
	} while(0)

int main() {
	int a, b;
	while (~scanf("%d%d", &a, &b)) {
		printf("%d\n", a + b);
	}
	return 0;
}

