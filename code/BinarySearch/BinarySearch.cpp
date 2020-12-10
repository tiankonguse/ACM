/*************************************************************************
 > File Name: BinarySearch.cpp
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

int BinarySearch_min_eq(int len, int* array, int value) {

    int left = 0;
    int right = len - 1; //[left, right]
    int mid = 0;

    while(left <= right) {
        mid = (left + right)/2;
        if(array[mid] < value) {
            left = mid + 1; //小于value，答案在右边
        } else if(array[mid] > value) {
            right = mid - 1; //大于value，答案在左边
        } else {
            if(left == right) {
                return mid; //找到了
            } else {
                right = mid; //答案肯定在左边或者是mid
            }
        }
    }
    return -1;//没找到
}

int BinarySearch_min_e_g(int len, int* array, int value) {

    int left = 0;
    int right = len - 1; //[left, right]
    int mid = 0;

    while(left <= right) {
        mid = (left + right)/2;
        if(array[mid] < value) {
            left = mid + 1; //小于value，答案在右边
        } else {
            if(left == right) {
                return mid;//找到了
            } else {
                right = mid;//答案肯定在左边或者是mid
            }
        }
    }

    return -1;
}

int BinarySearch_min_gt(int len, int* array, int value) {

    int left = 0;
    int right = len - 1; //[left, right]
    int mid = 0;

    while(left <= right) {
        mid = (left + right)/2;
        if(array[mid] <= value) {
            left = mid + 1; //小于等于value, 答案在右边
        } else {
            if(left == right) {
                return mid;
            } else {
                right = mid;//答案肯定在左边或者是mid
            }
        }
    }

    return -1;
}

bool check(int mid, int value){
    return 0;
}

int BinarySearch_min_tpl(int len, int* array, int value) {

    int left = 0;
    int right = len - 1; //[left, right]
    int mid = 0;

    while(left <= right) {
        mid = (left + right)/2;
        if(check(mid, value)) {
            //根据情况确认一个边界
        } else {
            if(left == right) {
                return mid; //找到了
            } else {
                //确认另一个边界
            }
        }
    }


    return -1;
}

int BinarySearch_max_lt(int len, int* array, int value) {

    int left = 0;
    int right = len; //[left, right)
    int mid = 0;

    while(left < right) {
        mid = (left + right)/2;
        if(array[mid] >= value) {
            right = mid; //大于等于，答案在左边
        } else {
            if(left + 1 == right) {
                return mid; //找到了
            } else {
                left = mid;
            }
        }
    }

    return -1;
}

void test(int n) {
    int array[100];
    printf("test case: %d\n", n);

    int value = 1;
    for (int i = 0; i < n; i+=3) {
        array[i] = value * 3;
        if(i+1 < n)
            array[i+1] = value * 3;
        if(i+1 < n)
            array[i+2] = value * 3;
        value++;
    }
    for (int i = 0; i < n; i++) {
        printf("%-03d ", i);
    }
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("%-03d ", array[i]);
    }
    printf("\n");
    int pos = 0;
    for(int i=0; i<n; i++) {
        pos = BinarySearch_min_eq(n, array, i);
        printf("action[%-15s] find[%d] pos[%d]\n", "min_eq", i, pos);
    }


    for (int i = 0; i < n; i++) {
        printf("%-03d ", i);
    }
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("%-03d ", array[i]);
    }
    printf("\n");
    for(int i=0; i<n; i++) {
        pos = BinarySearch_min_e_g(n, array, i);
        printf("action[%-15s] find[%d] pos[%d]\n", "min_e_g", i, pos);
    }

    for (int i = 0; i < n; i++) {
        printf("%-03d ", i);
    }
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("%-03d ", array[i]);
    }
    printf("\n");
    for(int i=0; i<n; i++) {
        pos = BinarySearch_min_gt(n, array, i);
        printf("action[%-15s] find[%d] pos[%d]\n", "min_gt", i, pos);
    }

    for (int i = 0; i < n; i++) {
        printf("%-03d ", i);
    }
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("%-03d ", array[i]);
    }
    printf("\n");
    for(int i=0; i<n; i++) {
        pos = BinarySearch_max_lt(n, array, i);
        printf("action[%-15s] find[%d] pos[%d]\n", "max_lt", i, pos);
    }

}

int main() {

    test(21);
    return 0;
}
