#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<cmath>
#include<stack>
#include<algorithm>
using namespace std;

__int64 bestNum;   //约数最多的数
__int64 bestSum;   //约数最多的数的约数个数
const int M=1000;
__int64 n=500000;//求n以内的所有的反素数
__int64 rprim[M][2];
//2*3*5*7*11*13*17>n，所以只需考虑到17即可
__int64 sushu[14]={2,3,5,7,11,13,17,19,23,29};  

//当前走到num这个数，接着用第k个素数，num的约数个数为sum，
//第k个素数的个数上限为limit
void getNum(__int64 num,__int64 k,__int64 sum,__int64 limit)  {
 	if(num>n)return;
	if(sum>bestSum){
		bestSum = sum;
		bestNum = num;
	}else if(sum == bestSum && num < bestNum){  //约数个数一样时，取小数
		bestNum = num;
	}
	if(k>=7) return; //只需考虑到素数17,即sushu[6]
  
	for(__int64 i=1,p=1;i<=limit;i++){   //素数k取i个
		p*=sushu[k];
		getNum(num*p,k+1,sum*(i+1),i);
	}
}

__int64 log2(__int64 n){   //求大于等于log2（n）的最小整数
	__int64 i = 0;
	__int64 p = 1;
	while(p<n){
		p*=2;
		i++;
	}
	return i;
}

int main()
{

 n = 500000;
 int i = 0;
	while(n>0){
		bestNum = 1;
		bestSum = 1;
		getNum(1,0,1,log2(n));
		printf("bestNum=%I64d  bestSum=%I64d\n",bestNum,bestSum);
		n = bestNum - 1;
		rprim[i][0]=bestNum;
		rprim[i][1]=bestSum;
		i++;
	}
 printf("%d\n",i);   //反素数的个数
 getchar();
 return 0;
}
