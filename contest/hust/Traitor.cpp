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
#ifdef __int64
typedef __int64 LL;
#else
typedef long long LL;
#endif

const int N = 11111;
int pre[N];
int bad[N];
int used[N];
int see[N];
int chlidNum[N];
queue<int> leaf;
int n,m;

void init() {
    memset(pre,0,sizeof(pre));
    memset(used,0,sizeof(used));
    memset(see,0,sizeof(see));
    memset(bad,0,sizeof(bad));
    memset(chlidNum,0,sizeof(chlidNum));
    while(!leaf.empty()) {
        leaf.pop();
    }
}
void read() {
    int p;
    for(int i=1; i<=n; i++) {
        scanf("%d",&p);
        pre[i] = p;
        chlidNum[p]++;
    }
    chlidNum[0] = 0;
    for(int i=1; i<=m; i++) {
        scanf("%d",&p);
        bad[p] = 1;
    }
}
void solver() {
	int ans = 0;
	for(int i=1;i<=n;i++){
		if(chlidNum[i] == 0){
			leaf.push(i);
		}
	}
	int now, p;
	while(!leaf.empty()){
		node++;
		now = leaf.front();
		leaf.pop();
		p = pre[now];
		if(p == 0){
			continue;
		}
		if(bad[now] && !see[now] &&  !used[p]){
			ans++,see[now] = 1,used[p] = 1;
		}else if(bad[p] && !see[p] && !used[now]){
			ans++,see[p] = 1,used[now] = 1;
		}else if(bad[now] && bad[p] && !see[now] && !see[p] &&  used[now] && used[p] ){
			ans++,see[p] = 1,used[now] = 1;
		}
		chlidNum[p]--;
		if(chlidNum[p] == 0){
			leaf.push(p);
		}
	}
	printf("%d\n",ans);
}
int main() {
    while(scanf("%d%d",&n,&m),n) {
        init();
        read();
        solver();
    }



    return 0;
}
/*
According to an intelligence source, we've got a traitor in ACM Security Agency (ASA). ASA has
a hierarchical structure where each agent has a manager and there are also some (at least one) top
managers who are not managed by anyone. Our source doesn't exactly know the traitor, but he has a
list of suspects. Therefore, all we know is that there is exactly one traitor in our agency and we have a
list of suspects. In order to find that traitor, we want to assign a watcher for each suspect, satisfying
the following three conditions:
1. Two suspects cannot watch each other.
2. Each suspect should be watched by either his manager or one of his direct employees.
3. Nobody can watch more than one suspect.
If we want to satisfy all above conditions, it may be impossible to watch all suspects. Therefore,
you should write a program that gets the structure of ASA and the list of suspects as the input and
finds the maximum number of suspects for whom the watcher assignment is possible. In the following
figure that illustrates the organizational structure of ASA with two top managers and eleven agents, the
suspects are indicated with gray color. One watcher assignment covering 7 out of 8 suspects is possible
in this case which is shown by arrows. An arrow from agent x to agent y, means agent x is supposed
to watch agent y. It can be shown that in this example there is no watcher assignment covering all
suspects.

*/
