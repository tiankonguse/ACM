#include<iostream>
#include<string>
#include<queue>
#include<cmath>
#include<stack>
#include<algorithm>
using namespace std;
stack<int>sta1;
stack<int>sta2;
int min1,min2,min0;
int str[1010];
char map[2010];
int num;

void chuzhan(){
		while(1){
			if(min0==min1){
				map[num++]='b';
				sta1.pop();
				if(!sta1.empty())min1=sta1.top();
				else{min1=1010;}
				min0++;
			}else if(min0==min2){
				map[num++]='d';
				sta2.pop();
				if(!sta2.empty())min2=sta2.top();
				else{min2=1010;}
				min0++;
			}else{
				break;
			}
		}
}

void chuzhan1(){
		while(1){
			if(min0==min1){
				map[num++]='b';
				sta1.pop();
				if(!sta1.empty())min1=sta1.top();
				else{min1=1010;}
				min0++;
			}else{
				break;
			}
		}
}
void chuzhan2(){
		while(1){
			if(min0==min1){
				map[num++]='b';
				sta1.pop();
				if(!sta1.empty())min1=sta1.top();
				else{min1=1010;}
				min0++;
			}else{
				break;
			}
		}
}

bool ok1(int k){
	chuzhan1();
	if(min1<str[k])return false;
	sta1.push(str[k]);
	map[num++]='a';
	min1=sta1.top();
	chuzhan1();
	return true;
}
bool ok2(int k){
	chuzhan();
	if(min2<str[k])return false;
	sta2.push(str[k]);
	map[num++]='c';
	min2=sta2.top();
	chuzhan();
	return true;
}

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF){
		while(!sta1.empty())sta1.pop();
		while(!sta2.empty())sta2.pop();
		min1=min2=1010;
		min0=1;
		num=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&str[i]);
		}
		int i;
		for(i=1;i<=n;i++){
			if(ok1(i))continue;
			if(ok2(i))continue;
			break;
		}
		if(i>n){
			chuzhan();
			printf("%c",map[0]);
			for(int i=1;i<num;i++){
				printf(" %c",map[i]);
			}
			printf("\n");
		}else{
			printf("0\n");
		}
		
	}
	return 0;
}
