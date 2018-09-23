/*************************************************************************
 > File Name: DoubleLinkedList.cpp
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


struct DoubleLink {
    DoubleLink(int value = 0):_value(value),_next(NULL),_pre(NULL) {}
    int _value;
    struct DoubleLink* _next;
    struct DoubleLink* _pre;
};

void insert(DoubleLink* head, DoubleLink* node) {
    if(head->_next){
        head->_next->_pre = node;
        node->_next = head->_next;
    }
    head->_next = node;
    node->_pre = head;
}

void output(DoubleLink* head) {
    static int times = 0;
    printf("[%d]link ", times);
    while(head != NULL) {
        printf("%d ", head->_value);
        head = head->_next;
    }
    printf("\n");
}

void reoutput(DoubleLink* tail) {
    static int times = 0;
    printf("[%d]relink ", times);
    while(tail != NULL) {
        printf("%d ", tail->_value);
        tail = tail->_pre;
    }
    printf("\n");
}


void testDoubleLink() {
    int value  = 0;
    DoubleLink* node = NULL;
    DoubleLink* head = new DoubleLink(0);
    DoubleLink* tail = head;
    for(int i=1; i<10; i++) {
        node = new DoubleLink(i);
        insert(tail, node);
        tail = node;
    }
    output(head);
    reoutput(tail);
}


int main() {

    testDoubleLink();
    return 0;
}
