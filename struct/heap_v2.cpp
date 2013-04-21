/*************************************************************************
    > File Name: heap_v2.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/4/18 19:52:40
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include <ctime>
#include <cmath>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<functional>
#include<algorithm>
#include <cassert>
using namespace std;

const int maxn = 10000;

struct Heap{
    private:
        vector<int> org;
        vector<int> h;
        int _size;
    public:
        Heap();
        void insert(int val);
        void pop();
        void del(int val);
        bool update(int oldval,int newval);
        int top();
        int size();
        bool empty();
        void clear();
    private:
        void down(int pre);
        void up(int son);
        bool compare(int pre,int son);

};

Heap::Heap() {
    _size = 0;
    h.resize(maxn);
    org.resize(maxn, 0);
}

void Heap::clear(){
    _size = 0;
    org.resize(maxn, 0);
}

bool Heap::empty(){
    return !_size;
}

//堆的性质返回true
//也就是儿子不大于父亲返回true
bool Heap::compare(int pre,int son){
    return h[pre] >= h[son];//最大堆
   // return array[pre] <= array[son];//最小堆
}


void Heap::up(int son){
    if(son == 1)return ;

    int pre = son>>1;

    if(!compare(pre,son)){
        swap(org[h[pre]], org[h[son]]);
        swap(h[pre],h[son]);
        up(pre);
    }
}

void Heap::down(int pre){

    int right = pre<<1|1;
    int left = pre<<1;

    if(right <= _size && compare(right,pre) && compare(right,left)){
        //判断右儿子是否是父亲
        swap(h[pre],h[right]);
        swap(org[h[pre]], org[h[right]]);
        down(right);
    }else if(left <= _size && compare(left,pre)){

        //判断左儿子是否是父亲
        swap(h[pre],h[left]);
        swap(org[h[pre]], org[h[left]]);
        down(left);
    }
}



void Heap::insert(int val){
    assert(org[val] == 0);
    ++_size;
    org[val] = _size;
    h[_size] = val;
    up(_size);
}

void Heap::pop(){
    org[h[1]] = 0;
    h[1] = h[_size];
    org[h[1]] = 1;
    _size--;
    down(1);
}

void Heap::del(int val){
    int pos = org[val];
    h[pos] = h[_size];
    org[h[_size]] = pos;

    _size--;
    org[val] = 0;

    down(pos);
}

int Heap::size(){
    return _size;
}


int Heap::top(){
    return h[1];
}




int main() {
    Heap heap;

    heap.insert(1);
    heap.insert(3);
    heap.insert(5);
    heap.insert(7);
    heap.insert(2);
    heap.insert(6);
    heap.insert(4);




    while(!heap.empty()){
        printf("%d\n",heap.top());
        heap.pop();
    }


    return 0;
}
