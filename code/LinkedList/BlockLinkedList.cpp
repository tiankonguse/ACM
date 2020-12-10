/*************************************************************************
 > File Name: BlockLinkedList.cpp
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

const int MAX_ARRAY = 100;
const int HALF_ARRAY = MAX_ARRAY/2;

struct BlockLink {
    BlockLink():_next(NULL),_useSize(0) {}
    int _vecValue[MAX_ARRAY]; //假设最多1W个数据，这里开方为100
    struct BlockLink* _next;
    int _useSize;
};

class BlockLinkPool {
public:
    BlockLinkPool():head(NULL) {
    }
    void append(int value) {
        if(head == NULL) {
            head = new BlockLink();
        }
        struct BlockLink* it = head;
        while(it->_next != NULL) {
            it = it->_next;
        }
        if(it->_useSize == MAX_ARRAY) {
            it->_next = new BlockLink();
            it = it->_next;
        }
        it->_vecValue[it->_useSize++] = value;
    }
    //从0开始
    int& get(int index) {
        struct BlockLink* it = head;//假设不会越界
        while(it->_useSize <= index) {
            index -= it->_useSize;
            it = it->_next;
        }
        return it->_vecValue[index];
    }
    void set(int index, int value) {
        get(index) = value;
    }
    //定义：插入在index位置之前,从0开始
    void insert(int index, int value) {
        struct BlockLink* it = head;//假设不会越界
        while(it->_useSize <= index) {//等于的时候是下个数组的起始位置
            index -= it->_useSize;
            it = it->_next;
        }
        if(it->_useSize == MAX_ARRAY) {
            struct BlockLink* newNode = new BlockLink();
            newNode->_next = it->_next;
            it->_next = newNode;

            //先分一半到新数组
            int newSize = HALF_ARRAY;
            int leftStart = newSize;
            for(int i=0; leftStart < MAX_ARRAY; i++, leftStart++) {
                newNode->_vecValue[i] = it->_vecValue[leftStart];
            }
            newNode->_useSize = leftStart - newSize;
            it->_useSize -= leftStart - newSize;

            //再次查找
            if(it->_useSize <= index) {
                index -= it->_useSize;
                it = it->_next;
            }
        }

        //从后向前移动
        for(int i = it->_useSize - 1; i >= index; i--) {
            it->_vecValue[i+1] = it->_vecValue[i];
        }
        it->_vecValue[index] = value;

    }
    //定义：插入在index位置之前,从0开始
    void remove(int index) {
        struct BlockLink* it = head;//假设不会越界
        while(it->_useSize <= index) {//等于的时候是下个数组的起始位置
            index -= it->_useSize;
            it = it->_next;
        }
        //从后向前移动
        for(int i = index; i < it->_useSize; i++) {
            it->_vecValue[i] = it->_vecValue[i+1];
        }
        it->_useSize--;

        //检查是否需要合并, 之和小于数组的一半就合并
        if(it->_next != NULL && it->_useSize + it->_next->_useSize < HALF_ARRAY) {
            struct BlockLink* delNode = it->_next;
            for(int i = 0; i < delNode->_useSize; i++, it->_useSize++) {
                it->_vecValue[it->_useSize] = delNode->_vecValue[i];
            }
            it->_next = it->_next->_next;
            delete delNode;
        }

    }
private:
    struct BlockLink* head;
};



void testSingleLink() {

}



int main() {

    testSingleLink();
    return 0;
}
