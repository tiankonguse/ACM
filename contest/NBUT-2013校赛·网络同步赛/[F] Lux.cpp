/*************************************************************************
    > File Name: [F] Lux.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/18 17:30:06
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<functional>
#include<algorithm>
using namespace std;
typedef long long LL;
LL NN = 2147483647LL;
const int N= (2147483647>>3)+1;
const int M=14630853;
char is[N];
LL prm[M];
void setIs(int pos){
    is[pos>>3] &= ~(1<<(pos%8));
}

bool getIs(int pos){
    return is[pos>>3] & (1<<(pos%8));
}

int getprm(){
	int e = (int)(sqrt(0.0 + NN) + 1),k=0,i;
	memset(is, 0XFF, sizeof(is));

	prm[k++] = 2;
	setIs(0);
	setIs(1);
	for (i = 4; i < N; i += 2){
        setIs(i);
	}

	for(i=3;i<e;i+=2){
		if(getIs(i)){
			prm[k++]=i;
			for(int s=i+i,j=i*i;j<N;j+=s){
                setIs(j);
			}
		}
	}
	for (; i < N; i += 2)
		if (getIs(i))prm[k++] = i;
	return k;
}
int main() {
    int k=getprm();
    LL a,b;

    printf("--%d\n",k);
    for(int i=0;i<100;i++){
        printf("--%d  %d\n",i,prm[i]);
    }
    return 0;
}
