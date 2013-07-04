/*************************************************************************
    > File Name: treap.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/7 20:37:03
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

const int maxn = 100010;
const int LEFT = 1;
const int RIGHT = 0;

int cnt = 1, rt = 0;

struct Treap{
    int key, val, pri, ch[2];
    void set(int& _key, int& _val, int _pri){
        key = _key, val = _val, pri = _pri, ch[0] = ch[1] = 0;
    }
}treap[maxn];


void rotate(int& node, int f){
    int pre_node =treap[node].ch[!f];
    treap[node].ch[!f] = treap[pre_node].ch[f];
    treap[node].ch[f] = node;
    node = pre_node;
}

void insert(int& x, int& key, int& val){
    if(x == 0){
        treap[x = cnt++].set(key,val,rand());
    }else{
        int f = key < treap[x].key;
        insert(treap[x].ch[!f], key, val);
        if(treap[x].pri < treap[ treap[x].ch[!f] ].pri){
            rotate(x,f);
        }
    }
}

int get(int x, int f){
    while(treap[x].ch[f]){
        x = treap[x].ch[f];
    }
    return f;
}



void del(int &x, int key){
    if(treap[x].key == key){
        if(!treap[x].ch[0] || !treap[x].ch[1]){
            if(!treap[x].ch[0]){
                x = treap[x].ch[1];
            }else{
                x = treap[x].ch[0];
            }
        }else{
            int f = treap[ treap[x].ch[0] ].pri > treap[ treap[x].ch[1] ].pri;
            rotate(x, f);
            del(treap[x].ch[f], key);
        }
    }else{
        int f = treap[x].key > key;
        del(treap[x].ch[!f], key);
    }
}

int main() {
    int key,val;
    insert(rt, key, val);//插入元素
    get(rt, 1);//最大值
    get(rt, 0);//最小值
    del(rt,treap[x].key);

    return 0;
}
