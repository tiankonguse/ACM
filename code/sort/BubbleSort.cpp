/*************************************************************************
  > File Name: BubbleSort.cpp
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

void bubbleSort(int len, int* array) {
	for (int i = len - 1; i > 0; i--) {
		for (int j = 0; j < i ; j++) {
			if (array[j] > array[j+1]) {   
				swap(array[j], array[j+1]);
			}
		}
	}
}

int main() {
	int array[10];

	for(int i=0; i<10; i++) {
		array[i] = 10-i;
	}
	int n = 9; 
	for(int i=0; i<n; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
	bubbleSort(n, array);
	for(int i=0; i<n; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");

	return 0;
}
