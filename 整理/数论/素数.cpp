/*************************************************************************
    > File Name: 素数.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/4/28 19:47:46
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
const int N=1100000;
const int M=300000;
bool is[N];
int prm[M];
int getprm(){
	int e = (int)(sqrt(0.0 + N) + 1),k=0,i,s,j;
	memset(is, 1, sizeof(is));

	prm[k++] = 2;
	is[0] = is[1] = 0;
	for (i = 4; i < N; i += 2) is[i] = 0;

	for(i=3;i<e;i+=2){
		if(is[i]){
			prm[k++]=i;
			for(s=i+i,j=i*i;j<N;j+=s)is[j]=0;
		}
	}

	for (; i < N; i += 2){
		if (is[i]){
            prm[k++] = i;
		}
	}

	return k;
}


int main() {
    int k = getprm();
    //printf("%d\n",k);
    int n, i;
    while(scanf("%d",&n), n){
        for(i = 1; ;++i){
            if(is[n - prm[i]])break;
        }
        printf("%d = %d + %d\n",n,prm[i],n - prm[i]);
    }
    return 0;
}
