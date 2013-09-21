#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<cmath>
#include<stack>
#include<algorithm>
using namespace std;
int main()
{
	char str1[10],str[10];
	int n;
	while(scanf("%d",&n)!=EOF){
		memset(str1,0,sizeof(str1));
		while(n--){
			scanf("%s",str);
			for(int i=0;i<9;i++)str1[i]^=str[i];
		}
		puts(str1);
	}
	
	return 0;
}
