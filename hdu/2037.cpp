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
using namespace std;
#ifdef __int64
typedef __int64 LL;
#else
typedef long long LL;
#endif

struct Node{
	int start;
	int end;
	Node(int start = 0, int end = 0):start(start),end(end){}
	bool operator<(const Node &t2)const {
		if(this->end == t2.end){
			return this->start < t2.start;
		}else{
			return this->end < t2.end;
		}
	}
};

int main() {
	int n;

	while(scanf("%d",&n),n){
        vector<Node> nodeList;
		for(int i=0;i<n;i++){
			Node tmp;
			scanf("%d%d",&tmp.start, &tmp.end);
			nodeList.push_back(tmp);
		}
		sort(nodeList.begin(), nodeList.end());


		//printf("sort: \n");
		//for(int i=0;i<n;i++){
        //    printf("%d: %d %d\n", i, nodeList[i].start, nodeList[i].end);
		//}
		//printf("\n");

		int ans = 0;
		int preTime = 0;
        for(int i=0;i<n;i++){
            Node& now = nodeList[i];
            if(now.start >= preTime){
                ans++;
                preTime = now.end;
                //printf("ans %d: %d %d\n", ans, now.start, now.end);
            }
        }
        printf("%d\n", ans);

	}

    return 0;
}
