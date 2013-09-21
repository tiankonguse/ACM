#include<iostream>
#include<cstring>
#include<map>
#include<algorithm>
#include<stack>
#include<queue>
#include<cstring>
#include<cmath>
#include<string>
#include<cstdlib>
#include<vector>
#include<cstdio>
#include<functional>

using namespace std;

const int MAXN = 100010;

struct Node {
    int key, dist, lc, rc;
    void init(int _dist = 0, int _key = 0) {
        key = _key;
        dist = _dist;
        lc = rc = 0;
    }

} nodes[MAXN];
int memeryNode[MAXN];
int allocNode,allocMemery;

void initNode() {
    nodes[0].init(-1);//0作为NULL节点
    allocNode = 1;
    allocMemery = 0;
}

int newNode(int x) {
    int tmp;
    if(allocMemery) {
        tmp = memeryNode[--allocMemery];
    } else {
        tmp = allocNode++;
    }
    nodes[tmp].init(0, x);
    return tmp;
}

void deleteNode(int A) {
    memeryNode[allocMemery++] = A;
}

int merge(int A, int B) {
    if (A != 0 && B != 0) {
        if (nodes[A].key < nodes[B].key) {
            swap(A, B);
        }
        nodes[A].rc = merge(nodes[A].rc, B);
        int &lc = nodes[A].lc;
        int &rc = nodes[A].rc;
        if (nodes[lc].dist < nodes[rc].dist) {
            swap(lc, rc);
        }
        nodes[A].dist = nodes[rc].dist + 1;
    } else {
        A = A == 0 ? B : A;
    }
    return A;
}


int pop(int A) {
    int t = merge(nodes[A].lc, nodes[A].rc);
    deleteNode(A);
    return t;
}

void insert(int v) {
    merge(0, newNode(v));
}


int main() {

    return 0;
}
