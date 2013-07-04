/*************************************************************************
    > File Name: Panoramix's Prediction.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/4/28 20:15:54
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
const int N=100;
const int M=30;
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

int find_next(int val,int left,int right){
    int mid;
    while(true){
        mid = (left + right)>>1;
        if(val == prm[mid]){
            break;
        }else if(val > prm[mid]){
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }

    return prm[mid+1];
}

int main() {
    int k=getprm();

    int n,m;
    while(~scanf("%d%d",&n,&m)){
       printf("%s\n",find_next(n,0,k-1) == m ? "YES":"NO");
    }




    return 0;
}
