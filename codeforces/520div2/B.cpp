#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <ctime>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <functional>
using namespace std;

const int N=1000000;
const int M=300000;
bool is[N];
int prm[M];
int getprm() {
	int e = (int)(sqrt(0.0 + N) + 1),k=0,i;
	memset(is, 1, sizeof(is));
	prm[k++] = 2;
	is[0] = is[1] = 0;
	for (i = 4; i < N; i += 2) is[i] = 0;
	for(i=3; i<e; i+=2) {
		if(is[i]) {
			prm[k++]=i;
			for(int s=i+i,j=i*i; j<N; j+=s)is[j]=0;
		}
	}
	for (; i < N; i += 2)
		if (is[i])prm[k++] = i;
	return k;
}

int main() {
	int prmNum = getprm();


	int n;
	scanf("%d", &n);

	if(n == 1 || is[n]) {
		printf("%d 0\n", n);
		return 0;
	}

	int maxNum = -1;
	int second = -1; //ÐèÒª mul 

	int sum = 1;
	int nowNum = 0;
	for(int i=0; i<prmNum && n > 1; i++) {
		nowNum = 0;
		while(n % prm[i] == 0) {
			nowNum++;
			n = n / prm[i];
		}
		if(nowNum) {
			sum *=  prm[i];

			if(maxNum > 0 && nowNum != maxNum) {
				second = 1;
			}
			if(nowNum > maxNum) {
				maxNum = nowNum;
			}
		}
	}

	//printf("%d %d\n", maxNum, second);


	int ans = 0;
	if(maxNum & (maxNum-1) || second != -1) {
		if(maxNum & (maxNum-1)){
			ans++;
		}
		ans++;
	}
	while(maxNum > 1) {
		ans++;
		maxNum/=2;
	}

	printf("%d %d\n", sum, ans);







	return 0;
}
