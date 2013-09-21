#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<algorithm>
#include<functional>
using namespace std;
int str[3][4];
int p[3]={1000,1000,1000};
int q[3]={10,12,16};
int sum[3];
bool ok(){
	sum[0]=sum[1]=sum[2]=0;
	for(int i=0;i<4;i++)
	for(int j=0;j<3;j++)
		sum[j]+=str[j][i];
	if(sum[0]!=sum[1])return false;
	if(sum[1]!=sum[2])return false;
	return true;
}
void add(){
	for(int j=0;j<3;j++){
		str[j][0]++;
		for(int i=0;str[j][i]==q[j];i++){
			str[j][i]=0;
			str[j][i+1]++;
		}
	}
	
}
int main(){

	for(int i=0;i<4;i++)
	for(int j=0;j<3;j++){
		str[j][i]=p[j]%q[j];
		p[j]/=q[j];
	}
	for(int i=1000;i<10000;i++){
		if(ok())cout<<i<<endl;
		add();
	}
	
	cin>>str[0][0];

	return 0;
}
