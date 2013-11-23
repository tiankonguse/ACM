#include<iostream>
using namespace std;
const int N=400011;
char str[N];
int restr[N],n;
int fail[N];
int initfail(char *pat){
	memset(fail,-1,sizeof(fail));
	int i,k;
	for(i=1,k;pat[i];++i){
		for(k=fail[i-1];k>=0 && pat[i]!=pat[k+1];k=fail[k]);
		if(pat[k+1] == pat[i])fail[i]=k+1; 
	}
return i;
} 

//返回匹配的第一个位置 
//返回匹配的个数  ans
int kmp(char* pat){
	int n=initfail(pat)-1; 
	int k=0;
	restr[k++]=n;
	int i=n;
	while(fail[i]!=-1){
		restr[k++]=fail[i];
		i=fail[i];
	}
	return k;
}
 
int main(){
	while(cin>>str){
		int k=kmp(str);
		for(k--;k;k--){
			printf("%d ",restr[k]+1);
		}
		printf("%d\n",restr[k]+1);
	}
return 0;
}
