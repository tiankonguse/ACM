/*************************************************************************
 > File Name: LinkedListEx.cpp
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


struct SingleLinkEx {
    SingleLinkEx(int value = 0):_value(value),_next(-1) {}
    int _value;
    int _next;
};

class SingleLinkExPool {
public:
    SingleLinkExPool():_useMax(0),_emptyHead(-1) {}
    SingleLinkEx* get(int index) {
        return &dataPool[index];
    }
    int getNode(int defauleVal = 0) {
        int index = -1;
        //优先从回收池中分配，没有则从未使用的空间分配。
        if(_emptyHead != -1) {
            index = _emptyHead;
            _emptyHead = get(_emptyHead)->_next;
        } else {
            index = _useMax++; //咱不检查边界
        }
        reset(index, defauleVal);
        return index;
    }
    void freeNode(int index) {
        get(index)->_next = _emptyHead;
        _emptyHead = index;
    }
    void insert(int head, int node) {
        get(node)->_next = get(head)->_next;
        get(head)->_next = node;
    }
    void output(int head) {
        static int times = 0;
        printf("[%d]link ", times);
        while(head != -1) {
            printf("pos[%d] value[%d]\n", head, get(head)->_value);
            head = get(head)->_next;
        }
        printf("\n");
    }
private:
    void reset(int index, int defauleVal) {
        get(index)->_value = defauleVal;
        get(index)->_next = -1;
    }
private:
    SingleLinkEx dataPool[100];
    int _useMax;
    int _emptyHead;
};





void testSingleLink() {
    SingleLinkExPool linkPool;
    int head = linkPool.getNode(0);
    int tail = head;
    for(int i=1; i<10; i++) {
        int node = linkPool.getNode(i);
        linkPool.insert(tail, node);
        tail = node;
    }
    linkPool.output(head);
}



int main() {

    testSingleLink();
    return 0;
}
