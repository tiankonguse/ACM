#include<string>
#include<iostream>
using namespace std;
int str[3500];
int main()
{
	memset(str,0,sizeof(str));
	int n,m;
	int w,d,tmp;
	while(~scanf("%d%d",&n,&m)){
		for(int i=0;i<n;i++){
			scanf("%d%d",&w,&d);
			for(int j=m;j>=w;j--){
				tmp=str[j-w]+d;
				if(tmp>str[j])str[j]=tmp;
			}
		}
		printf("%d\n",str[m]);	
	}
return 0;
}
