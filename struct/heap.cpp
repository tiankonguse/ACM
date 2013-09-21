/*************************************************************************
    > File Name: heap.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/4/15 9:54:06
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<functional>
#include<algorithm>
using namespace std;



const int maxn = 10000;

struct Heap{
	int size;
	int array[maxn];
	void bulid();
	void insert(int val);
	int top();
	void pop();
	bool empty();
	void push_down_recursive(int pre);
	void push_down_loop(int pre);
	void _push_down(int);
	void push_up(int son);
	bool compare(int pre,int son);
};


void Heap::bulid(){
    size = 0;
}
bool Heap::empty(){
    return size == 0;
}


void Heap::insert(int val){
    array[++size] = val;
    push_up(size);
}

//堆的性质返回true
//也就是儿子不大于父亲返回true
bool Heap::compare(int pre,int son){
    return array[pre] >= array[son];//最大堆
   // return array[pre] <= array[son];//最小堆
}

void Heap::push_up(int son){
    if(son == 1)return ;

    int pre = son>>1;

    if(!compare(pre,son)){
        swap(array[pre],array[son]);
        push_up(pre);
    }
}


int Heap::top(){
    return array[1];
}


void Heap::pop(){
    array[1] = array[size--];
    push_down_recursive(1);
}


void Heap::push_down_recursive(int pre){
    if((pre<<1|1) <= size && compare(pre<<1|1,pre) && compare(pre<<1|1,pre<<1)){
        //判断右儿子是否是父亲
        swap(array[pre],array[pre<<1|1]);
        push_down_recursive(pre<<1|1);
    }else if((pre<<1) <= size && compare(pre<<1,pre)){
        //判断左儿子是否是父亲
        swap(array[pre],array[pre<<1]);
        push_down_recursive(pre<<1);
    }
}
void Heap::push_down_loop(int pre){
    while(true){
        if((pre<<1|1) <= size && compare(pre<<1|1,pre) && compare(pre<<1|1,pre<<1)){
            //判断右儿子是否是父亲
            swap(array[pre],array[pre<<1|1]);
            pre = pre<<1|1;
        }else if((pre<<1) <= size && compare(pre<<1,pre)){
            //判断左儿子是否是父亲
            swap(array[pre],array[pre<<1]);
             pre = pre<<1;
        }else{
            break;
        }
    }
}


void Heap::_push_down(int pre){

    int left = pre<<1;

    if(left > size){
        //没有儿子
        return;
    }else if(left == size){
        //只有左儿子
        if(!compare(pre,left)){
            swap(array[pre],array[left]);
        }
        return;
    }else{
        //有两个儿子
        int right = pre<<1|1;
        if(compare(pre,left) && compare(pre,right)){
            //满足堆的性质
            return;
        }

        //不满足堆的性质
        if(compare(left,right)){
            //做儿子可以当作右儿子的父亲
            swap(array[pre],array[left]);
            _push_down(left);
        }else{
            //做儿子不可以当作右儿子的父亲
            swap(array[pre],array[right]);
            _push_down(right);
        }
    }
}

int main() {
    Heap heap;
    heap.bulid();

    heap.insert(1);
    heap.insert(3);
    heap.insert(5);
    heap.insert(7);
    heap.insert(2);
    heap.insert(6);
    heap.insert(4);




    while(!heap.empty()){
//    for(int i=1;i<=heap.size;i++){
//        printf("%d ",heap.array[i]);
//    }
//    puts("");
        printf("%d\n",heap.top());
        heap.pop();
//    for(int i=1;i<=heap.size;i++){
//        printf("%d ",heap.array[i]);
//    }
//    puts("\n--------------------");
    }


    return 0;
}
