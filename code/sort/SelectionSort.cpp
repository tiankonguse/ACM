/*************************************************************************
  > File Name: SelectionSort.cpp
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

void SelectionSort(int len, int* array) {
	for (int i = len - 1; i > 0; i--) {
		int now = 0;
		for (int j = 1; j <= i ; j++) {
			if (array[now] < array[j]) {
				now = j;
			}
		}
		swap(array[now], array[i]);
	}
}

int main() {
	int array[10];

	for(int i=0; i<10; i++) {
		array[i] = 10 - i ;
	}
	
	int n = 7; 
	
	for(int i=0; i<n; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
	SelectionSort(n, array);
	for(int i=0; i<n; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");

	return 0;
}
