#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<cmath>
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
} dequeNode,heapNode,now;

struct Edge {
    int from,to;
    Edge(int from,int to):from(from),to(to) {}
};

vector<Edge>edgeOne,edgeTwo;
priority_queue<Node> heapOne,heapTwo;
deque<Node> queOne, queTwo;
bool ok;

int check(priority_queue<Node>&heapOne, deque<Node>&queOne) {
    while(!queOne.empty()) {
        queOne.pop_back();
    }
    int num,i,lastDu;
    bool ansNum = false;

    while(!heapOne.empty()) {
        num = heapOne.top().du;
        heapOne.pop();
        if(num > heapOne.size()) {
            return 0;
        }
        for(i=0; i<num; i++) {
            queOne.push_back(heapOne.top());
            heapOne.pop();
        }
        if((!heapOne.empty() && heapOne.top().du == queOne.back().du) || (!heapOne.empty() &&  queOne.front().du == num &&  queOne.back().du +1 >= heapOne.top().du)) {
            ansNum = true;
        }
        while(!queOne.empty()) {
            dequeNode = queOne.back();
            queOne.pop_back();
            if(dequeNode.du > 1) {
                dequeNode.du--;
                heapOne.push(dequeNode);
            }
        }
    }
    return ansNum?2:1;
}

bool getAns(priority_queue<Node>& heapOne, vector<Edge>&edgeOne, deque<Node>&queOne) {
    while(!queOne.empty()) {
        queOne.pop_back();
    }
    int i,num;
    while(!heapOne.empty()) {
        now = heapOne.top();
        heapOne.pop();
        num = now.du;
        for(i=0; i<num; i++) {
            queOne.push_back(heapOne.top());
            heapOne.pop();
        }
        if(ok && !heapOne.empty() && heapOne.top().du == queOne.back().du) {
            ok = false;
            heapTwo = heapOne;
            queTwo = queOne;
            edgeTwo = edgeOne;

            heapNode = heapTwo.top();
            heapTwo.pop();

            dequeNode = queTwo.back();
            queTwo.pop_back();

            heapTwo.push(dequeNode);
            queTwo.push_back(heapNode);

            while(!queTwo.empty()) {
                dequeNode = queTwo.back();
                queTwo.pop_back();
                edgeTwo.push_back(Edge(now.pos, dequeNode.pos));
                if(dequeNode.du > 1) {
                    dequeNode.du--;
                    heapTwo.push(dequeNode);
                }
            }
            getAns(heapTwo, edgeTwo, queTwo);

        } else if(ok && !heapOne.empty() && queOne.front().du == now.du &&  queOne.back().du +1 >= heapOne.top().du) {
            ok = false;
            heapTwo = heapOne;
            queTwo = queOne;
            edgeTwo = edgeOne;

            dequeNode= queTwo.front();
            queTwo.pop_front();
            queTwo.push_front(now);
            Node now  = dequeNode;

            while(!queTwo.empty()) {
                dequeNode = queTwo.back();
                queTwo.pop_back();
                edgeTwo.push_back(Edge(now.pos, dequeNode.pos));
                if(dequeNode.du > 1) {
                    dequeNode.du--;
                    heapTwo.push(dequeNode);
                }
            }
            getAns(heapTwo, edgeTwo, queTwo);
        }

        while(!queOne.empty()) {
            dequeNode = queOne.back();
            queOne.pop_back();
            edgeOne.push_back(Edge(now.pos, dequeNode.pos));
            if(dequeNode.du > 1) {
                dequeNode.du--;
                heapOne.push(dequeNode);
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
        while(!queTwo.empty())queTwo.pop_back();
        while(!queOne.empty())queOne.pop_back();
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
        state = check(heapTwo, queTwo);
        if(state == 0) {
            printf("IMPOSSIBLE\n");
        } else if(state == 1) {
            ok = false;
            getAns(heapOne, edgeOne, queOne);
            printf("UNIQUE\n");
            printf("%d %d\n",n,sum);
            for(i=0; i<edgeOne.size(); i++) {
                printf(i?" %d":"%d",edgeOne[i].from);
            }
            puts("");
            for(i=0; i<edgeOne.size(); i++) {
                printf(i?" %d":"%d",edgeOne[i].to);
            }
            puts("");
        } else {
            ok = true;
            getAns(heapOne, edgeOne, queOne);
            printf("MULTIPLE\n");
            printf("%d %d\n",n,sum);
            for(i=0; i<edgeOne.size(); i++) {
                printf(i?" %d":"%d",edgeOne[i].from);
            }
            puts("");
            for(i=0; i<edgeOne.size(); i++) {
                printf(i?" %d":"%d",edgeOne[i].to);
            }
            puts("");

            printf("%d %d\n",n,sum);
            for(i=0; i<edgeTwo.size(); i++) {
                printf(i?" %d":"%d",edgeTwo[i].from);
            }
            puts("");
            for(i=0; i<edgeTwo.size(); i++) {
                printf(i?" %d":"%d",edgeTwo[i].to);
            }
            puts("");
        }

    }



    return 0;
}
