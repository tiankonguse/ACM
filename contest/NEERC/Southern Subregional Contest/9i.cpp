/*************************************************************************
    > File Name: 0.cpp
    > Author: tiankonguse
    > Mail: i@tiankonguse.com
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<map>
#include<string>
#include<cmath>
#include<queue>
#include<stack>
#include<functional>
#include<algorithm>
using namespace std;
struct Node {
    int id,line,val;
} node,node3; //自定义优先级类型
struct cmp1 {
    bool operator()(const Node &t1,const Node &t2)const {
        return t1.val>t2.val;
    }
};

struct cmp2 {
    bool operator()(const Node &t1,const Node &t2) {
        return t1.val<t2.val;
    }
};
struct cmp3 {
    bool operator()(const Node &t1,const Node &t2) {
        return t1.id>t2.id;
    }
};

priority_queue<Node,vector<Node>,cmp1> Q1,Q2,Q3;
priority_queue<Node,vector<Node>,cmp2> ans,max_Q3;
priority_queue<Node,vector<Node>,cmp3> _ans;



int main() {

    int n,a,b,i,aa;
    int num,sum;
    while(~scanf("%d%d%d",&n,&a,&b)) {
        while(!Q1.empty())Q1.pop();
//        Q1.pop();
        while(!Q2.empty())Q2.pop();
        while(!Q3.empty())Q3.pop();
        while(!ans.empty())ans.pop();
        while(!_ans.empty())_ans.pop();
        while(!max_Q3.empty())max_Q3.pop();

        num = sum = 0;
        aa=a;
        for(i=0; i<n; i++) {
            node.line = i+1;
            scanf("%d%d",&node.id,&node.val);
            if(node.id == 1) {
                Q1.push(node);
            } else if(node.id == 2) {
                Q2.push(node);
            } else {
                Q3.push(node);
            }
        }
        while(a--) {
            if(!Q1.empty()) {
                num++;
                sum +=Q1.top().val;
                ans.push(Q1.top());
                Q1.pop();
            } else {
                if(!Q3.empty()) {
                    num++;
                    sum +=Q3.top().val;
                    node = Q3.top();
                    node.id = 1;
                    ans.push(node);
                    Q3.pop();
                }
            }
        }
        while(b--) {
            if(!Q2.empty()) {
                num++;
                sum +=Q2.top().val;
                ans.push(Q2.top());
                Q2.pop();
            } else {
                if(!Q3.empty()) {
                    num++;
                    sum +=Q3.top().val;
                    node = Q3.top();
                    node.id = 2;
                    ans.push(node);
                    Q3.pop();
                }
            }
        }

        while(!Q3.empty()){
            max_Q3.push(Q3.top());
            Q3.pop();
        }

        while(!max_Q3.empty() && !ans.empty()) {
            node3 = max_Q3.top();
            max_Q3.pop();
            node = ans.top();
            if(node.val > node3.val) {
                ans.pop();
                node3.id = node.id;
                sum = sum - node.val + node3.val;
                ans.push(node3);
            }
        }

        printf("%d %d\n", num, sum);
        while(!ans.empty()) {
            node = ans.top();
            ans.pop();
            _ans.push(node);
        }
        bool ok = true;
        i=1;
        while(!_ans.empty()) {
            node = _ans.top();
            _ans.pop();
            if(ok && node.id == 2){
                ok = false;
                if(i != aa+1){
                    i = aa+1;
//                    printf("i=%d\n",i);
                }
            }
            printf("%d %d\n",node.line, i++);
        }

    }

    return 0;
}
