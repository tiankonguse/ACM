#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<algorithm>
#include<functional>
using namespace std;
int main(){
	char str[4];
	char have[][8]={"","has","have","have"};
	char map[][8]={"","one","two","three"};
	char num[][8]={"","number","numbers","numbers"};
	char be[][8]={"","is","are","are"};
	int l;
	while(cin>>str){
		l=strlen(str);
		printf("%s %s %s %s,%s %c",str,have[l],map[l],num[l],be[l],str[l-1]);
		for(int i=l-2;i>=0;i--){
			printf(",%c",str[i]);	
		}
		printf("\n");
	}
	return 0;
}
