/*************************************************************************
 > File Name: array.cpp
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

void base() {
    const int N = 10;
    int array[N];
    for(int i=0; i<N; i++) {
        array[i] = i * i;
    }
    for(int i=0; i<N; i++) {
        printf("%d\n", array[i]);
    }
}

/*
    int capacity() {
        return _capacity;
    }
    int& operator[](int index) {
        return this->_data[index];
    }
    const int& operator[](int index)const {
        return this->_data[index];
    }
*/

class LoopQueue {
public:
    LoopQueue():_data(NULL),_capacity(0),_size(0),_head(0),_tail(0) {}
    void push(int value) {
        if(_size == _capacity) this->grow();//已经满了
        if(_tail == _capacity) _tail = 0;//队尾移到最后了
        this->_data[_tail++] = value;
        _size++;
    }
    void pop() {
        _head++;
        _size--;
        if(_head == _capacity) _head = 0;//队首移到最后了
    }
    int front() {
        return this->_data[_head];
    }
    bool empty() {
        return _size == 0;
    }
private:
    void grow() {
        _capacity = (_capacity + 1) * 2;
        int* newdata = new int[_capacity];
        if(_data != NULL) {//空间copy
            memcpy(newdata, _data+_head, sizeof(int) * _size - _head);
            memcpy(newdata + _size - _head, _data, sizeof(int) * _head);
            delete[] _data;
            _head=0;
            _tail=_size;
        }
        _data = newdata;
    }
private:
    int* _data;
    int _capacity;
    int _size;
    int _head;
    int _tail;
};

void testLoopQueue() {
    printf("DoubleQueue\n");
    LoopQueue loopQueue;
    loopQueue.push(1);
    loopQueue.push(2);
    loopQueue.pop();
    loopQueue.push(3);


    printf("index[%d] value[%d]\n", loopQueue.head(), loopQueue.front());
    loopQueue.push(4);
    printf("index[%d] value[%d]\n", loopQueue.head(), loopQueue.front());
    loopQueue.pop();
    printf("index[%d] value[%d]\n", loopQueue.head(), loopQueue.front());
    loopQueue.pop();
    printf("index[%d] value[%d]\n", loopQueue.head(), loopQueue.front());

}

class FullArray {
public:
    FullArray():_data(NULL),_capacity(0),_size(0) {
    }
    ~FullArray() {
        if(_data != NULL) {
            delete[] _data;
            _data = NULL;
        }
    }
    int size() {
        return _size;
    }
    void push_back(int value) {
        if(_size == _capacity) {
            this->grow();
        }
        this->_data[_size++] = value;
    }
    void pop_back() {
        _size--;
    }
    const int& at(int index)const {
        return this->_data[index];
    }
    int& at(int index) {
        return this->_data[index];
    }
protected:
    void grow() {
        _capacity = (_capacity + 1) * 2;
        int* newdata = new int[_capacity];
        if(_data != NULL) {
            memcpy(newdata, _data, sizeof(int) * _size);
            delete[] _data;
        }
        _data = newdata;
    }
protected:
    int* _data;
    int _capacity;
    int _size;
};


class DoubleQueue : public FullArray {
public:
    DoubleQueue():_head(0) {
    }
    //void push_back(int value);父类已实现
    void push_front(int value) {
        if(_head>0) {
            this->at(--_head) = value;
        } else {
            //怎么办呢？走不通了。
        }
    }
    //void pop_back();父类已实现
    void pop_front() {
        _head++;
    }
    int front() {
        return this->at(_head);
    }
    int back() {
        return this->at(size() - 1);
    }
    bool empty() {
        return this->size() == _head;
    }
protected:
    int _head;
};


void testDoubleQueue() {
    printf("DoubleQueue\n");
    DoubleQueue doubleQueue;
    printf("empty=%d\n", doubleQueue.empty());

    doubleQueue.push_back(0);
    doubleQueue.pop_front();
    doubleQueue.push_back(0);
    doubleQueue.pop_front();
    printf("empty=%d\n", doubleQueue.empty());


    doubleQueue.push_front(1);
    doubleQueue.push_front(2);
    doubleQueue.push_back(3);
    doubleQueue.push_back(4);
    printf("empty=%d\n", doubleQueue.empty());

    while(!doubleQueue.empty()) {
        if(!doubleQueue.empty()) {
            printf("value=%d\n", doubleQueue.front());
            doubleQueue.pop_front();
        }
        if(!doubleQueue.empty()) {
            printf("value=%d\n", doubleQueue.back());
            doubleQueue.pop_back();
        }
    }
}

class FullQueue: protected FullArray {
public:
    FullQueue():_head(0) {
    }
    void push(int value) {
        this->push_back(value);
    }
    void pop() {
        _head++;
    }
    int front() {
        return this->at(_head);
    }
    bool empty() {
        return this->size() == _head;
    }
protected:
    int _head;
};

class FullStack : protected FullArray {
public:
    void push(int value) {
        this->push_back(value);
    }
    void pop() {
        this->pop_back();
    }
    int top() {
        return this->at(size() - 1);
    }
    bool empty() {
        return this->size() == 0;
    }
};

void testQueue() {
    printf("FullQueue\n");
    FullQueue fullQueue;
    printf("empty=%d\n", fullQueue.empty());
    fullQueue.push(1);
    fullQueue.push(2);
    fullQueue.push(3);
    printf("empty=%d\n", fullQueue.empty());

    while(!fullQueue.empty()) {
        printf("value=%d\n", fullQueue.front());
        fullQueue.pop();
    }
}

void testStack() {
    printf("FullStack\n");
    FullStack fullStack;
    printf("empty=%d\n", fullStack.empty());
    fullStack.push(1);
    fullStack.push(2);
    fullStack.push(3);
    printf("empty=%d\n", fullStack.empty());

    while(!fullStack.empty()) {
        printf("value=%d\n", fullStack.top());
        fullStack.pop();
    }
}

void testArray() {
    printf("FullArray\n");
    FullArray fullArray;
    printf("size=%d\n", fullArray.size());
    fullArray.push_back(1);
    printf("size=%d\n", fullArray.size());
    fullArray.push_back(2);
    for(int i=0; i<fullArray.size(); i++) {
        printf("pos[%d]=%d\n",i,fullArray.at(i));
    }
}

int main() {


    //testArray();
    // testStack();
    // testQueue();
    // testDoubleQueue();
    testLoopQueue();
    return 0;
}
