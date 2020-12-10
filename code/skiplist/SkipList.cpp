/*************************************************************************
 > File Name: SkipList.cpp
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

const int MAXLEVEL= 32;

class SkipListNode {
    class SkipListLevel {
    public:
        SkipListLevel():next(NULL),num(1) {
        }
        SkipListNode* next;
        int num;//当前next会跳过多少个节点,包含当前节点
    };
public:
    SkipListNode(int v = -1, int l = -1):value(v),maxlevel(l) {
    }
    int value;
    int maxlevel;
    SkipListLevel level[MAXLEVEL];
};

class SkipList {
    int level;
    unsigned long length;
    SkipListNode _header;
public:
    SkipList():level(1),length(0) {
    }

    //根据值查位置，不存在返回-1
    int findByValue(int value) {
        SkipListNode* head = &_header;
        int pos = -1;
        //查找小于等于value的最后一个节点
        for(int i=MAXLEVEL-1; i>=0; i--) {
            //next不是NULL, 且大于左边界，左边界右移
            while(head->level[i].next && head->level[i].next->value <= value) {
                pos += head->level[i].num; //左边界右移，计算偏移量
                head = head->level[i].next;
            }
        }
        //如果value是最小值，则本身就是-1，如果value不是最小值，则肯定不一样
        if(head->value != value) {
            pos = -1;
        }
        return pos;
    }

    //根据位置查值，肯定存在
    int getByPos(int rank) {
        SkipListNode* head = &_header;
        int pos = 0;
        //查找小于等于value的最后一个节点
        for(int i=MAXLEVEL-1; i>=0; i--) {
            //next不是NULL, 且跳过节点后还没到达目标位置
            while(head->level[i].next && head->level[i].num + pos <= rank) {
                pos += head->level[i].num; //左边界右移，计算偏移量
                head = head->level[i].next;
            }
        }
        return pos;
    }
    void insert(int value) {
        SkipListNode* head = &_header;
        SkipListNode *pre[MAXLEVEL]; //插入时，可能需要更新的表头
        int preNum[MAXLEVEL];//需要更新的表头之前有多少节点

        int pos = -1;
        for(int i=MAXLEVEL-1; i>=0; i--) {
            //next不是NULL, 且大于左边界，左边界右移
            preNum[i] = i == (MAXLEVEL-1) ? 0 : preNum[i+1];//由于计算之前的，继承上一层的
            while(head->level[i].next && head->level[i].next->value <= value) {
                preNum[i] += head->level[i].num;//左边界右移，累加上偏移量
                head = head->level[i].next;
            }
            pre[i] = head;
        }

        SkipListNode* node = new SkipListNode();
        node->maxlevel = rand()%MAXLEVEL;
        node->value = value;

        //在update和update的下个节点之间插入node
        for(int i=0; i< node->maxlevel; i++) {
            node->level[i].next = pre[i]->level[i].next;
            pre[i]->level[i].next = node;
            //插入位置到下个位置之间的个数 减去 插入后占用的个数 就是新的之间的个数
            node->level[i].num = pre[i]->level[i].num - (preNum[0] - preNum[i]);
            //插入位置之前的节点数 减去 第i层之前的节点数 + 1 就是插入位置到下个位置之间的个数
            pre[i]->level[i].num = (preNum[0] - preNum[i]) + 1;
        }

        for (int i = node->maxlevel; i < MAXLEVEL; i++) {
            pre[i]->level[i].num++; //新节点的高度不允许，没更新到
        }
    }
};



int main() {

    return 0;
}
