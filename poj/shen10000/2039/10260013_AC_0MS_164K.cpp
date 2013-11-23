#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<string>
#include<vector>
#include<stack>
#include<math.h>
#include<queue>
#include<iostream>
using namespace std;

int main()
{
char str0[202];
char str1[202];
int n;
while(scanf("%d",&n),n){
	scanf("%s",str0);
	
	int map[2]={(n<<1)+1,-1};
	int tmp=0,now;
	int l=strlen(str0)/n;
	int k=0;
	for(int i=0;i<n;i++){
		map[0]-=2;
		map[1]+=2;
		now=i;
		tmp=0;
		for(int j=0;j<l;j++){
			str1[k++]=str0[now];
			now+=map[tmp];
			tmp=tmp?0:1;
		}
	}
	str1[k]='\0';
	printf("%s\n",str1);
}
return 0;
}
