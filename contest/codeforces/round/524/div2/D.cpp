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

//			LL leftBlock = 1; //ʣ��ķ������������еĴ���Ϊ  leftBlock * f(blockSize) + leftK
//			LL blockSize = n-1; //ʣ��ķ���ı߳� 2^blockSize
//			LL leftK = 0; //ʣ��Ĵ󷽿�ת��ΪС����ʱ�������еĴ���
// ���Ӷ� log(n)
bool checkLeft(LL k, LL leftBlock, LL blockSize, LL leftK) {
	if(k <= leftK) {
		return true;
	}
	k -= leftK;

	//��������
	while(blockSize > 0) {
		//�������У��з���������k
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
	//������ڴ𰸣�·��ֻ��Ҫ�ȴ�ֱ���ϣ��ٺ�����ת���ɡ�
	//��Ҫ��֤���·���ϵ�С�����εı߳���ȣ� �����������൱�ڻ���������� k С�ڵ��ڻ����� ������ڴ�

	//����һ��
	k--;
	LL blockSize = n-1; //һ��С����ı߳� 2^side
	LL num = 2; //һ��С����ĸ����� �ܸ��� 2 * num - 1

	LL leftBlock = 1; //ʣ��ķ������������еĴ���Ϊ  leftBlock * f(blockSize) + leftK
	LL leftK = 0; //ʣ��Ĵ󷽿�ת��ΪС����ʱ�������еĴ���


	//����Ѿ����ڴ��ˣ��ȷ��ش�
	if(checkLeft(k, leftBlock, blockSize, leftK)) {
		return blockSize;
	}

	//��������
	while(blockSize > 0 && k >= 2 * num - 1) {
		//��ʼ��
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
