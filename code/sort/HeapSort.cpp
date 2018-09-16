/*************************************************************************
 > File Name: HeapSort.cpp
 > Author: tiankonguse(skyyuan)
 > Mail: i@tiankonguse.com
 > Created Time: Sat 15 Sep 2018 02:14:42 PM UTC
 ***********************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
#include<queue>
#include<map>
#include<cmath>
#include<stack>
#include<algorithm>
#include<functional>
#include<stdarg.h>
using namespace std;
#ifdef __int64
typedef __int64 LL;
#else
typedef long long LL;
#endif
void swap(int &first, int& second) {
	int temp = first;
	first = second;
	second = temp;
}
void down_heapify(int len, int* array) {
	int pre = 0;
	while (pre < len) {
		int left = pre * 2 + 1;
		int right = pre * 2 + 2;

		if (right < len) { //有两个儿子
			if (array[left] > array[right] && array[left] > array[pre]) {
				swap(array[left], array[pre]);
				pre = left;
			} else if(array[right] > array[left] && array[right] > array[pre]) {
				swap(array[right], array[pre]);
				pre = right;
			} else {
				break;//已经满足最大堆的性质
			}
		} else if (left < len) { //只有一个儿子
			if (array[left] > array[pre]) {
				swap(array[left], array[pre]);
				pre = left;
			} else {
				break;//已经满足最大堆的性质
			}
		} else {
			break;//没有儿子了
		}
	}
}

void buildMaxHeap(int len, int* array) {
	for (int i = 0; i < len; i++) {
		int node = i;
		int pre = (node - 1) / 2;
		while (node > 0 && array[pre] < array[node]) {
			swap(array[pre], array[node]);
			node = pre;
		}
	}
}

void HeapSort(int len, int* array) {
	buildMaxHeap(len, array);
	for (int i = len - 1; i > 0; i--) {
		swap(array[i], array[0]);
		down_heapify(i, array);
	}
}

void test(int n) {
	int array[10];
	int tmparray[10];
	printf("test case: %d\n", n);

	for (int i = 0; i < n; i++) {
		array[i] = n - i;
	}

	for (int i = 0; i < n; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
	HeapSort(n, array);
	for (int i = 0; i < n; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
}

int main() {

	for(int i=1; i<=10; i++) {
		test(i);
	}
	return 0;
}
