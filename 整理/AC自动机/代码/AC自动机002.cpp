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
const int kind = 26,N=1000001;

int tire[N][kind],fail[N],word[N];
int size = 0;
queue<int>que;

void init() {
    memset(word,0,sizeof(word));
    memset(tire[0],0,sizeof(tire[0]));
    while(!que.empty())que.pop();
    fail[0] = 0;
    size=1;
}

void insert(char *str, int val) {
    int p = 0, i;
    for(; *str; str++) {
        i = *str - 'a';
        if(!tire[p][i]) {
            memset(tire[size],0,sizeof(tire[size]));
            word[size]=0;
            tire[p][i]= size++;
        }
        p = tire[p][i];
    }
    word[p] += val;
}

void build_ac_automation() {
    int i,pre;

    for(i=0; i< kind; i++) {
        if(tire[0][i]) {
            fail[tire[0][i]]=0;
            que.push(tire[0][i]);
        }
    }

    while(!que.empty()) {
        pre = que.front();
        que.pop();
        for(i=0; i<kind; i++) {
            if(tire[pre][i]) {
                que.push(tire[pre][i]);
                fail[tire[pre][i]] = tire[fail[pre]][i];
            } else {
                tire[pre][i] = tire[fail[pre]][i];
            }
        }
    }
}
int query(char* str) {
    int cnt=0,i,tmp;
    int p = 0;
    for(; *str; str++) {
        i= *str-'a';
        while(tire[p][i] == 0 && p) p=fail[p];
        p = tire[p][i];
        tmp = p;
        while(tmp) {
            cnt += word[tmp];
            word[tmp] = 0;
            tmp = fail[tmp];
        }
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
        insert(keyword,1);
    }
    build_ac_automation();
    scanf("%s",str);
    printf("%d\n",query(str));
    return 0;
}
