#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<cmath>
#include<stack>
#include<algorithm>
using namespace std;
const int N=200100;
int _map[N],str[N];
int n,m;
int begin;
int num;
int ans;
int _min(int a,int b){
	return a<b?a:b;
}
int main()
{
	while(~scanf("%d%d",&n,&m)){
		for(int i=0;i<n;i++)scanf("%d",&str[i]);
		if(n<m)puts("NO");
		else{
			memset(_map,0,sizeof(int)*(m+4));
			num=0;
			int i=0;
			while(num<m && i<n){
				_map[str[i]]++;
				if(str[i]<=m && str[i]>=1 && _map[str[i]]==1)num++;
				i++;
			}
			if(num<m)puts("NO");
			else{
				begin=0;
				while(str[begin]<=0 || str[begin]>m || _map[str[begin]]>1){
					_map[str[begin++]]--;
				}
				ans=i-begin;
				for(;i<n;i++){
					if(str[i]==str[begin]){
						begin++;
						while(_map[str[begin]]>1 || str[begin]<=0 || str[begin]>m){
							_map[str[begin++]]--;
						}
						ans=_min(ans,i-begin+1);						
					}else{
						_map[str[i]]++;
					}
				}
				printf("%d\n",ans);
			}
		}
	}
	return 0;
}
