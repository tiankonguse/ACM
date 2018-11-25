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

const int debug = 0;
typedef unsigned uint;
typedef unsigned char uchar;

//			LL leftBlock = 1; //剩余的方块数，可以切的次数为  leftBlock * f(blockSize) + leftK
//			LL blockSize = n-1; //剩余的方块的边长 2^blockSize
//			LL leftK = 0; //剩余的大方块转化为小方块时，虚拟切的次数
// 复杂度 log(n)
bool checkLeft(LL k, LL leftBlock, LL blockSize, LL leftK) {
	if(k <= leftK) {
		return true;
	}
	k -= leftK;

	//还可以切
	while(blockSize > 0) {
		//还可以切，切方块数大于k
		if(leftBlock >= k) {
			return true;
		}

		k -= leftBlock;
		leftBlock *= 4;
		blockSize--;
	}

	return false;
}

int getAns(LL n, LL k) {
	//如果存在答案，路径只需要先垂直向上，再横向右转即可。
	//需要保证这个路径上的小正方形的边长相等， 其他正方形相当于缓冲区，如果 k 小于等于缓存区 ，则存在答案

	//先切一下
	k--;
	LL blockSize = n-1; //一个小方块的边长 2^side
	LL num = 2; //一边小方块的个数。 总个数 2 * num - 1

	LL leftBlock = 1; //剩余的方块数，可以切的次数为  leftBlock * f(blockSize) + leftK
	LL leftK = 0; //剩余的大方块转化为小方块时，虚拟切的次数


	//如果已经存在答案了，先返回答案
	if(checkLeft(k, leftBlock, blockSize, leftK)) {
		return blockSize;
	}

	//还可以切
	while(blockSize > 0 && k >= 2 * num - 1) {
		//开始切
		k -= (2 * num - 1);
		blockSize--;
		num *= 2;

		leftK += leftBlock;
		leftBlock = leftBlock * 4 + 2 * num - 3;
		if(checkLeft(k, leftBlock, blockSize, leftK)) {
			return blockSize;
		}
	}
	return -1;
}

int main() {


#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
	LL t,n,k;
	while(~scanf("%lld", &t)) {
		while(t--) {
			scanf("%lld%lld",&n,&k);
			LL ans = getAns(n, k);
			if(ans >= 0) {
				printf("YES %lld\n", ans);
			} else {
				printf("NO\n");
			}
		}
	}


	return 0;
}
