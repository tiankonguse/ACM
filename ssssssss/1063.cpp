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
	char str[400];
	char have[][8]={"has","have"};
	char map[][8]={"","one","two","three","four","five","six","seven","eight","nine","ten"};
	char num[][8]={"number","numbers"};
	char be[][8]={"is","are"};
	int l;
	char *p;
	int h;
	while(cin>>str){
		if(str[0]=='-')p=str+1;
		else p=str;
		l=strlen(p);
		if(l==1)h=0;
		else h=1;
		printf("%s %s %s %s,%s %c",str,have[h],map[l],num[h],be[h],p[l-1]);
		for(int i=l-2;i>=0;i--){
			printf(",%c",p[i]);	
		}
		printf("\n");
	}
	return 0;
}
