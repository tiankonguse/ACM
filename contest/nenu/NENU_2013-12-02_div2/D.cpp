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


int main() {
	int n;
	int i,pos;
	vector<int>ans;
	int str[5]={2,3,5,7};
	int num[5];
	while(~scanf("%d",&n)){

		if(n <= 1){
			printf("%d\n",n?1:10);
			continue;
		}

		memset(num,0,sizeof(num));

		for(i=0;i<4;i++){
			while(n%str[i] == 0){
				num[i]++;
				n /= str[i];
			}
		}

		if(n != 1){
			puts("-1");
			continue;
		}

		ans.clear();

		pos = 3;
		while(num[pos]){
			ans.push_back(str[pos]);
			num[pos]--;
		}

		pos = 2;
		while(num[pos]){
			ans.push_back(str[pos]);
			num[pos]--;
		}

		pos = 1;
		while(num[pos]>=2){
			ans.push_back(9);
			num[pos] -=2;
		}

		pos = 0;
		while(num[pos]>=3){
			ans.push_back(8);
			num[pos] -=3;
		}

		if(num[1] == 0){
			if(num[0] == 0){

			}else if(num[0] == 1){
				ans.push_back(2);
			}else{
				//=2
				ans.push_back(4);
			}
		}else{
			if(num[0] == 0){
				ans.push_back(3);
			}else if(num[0] == 1){
				ans.push_back(6);
			}else{
				//=2
				ans.push_back(2);
				ans.push_back(6);
			}
		}

		sort(ans.begin(),ans.end());

		for(i=0;i<ans.size();i++){
			printf("%d",ans[i]);
		}

		puts("");


	}

	    return 0;
}
