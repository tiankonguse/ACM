/*************************************************************************
  > File Name: MergeSort.cpp
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

void MergeSort(int len, int* array, int* tmparray) {
	if(len <= 1){
		return ;
	}
	int mid = len/2; //[0, len)
	int leftStart = 0, leftEnd = mid; //[0,mid),
	int rightStart = mid, rightEnd = len; //[mid, len)

	MergeSort(leftEnd - leftStart,  array + leftStart, tmparray);
	MergeSort(rightEnd - rightStart, array + rightStart, tmparray);

	int tmpIndex = 0;
	while(tmpIndex < len){
		if(leftStart == leftEnd){//左边没了，右边的直接复制
			tmparray[tmpIndex++] = array[rightStart++];
		}else if(rightStart == rightEnd){//右边的没了，直接复制
			tmparray[tmpIndex++] = array[leftStart++];
		}else if(array[leftStart] < array[rightStart]){
			tmparray[tmpIndex++] = array[leftStart++];
		}else{
			tmparray[tmpIndex++] = array[rightStart++];
		}
	}
	for(tmpIndex=0;tmpIndex<len;tmpIndex++){
		array[tmpIndex] = tmparray[tmpIndex];
	}
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
	MergeSort(n, array, tmparray);
	for (int i = 0; i < n; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");

	return 0;
}
