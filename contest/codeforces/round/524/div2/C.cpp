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


void getWhoteBlack(LL point_x1,LL point_y1,LL point_x2,LL point_y2, LL &white, LL &black) {
	LL point_x12 = point_x2 - point_x1 + 1;
	LL point_y12 = point_y2 - point_y1 + 1;
	if(point_x12 %2 == 0 || point_y12 % 2 == 0) {
		white =point_x12 * point_y12 / 2;
		black = point_x12 * point_y12 / 2;
	} else {
		if((point_x1 + point_y1) % 2 == 0) {
			white =point_x12 * point_y12 / 2 + 1;
			black = point_x12 * point_y12 / 2;
		} else {
			white =point_x12 * point_y12 / 2;
			black = point_x12 * point_y12 / 2 + 1;
		}
	}
}


LL point_x1,point_y1,point_x2,point_y2;
LL point_x3,point_y3,point_x4,point_y4;

//�Ծ��ν��к�ɫȾɫ
void colorBlack(LL& ansWhite, LL& ansBlack) {
	LL white, black ;

	//�������
	if(point_y4 < point_y1 || point_y3 > point_y2 || point_x4 < point_x1 || point_x3 > point_x2) {
		getWhoteBlack(point_x3,point_y3,point_x4,point_y4, white, black);
		ansWhite -= white;
		ansBlack += white;
		return;
	}

	//��ɫ����������д���ɫ
	if(point_y3<point_y1) {
		getWhoteBlack(point_x3,point_y3,point_x4,point_y1-1, white, black);
		ansWhite -= white;
		ansBlack += white;
		point_y3 = point_y1;
	}

	//��ɫ����������д���ɫ
	if(point_y4 > point_y2) {
		getWhoteBlack(point_x3,point_y2+1,point_x4,point_y4, white, black);
		ansWhite -= white;
		ansBlack += white;
		point_y4 = point_y2;
	}

	//��ɫ����������д���ɫ
	if(point_x3 < point_x1) {
		getWhoteBlack(point_x3,point_y3,point_x1-1,point_y4, white, black);
		ansWhite -= white;
		ansBlack += white;
		point_x3 = point_x1;
	}

	//��ɫ����������д���ɫ
	if(point_x4 > point_x2) {
		getWhoteBlack(point_x2+1,point_y3,point_x4,point_y4, white, black);
		ansWhite -= white;
		ansBlack += white;
		point_x4 = point_x2;
	}

	//��ʱ��ɫ��Ҫ���Ǵ���ɫ
	getWhoteBlack(point_x3,point_y3,point_x4,point_y4, white, black);
	ansWhite -= (white + black);
	ansBlack += (white + black);
}

int main() {


#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
	LL t,n,m;
	LL white, black ;
	LL ansWhite, ansBlack ;

	while(~scanf("%lld",&t)) {
		while(t--) {
			scanf("%lld%lld",&n,&m);
			scanf("%lld%lld%lld%lld",&point_x1,&point_y1,&point_x2,&point_y2);
			scanf("%lld%lld%lld%lld",&point_x3,&point_y3,&point_x4,&point_y4);

			//����Ĭ�ϵĺڰ׷ֲ�
			getWhoteBlack(1,1,n,m, ansWhite, ansBlack);

			//�Ծ��ν��а�ɫȾɫ
			getWhoteBlack(point_x1,point_y1,point_x2,point_y2, white, black);
			ansWhite += black;
			ansBlack -= black;

			//�Ծ��ν��к�ɫȾɫ
			colorBlack(ansWhite, ansBlack);

			printf("%lld %lld\n",ansWhite, ansBlack);
		}
	}


	return 0;
}
