/*************************************************************************
    > File Name: 比赛难度.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/17 21:46:04
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

const int N = 10010;
struct T {
    T*next;
    int count,val;
    bool have = false;
    int pos;
    void init(int count, int val) {
        this->count = count;
        this->val = val;
        have = true;
        next = NULL;
    }
    T() {};
    T(int count, int val):count(count),val(val) {};
    bool operator<(const T &b)const {
        return val <b.val;
    }
} str[N*20],*root,_top,*now_pre,*now,*last,*first;
int num;
int lev[N];

int m;
bool have_m;
int now_num;
int m_val;
T* m_pos;

map<int,int>Map;
priority_queue<T>heap;

void find(int val){
     if(Map.find(_top.val) == Map.end()) {

     }
}

void add(int val) {
    now = root;
    now_pre = NULL;
    now_num = 0;

    while(now != NULL) {
        //now加入左侧队列
        if(have_m && m_val <= now->val + val){
            clear_heap();
            return;
        }

        heap.push(T(now->count, now->val + val));
//        printf("--now c=%d v=%d\n",now->count,now->val);
        now_num += now->count;

        //把小于等于now的数加到队列中
        while(!heap.empty() && heap.top().val <= now->val) {
            _top = heap.top();
            heap.pop();

            find(_top.val);

            if(Map.find(_top.val) == Map.end()) {

                Map[_top.val] = first->pos;
                now_pre->next = first;
                first = first->next;
                now_pre = now_pre->next;
                now_pre->init(0,_top.val);
                now_pre->next = now;
            }
            str[Map[_top.val]].count += _top.count;
            now_num += _top.count;
        }
        if(now_num >= m) {
            now->next = NULL;
            while(!heap.empty()){
                _top = heap.top();heap.pop();

            }
            return ;
        }
        now_pre = now;
        now = now_pre->next;
//        printf("--now_num=%d  heap.size=%d\n",now_num,heap.size());
    }
    now = now_pre;
    while(!heap.empty()) {
        _top = heap.top();heap.pop();
        if(Map.find(_top.val) == Map.end()) {
            Map[_top.val] = num;
            now->next = str + num++;
            now = now->next;
            now->init(0,_top.val);
        }
        str[Map[_top.val]].count += _top.count;
        now_num += _top.count;
        if(now_num >= m) {
            now->next = NULL;
            while(!heap.empty())heap.pop();
            return ;
        }
    }
}

int findAns(){
    now = root;
    int now_num = 0;
    while(1){
        now_num += now->count;
        if(now_num >=m)return now->val;
        now = now->next;
    }
}

int main() {
    int n,i,j,cas,ca=1;
    scanf("%d",&cas);
    while(cas--) {
        scanf("%d%d",&n,&m);
        //m++;
//        printf("--m=%d\n",m);
        Map.clear();
        have_m = false;
        for(i=1;i<n;i++){
            str[i-1].pos = i-1;
            str[i-1].next = str[i];
            str[i-1].have=false;
        }
        last = &str[n-1];
        last->pos = n-1;
        last->have = false;
        while(!heap.empty())heap.pop();

        str[0].init(1,0);
        first = &str[1];
        num = 1;
        root = str;

        for(i=0; i<n; i++) {
            scanf("%d",&lev[i]);
        }
        sort(lev,lev+n);

        for(i=0; i<n; i++) {
//            printf("--add i=%d  val=%d\n",i,lev[i]);
            add(lev[i]);
        }
        printf("Case #%d: %d\n",ca++,findAns());


    }
    return 0;
}
