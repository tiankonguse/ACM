/*************************************************************************
 > File Name: LinkedList.cpp
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


struct SingleLink {
    SingleLink(int value = 0):_value(value),_next(NULL) {}
    int _value;
    struct SingleLink* _next;
};

void insert(SingleLink* head, SingleLink* node) {
    node->_next = head->_next;
    head->_next = node;
}

void append(SingleLink* head, SingleLink* node) {
    while(head->_next != NULL) {
        head = head->_next;
    }
    insert(head, node);
}

SingleLink* find(SingleLink* head, int value) {
    while(head != NULL) {
        if(head->_value == value)break;
        head = head->_next;
    }
    return head;
}

void output(SingleLink* head) {
    static int times = 0;
    printf("[%d]link ", times);
    while(head != NULL) {
        printf("%d ", head->_value);
        head = head->_next;
    }
    printf("\n");
}

void testSingleLink() {
    int value  = 0;
    SingleLink* node = NULL;
    SingleLink* head = new SingleLink(0);
    for(int i=1; i<10; i++) {
        node = new SingleLink(i);
        append(head, node);
    }
    output(head);

    value = 4;
    node = find(head, value);
    if(node == NULL) {
        printf("value[%d] not find\n", value);
    } else {
        printf("value[%d] find, insert after[%d]\n", value, value*value);
        SingleLink* newnode = new SingleLink(value*value);
        insert(node, newnode);
    }
    output(head);
}



int main() {

    testSingleLink();
    return 0;
}
