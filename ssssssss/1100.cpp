#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<stack>
#include<cmath>
#include<functional>
#include<algorithm>
using namespace std;
int str0[4];


void print(){
	for(int i=0;i<3;i++)printf("%d",str0[i]);
	puts("");
}
void dfs(int *p,int lev){
	if(lev==0){
		for(int i=0;i<4;i++){
			if(p[i]){
				str0[lev]=i+1;
				p[i]--;
				dfs(p,lev+1);
				p[i]++;
			}
		}
		
	}else if(lev==1){
		for(int i=0;i<4;i++){
			if(p[i]){
				str0[lev]=i+1;
				p[i]--;
				dfs(p,lev+1);
				p[i]++;
			}
		}
	}else if(lev==2){
		for(int i=0;i<4;i++){
			if(p[i]){
				str0[lev]=i+1;
				p[i]--;
				dfs(p,lev+1);
				p[i]++;
			}
		}
	}else{
		print();
	}
}

int main()
{
	int str1[4]={1,1,1,2};;
		dfs(str1,0);

	return 0;
}
