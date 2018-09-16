/*************************************************************************
  > File Name: QuickSort.cpp
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
void QuickSort(int len, int* array) {
	if(len <= 1){
		return ;
	}
	int leftStart = 1; //[0,leftStart),
	int rightEnd = len-1; //(rightEnd, len)

	while(leftStart < rightEnd){
		if(array[leftStart] > array[0]){
			swap(array[leftStart], array[rightEnd]);
			rightEnd--; //之后的都大于array[0]
		}else{
			leftStart++;//之前的都小于等于array[0]
		}
	}
	//这个时候 leftStart = rightEnd，这个位置进行特殊判断
	if(array[leftStart] > array[0]){
		leftStart--;
		swap(array[leftStart], array[0]);
	}else{
		swap(array[leftStart], array[0]);
	}

	QuickSort(leftStart,  array);//[0, leftStart)
	QuickSort(len - leftStart - 1, array + leftStart + 1);
}

int main() {
	int array[10];
	int tmparray[10];

	for (int i = 0; i < 10; i++) {
		array[i] = 10 - i;
	}

	int n = 8;

	for (int i = 0; i < n; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
	QuickSort(n, array);
	for (int i = 0; i < n; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");

	return 0;
}
