#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<cmath>
#include<stack>
#include<algorithm>
#include<functional>
#include<stdarg.h>
using namespace std;
typedef long long LL;

struct Node {
    int pos;
    int du;
    Node(int pos=0, int du=0):pos(pos),du(du) {}
    bool operator < (const Node& that)const {
        return this->du < that.du;
    }
} stackNode,heapNode,now;

struct Edge {
    int from,to;
    Edge(int from,int to):from(from),to(to) {}
};

vector<Edge>edgeOne,edgeTwo;
priority_queue<Node> heapOne,heapTwo;
stack<Node> staOne, staTwo;
bool ok;

int check(priority_queue<Node>&heapOne, stack<Node>&staOne) {
    while(!staOne.empty()) {
        staOne.pop();
    }
    int num,i,lastDu;
    bool ansNum = false;

    while(!heapOne.empty()) {
        num = heapOne.top().du;
        heapOne.pop();
        if(num > heapOne.size()) {
            return 0;
        }
        if(num < heapOne.size()) {
            ansNum = true;
        }
        for(i=0; i<num; i++) {
            staOne.push(heapOne.top());
            heapOne.pop();
        }

        while(!staOne.empty()) {
            stackNode = staOne.top();
            staOne.pop();
            if(stackNode.du > 1) {
                stackNode.du--;
                heapOne.push(stackNode);
            }
        }
    }
    return ansNum?2:1;
}

bool getAns(priority_queue<Node>& heapOne, vector<Edge>&edgeOne, stack<Node>&staOne) {
    while(!staOne.empty()) {
        staOne.pop();
    }
    int i,num;
    while(!heapOne.empty()) {
        now = heapOne.top();
        heapOne.pop();
        num = now.du;
        for(i=0; i<num; i++) {
            staOne.push(heapOne.top());
            heapOne.pop();
        }
        if(ok && !heapOne.empty()) {
            ok = false;
            heapTwo = heapOne;
            staTwo = staOne;
            edgeTwo = edgeOne;

            heapNode = heapTwo.top();
            heapTwo.pop();

            stackNode = staTwo.top();
            staTwo.pop();

            heapTwo.push(stackNode);
            staTwo.push(heapNode);

            while(!staTwo.empty()) {
                stackNode = staTwo.top();
                staTwo.pop();
                edgeTwo.push_back(Edge(now.pos, stackNode.pos));
                if(stackNode.du > 1) {
                    stackNode.du--;
                    heapTwo.push(stackNode);
                }
            }
            getAns(heapTwo, edgeTwo, staTwo);
        }

        while(!staOne.empty()) {
            stackNode = staOne.top();
            staOne.pop();
            edgeOne.push_back(Edge(now.pos, stackNode.pos));
            if(stackNode.du > 1) {
                stackNode.du--;
                heapOne.push(stackNode);
            }
        }

    }
}

int main() {
    int n;
    int sum,i,du,state;
    while(~scanf("%d",&n)) {
        while(!heapOne.empty())heapOne.pop();
        while(!heapTwo.empty())heapTwo.pop();
        while(!staTwo.empty())staTwo.pop();
        while(!staOne.empty())staOne.pop();
        edgeOne.clear();
        edgeTwo.clear();
        sum = 0;
        for(i=1; i<=n; i++) {
            scanf("%d",&du);
            sum += du;
            if(du == 0)continue;
            heapOne.push(Node(i, du));
        }
        sum /= 2;

        heapTwo = heapOne;
        state = check(heapTwo, staTwo);
        if(state == 0) {
            printf("IMPOSSIBLE\n");
        } else if(state == 1) {
            ok = false;
            getAns(heapOne, edgeOne, staOne);
            printf("UNIQUE\n");
            printf("%d %d\n",n,sum);
            for(i=0;i<edgeOne.size();i++){
				printf(i?" %d":"%d",edgeOne[i].from);
            }
            puts("");
            for(i=0;i<edgeOne.size();i++){
				printf(i?" %d":"%d",edgeOne[i].to);
            }
            puts("");
        } else {
            ok = true;
            getAns(heapOne, edgeOne, staOne);
            printf("MULTIPLE\n");
            printf("%d %d\n",n,sum);
            for(i=0;i<edgeOne.size();i++){
				printf(i?" %d":"%d",edgeOne[i].from);
            }
            puts("");
            for(i=0;i<edgeOne.size();i++){
				printf(i?" %d":"%d",edgeOne[i].to);
            }
            puts("");

            printf("%d %d\n",n,sum);
            for(i=0;i<edgeTwo.size();i++){
				printf(i?" %d":"%d",edgeTwo[i].from);
            }
            puts("");
            for(i=0;i<edgeTwo.size();i++){
				printf(i?" %d":"%d",edgeTwo[i].to);
            }
            puts("");
        }

    }



    return 0;
}
