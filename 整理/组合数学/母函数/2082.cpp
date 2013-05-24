#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<cmath>
#include<stack>
#include<algorithm>
using namespace std;
int first[60],second[60];
int main()
{
	int t;
	int _max,tmp,_maxtmp,num;
	int i,j,k;
	int ans;
	
	scanf("%d",&t);
	while(t--){
		memset(first,0,sizeof(first));
		memset(second,0,sizeof(second));
		first[0]=1;_max=0;
		for(i=1;i<=26;i++){
			scanf("%d",&num);
			if(num==0)continue;
			_maxtmp=_max;
			for(j=0;j<=_max;j++){
				for(k=0; k<=num && (tmp=k*i+j)<=50;k++){
					second[tmp]+=first[j];
					if(tmp>_maxtmp)_maxtmp=tmp;
				}
			}
			_max=_maxtmp;
			for(j=0;j<=_max;j++){
				first[j]=second[j];
				second[j]=0;
			}
		}
		ans=0;
		for(i=1;i<=_max;i++){
			ans+=first[i];
		}
		printf("%d\n",ans);
	}
	return 0;
}
