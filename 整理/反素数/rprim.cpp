#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<cmath>
#include<stack>
#include<algorithm>
using namespace std;
typedef __int64 INT;
INT bestNum;   //约数最多的数
INT bestSum;   //约数最多的数的约数个数
const int M=1000; //反素数的个数 
INT n=500000;//求n以内的所有的反素数
INT rprim[M][2];
//2*3*5*7*11*13*17>n，所以只需考虑到17即可
INT prim[14]={2,3,5,7,11,13,17,19,23,29};  

//当前走到num这个数，接着用第k个素数，num的约数个数为sum，
//第k个素数的个数上限为limit
void getNum(INT num,INT k,INT sum,INT limit)  {
 	if(num>n)return;
	if(sum>bestSum){
		bestSum = sum;
		bestNum = num;
	}else if(sum == bestSum && num < bestNum){  //约数个数一样时，取小数
		bestNum = num;
	}
	if(k>=7) return; //只需考虑到素数17,即prim[6]
  
	for(INT i=1,p=1;i<=limit;i++){   //素数k取i个
		p*=prim[k];
		getNum(num*p,k+1,sum*(i+1),i);
	}
}

INT log2(INT n){   //求大于等于log2（n）的最小整数
	INT i = 0;
	INT p = 1;
	while(p<n){
		p*=2;
		i++;
	}
	return i;
}

int getrprim(){
	int i = 0;
	while(n>0){
		bestNum = 1;
		bestSum = 1;
		getNum(1,0,1,log2(n));
		n = bestNum - 1;
		rprim[i][0]=bestNum;
		rprim[i][1]=bestSum;
		i++;
	}
	return i;	
}


int main()
{

 n = 500000;
 printf("%d\n",getrprim());   //反素数的个数
 getchar();
 return 0;
}
