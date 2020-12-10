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


struct LoopDoubleLink {
    LoopDoubleLink(int value = 0):_value(value) {
        _pre = _next = this;
    }
    int _value;
    struct LoopDoubleLink* _next;
    struct LoopDoubleLink* _pre;
};

void insert(LoopDoubleLink* head, LoopDoubleLink* node) {
    //绑定 next 与 Node的关系
    node->_next = head->_next;
    head->_next->_pre = node;
    //绑定 head 与 node的关系
    head->_next = node;
    node->_pre = head;
}

void output(LoopDoubleLink* head) {
    static int times = 0;
    printf("[%d]link %d", times, head->_value);
    LoopDoubleLink* it = head->_next;
    while(it != head) {
        printf(" %d", it->_value);
        it = it->_next;
    }
    printf("\n");
}

void testDoubleLink() {
    LoopDoubleLink* head = new LoopDoubleLink(0);
    for(int i=1; i<10; i++) {
        LoopDoubleLink*  node = new LoopDoubleLink(i);
        insert(head->_pre, node);
    }
    output(head);
}


int main() {

    testDoubleLink();
    return 0;
}
