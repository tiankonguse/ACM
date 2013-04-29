/*************************************************************************
    > File Name: C.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/4/29 11:00:54
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<functional>
#include<algorithm>
#include<cmath>
using namespace std;

int const N = 100000;
int const M = 100000;

bool is[N];
int prm[N];

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
    int i,j,k,s,now,a;
    getprm() ;
    while(scanf("%d",&a)!=EOF&&a){
        s=0;
        for(i=0;;i++){
            now=0;
            if(prm[i]>a)break;
            for(j=i;;j++){
                now+=prm[j];
                if(now==a){
                    s++;
                    break;
                }
                if(now>a)break;
            }
        }
        printf("%d\n",s);
    }
    return 0;
}
