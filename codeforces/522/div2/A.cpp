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


int main() {


#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif


	int n,k;
	map<int, int> m;
	
	while(~scanf("%d%d",&n,&k)){
		m.clear();
		int maxNum = 0;
		for(int i=0; i< n;i++){
			int a;
			scanf("%d",&a);
			m[a];
			m[a]++;
			if(maxNum < m[a]){
				maxNum = m[a];
			}
		}
		int utensils = m.size();
		int maxSet = (maxNum + k - 1)/k;
		printf("%d\n", k*utensils*maxSet - n);
	}
	
	 


    return 0;
}
