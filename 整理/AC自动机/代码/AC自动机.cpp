/*************************************************************************
    > File Name: AC自动机.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/23 16:09:14
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
const int kind = 26;
struct Tire {
    int fail;       //失败指针
    int next[kind]; //Tire每个节点的个子节点（最多个字母）
    int count;        //是否为该单词的最后一个节点
    void init() {          //构造函数初始化
        fail = 0;
        count = 0;
        memset(next,-1,sizeof(next));
    }
} tire[5000001];        //队列，方便用于bfs构造失败指针
int size = 0;
queue<int>que;

void init() {
    tire[0].init();
    size = 1;
    while(!que.empty())que.pop();
}

void insert(char *str) {
    int p = 0, i=0,index;
    while(str[i]) {
        index=str[i]-'a';
        if(tire[p].next[index] == -1) {
            tire[size].init();
            tire[p].next[index]= size++;
        }
        p = tire[p].next[index];
        i++;
    }
    tire[p].count++;     //在单词的最后一个节点count+1，代表一个单词
}

void build_ac_automation() {
    int i,pre,pre_fail,child;

    tire[0].fail = -1;
    que.push(0);

    while(!que.empty()) {
        pre = que.front();
        que.pop();

        for(i=0; i<kind; i++) {
            if(tire[pre].next[i] != -1) {
                child = tire[pre].next[i] ;
                pre_fail = tire[pre].fail;
                while(pre_fail != -1) {
                    if(tire[pre_fail].next[i] != -1) {
                        tire[ child ].fail = tire[pre_fail].next[i];
                        break;
                    }
                    pre_fail = tire[pre_fail].fail;
                }
                if(pre_fail == -1) {
                    tire[ child ].fail = 0;
                }
                que.push(child);
            }
        }
    }
}
int query(char* str) {
    int i=0,cnt=0,index,tmp;
    int p = 0;
    while(str[i]) {
        index=str[i]-'a';
        while(tire[p].next[index] == -1 && p != 0) p=tire[p].fail;
        p = tire[p].next[index];
        tmp = p = (p==-1 ? 0:p);
        while(tmp != 0 && tire[tmp].count != -1) {
            cnt += tire[tmp].count;
            tire[tmp].count = -1;
            tmp = tire[tmp].fail;
        }
        i++;
    }
    return cnt;
}
int main() {
    char keyword[51];     //输入的单词
    char str[1000005];    //模式串
    int n;
    scanf("%d",&n);
    init();
    while(n--) {
        scanf("%s",keyword);
        insert(keyword);
    }
    build_ac_automation();
    scanf("%s",str);
    printf("%d\n",query(str));
    return 0;
}
