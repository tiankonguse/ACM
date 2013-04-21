/*************************************************************************
    > File Name: heap_winguse01.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/4/18 19:27:25
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
struct Heap { /// greater
    std::vector<int> h;
    std::vector<int> pos;
    std::vector<int> &org;
    int size;

    Heap(std::vector<int> &__org): org(__org) {
        size = 0;
        h.resize(org.size());
        pos.resize(org.size(), 0);
    }

    void clear() {
        for(int i = 1; i <= size; i++) {
            pos[h[i]] = 0;
        }
        size = 0;
    }

    void up(int orgIdx) {
        int idx = pos[orgIdx];
#ifdef ASSERT_ON
        if(idx < 1 || idx > size) {
            printf("orgIdx = %d, idx = %d, size = %d\n", orgIdx, idx, size);
            for(int i = 1; i <= idx; i++) {
                printf("%3d", h[i]);
            }
        }
        assert(idx >= 1 && idx <= size);
#endif
        while(idx > 1 && org[h[idx>>1]] < org[h[idx]]) {
            std::swap(h[idx], h[idx>>1]);
            std::swap(pos[h[idx]], pos[h[idx>>1]]);
//            pos[h[idx]] = idx;
            idx >>= 1;
//            pos[h[idx]] = idx;
        }
    }

    void down(int orgIdx) {
        int idx = pos[orgIdx];
#ifdef ASSERT_ON
        assert(idx >= 1 && idx <= size);
#endif
        while(true) {
            if((idx << 1 | 1) <= size && org[h[idx<<1|1]] > org[h[idx]] && org[h[idx<<1|1]] > org[h[idx<<1]]) {
                std::swap(h[idx<<1|1] , h[idx]);
                pos[h[idx]] = idx;
                idx <<= 1;
                idx |= 1;
                pos[h[idx]] = idx;
            } else if((idx << 1) <= size && org[h[idx<<1]] > org[h[idx]]) {
                std::swap(h[idx<<1] , h[idx]);
                pos[h[idx]] = idx;
                idx <<= 1;
                pos[h[idx]] = idx;
            } else {
                break;
            }
        }
    }

    void insert(int orgIdx) {
        size++;
        h[size] = orgIdx;
        pos[orgIdx] = size;
        up(orgIdx);
    }

    void pop(){
        del(h[1]);
    }

    void del(int orgIdx) {
        int value = org[orgIdx], idx = pos[orgIdx];
#ifdef ASSERT_ON
        assert(idx >= 1 && idx <= size);
#endif
        pos[orgIdx] = 0;
        if(idx == size) {
            size--;
            return;
        }
        h[idx] = h[size--];
        pos[h[idx]] = idx;
        if(org[h[idx]] < value)
            down(h[idx]);
        else
            up(h[idx]);
    }

//    bool update(int orgIdx, int value) {
//        if(pos[orgIdx] == 0) {
//            return false;
//        }
//        if(org[orgIdx] < value) {
//            org[orgIdx] = value;
//            down(orgIdx);
//        } else {
//            org[orgIdx] = value;
//            up(orgIdx);
//        }
//        return true;
//    }

    bool updateDeta(int orgIdx, int deta) {
        if(deta == 0)return true;
        if(pos[orgIdx] == 0) {
            return false;
        }
        org[orgIdx] += deta;
        if(deta < 0) {
            down(orgIdx);
        } else {
            up(orgIdx);
        }
        return true;
    }

    int getTop() {
#ifdef ASSERT_ON
        assert(size > 0);
        for(int i = 1; i <= size; i++) {
            assert(org[h[1]] >= org[h[i]]);
        }
#endif
        return org[h[1]];
    }
};

class Test {
public:
    const int MY_MASK;
    static const int test;
    Test(int s) : MY_MASK(s) {}
};
const int Test::test = 1;
std::vector<int> org;

int main() {
//    Test t(2);
//    printf("%d %d\n",t.MY_MASK, t.test);
    std::vector<int> org;

    for(int i=0;i<=100;i++)org.push_back(i);
    Heap heap(org);
    for(int i=1;i<=100;i++)heap.insert(i);



    while(heap.size){
        printf("%d\n",heap.getTop());
        heap.pop();
    }

    return 0;
}
