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
typedef long long LL; 

const int kind = 4,N=1001;
int tire[N][kind], fail[N], word[N];
int size = 0;
queue<int>que;
int tire_map[256];
const char * const tire_str = "ACTG";

void init(){
	char const* p = tire_str;
	int i = 0;
	while(*p){
		tire_map[*p] = i++;
	}
	memset(word, 0, sizeof(word));
	memset(tire[0], 0, sizeof(tire[0]));
	while(!que.empty()){
		que.pop();
	}
	fail[0] = 0;
	size = 1;
}

void insert(char const* str){
	int p = 0, i;
	for( ; *str; str++){
		i = tire_map[*str];
		if(!tire[p][i]){
			memset(tire[size], 0, sizeof(tire[0]));
			word[size] = 0;
			tire[p][i] = size++;
		}
		p = tire[p][i];
	}
	word[p] = 1;
}

void build_ac_automation(){
	int i, pre;
	for( i = 0; i < kind; i++){
		if(tire[0][i]){
			fail[tire[0][i]] = 0;
			que.push(tire[0][i]);
		}
	}

	while(!que.empty()){
		pre = que.front();
		que.pop();
		for(int i = 0; i < kind; i++){
			if(tire[pre][i]){
				que.push(tire[pre][i]);
				fail[tire[pre][i]] = tire[fail[pre]][i];
			}else{
				tire[pre][i] = tire[fail[pre][i]];
			}
		}
	}

}




int main(int argc, char* argv[]){
	
	

    return 0;
}

