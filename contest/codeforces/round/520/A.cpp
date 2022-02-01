#include<iostream>
#include<stack>
#define debug 0
using namespace std;
int main() {

	int n;
	int array[1000];
	scanf("%d", &n);
	array[0] = 0;
	for(int i=1; i<=n; i++) {
		scanf("%d", &array[i]);
	}
	array[n+1] = 1001;
	array[n+2] = 1003;
	n = n + 3;
	
	int maxNum = 1;

	int preNum = 1;
	for(int i=1; i<n; i++) {
		if(array[i-1] + 1 == array[i]) {
			preNum++;
		} else {
			if(preNum > maxNum) {
				maxNum = preNum;
			}
			preNum = 1;
		}
	}

	int ans = maxNum - 2;
	if(ans < 0) {
		ans = 0;
	}
	printf("%d\n", ans);


	return 0;
}
