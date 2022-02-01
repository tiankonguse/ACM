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
bool ok;
bool vincent;


bool check(priority_queue<Node>&heapOne) {
    deque<Node> queOne;
    int num,i,lastDu;

    while(!heapOne.empty()) {
        now = heapOne.top();
        heapOne.pop();
        num = now.du;

        if(num > heapOne.size()) {
            return false;
        }else if(num < heapOne.size()){
        	vincent=true;
        }

        for(i=0; i<num; i++) {
            queOne.push_back(heapOne.top());
            heapOne.pop();
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
    return true;
}



bool getAns(priority_queue<Node>& heapOne, vector<Edge>&edgeOne) {
    deque<Node> queOne;
    int i,num;

    while(!heapOne.empty()) {
        now = heapOne.top();
        heapOne.pop();
        num = now.du;

        if(num > heapOne.size()) {
            return false;
        }

        for(i=0; i<num; i++) {
            queOne.push_back(heapOne.top());
            heapOne.pop();
        }

        if(ok && !heapOne.empty()) {
            ok = false;
            heapTwo = heapOne;
            deque<Node> queTwo = queOne;
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
            if(!getAns(heapTwo, edgeTwo)) {
                ok = true;
            }
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
    return true;
}

void output(vector<Edge>&edgeOne, int &n, int &sum) {
    printf("%d %d\n",n,sum);
    for(int i=0; i<edgeOne.size(); i++) {
        printf(i?" %d":"%d",edgeOne[i].from);
    }
    puts("");
    for(int i=0; i<edgeOne.size(); i++) {
        printf(i?" %d":"%d",edgeOne[i].to);
    }
    puts("");
}

int main() {
    int n;
    int sum,i,du,state;
    while(~scanf("%d",&n)) {
        while(!heapOne.empty())heapOne.pop();
        while(!heapTwo.empty())heapTwo.pop();
        edgeOne.clear();
        edgeTwo.clear();
		vincent=false;
        sum = 0;
        for(i=1; i<=n; i++) {
            scanf("%d",&du);
            sum += du;
            if(du == 0)continue;
            heapOne.push(Node(i, du));
        }
        sum /= 2;

        ok = true;
        if(!getAns(heapOne, edgeOne)) {
            printf("IMPOSSIBLE\n");
        } else {
            if(ok) {
            	if(vincent==true){
            		int b=0;
					cout<<1/b;
            	}
                printf("UNIQUE\n");
                output(edgeOne,n,sum);
            } else {
            	if(vincent==false){
            		int b=0;
					cout<<1/b;
            	}
                printf("MULTIPLE\n");
				output(edgeOne,n,sum);
				output(edgeTwo,n,sum);
            }
        }

    }

    return 0;
}
