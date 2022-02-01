#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<string>
#include<queue>
#include<ctime>
#include<cmath>
#include<stack>
#include<algorithm>
#include<functional>
using namespace std;
typedef long long LL;

const LL MAX = 1000000000000000;
const LL MAX_LOG = 15;
LL get1(){
	return rand()%MAX;
}
LL get2(){
	return ((LL)1)<<(rand()%MAX_LOG);
}

int main(int argc, char* argv[]) {
	srand(time(NULL));

	freopen("2048.in","w",stdout);
	int n = 100;
	LL data;
	printf("%d\n",2);
	while(n--){
		data = get1();
		if(data >1){
			printf("%lld\n",data);
		}
		data = get2();
		if(data >1){
			printf("%lld\n",data);
		}
	}

    return 0;
}






